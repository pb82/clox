//
// Created by peter on 23.06.23.
//

#ifndef LOX_COMPILER_H
#define LOX_COMPILER_H

#include "common.h"
#include "chunk.h"
#include "vm.h"

ObjFunction *compile(const char *source, Chunk *chunk);

#endif //LOX_COMPILER_H
