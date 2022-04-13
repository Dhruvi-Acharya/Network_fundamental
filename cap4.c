
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netpacket/packet.h>
#include<net/ethernet.h>

main(){
	int pack_socket,n;
	struct sockaddr_ll sa;
	socklen_t sl;
	char buf[2000];

	//sock_raw keeps physical layer header sock_dgram removes it

//	sl = sizeof(struct sockaddr_ll);

	pack_socket=socket(PF_PACKET,SOCK_DGRAM,htons(ETH_P_ALL));

	//pack_socket=socket(PF_PACKET,SOCK_RAW,htons(ETH_P_ALL));


	if(pack_socket<0){
		printf("failed to open packet socket\n");
		exit(0);
	}

	printf("packet socket successfully opened\n");
	while(1){
		sl = sizeof(struct sockaddr_ll);
		n=recvfrom(pack_socket,buf,2000,0,(struct sockaddr *)&sa,&sl);
		printf("received packet of length %d\n",n);
		printf("packet type: %d\n",sa.sll_pkttype);
		printf("hardware address length: %d\n",sa.sll_halen);
		printf("protocol: %x\n",ntohs(sa.sll_protocol));
	}
	close(pack_socket);
}