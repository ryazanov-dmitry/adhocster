#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>

#ifndef SOCKET_C
#define SOCKET_C
struct AdhocsterSocket
{
    struct sockaddr_in addr;
    int socketDescriptor;
};

/*
This function is responsible for creating structures
for adhocster's message broadcast: UDP socket with configurable
broadcast address.
*/
struct AdhocsterSocket* create_adhocster_socket(char broadcastIp[], int port)
{
    // TODO: IPPROTO_UDPLITE?
    int socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (socket_desc < 0)
    {
        return NULL;
    }

    struct sockaddr_in broadcast_addr;
    broadcast_addr.sin_family = AF_INET;
    // TODO: Make configurable.
    broadcast_addr.sin_addr.s_addr = inet_addr(broadcastIp);
    broadcast_addr.sin_port = port;

    struct AdhocsterSocket *adhocsterSocket = malloc(sizeof(struct AdhocsterSocket));
    adhocsterSocket->addr = broadcast_addr;
    adhocsterSocket->socketDescriptor = socket_desc;

    return adhocsterSocket;
}
#endif