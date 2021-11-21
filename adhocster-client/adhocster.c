#include "../core/socket.c"
#include "../core/listen.c"
#include "../core/broadcast.c"
#include <stdio.h>

#define BROADCAST_IP "127.0.0.1"
#define ADHOCSTER_PORT 1337
#define CLIENT_MESSAGE_LENGTH 50

void incoming_message_renderer(char m[]);

int main()
{
    // TODO: Make ip configurable.
    struct AdhocsterSocket *broadcastSocket = create_adhocster_socket(BROADCAST_IP, ADHOCSTER_PORT);
    int listenCode = listen_adhoc(broadcastSocket, incoming_message_renderer);

    if (listenCode < 0)
    {
        printf("Failed to listen broadcast address.");
    }

    struct AdhocsterSocket *clientSocket = create_adhocster_socket(BROADCAST_IP, ADHOCSTER_PORT);

    while (1)
    {
        char clientMessage[CLIENT_MESSAGE_LENGTH];
        fgets(clientMessage, CLIENT_MESSAGE_LENGTH, stdin);

        broadcast(clientSocket, clientMessage);
    }
}

void incoming_message_renderer(char m[])
{
    printf("%s\n", m);
}
