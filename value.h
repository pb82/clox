//
// Created by peter on 20.06.23.
//

#ifndef LOX_VALUE_H
#define LOX_VALUE_H

#include "common.h"

typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value *values;
} ValueArray;

void initValueArray(ValueArray *array);
void freeValueArray(ValueArray *array);
void writeValueArray(ValueArray *array, Value value);
void printValue(Value value);

#endif //LOX_VALUE_H
