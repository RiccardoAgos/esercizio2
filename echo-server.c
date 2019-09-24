#include <stdio.h>
#include "socket-lib.h"

#define HOST "127.0.0.1"
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

    if(socket_bind(socket, HOST, PORT) < 0) {
        fprintf(stderr, "Failed to bind socket to %s:%d\n", HOST, PORT);
        return 1;
    }

    printf("Socket bound to %s:%d\n", HOST, PORT);

    if(socket_listen(socket) < 0) {
        fprintf(stderr, "Failed to listen\n");
        return 1;
    }

    printf("Waiting for incoming connections...\n");
    while(1) {
        SOCKET_T incoming = socket_accept(socket);
        if(incoming == 0) {
            fprintf(stderr, "Could not accept connection\n");
            break;
        }

        printf("Connected!\n");

        // Read message
        char client_message[256];
        int client_message_size = socket_read_all(incoming, client_message, 256);
        socket_close_receive(incoming);
        printf("Read %d bytes... ", client_message_size);

        for(int i=0; i < client_message_size; i++)
        {
            if(i%2 == 0){
                client_message[i] = toupper(client_message[i]);

            }
        }


        int sent = send(incoming, client_message, client_message_size, 0);
        socket_close(incoming);
        printf("and %d bytes sent back.\n", sent);
    }

    socket_close(socket);

    if(socket_quit() != 0) {
        fprintf(stderr, "Socket finalization failed\n");
        return 1;
    }

    return 0;
}
