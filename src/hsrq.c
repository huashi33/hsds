#include "hsrq.h"

hsrq_t *hsrp_open(uint32_t s){
    uint32_t trueSize = 4096;
    while(trueSize < s){
        trueSize << 1;
    }

    hsrq_t *rq = malloc(sizeof(hsrq_t) + trueSize);
    rq->size = s;
    rq->in = 0;
    rq->out = 0;
    return rq;
}

int hsrp_close(hsrq_t *rq){
    if(rq){
        free(rq);
    }
    return 0;
}

int hsrp_push(hsrq_t *rq, void *data, uint32_t size){
    uint32_t len = HSRQ_MIN(rq->size - (rq->in - rq->out),size);
    uint32_t trueIn = rq->in&(rq->size-1);
    uint32_t l1 = HSRQ_MIN(len,rq->size - trueIn);
    memcpy(rq->data + trueIn, data, l1);
    memcpy(rq->data, (char *)data + l1, len - l1);
    rq->in += len;
    return len;
}


int hsrp_pop(hsrq_t *rq, void *data, uint32_t size){
    uint32_t len = HSRQ_MIN(rq->in - rq->out,size);
    uint32_t trueOut = rq->out&(rq->size-1);
    uint32_t l1 = HSRQ_MIN(len,rq->size - trueOut);
    memcpy(data,rq->data + trueOut,l1);
    memcpy((char *)data + l1,rq->data,  len - l1);
    rq->out += len;
    return len;
}
