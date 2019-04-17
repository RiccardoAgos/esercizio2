#include <stdio.h>
#include "socket-lib.h"

#define HOST "localhost"
#define PORT 1234

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
    char input[256];
    memset(input, 0, sizeof(char) * 256);
    printf("Input: ");
    scanf("%s", input);
    int sent = send(socket, input, strlen(input) * sizeof(char), 0);
    socket_close_send(socket);

    printf("%d bytes sent\n", sent);

    char output[256];
    int read_size = socket_read_all(socket, output, 256);
    printf("%s\n", output);

    if(socket_quit(socket) != 0) {
        fprintf(stderr, "Socket finalization failed\n");
        return 1;
    }

    return 0;
}
