# Notes on _Computer System: A Programmer's Perspetive_

Author: Junjia Wang

Date: Since 28 Nov 2021

## 1. Computer Network

### Basic of Network

Type1: Host(Adapter) -> Hub(1Mbps) -> Bridge(1Gbps) = LAN

Type2 : Host + Host = LAN -> Router + Router = WAN

Internet Protocol will define:

* Naming Scheme
* Delivery Mechanism

Data Transformation from Host A to Host B

LAN1 Frame Header: to router

Frame include internet Header: to Host B

Router fetch internet Header,  then create a new LAN2 Frame Header, to Host B, forward it to LAN2 adapter2

LAN2 adapter forward it to host B, then protocol software strips off the two headers, send it to server's address

### The Global IP Intenet

IP Protocol: unreliable, from host to host

UDP(Unreliable Datagram Protocol): extended IP, from process to process

Internet Properties:

* The set of hosts is mapped to a set of 32-bit *IP addresses.*
* The set of IP addresses is mapped to a set of identifiers called *Internet domain names.*
* A process on one Internet host can communicate with a process on any other Internet host over a *connection*.

IPv4 vs Ipv6

* The original Internet protocol, with its 32-bit addresses, is known as Internet Protocol Version 4 (IPv4).
* Internet Protocol Version 6 (IPv6), that uses 128-bit addresses and that was intended as the successor to IPv4.

IP address presented:

0x8002c2f2 = 128.2.194.242 (dotted-decimal representation)

ICANN (Internet Corporation for Assigned Names and Numbers) maintain the first-level domain names

Their DNS Database define millions of host-entries, mappping from domain names to IP addresses.

localhost -> *loopback address* 127.0.0.1:

multiple domain name -> same IP address

In the most general case, multiple domain names are mapped to the same set of multiple IP addresses:

```shell
linux> *nslookup www.twitter.com* 
 Address: 199.16.156.6
 Address: 199.16.156.70
 Address: 199.16.156.102 Address: 199.16.156.230
```

### Internet Connections

A *socket* is an end point of a connection

* Web servers typically use port 80, and email servers use port 25. 

* Web service is http, and the well-known name for email is smtp.

* The mapping between well-known names and well-known ports is contained in a file called /etc/services.

This pair of socket addresses is known as a *socket pair* and is denoted by the tuple

```
(*cliaddr*:*cliport*, *servaddr*:*servport*)
```

### The Sockets Interface

* A set of functions in conjuction with Unix I/O functions
* Implemented by UCB

```C
  /* IP socket address structure */
  struct sockaddr_in  {
    uint16_t        sin_family;  /* Protocol family (always AF_INET) */
    uint16_t        sin_port;    /* Port number in network byte order */
    struct in_addr  sin_addr;    /* IP address in network byte order */
    unsigned char   sin_zero[8]; /* Pad to sizeof(struct sockaddr) */
};
/* Generic socket address structure (for connect, bind, and accept) */
struct sockaddr {
        uint16_t  sa_family;    /* Protocol family */
        char      sa_data[14];  /* Address data  */
    };

```
