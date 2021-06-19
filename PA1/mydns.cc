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


int main(int argc, char *argv[])
{
  // define your variables here                                                                          
  int i;
  struct hostent *he;
  struct in_addr **addr_list;

  // check that there are enough parameters                                                              
  if (argc != 2)
    {
      fprintf(stderr, "Usage: mydns <hostname>\n");
      exit(-1);
    }






  // Address resolution stage by using gethostbyname()                                                   
  // Write your code here!
  // Print to standard output


 if ((he = gethostbyname(argv[1])) == NULL) {  // get the host info
        herror("gethostbyname");
        return 2;
    }

    
    
    addr_list = (struct in_addr **)he->h_addr_list;
    for(i = 0; addr_list[i] != NULL; i++) {
      printf("Name:   %s\n", he->h_name);
      printf("Address:   %s\n", inet_ntoa(*addr_list[i]));
    }
    printf("\n"); \\taken from https://beej.us/guide/bgnet/html/#gethostnameman

    return 0;
}
