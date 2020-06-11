#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

void main()
{
	int sockfd;
	struct sockaddr_in serverAddr;
	int newSocket;
	struct sockaddr_in newAddr;
	socklen_t addr_size;
	char buffer[1024];

	sockfd=socket(PF_INET,SOCK_STREAM,0);
	memset(&serverAddr,'\0',sizeof(serverAddr)); //set memory 
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(8080);
	serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	bind(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));

	listen(sockfd,5);
	addr_size=sizeof(newAddr);

	
	newSocket=accept(sockfd,(struct sockaddr*)&newAddr,&addr_size);
	
	scanf("%s",buffer);
	send(newSocket,buffer,strlen(buffer),0);
}
;
