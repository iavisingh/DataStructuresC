#include "../inc/RingBuffer.h"
#include <stdlib.h>
#include <string.h>

RingBufferError_t CreateRingBuffer(RingBufferHandle_t **Handle, uint32_t MaxLen) 
{
#if defined XIGNORE_MALLOC
    if(!Handle) return RINGBUFFER_INVALID_ARG;
    memset(Handle->dat, 0, STATIC_RB_SIZE);
    Handle->MaxLen = STATIC_RB_SIZE;
#else
    if(!Handle || !MaxLen) return RINGBUFFER_INVALID_ARG;
    Handle->dat = calloc(1, MaxLen);
    if(!Handle->dat) return RINGBUFFER_MEM_ERROR;
    Handle->MaxLen = MaxLen;
#endif
    Handle->ReadIdx = Handle->WriteIdx = 0;
    return RINGBUFFER_NO_ERROR;
}
RingBufferError_t SendDataRingBuffer(RingBufferHandle_t *Handle, uint8_t *Dat, uint32_t Len, uint32_t TimeoutMs) 
{
    if(Handle)
}
RingBufferError_t ReadDataRingBuffer(RingBufferHandle_t *Handle, uint8_t *Data, uint32_t Len, uint32_t *ActualRead);
RingBufferError_t CurrentRingBufferSize(RingBufferHandle_t *Handle, uint32_t *Avail);
RingBufferError_t DeleteRingBuffer(RingBufferHandle_t **Handle);