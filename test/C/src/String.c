#include "String.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    String *line;
    String *appendix;
    int i;
    int size;
    char *raw = (char*)"[appendix]";
    char *cs;
    char *ds;

    printf("input string: ");
    line = String_readLine();
    String_chomp(line);

    size = String_size(line);
    cs = (char*)malloc(sizeof(char) * size + 1);
    String_copy(line, cs);

    printf("length: %d\n", size);
    printf("content: %s\n", cs);

    if(size == 0){
        return 0;
    }

    printf("first: %c\n", String_at(line, 0));
    printf("center: %c\n", String_charAt(line, (size - 1) / 2));

    appendix = String_load(raw);
    for(i = 0; i < 20; i++){
        String_pushBack(appendix, '0' + char(i % 10));
    }

    String_append(line, appendix);
    ds = String_toCString(line);

    printf("appended: %s\n", ds);

    String_free(line);
    free(cs);
    free(ds);

    return 0;
}
