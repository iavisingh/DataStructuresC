#ifndef XQUEUE_H
#define XQUEUE_H

#include <stdint.h>
#include <pthread.h>

typedef enum {
    QUEUE_UNINITIALISED,
    QUEUE_NO_MEM,
    QUEUE_CREATE_ERROR,
    QUEUE_NO_ERROR = 0
} QueueError_t;

typedef struct {
    void *Dat;
    uint32_t MsgSize;
    uint32_t MaxCount;
    uint32_t ReadIdx;
    uint32_t WriteIdx;
} QueueHandle_t;

QueueError_t CreateQueue(QueueHandle_t *Handle, uint32_t MsgCount, uint32_t MsgSize);
QueueError_t SendToQueue(QueueHandle_t Handle, uint8_t *Msg, uint32_t TimeoutMs);
QueueError_t ReceiveFromQueue(QueueHandle_t Handle, uint8_t *Msg, uint32_t TimeoutMs);
QueueError_t DeleteQueue(QueueHandle_t *Handle);

#endif