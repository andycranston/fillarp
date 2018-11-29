# fillarp

Fill ARP table by sending dummy packets to a specified IPv4 address range.

## what is this useful

By sending dummy packets to a range of IP addresses on
the local LAN segment a side effect is
that the local ARP (Address Resolution Protocol) cache will be populated
with entries.

The upshot of this is that by running:

```
arp -n
```

the mapping between MAC addresses and IP addresses can be determined.

## compiling

The is a Makefile to must run:

```
make
make userinstall
```

This will copy the compiled `fillarp` command to the `$HOME/bin` directory.

## running

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

## warnings

You must be careful not to fill up the ARP cache on you system.  With this
in mind the `fillarp` command will never send more than 256 packets in any
single run.  If in doubt check with your local network administrator.  You never
know they might have a use of their own for the `fillarp` command :-]

-------------------------------------------------------

End of document
