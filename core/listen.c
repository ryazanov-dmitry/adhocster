#include "socket.c"
#include <threads.h>

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

    //
    thrd_create(&thr[n], mythread, NULL);
}

void listen_loop(void)
{
    while (true)
    {

        int recvCode = recvfrom(
            socklistenSocket->socketDescriptor,
            client_message,
            sizeof(client_message),
            0,
            (struct sockaddr *)&client_addr,
            &client_struct_length);
    }
}