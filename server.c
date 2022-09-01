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
int sockfd,fd1,i;
char buf[100]; 
struct sockaddr_in sa;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
 sa.sin_family=AF_INET;
 sa.sin_addr.s_addr=INADDR_ANY;
 sa.sin_port=60018;
 i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
 printf("test %d%d\n",sockfd,i);
struct sockaddr *from;
int l = sizeof(struct sockaddr);
//------------------------------MAIN CODE STARTS HERE------------------------------
 buf[100];
	recvfrom(sockfd, buf, 100, 0,(struct sockaddr *)&from,&l);
	printf("%s\n", buf);
 for(int k=0; k < 100; k++) buf[k] = '\0';
	strcpy(buf,"Message acknowledged.");
	sendto(sockfd, buf, 100, 0,(struct sockaddr*)&from,l);

close(fd1);
 }
