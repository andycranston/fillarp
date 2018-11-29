/*
 *  @(!--#) @(#) fillarp.c, version 005, 29-november-2018
 *
 *  fill the arp table with a range of possible entries over a IPv4 subnet
 *
 */

/*****************************************************************************/

/*
 *  includes
 */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*****************************************************************************/

/*
 *  defines
 */

#define PORTBASE 55555

#define MAX_IPv4_ADDRESS_LENGTH 15

#define FAILSAFE_MAX 256

#define MESSAGE_TEXT "This UDP packet sent by program fillarp by Andy Cranston (andy@cranstonhub.com) - https://github.com/andycranston/fillarp"

/*****************************************************************************/

/*
 *  globals
 */

char *progname;

/*****************************************************************************/

void usage()
{
  fprintf(stderr, "%s: not enough arguments\n", progname);
  fprintf(stderr, "\tusage:\n");
  fprintf(stderr, "\t\t%s basenetwork startsubnet endsubnet\n", progname);
  fprintf(stderr, "\texample:\n");
  fprintf(stderr, "\t\t%s 192.168.1 1 254\n", progname);

  return;
}

/*****************************************************************************/

char *basename(filespec)
  char *filespec;
{
  char *bname;

  bname = filespec;

  while (*filespec != '\0') {
    if (*filespec == '/') {
      bname = filespec + 1;
    }

    filespec++;
  }

  return (bname);
}

/*****************************************************************************/

int main(argc, argv)
  int   argc;
  char *argv[];
{
  int       sock;
  struct    sockaddr_in   destaddress;
  socklen_t addresssize;
  char     *basenetwork;
  int       startsubnet;
  int       endsubnet;
  char      ipaddress[MAX_IPv4_ADDRESS_LENGTH+sizeof(char)];
  int       i;
  int       failsafecounter;
  int       messagetextlength;

  progname = basename(argv[0]);

  if (argc < 4) {
    usage();
    exit(1);
  }

  basenetwork = argv[1];
  startsubnet = atoi(argv[2]);
  endsubnet   = atoi(argv[3]);

  if (startsubnet < 0) {
    fprintf(stderr, "%s: start subnet number is negative\n", progname);
    exit(1);
  }

  if (startsubnet > 255) {
    fprintf(stderr, "%s: start subnet number greater than 255\n", progname);
    exit(1);
  }

  if (endsubnet < 0) {
    fprintf(stderr, "%s: end subnet number is negative\n", progname);
    exit(1);
  }

  if (endsubnet > 255) {
    fprintf(stderr, "%s: end subnet number greater than 255\n", progname);
    exit(1);
  }

  if (startsubnet > endsubnet) {
    fprintf(stderr, "%s: start subnet number greater than end subnet number\n", progname);
    exit(1);
  }

  messagetextlength = strlen(MESSAGE_TEXT);

  failsafecounter = 0;

  for (i = startsubnet; i<= endsubnet; i++) {
    failsafecounter++;

    if (failsafecounter > FAILSAFE_MAX) {
      fprintf(stderr, "%s: sent too many packets - limit is %d\n", progname, FAILSAFE_MAX);
      exit(1);
    }

    snprintf(ipaddress, MAX_IPv4_ADDRESS_LENGTH, "%s.%d", basenetwork, i);

    /* printf("[%s]\n", ipaddress); */

    sock = socket(PF_INET, SOCK_DGRAM, 0);

    destaddress.sin_family      = AF_INET;
    destaddress.sin_port        = htons(PORTBASE);
    destaddress.sin_addr.s_addr = inet_addr(ipaddress);

    memset(destaddress.sin_zero, '\0', sizeof(destaddress.sin_zero));

    addresssize = sizeof(destaddress);

    sendto(sock, MESSAGE_TEXT, messagetextlength, 0, (struct sockaddr *)&destaddress, addresssize);

    close(sock);
  }

  exit(0);
}

/**********************************************************************/
