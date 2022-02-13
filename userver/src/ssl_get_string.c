#include "server.h"

/*
** gets a string from the client and terminates it
*/
char *ssl_get_string(SSL *ssl) {
    int bytes;
    char *message;

    message = malloc(sizeof *message * 1024);
    bytes = SSL_read(ssl, message, 1024); /* receiving message */
    if (bytes > 0)
        message[bytes] = 0;
    else
        message[0] = 0;
    return message;
}
