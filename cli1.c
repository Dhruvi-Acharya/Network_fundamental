#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

main(){
	char buf[200];
	char *serv_ip = "127.0.0.1";
	int n;

	int sockfd,ret_val;
	struct sockaddr_in servaddr;

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8000);

	inet_pton	
}