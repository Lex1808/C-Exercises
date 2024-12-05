#include <stdio.h>

typedef unsigned long DWORD;
typedef unsigned char BYTE;

union {
    struct {
        DWORD eax;
        DWORD ebx;
        DWORD ecx;
        DWORD edx;
    } dword;
    struct {
        BYTE al;
        BYTE ah;
        BYTE dummyal;
        BYTE dummyah;
        BYTE bl;
        BYTE bh;
        BYTE dummybl;
        BYTE dummybh;
        BYTE cl;
        BYTE ch;
        BYTE dummycl;
        BYTE dummych;
        BYTE dl;
        BYTE dh;
        BYTE dummydl;
        BYTE dummydh;         
    } byte;
} reg32;

