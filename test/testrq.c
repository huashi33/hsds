#include <stdio.h>
#include <stdlib.h>
#include "../src/hsrq.h"

int main(int argc, char *argv[]) {
    printf("testrq\n");


    hsrq_t *rq = hsrp_open(4096);


    hsrp_push(rq, "hello", 5);
    char data[16] = {0};
    hsrp_pop(rq, data, 5);
    printf("%s\n", data);


    hsrp_close(rq);
    return 0;
}