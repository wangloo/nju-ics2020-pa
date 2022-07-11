#include <klib.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
    size_t i;

    for (i = 0; s[i] != '\0'; i++);
    return i;
}

char *strcpy(char* dst,const char* src) {
    const char *p = src;
    char *q = dst;

    while(*p != '\0') {
        *q = *p;
        p++;
        q++;
    }
    *q = '\0'; // add terminator
  return dst;
}

char* strncpy(char* dst, const char* src, size_t n) {
  return NULL;
}

char* strcat(char* dst, const char* src) {
    size_t dst_len = strlen(dst);
    size_t i;
    
    for (i = 0; src[i] != '\0'; i++) {
        dst[dst_len + i] = src[i];
    }
    dst[dst_len + i] = '\0';
    
  return dst;
}

int strcmp(const char* s1, const char* s2) {
    assert(NULL != s1 && NULL != s2);

    const char *p = s1;
    const char *q = s2;
    int res = 0;

    while (*p != '\0' && *q != '\0') {
        if (*p == *q) {
            p++;
            q++;
        } else {
            res = *p - *q;
            return res;
        }
    }

    if (*p == '\0' && *q != '\0') res = -1;
    if (*p != '\0' && *q == '\0') res = 1;

    return res;
}

int strncmp(const char* s1, const char* s2, size_t n) {
  return 0;
}

void* memset(void* v,int c,size_t n) {
    unsigned char *p = v;
    
    while (n--) {
        *p++ = (unsigned char)c;
    }

    return v;
}

void* memmove(void* dst,const void* src,size_t n) {
  return NULL;
}

void* memcpy(void* out, const void* in, size_t n) {
  return NULL;
}

int memcmp(const void* s1, const void* s2, size_t n) {
    assert(NULL != s1 && NULL != s2);

    const unsigned char *p = s1;
    const unsigned char *q = s2;
    int res = 0;

    while (n--) {
        if (*p == *q) {
            p++;
            q++;
        } else {
            res = *p - *q;
            return res;
        }
    }

    return 0;
}

#endif
