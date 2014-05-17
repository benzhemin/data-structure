#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "cstdstring.h"

string *create_string(unsigned len){
    string *s = malloc(sizeof(string));
    init_string(s, len);
    return s;
}

string *create_with_string(char *str){
    string *s = malloc(sizeof(string));
    init_string(s, 0);
    string_append(s, str);
    return s;
}

void init_string(string *s, unsigned len){
    s->str = malloc(sizeof(char) * (len+1));
    memset(s->str, 0, len+1);
    s->length = len;
}

void destory_string(string *s){
    free(s->str);
    free(s);
}

void string_copy(string *s, char **pstr){
    char *new_str = malloc(strlen(s->str)+1);
    assert(new_str != NULL);
    strcpy(new_str, s->str);
    if (pstr != NULL) {
        *pstr = new_str;
    }
}

void string_append(string *s, char *append_str){
    if (append_str == NULL || strlen(append_str)<1) {
        return ;
    }
    
    unsigned long str_len = strlen(s->str);
    unsigned long append_len = strlen(append_str);
    
    s->str = realloc(s->str, strlen(s->str)+append_len+1);
    s->length += append_len;
    
    strcpy(s->str+str_len, append_str);
}


















