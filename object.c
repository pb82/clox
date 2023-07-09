//
// Created by peter on 07.07.23.
//

#include <stdio.h>
#include <string.h>

#include "memory.h"
#include "object.h"
#include "vm.h"

#define ALLOCATE_OBJ(type, objectType) (type *)allocateObject(sizeof(type), objectType)

static Obj *allocateObject(size_t size, ObjType type) {
    Obj *obj = (Obj *) reallocate(NULL, 0, size);
    obj->type = type;

    obj->next = vm.objects;
    vm.objects = obj;

    return obj;
}

static ObjString *allocateString(char *chars, int length) {
    ObjString *string = reallocate(NULL, 0, sizeof(ObjString) + length + 1);
    string->length = length;
    memcpy(string->chars, chars, length);
    string->chars[length] = '\0';
    string->obj.type = OBJ_STRING;
    string->obj.next = vm.objects;
    string->length = length;
    return string;
}

ObjString *takeString(char *chars, int length) {
    return allocateString(chars, length);
}

ObjString *copyString(const char *chars, int length) {
    return allocateString(chars, length);
}

void printObject(Value value) {
    switch (OBJ_TYPE(value)) {
        case OBJ_STRING:
            printf("%s", AS_CSTRING(value));
            break;
    }
}