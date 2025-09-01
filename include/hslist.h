#ifndef HSLIST_H
#define HSLIST_H

#include "hsdef.h"

typedef struct hslistitem_{
    struct hslistitem_ *next;
}hslistitem_t;



typedef int(*hslist_compare_t)(hslistitem_t *i,hslistitem_t *target);
typedef int(*hslist_foreach_t)(hslistitem_t *i,int index);
typedef struct hslist_{
    hslistitem_t*    head;
    size_t           size;
}hslist_t;



HSFC_EXPORT hslist_t* hslist_open();
HSFC_EXPORT int hslist_close(hslist_t *);

HSFC_EXPORT hslistitem_t* hslist_at(hslist_t *l,int index);
HSFC_EXPORT int hslist_append(hslist_t *l,hslistitem_t *i);
HSFC_EXPORT int hslist_insert(hslist_t *l,hslistitem_t *i,int index);
HSFC_EXPORT hslistitem_t* hslist_remove(hslist_t *l,int index);

//need set compare-func
HSFC_EXPORT hslistitem_t* hslist_remove_first(hslist_t *l,hslistitem_t *tar,hslist_compare_t cmp);
HSFC_EXPORT hslistitem_t* hslist_find_first(hslist_t *l,hslistitem_t *tar,hslist_compare_t cmp);

//need set foreach-func
HSFC_EXPORT int hislist_foreach(hslist_t *l,hslist_foreach_t f);
#endif