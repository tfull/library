#ifndef __STRING_H__
#define __STRING_H__

typedef struct{
    char *data;
    int size;
    int capacity;
}String;

void String_append(String*, char);
char String_charAt(String*, int);
void String_copy(String*, char*);
void String_free(String*);
String *String_new(void);
String *String_readLine(void);
int String_size(String*);

#endif
