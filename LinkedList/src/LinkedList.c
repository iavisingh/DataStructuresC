#include "../inc/LinkedList.h"
#include <stdlib.h>

ListHandle_t CreateList(void *BaseStruct, int SizeOfStruct) {
    ListHandle_t Handle = malloc(SizeOfStruct + (sizeof(ListHandle_t) * 2));
    return Handle;
}

