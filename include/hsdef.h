#ifndef HSDEF_H
#define HSDEF_H


#include <stddef.h>


#define HSFC_DYNAMICLIB
//HSFC_EXPORT
#if defined(HSFC_STATICLIB) || defined(HSFC_SOURCE)
  #define HSFC_EXPORT
#elif defined(_MSC_VER)
  #if defined(HSFC_DYNAMICLIB) || defined(HSFC_EXPORTS)
      #define HSFC_EXPORT __declspec(dllexport)
  #else
      #define HSFC_EXPORT  __declspec(dllimport)
  #endif
#elif defined(__GNUC__)
  #define HSFC_EXPORT __attribute__((visibility("default")))
#else
  #define HSFC_EXPORT
#endif


//define for return 
#define HSDS_RET_OK       0x00000000
#define HSDS_RET_FILE     0x00000001
#define HSDS_RET_NOSPACE  0x00000002
#define HSDS_RET_NOTFOUND 0x00000003
#define HSDS_RET_HASEXIST 0x00000004
#define HSDS_RET_MALLOC   0x00000005

#define HSDS_RET_PARAM(N) (0x000001F0+(N))

//define for tool 
#define HSDS_ALLOC(S) malloc(S)
#define HSDS_FREE(P) free(P)
#define HSDS_REALLOC(P,S) realloc(P,S)
//--get min pow(2,n) greater than v
#define HSDS_GETMINPOW(V,INITV) while (INITV < V) INITV <<= 1;
#endif