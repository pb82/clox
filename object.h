//
// Created by peter on 07.07.23.
//

#ifndef LOX_OBJECT_H
#define LOX_OBJECT_H

#include "common.h"
#include "value.h"
#include "chunk.h"

#define OBJ_TYPE(value) (AS_OBJ(value)->type)

#define IS_STRING(value) isObjType(value, OBJ_STRING)
#define AS_STRING(value) ((ObjString *) AS_OBJ(value))
#define AS_CSTRING(value) (((ObjString *) AS_OBJ(value))->chars)

#define IS_FUNCTION(value) isObjType(value, OBJ_FUNCTION)
#define AS_FUNCTION(value) ((ObjFunction *) AS_OBJ(value))

typedef enum {
    OBJ_FUNCTION,
    OBJ_STRING,
} ObjType;

struct Obj {
    ObjType type;
    struct Obj *next;
};

struct ObjString {
    Obj obj;
    int length;
    char *chars;
    uint32_t hash;
};

typedef struct {
    Obj obj;
    int arity;
    Chunk chunk;
    ObjString *name;
} ObjFunction;

ObjFunction *newFunction();

ObjString *takeString(char *chars, int length);

ObjString *copyString(const char *chars, int length);

void printObject(Value value);

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

#endif //LOX_OBJECT_H
