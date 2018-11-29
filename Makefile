#
# Makefile for the fillarp command
#
# "make" to compile in current directory
#
# "make userinstall" to copy compiled binary to $HOME/bin
#

fillarp: fillarp.c
	gcc -o fillarp fillarp.c

fillarp.c:

userinstall:
	cp -p fillarp     $(HOME)/bin/fillarp
	chmod u=rwx,go=rx $(HOME)/bin/fillarp
