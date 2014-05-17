#ifndef HuffImprove_cstdstring_h
#define HuffImprove_cstdstring_h

typedef struct {
    char *str;
    unsigned length;
}string;

string *create_string(unsigned len);
string *create_with_string(char *str);

void init_string(string *s, unsigned len);
void destory_string(string *s);

void string_copy(string *s, char **pstr);

void string_append(string *s, char *append_str);

#endif
