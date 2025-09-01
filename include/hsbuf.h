#ifndef HS_BUF_H
#define HS_BUF_H
#include <stdint.h>
#include "hsdef.h"

#define DYNAMICDATA_DATA_SIZE_MAX 1024*1024*1024    //1 GB
#define DYNAMICDATA_DATA_SIZE_MIN 512               //512 byte




typedef struct hsbuf_{
    size_t      dataSize;
    size_t      capacity;
    uint8_t*    data;
}hsbuf_t;




HSFC_EXPORT int hsbuf_create(hsbuf_t *b,size_t s);
HSFC_EXPORT int hsbuf_destroy(hsbuf_t *b);
HSFC_EXPORT int hsbuf_push(hsbuf_t *b,const void *d,size_t dSize);
HSFC_EXPORT int hsbuf_print(hsbuf_t *b,size_t ofs,size_t size);






#endif
