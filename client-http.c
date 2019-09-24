#include <stdio.h>
#include "socket-lib.h"

#define HOST "www.example.org"
#define PORT 80

int main() {
    if(socket_init() != 0) {
        fprintf(stderr, "Socket initialization failed\n");
        return 1;
    }

    SOCKET_T socket = socket_create();
    if(socket == 0) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    if(socket_connect(socket, HOST, PORT) < 0) {
        fprintf(stderr, "Failed to connect socket\n");
        return 1;
    }

    printf("Connected!\n");

    // Read user input
    char input[1024] =
        "GET / HTTP/1.0\r\n"
        "Host: www.example.org\r\n\r\n";

    send(socket, input, strlen(input) * sizeof(char), 0);
    socket_close_send(socket);

    char output[1024];
    int read_size = socket_read_all(socket, output, 1024);
    printf("%s\n", output);
    socket_close(socket);

    if(socket_quit() != 0) {
        fprintf(stderr, "Socket finalization failed\n");
        return 1;
    }

    return 0;
}
