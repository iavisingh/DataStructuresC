#ifndef XRINGBUFFER_H
#define XRINGBUFFER_H

#include <stdint.h>

#if defined XIGNORE_MALLOC
#define STATIC_RB_SIZE 2048
#endif

#define RING_BUFF_INITIALISED 0x44

typedef enum {
    RINGBUFFER_GENERIC_FAILURE = -100,
    RINGBUFFER_MEM_ERROR,
    RINGBUFFER_READ_ERROR,
    RINGBUFFER_WRITE_ERROR,
    RINGBUFFER_INVALID_ARG,
    RINGBUFFER_NO_ERROR = 0
} RingBufferError_t;

typedef struct {
#if defined XIGNORE_MALLOC
    uint8_t dat[STATIC_RB_SIZE];
#else
    uint8_t *dat;
#endif
    uint32_t ReadIdx;
    uint32_t WriteIdx;
    uint32_t MaxLen;
    uint8_t State;
} RingBufferHandle_t;

RingBufferError_t CreateRingBuffer(RingBufferHandle_t **Handle, uint32_t MaxLen);
RingBufferError_t SendDataRingBuffer(RingBufferHandle_t *Handle, uint8_t *Dat, uint32_t Len, uint32_t TimeoutMs);
RingBufferError_t ReadDataRingBuffer(RingBufferHandle_t *Handle, uint8_t *Data, uint32_t Len, uint32_t *ActualRead);
RingBufferError_t CurrentRingBufferSize(RingBufferHandle_t *Handle, uint32_t *Avail);
RingBufferError_t DeleteRingBuffer(RingBufferHandle_t **Handle);


#endif