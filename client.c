#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
  int i,sockfd;
  char buf[100];
  struct sockaddr_in sa;
  sockfd=socket(AF_INET,SOCK_DGRAM,0);
  sa.sin_family=AF_INET;
  sa.sin_addr.s_addr=inet_addr("127.0.0.1"); //Loop back IP address
  sa.sin_port=60018;
	//-------------MAIN CODE STARTS HERE --------------------
int l = sizeof(sa);
	strcpy(buf,"message from client - Anurag Maurya");
	sendto(sockfd, buf, 100, 0,(struct sockaddr *)&sa,l);
	for(i=0; i < 100; i++) buf[i] = '\0';
  recvfrom(sockfd, buf, 100, 0,(struct sockaddr*)sa.sin_addr.s_addr,l);
	printf("%s\n", buf);
close(sockfd);
}
