#include "hslist.h"
#include <stdlib.h>


static char* hslist_alloc(size_t s){
    return (char *)malloc(s);
}
static void hslist_free(void *p){
    free(p);
}


hslist_t *hslist_open(){
    hslist_t *l = (hslist_t *)hslist_alloc(sizeof(hslist_t));
    l->head = NULL;
    l->size = 0;
    return l;
}
int hslist_close(hslist_t *l){
    hslist_free(l);
    return 0;
}

hslistitem_t *hslist_at(hslist_t *l, int index){
    if (index < 0 || index >= l->size){
        return NULL;
    } 

    if(0 == index){
        return l->head;
    }

    hslistitem_t *cur = l->head;
    for (size_t i = 0; i < index; ++i){
        cur = cur->next;
    }
    return cur;
}

int hslist_append(hslist_t *l,hslistitem_t *i){
    i->next = NULL;
    hslistitem_t *cur = l->head;
    if(!cur){
        l->head = i;
    }
    else{
        while (cur->next){
            cur = cur->next;
        }
        cur->next = i;
    }
    ++l->size;
    return 0;
}
int hslist_insert(hslist_t *l,hslistitem_t *i,int index){
    if (index < 0 || index >= l->size){
        return -1;
    } 

    if(0 == index){
        i->next = l->head;
        l->head = i;
        
    }
    else{
        hslistitem_t *cur = l->head;
        for (size_t i = 0; i < index-1; ++i){
            cur = cur->next;
        }

        i->next = cur->next;
        cur->next = i;
    }
    ++l->size;

    return 0;
}
hslistitem_t* hslist_remove(hslist_t *l,int index){
    if (index < 0 || index >= l->size){
        return NULL;
    }
    hslistitem_t* toRemove;
    if(0 == index){
        toRemove = l->head;
        l->head = l->head->next;
    }
    else{
        hslistitem_t *cur = l->head;
        for (size_t i = 0; i < index-1; ++i){
            cur = cur->next;
        }
        toRemove = cur->next;
        cur->next = toRemove->next;

    }
    --l->size;
    return toRemove;

}
hslistitem_t* hslist_find_first(hslist_t *l,hslistitem_t *tar,hslist_compare_t cmp){
    if(!cmp || !l->size){
        return NULL;
    }

    hslistitem_t* toRet = NULL;
    hslistitem_t *cur = l->head;
    for (size_t i = 0; i < l->size; ++i){
        if(cmp(cur,tar)){
            toRet = cur;
            break;
        }
        cur = cur->next;
    }
    return toRet;
}

hslistitem_t *hslist_remove_first(hslist_t *l, hslistitem_t *tar,hslist_compare_t cmp)
{
    if(!cmp || !l->size){
        return NULL;
    }

    hslistitem_t* toRemove;
    if(cmp(l->head,tar)){
        toRemove = l->head;
        l->head = l->head->next;
    }
    else{
        toRemove = l->head;
        hslistitem_t *cur = toRemove->next;
        for (size_t i = 0; i < l->size-1; ++i){
            if(cmp(cur,tar)){
                toRemove->next = cur->next;
                toRemove = cur;
                break;
            }
            toRemove = cur;
            cur = cur->next;
        }
    }
    --l->size;
    return toRemove;
}
int hislist_foreach(hslist_t *l,hslist_foreach_t f){
    if(!f){
        return -1;
    }

    hslistitem_t *it = l->head;
    for(int i = 0;i < l->size;++i){
        f(it,i);
        it = it->next;
    }  
    return 0;
}