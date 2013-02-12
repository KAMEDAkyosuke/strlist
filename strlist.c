#include "strlist.h"

#include <stdlib.h>
#include <string.h>

strlist_t* strlist_append(strlist_t* list, const char* data, const int len)
{
    strlist_t *new_item = (strlist_t*) malloc(sizeof(strlist_t));
    new_item->next = NULL;
    new_item->data = (char*) malloc(sizeof(char) * (len + 1));
    memcpy(new_item->data, data, sizeof(char) + (len + 1));
    new_item->len = len;

    if(list == NULL){
        return new_item;
    }
    else{
        strlist_t* last = list;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = new_item;
        return list;
    }
}

void strlist_free(strlist_t* list)
{
    strlist_t *current = list;
    while(current != NULL){
        free(current->data);
        current->data = NULL;
        
        strlist_t* tmp = current;
        current = current->next;
        free(tmp);
        tmp = NULL;
    }
}

const char* strlist_to_str(strlist_t* list)
{
    int len = 0;
    strlist_t* current = list;
    while(current != NULL){
        len += current->len;
        current = current->next;
    }
    
    if(len == 0){
        return NULL;
    }
    
    char* result = (char*) malloc(sizeof(char) * (len + 1));
    result[len] = '\0';
    
    current = list;
    int pos = 0;
    while(current != NULL){
        memcpy(result + pos, current->data, sizeof(char) * current->len);
        pos += current->len;
        current = current->next;
    }
    return result;
}
