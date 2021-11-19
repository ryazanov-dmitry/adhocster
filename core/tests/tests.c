#include <stdio.h>
#include "../broadcast.c"
#include "../socket.c"

void assert(int, int);
void broadcast_happypath(void);
void plus_happypath(void);
void create_udp_socket(void);
void create_adhocster_socket_happypath(void);

int main()
{
    plus_happypath();
    create_adhocster_socket_happypath();
}

/////// Tests

void create_adhocster_socket_happypath(void)
{
    printf("Testing: create_adhocster_socket_happypath\n");
    struct AdhocsterSocket *socket = create_adhocster_socket();
}

void broadcast_happypath(void)
{
    // int udpSocket = create_adhocster_socket();
    // char *message = "hello";
    // broadcast(message, udpSocket);
}

void plus_happypath(void)
{
    printf("Testing: plus_happypath\n");

    int result = plus(2, 1);

    assert(2, result);
}

/////// Testing Library

void assert(int expected, int actual)
{
    if (expected != actual)
    {
        printf("Fail: '%d' != '%d'\n", expected, actual);
        return;
    }
}
