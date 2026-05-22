#include <stdlib.h>
#include <string.h>

int main(void) {
    char *buf = malloc(100);

    strcpy(buf, "hello");

    free(buf);

    return 0;
}

