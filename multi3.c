#include <stdio.h>
#include <sys/types.h>//socket
#include <sys/socket.h>//socket
#include <string.h>//memset
#include <stdlib.h>//sizeof
#include <netinet/in.h>//INADDR_ANY
#include <string.h>
#include <strings.h>
#include<sys/time.h>
#include<fcntl.h>

main(){
	int fd1,fd2;
	fd_set read_set,write_set,except_set;
	char buf[10];
	struct timeval timeout;
	int n;

	timeout.tv_sec = 90;

	fd1 = open("./cliudp",O_RDWR);
	fd2 = open("./srvudp",O_RDWR);

	FD_ZERO(&read_set);

	FD_SET(fd1,&read_set);
	FD_SET(fd2,&read_set);

	n = select(FD_SETSIZE,&read_set,NULL,NULL,&timeout);

	if(n<0){
		perror("select ");
		exit(1);
	}

	if(FD_ISSET(fd1,&read_set)){
		printf("reading from fd1 (max)\n");
		n = read(fd1,buf,10);
		printf("read %d from max\n",n);
	}

	if(FD_ISSET(fd2,&read_set)){
		printf("reading from fd2 (dup2)\n");
		n = read(fd2,buf,10);
		printf("read %d from dup2\n",n);	
	}

	printf("no of descriptor ready = %d\n",n);
}