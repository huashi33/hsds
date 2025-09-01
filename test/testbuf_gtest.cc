#include <stdio.h>
#include "gtest/gtest.h"
#include <string.h>
#include <stdlib.h>
extern "C"{
    #include "hsbuf.h"
}
#define HSDS_LOG(FMT,...) printf("[%s(%d)]" FMT "\n",__FUNCTION__,__LINE__,##__VA_ARGS__)
#define HSDS_CHECKRET(R) if(R) {HSDS_LOG("[%08X]check fail",R);return R;}


TEST(testds,t1){
    const char *ctx = "thisisgtest";
    int times = 4;
    printf("hw:%s\n",ctx);
    // return 0;

    int r;
    hsbuf_t b;
    r = hsbuf_create(&b,1);
    // HSDS_CHECKRET(r);
    EXPECT_EQ(0,r);

    //write
    // const char *ctx = argv[1];
    size_t ctxLen = strlen(ctx);
    // int times = atoi(argv[2]);
    for(size_t i = 0;i < times;++i){
        r = hsbuf_push(&b,ctx,ctxLen);
        // HSDS_CHECKRET(r);
        EXPECT_EQ(0,r);
    }
    
    HSDS_LOG("push %s %d times,b.cap:%zu,b.dsize:%zu",ctx,times,b.capacity,b.dataSize);

    //read
    char readTxt[128] = {0};
    for(size_t i = 0;i < times;++i){
        memcpy(readTxt,b.data + i*ctxLen,ctxLen);
        readTxt[ctxLen]=0;
        HSDS_LOG("[%zu]%s",i,readTxt);
    }

    r = hsbuf_destroy(&b);
    // HSDS_CHECKRET(r);
    EXPECT_EQ(0,r);
    // return r;
}



TEST(testds,t2){
    EXPECT_EQ(0,0);
}