#ifndef HuffImprove_cstdstring_h
#define HuffImprove_cstdstring_h

#ifndef bool
#define bool int

#define TRUE 1
#define FALSE 0

#endif

typedef struct {
    char *str;
    unsigned length;
}string;

string *create_string(unsigned len);
string *create_with_string(char *str);

void init_string(string *s, unsigned len);
void destory_string(string *s);

bool string_empty(string *s);

void string_copy(string *s, char **pstr);

void string_append(string *s, char *append_str);

#endif
