#include<netdb.h>
#include<stdio.h>

main(){
	char **names;
	int i;

	struct servent *se = NULL;

	while((se = getservent())!=NULL){
		printf("-----------\n");
		printf("Official service name = %s\n",se->s_name);
		printf("port no = %d\n",ntohs(se->s_port));
		printf("protocol = %s\n",se->s_proto);
		names = se->s_aliases;

		for(i=0;names[i]!=NULL;i++)
			printf("...%s...\n",names[i]);

		printf("-----------\n");
	}
}