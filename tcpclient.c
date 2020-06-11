#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

void main()
{
	int clientSocket;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	
	//Establish Connection
	clientSocket=socket(PF_INET,SOCK_STREAM,0);  //Create End point for communication
	memset(&serverAddr,'\0',sizeof(serverAddr)); //set memory 
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(8080);
	serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	//Start Connection
	connect(clientSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));

	//Receive Data from Sever
	recv(clientSocket,buffer,1024,0);
	printf("Data Received: %s",buffer);

	
}

