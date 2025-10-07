#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 100
#define BUFFER_COUNT 5

typedef enum {
    a, // P1 → P2
    b, // P2 → P3
    c, // P3 → P1
    d, // P4 → P1
    e, // P3 → P4
} BufferID;

int buffers[BUFFER_COUNT];
int buffer_sizes[BUFFER_COUNT] = {2, 4, 4, 2, 2};

void removeTokens(BufferID id, int count) {
    if(buffers[id] == 0){
	printf("Buffer with id #%d underflowed.\n", id);
	exit(0);
    }
    buffers[id] -= count;
}

void addTokens(BufferID id, int count) {
    if(buffers[id] == buffer_sizes[id]){
	printf("Buffer with id #%d overflowed.\n", id);
	exit(0);
    }
    buffers[id] += count;
}

void p1() {
    printf("P1 fired\n");
    removeTokens(c, 4);
    removeTokens(d, 2);
    addTokens(a, 2);
}

void p2() {
    printf("P2 fired\n");
    removeTokens(a, 1);
    addTokens(b, 2);
}

void p3() {
    printf("P3 fired\n");
    removeTokens(b, 4);
    addTokens(c, 4);
    addTokens(e, 2);
}

void p4() {
    printf("P4 fired\n");
    removeTokens(e, 1);
    addTokens(d, 1);
}

void printBuffers() {
    printf("[");
    for (int i = 0; i < BUFFER_COUNT - 1; i++) {
        printf("%d", buffers[i]);
        printf(", ");
    }
    printf("%d", buffers[BUFFER_COUNT - 1]);
    printf("]\n");
}

int main() {
    addTokens(a, 2);

    printBuffers();
    p2();
    printBuffers();
    p2();
    printBuffers();
    p3();
    printBuffers();
    p4();
    printBuffers();
    p4();
    printBuffers();
    p1();
    printBuffers();

    return 0;
}
