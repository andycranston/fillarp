# fillarp

Fill ARP table by sending dummy packets to a specified IPv4 address range.

## Before reading more ...

You might want to look at the `arping` command by Thomas Habets.  Here are the details:

> Arping was written by Thomas Habets <thomas@habets.se>.

> http://www.habets.pp.se/synscan/

> git clone http://github.com/ThomasHabets/arping.git

## Why is the fillarp command useful?

By sending dummy packets to a range of IP addresses on the local LAN
segment a side effect is that the local ARP (Address Resolution Protocol)
cache will be populated with entries.

The upshot of this is that by running:

```
arp -n
```

the mapping between MAC addresses and IP addresses can be determined.

## Compiling

There is a Makefile - to compile and install run:

```
make
make userinstall
```

This will copy the compiled `fillarp` command to the `$HOME/bin` directory.

## Running

Let us assume your system has the IP address `192.168.1.13` with a subnet
of `255.255.255.0`.  By running:

```
fillarp 192.168.1 1 254
```

and then:

```
arp -n
```

you will see all active devices on you local LAN.

## Example arp output

Below is example output of a `arp -n` command after running `fillarp 192.168.1 1 254`:

```
Address                  HWtype  HWaddress           Flags Mask            Iface
192.168.1.49                     (incomplete)                              ens160
192.168.1.18                     (incomplete)                              ens160
192.168.1.216                    (incomplete)                              ens160
192.168.1.165                    (incomplete)                              ens160
192.168.1.134                    (incomplete)                              ens160
192.168.1.99                     (incomplete)                              ens160
192.168.1.76                     (incomplete)                              ens160
192.168.1.41                     (incomplete)                              ens160
192.168.1.10                     (incomplete)                              ens160
192.168.1.215                    (incomplete)                              ens160
192.168.1.176                    (incomplete)                              ens160
192.168.1.157                    (incomplete)                              ens160
192.168.1.126                    (incomplete)                              ens160
192.168.1.91             ether   20:10:7a:29:a0:77   C                     ens160
192.168.1.36                     (incomplete)                              ens160
192.168.1.1              ether   b8:27:eb:71:8a:f6   C                     ens160
192.168.1.226                    (incomplete)                              ens160
192.168.1.207            ether   00:0d:5d:07:6a:85   C                     ens160
192.168.1.168                    (incomplete)                              ens160
192.168.1.117                    (incomplete)                              ens160
192.168.1.86                     (incomplete)                              ens160
192.168.1.51                     (incomplete)                              ens160
192.168.1.28                     (incomplete)                              ens160
192.168.1.249                    (incomplete)                              ens160
192.168.1.218                    (incomplete)                              ens160
192.168.1.167                    (incomplete)                              ens160
192.168.1.128                    (incomplete)                              ens160
192.168.1.109                    (incomplete)                              ens160
192.168.1.78                     (incomplete)                              ens160
192.168.1.43                     (incomplete)                              ens160
192.168.1.244                    (incomplete)                              ens160
192.168.1.209                    (incomplete)                              ens160
192.168.1.178                    (incomplete)                              ens160
192.168.1.159                    (incomplete)                              ens160
192.168.1.120                    (incomplete)                              ens160
192.168.1.69                     (incomplete)                              ens160
192.168.1.38                     (incomplete)                              ens160
192.168.1.3              ether   b8:27:eb:c3:27:b5   C                     ens160
192.168.1.236                    (incomplete)                              ens160
192.168.1.201                    (incomplete)                              ens160
192.168.1.170                    (incomplete)                              ens160
192.168.1.119                    (incomplete)                              ens160
192.168.1.80                     (incomplete)                              ens160
192.168.1.61                     (incomplete)                              ens160
192.168.1.30                     (incomplete)                              ens160
192.168.1.251                    (incomplete)                              ens160
192.168.1.196                    (incomplete)                              ens160
192.168.1.161                    (incomplete)                              ens160
192.168.1.130                    (incomplete)                              ens160
192.168.1.111                    (incomplete)                              ens160
192.168.1.72                     (incomplete)                              ens160
192.168.1.21                     (incomplete)                              ens160
192.168.1.246                    (incomplete)                              ens160
192.168.1.211                    (incomplete)                              ens160
192.168.1.188                    (incomplete)                              ens160
192.168.1.153                    (incomplete)                              ens160
192.168.1.122                    (incomplete)                              ens160
192.168.1.71                     (incomplete)                              ens160
192.168.1.32                     (incomplete)                              ens160
192.168.1.238                    (incomplete)                              ens160
192.168.1.203                    (incomplete)                              ens160
192.168.1.148                    (incomplete)                              ens160
192.168.1.113                    (incomplete)                              ens160
192.168.1.82                     (incomplete)                              ens160
192.168.1.63                     (incomplete)                              ens160
192.168.1.24                     (incomplete)                              ens160
192.168.1.229                    (incomplete)                              ens160
192.168.1.198                    (incomplete)                              ens160
192.168.1.163                    (incomplete)                              ens160
192.168.1.140                    (incomplete)                              ens160
192.168.1.105                    (incomplete)                              ens160
192.168.1.74                     (incomplete)                              ens160
192.168.1.23                     (incomplete)                              ens160
192.168.1.240                    (incomplete)                              ens160
192.168.1.221                    (incomplete)                              ens160
192.168.1.190                    (incomplete)                              ens160
192.168.1.155                    (incomplete)                              ens160
192.168.1.100                    (incomplete)                              ens160
192.168.1.65             ether   50:c7:bf:5b:0d:56   C                     ens160
192.168.1.34                     (incomplete)                              ens160
192.168.1.15                     (incomplete)                              ens160
192.168.1.232                    (incomplete)                              ens160
192.168.1.181                    (incomplete)                              ens160
192.168.1.150                    (incomplete)                              ens160
192.168.1.115                    (incomplete)                              ens160
192.168.1.92             ether   7c:dd:90:a9:ab:16   C                     ens160
192.168.1.57                     (incomplete)                              ens160
192.168.1.26                     (incomplete)                              ens160
192.168.1.231                    (incomplete)                              ens160
192.168.1.192                    (incomplete)                              ens160
192.168.1.173                    (incomplete)                              ens160
192.168.1.142                    (incomplete)                              ens160
192.168.1.107                    (incomplete)                              ens160
192.168.1.52                     (incomplete)                              ens160
192.168.1.17                     (incomplete)                              ens160
192.168.1.242                    (incomplete)                              ens160
192.168.1.223                    (incomplete)                              ens160
192.168.1.184                    (incomplete)                              ens160
192.168.1.133                    (incomplete)                              ens160
192.168.1.102                    (incomplete)                              ens160
192.168.1.67                     (incomplete)                              ens160
192.168.1.44                     (incomplete)                              ens160
192.168.1.9                      (incomplete)                              ens160
192.168.1.234                    (incomplete)                              ens160
192.168.1.183                    (incomplete)                              ens160
192.168.1.144                    (incomplete)                              ens160
192.168.1.125                    (incomplete)                              ens160
192.168.1.94                     (incomplete)                              ens160
192.168.1.59                     (incomplete)                              ens160
192.168.1.4                      (incomplete)                              ens160
192.168.1.225                    (incomplete)                              ens160
192.168.1.194                    (incomplete)                              ens160
192.168.1.175                    (incomplete)                              ens160
192.168.1.136                    (incomplete)                              ens160
192.168.1.85             ether   60:30:d4:be:cd:34   C                     ens160
192.168.1.54                     (incomplete)                              ens160
192.168.1.19                     (incomplete)                              ens160
192.168.1.252                    (incomplete)                              ens160
192.168.1.217                    (incomplete)                              ens160
192.168.1.186                    (incomplete)                              ens160
192.168.1.135                    (incomplete)                              ens160
192.168.1.96                     (incomplete)                              ens160
192.168.1.77                     (incomplete)                              ens160
192.168.1.46                     (incomplete)                              ens160
192.168.1.11                     (incomplete)                              ens160
192.168.1.212                    (incomplete)                              ens160
192.168.1.177                    (incomplete)                              ens160
192.168.1.146                    (incomplete)                              ens160
192.168.1.127                    (incomplete)                              ens160
192.168.1.88                     (incomplete)                              ens160
192.168.1.37                     (incomplete)                              ens160
192.168.1.6              ether   00:0d:5d:07:6a:85   C                     ens160
192.168.1.227                    (incomplete)                              ens160
192.168.1.204                    (incomplete)                              ens160
192.168.1.169                    (incomplete)                              ens160
192.168.1.138                    (incomplete)                              ens160
192.168.1.87                     (incomplete)                              ens160
192.168.1.48                     (incomplete)                              ens160
192.168.1.29                     (incomplete)                              ens160
192.168.1.254            ether   a0:1b:29:50:91:2e   C                     ens160
192.168.1.219                    (incomplete)                              ens160
192.168.1.164                    (incomplete)                              ens160
192.168.1.129                    (incomplete)                              ens160
192.168.1.98                     (incomplete)                              ens160
192.168.1.79                     (incomplete)                              ens160
192.168.1.40                     (incomplete)                              ens160
192.168.1.245                    (incomplete)                              ens160
192.168.1.214                    (incomplete)                              ens160
192.168.1.179                    (incomplete)                              ens160
192.168.1.156                    (incomplete)                              ens160
192.168.1.121                    (incomplete)                              ens160
192.168.1.90                     (incomplete)                              ens160
192.168.1.39                     (incomplete)                              ens160
192.168.1.237                    (incomplete)                              ens160
192.168.1.206                    (incomplete)                              ens160
192.168.1.171                    (incomplete)                              ens160
192.168.1.116                    (incomplete)                              ens160
192.168.1.81                     (incomplete)                              ens160
192.168.1.50                     (incomplete)                              ens160
192.168.1.31                     (incomplete)                              ens160
192.168.1.248                    (incomplete)                              ens160
192.168.1.197                    (incomplete)                              ens160
192.168.1.166                    (incomplete)                              ens160
192.168.1.131                    (incomplete)                              ens160
192.168.1.108                    (incomplete)                              ens160
192.168.1.73                     (incomplete)                              ens160
192.168.1.42                     (incomplete)                              ens160
192.168.1.247                    (incomplete)                              ens160
192.168.1.208                    (incomplete)                              ens160
192.168.1.189                    (incomplete)                              ens160
192.168.1.158                    (incomplete)                              ens160
192.168.1.123                    (incomplete)                              ens160
192.168.1.68             ether   10:ae:60:d5:8f:3c   C                     ens160
192.168.1.33                     (incomplete)                              ens160
192.168.1.2              ether   a0:d3:c1:24:80:5d   C                     ens160
192.168.1.239                    (incomplete)                              ens160
192.168.1.200                    (incomplete)                              ens160
192.168.1.149                    (incomplete)                              ens160
192.168.1.118                    (incomplete)                              ens160
192.168.1.83                     (incomplete)                              ens160
192.168.1.60                     (incomplete)                              ens160
192.168.1.25                     (incomplete)                              ens160
192.168.1.250                    (incomplete)                              ens160
192.168.1.199                    (incomplete)                              ens160
192.168.1.160                    (incomplete)                              ens160
192.168.1.141                    (incomplete)                              ens160
192.168.1.110                    (incomplete)                              ens160
192.168.1.75                     (incomplete)                              ens160
192.168.1.20                     (incomplete)                              ens160
192.168.1.241                    (incomplete)                              ens160
192.168.1.210                    (incomplete)                              ens160
192.168.1.191                    (incomplete)                              ens160
192.168.1.152                    (incomplete)                              ens160
192.168.1.101                    (incomplete)                              ens160
192.168.1.70                     (incomplete)                              ens160
192.168.1.35                     (incomplete)                              ens160
192.168.1.12             ether   00:0c:29:3d:d2:f0   C                     ens160
192.168.1.233                    (incomplete)                              ens160
192.168.1.202                    (incomplete)                              ens160
192.168.1.151                    (incomplete)                              ens160
192.168.1.112                    (incomplete)                              ens160
192.168.1.93                     (incomplete)                              ens160
192.168.1.62                     (incomplete)                              ens160
192.168.1.27                     (incomplete)                              ens160
192.168.1.228                    (incomplete)                              ens160
192.168.1.193                    (incomplete)                              ens160
192.168.1.162                    (incomplete)                              ens160
192.168.1.143                    (incomplete)                              ens160
192.168.1.104                    (incomplete)                              ens160
192.168.1.53                     (incomplete)                              ens160
192.168.1.22                     (incomplete)                              ens160
192.168.1.243                    (incomplete)                              ens160
192.168.1.220                    (incomplete)                              ens160
192.168.1.185                    (incomplete)                              ens160
192.168.1.154                    (incomplete)                              ens160
192.168.1.103                    (incomplete)                              ens160
192.168.1.64                     (incomplete)                              ens160
192.168.1.45                     (incomplete)                              ens160
192.168.1.14                     (incomplete)                              ens160
192.168.1.235                    (incomplete)                              ens160
192.168.1.180                    (incomplete)                              ens160
192.168.1.145                    (incomplete)                              ens160
192.168.1.114                    (incomplete)                              ens160
192.168.1.95                     (incomplete)                              ens160
192.168.1.56                     (incomplete)                              ens160
192.168.1.5              ether   00:0f:90:4f:41:c0   C                     ens160
192.168.1.230                    (incomplete)                              ens160
192.168.1.195                    (incomplete)                              ens160
192.168.1.172                    (incomplete)                              ens160
192.168.1.137                    (incomplete)                              ens160
192.168.1.106                    (incomplete)                              ens160
192.168.1.55                     (incomplete)                              ens160
192.168.1.16                     (incomplete)                              ens160
192.168.1.253                    (incomplete)                              ens160
192.168.1.222                    (incomplete)                              ens160
192.168.1.187                    (incomplete)                              ens160
192.168.1.132                    (incomplete)                              ens160
192.168.1.97                     (incomplete)                              ens160
192.168.1.66                     (incomplete)                              ens160
192.168.1.47                     (incomplete)                              ens160
192.168.1.8              ether   e4:11:5b:40:d0:80   C                     ens160
192.168.1.213                    (incomplete)                              ens160
192.168.1.182                    (incomplete)                              ens160
192.168.1.147                    (incomplete)                              ens160
192.168.1.124                    (incomplete)                              ens160
192.168.1.89                     (incomplete)                              ens160
192.168.1.58                     (incomplete)                              ens160
192.168.1.7                      (incomplete)                              ens160
192.168.1.224                    (incomplete)                              ens160
192.168.1.205                    (incomplete)                              ens160
192.168.1.174                    (incomplete)                              ens160
192.168.1.139                    (incomplete)                              ens160
192.168.1.84             ether   50:dc:e7:0d:f1:e1   C                     ens160
```

## Warnings

You must be careful not to fill up the ARP cache on your system.  With this
in mind the `fillarp` command will never send more than 256 packets in
any single run.  Most UNIX/Linux ARP caches can hold 2048 entries so a
256 packet limit seems safe.

If in doubt about running `fillarp` on a host check with your local
network administrator.  You never know they might have a use of their
own for the `fillarp` command :-]

-------------------------------------------------------

End of document
