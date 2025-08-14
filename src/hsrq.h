#ifndef HSRQ_H
#define HSRQ_H

#include <stddef.h>
#include <stdint.h>

#define HSRQ_MIN(A,B) ((A) < (B) ? (A) : (B))


typedef struct hsrq_{
    uint32_t size;//2^n
    uint32_t in;
    uint32_t out;
    char     data[0];
}hsrq_t;






hsrq_t* hsrp_open(uint32_t s);
int hsrp_close(hsrq_t* rq);
int hsrp_push(hsrq_t* rq, void* data, uint32_t size);
int hsrp_pop(hsrq_t* rq, void* data, uint32_t size);



#endif