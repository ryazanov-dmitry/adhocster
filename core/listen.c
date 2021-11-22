#include "socket.c"
#include <pthread.h>

void *listen_loop(void *arg);

// TODO: How to do it without global var?
void (*messageHandler)(char m[]);
struct AdhocsterSocket *listenSocket;

int listen_adhoc(struct AdhocsterSocket *socket, void (*f)(char m[]))
{
    messageHandler = f;
    listenSocket = socket;

    int bindCode = bind(
        socket->socketDescriptor,
        (struct sockaddr *)&socket->addr,
        sizeof(socket->addr));

    if (bindCode < 0)
    {
        return bindCode;
    }

    pthread_t threadId;
    // thrd_create(&thr, listen_loop, NULL);
    pthread_create(&threadId, NULL, listen_loop, NULL);
}

void *listen_loop(void *arg)
{
    int addrSize = sizeof(listenSocket->addr);

    //TODO: Maybe it is not the best way?
    while (1)
    {

        char message[2000];

        int recvCode = recvfrom(
            listenSocket->socketDescriptor,
            message,
            sizeof(message),
            0,
            (struct sockaddr *)&listenSocket->addr,
            &addrSize);

        if(recvCode < 0)
        {
            printf("Failed to receive message.");
            return NULL;
        }

        messageHandler(message);
    }
}