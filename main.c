#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char *argv[]) {
    initVM();
    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);
    writeChunk(&chunk, OP_RETURN, 1);
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
    return 0;
}
