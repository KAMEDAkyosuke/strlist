#ifndef STRLIST_H
#define STRLIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct strlist{
    struct strlist* next;
    char* data;
    int len;
} strlist_t;

strlist_t* strlist_append(strlist_t* list, const char* data, const int len);
void strlist_free(strlist_t* list);
const char* strlist_to_str(strlist_t* list);

#ifdef __cplusplus
}
#endif

#endif
