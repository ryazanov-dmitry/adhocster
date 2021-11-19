#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>

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
struct AdhocsterSocket* create_adhocster_socket()
{
    // TODO: IPPROTO_UDPLITE?
    int socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (socket_desc < 0)
    {
        // TODO: Throw exception?
        return NULL;
    }

    struct sockaddr_in broadcast_addr;
    broadcast_addr.sin_family = AF_INET;
    // TODO: Make configurable.
    broadcast_addr.sin_addr.s_addr = inet_addr("192.168.0.255");
    broadcast_addr.sin_port = 1337;

    struct AdhocsterSocket *adhocsterSocket = malloc(sizeof(struct AdhocsterSocket));
    adhocsterSocket->addr = broadcast_addr;
    adhocsterSocket->socketDescriptor = socket_desc;

    return adhocsterSocket;
}