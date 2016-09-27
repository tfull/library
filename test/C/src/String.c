#include "String.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    String *line;
    int size;
    char *cs;

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

    String_free(line);

    return 0;
}
