//
// Created by peter on 20.06.23.
//

#ifndef LOX_DEBUG_H
#define LOX_DEBUG_H

#include "chunk.h"

void disassembleChunk(Chunk *chunk, const char *name);
int disassembleInstruction(Chunk *chunk, int offset);

#endif //LOX_DEBUG_H
