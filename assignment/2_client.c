#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char buf[200];
	char *serv_ip = "127.0.0.1";
	int n;
	int sockfd,ret_val;
	struct sockaddr_in servaddr;
// struct sockaddr srv1;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8001);
	inet_pton(AF_INET,serv_ip,&servaddr.sin_addr);
	ret_val = connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	if(ret_val<0)
	{
		perror("connect:");
		exit(1);
	}
	printf("Client established connection with server\n");
	printf("Enter the data that you want to send to the server\n");
	gets(buf);
	write(sockfd,buf,strlen(buf));
	sleep(1);
	n = read(sockfd,buf,200);
	buf[n] = '\0';
	printf("Hello1\n");
	printf("rec'd %s from server\n",buf);
	close(sockfd);
}