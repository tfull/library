#include "String.h"
#include <stdlib.h>

char charAt(String *s, int i){
    if(i < 0 || i >= s->size){
        return '\0';
    }else{
        return s->data[i];
    }
}

String String_append(String *s, char c){
    if(s->size == s->capacity){
        char *tmp;
        int i;

        s->capacity *= 2;
        tmp = (char*)malloc(s->capacity);
        for(i = 0; i < s->size; i++){
            tmp[i] = s->data[i];
        }
        free(s->data);
        s->data = tmp;
    }

    s->data[s->size] = c;
    s->size += 1;
}

String *String_new(void){
    String *s = (String*)malloc(sizeof(String));
    s->size = 0;
    s->capacity = 64;
    s->data = (char*)malloc(s->capacity);
}

String *String_readLine(void){
    char c;
    String *s = String_new();

    while((c = getchar()) != '\n'){
        String_append(s, c);
    }

    s->append(s, c);
    return s;
}

void String_free(String *s){
    free(s->data);
    free(s);
}

int String_size(String *s){
    return s->size;
}
