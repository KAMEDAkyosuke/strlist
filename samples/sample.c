#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../strlist.h"

int main(int argc, char **argv)
{
    // create new list
    strlist_t *list = strlist_append(NULL, "hello", strlen("hello"));
    
    // list to string
    const char *s1 = strlist_to_str(list);
    puts(s1);    /* "hello" */
    free((void*)s1);
    s1 = NULL;

    // append
    list = strlist_append(list, " world!!", strlen(" world!!"));
    
    // list to string
    const char *s2 = strlist_to_str(list);
    puts(s2);    /* "hello world!!" */
    free((void*)s2);
    s2 = NULL;
           
    // clean 
    strlist_free(list);
    list = NULL;

    return 0;
}
