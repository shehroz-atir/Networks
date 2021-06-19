#include <stdio.h> // basic I/O
#include <stdlib.h>
#include <sys/types.h> // standard system types
#include <netinet/in.h> // Internet address structures
#include <sys/socket.h> // socket API
#include <arpa/inet.h>
#include <netdb.h> // host to IP resolution
#include <string.h>
#include <unistd.h>

#define HOSTNAMELEN 40 // maximal host name length; can make it variable if you want
#define BUFLEN 1024 // maximum response size; can make it variable if you want
#define PORT 13 // port of daytime server

int main(int argc, char *argv[])
{
  // define your variables here
	int returnc, socket_d;
	char*	ptr;     
    char buffr[BUFLEN+1];
    struct hostent*     host_ip;  
    struct sockaddr_in	socket_add;            
    


  // check that there are enough parameters
  if (argc != 2)
    {
      fprintf(stderr, "Usage: mydaytime <hostname>\n");
      exit(-1);
    }
    host_ip=gethostbyname(argv[1]);
    if(!host_ip){
    	printf("Can not resolve hostname\n");
    	exit(-1);
    }

    socket_add.sin_family=AF_INET;
    socket_add.sin_port=htons(PORT);
    memcpy(&socket_add.sin_addr.s_addr, host_ip->h_addr_list[0], host_ip->h_length);

    socket_d=socket(AF_INET,SOCK_STREAM,0);
    returnc=connect(socket_d,(struct sockaddr *)&socket_add,sizeof(socket_add));
    ptr=buffr;

    while(returnc=read(socket_d,ptr,BUFLEN-(ptr-buffr))>0){
    	ptr=ptr+returnc;
    };
    printf("daytime: %s\n", buffr);
  // Write your code here

  return 0;
    }

