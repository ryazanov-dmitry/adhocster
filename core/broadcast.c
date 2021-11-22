#include <stdio.h>
#include "socket.c"

/*
Broadcasts string message using AdhocsterSocket.
Returns -1 if something went wrong.
*/
int broadcast(struct AdhocsterSocket *socket, char message[])
{
    ssize_t result = sendto(
        socket->socketDescriptor,
        message,
        strlen(message),
        0,
        (struct sockaddr *)&socket->addr,
        sizeof(socket->addr));

    if (result < 0)
    {
        printf("Failed to send.\n");
        return -1;
    }

    return result;
}
