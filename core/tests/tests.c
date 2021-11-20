#include <stdio.h>
#include "../broadcast.c"
#include "../socket.c"

void assert(int, int);
void broadcast_happypath(void);
void create_udp_socket(void);
void create_adhocster_socket_happypath(void);
void not_null(void *pointer);
void broadcast_wrongIp_error(void);
void not_negative(int result);
void broadcast_2_messages(void);

int main()
{
    create_adhocster_socket_happypath();
    broadcast_wrongIp_error();
    broadcast_happypath();
    broadcast_2_messages();
}

/////// Tests ////////////////////////////

void create_adhocster_socket_happypath(void)
{
    printf("create_adhocster_socket_happypath\n");

    struct AdhocsterSocket *socket = create_adhocster_socket("192.168.0.255", 1337);

    not_null(socket);
}

void broadcast_happypath(void)
{
    printf("broadcast_happypath\n");

    struct AdhocsterSocket *socket = create_adhocster_socket("192.168.0.255", 1337);
    char *message = "hello";
    int result = broadcast(socket, message);

    not_negative(result);
}

void broadcast_wrongIp_error(void)
{
    printf("broadcast_wrongIp_error\n");

    struct AdhocsterSocket *socket = create_adhocster_socket("123.192.168.0.255", 1337);
    char *message = "hello";
    int result = broadcast(socket, message);

    assert(-1, result);
}

void broadcast_2_messages(void)
{
    printf("broadcast_2_messages\n");

    struct AdhocsterSocket *socket = create_adhocster_socket("192.168.0.255", 1337);
    char *message = "hello";

    int result = broadcast(socket, message);
    not_negative(result);
    int result2 = broadcast(socket, message);
    not_negative(result2);
}

/////// Tests ////////////////////////////


/////// Testing Library

void assert(int expected, int actual)
{
    if (expected != actual)
    {
        printf("Fail: '%d' != '%d'\n", expected, actual);
    }
}

void not_null(void *pointer)
{
    if (!pointer)
    {
        printf("Fail: Is null pointer.\n");
    }
}

void not_negative(int result)
{
    if (result < 0)
    {
        printf("Fail: '%d' < 0.\n", result);
    }
}
