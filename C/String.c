#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char String_charAt(String *s, int i){
    if(i < 0 || i >= s->size){
        return '\0';
    }else{
        return s->data[i];
    }
}

void String_append(String *s, char c){
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
    return s;
}

String *String_readLine(void){
    char c;
    String *s = String_new();

    while((c = getchar()) != '\n'){
        String_append(s, c);
    }

    String_append(s, c);
    return s;
}

void String_free(String *s){
    free(s->data);
    free(s);
}

int String_size(String *s){
    return s->size;
}

int String_length(String *s){
    return s->size;
}

void String_copy(String *s, char *cs){
    int i;

    for(i = 0; i < s->size; i++){
        cs[i] = s->data[i];
    }

    cs[i] = '\0';
}

void String_chomp(String *s){
    if(s->size > 0 && s->data[s->size - 1] == '\n'){
        s->size -= 1;
    }
}

void String_stripL(String *s){
    int b = 0;
    int i;

    while(b <= s->size && isspace(s->data[b])){
        b++;
    }

    for(i = 0; i < s->size - b; i++){
        s->data[i] = s->data[i + b];
    }

    s->size -= b;
}

void String_stripR(String *s){
    while(s->size > 0 && isspace(s->data[s->size - 1])){
        s->size--;
    }
}
