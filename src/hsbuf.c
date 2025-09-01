#include "hsbuf.h"
#include <stdlib.h>
#include "hstool.h"
#include <stdio.h>
#include <string.h>
int hsbuf_create(hsbuf_t *b,size_t s){
    if(b && s && DYNAMICDATA_DATA_SIZE_MAX>s){
        b->capacity = DYNAMICDATA_DATA_SIZE_MIN;
        HSDS_GETMINPOW(s,b->capacity)
        // hstool_getminpow(s,DYNAMICDATA_DATA_SIZE_MIN);
        b->dataSize = 0;
        b->data = (uint8_t *)HSDS_ALLOC(b->capacity);
        return HSDS_RET_OK;
    }
    
    return !b ? HSDS_RET_PARAM(0): HSDS_RET_PARAM(1);
}
int hsbuf_destroy(hsbuf_t *b){
    if(b && b->capacity && b->data){
        HSDS_FREE(b->data);
        b->data = NULL;
        return HSDS_RET_OK;
    }
    return !b ? HSDS_RET_PARAM(0): HSDS_RET_PARAM(1);
}


static int hsbuf_realloc(hsbuf_t *b,size_t s){
    hsbuf_t target = *b;
    b->capacity = DYNAMICDATA_DATA_SIZE_MIN;
    HSDS_GETMINPOW(s,target.capacity)
    // target.capacity = hstool_getminpow(s,b->capacity);
    if(DYNAMICDATA_DATA_SIZE_MAX < target.capacity){
        return HSDS_RET_NOSPACE;
    }
    target.data = HSDS_REALLOC(target.data,target.capacity);
    if(!target.data ){
        return HSDS_RET_MALLOC;
    }
    *b = target;
    return HSDS_RET_OK;
}
int hsbuf_push(hsbuf_t *b,const void *d,size_t dSize){
    int r = HSDS_RET_OK;
    if(b && d && dSize){
        size_t targetSize = b->dataSize + dSize;
        if(b->capacity < targetSize){
            r = hsbuf_realloc(b,targetSize);
            if(HSDS_RET_OK != r){
                return r;
            }
        }

        memcpy(b->data + b->dataSize, d, dSize);
        b->dataSize = targetSize;
        return HSDS_RET_OK;
    }
    
    r = !b? HSDS_RET_PARAM(0):(!d?HSDS_RET_PARAM(1):HSDS_RET_PARAM(2));
    return r;
}

int hsbuf_print(hsbuf_t *b,size_t ofs,size_t size){
    for (uint64_t i = ofs; size--; i++){
        printf("%02X\t",b->data[i]);
    }
    return 0;
}



