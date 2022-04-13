#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>

#define PORT 8000
#define MAXSZ 100
int main()
{
	int sockfd;
	int newsockfd;

	struct sockaddr_in cliaddr,servaddr;

	int n;
	char msg[MAXSZ];
	int clilen;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	memset(&servaddr,0,sizeof(servaddr));

	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port=htons(PORT);

	//bind the socket with the server address and port
	bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

	//listen for connection from client
	listen(sockfd,5);

	//accept 
	while(1)
	{

		printf("\n***********server waiting for new client connection:*********\n");
		clilen=sizeof(cliaddr);
		newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);

		while(1){
			n=recv(newsockfd,msg,MAXSZ,0);
			if(n==0){
				close(newsockfd);
				break;
			}
			msg[n]=0;
			send(newsockfd,msg,n,0);

			printf("Receive and set:%s\n",msg);
		}
		
	}

	return 0;
}