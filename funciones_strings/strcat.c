#include <stdio.h>

char *mystrcat(char *s1, const char *s2);

int main(){
    char destino[20] = {"Hello "};
    char origen[20] = {"World"};
    printf("%s\n", mystrcat(destino, origen));
    return 0;
}

char *mystrcat(char *s1, const char *s2){
    char *inicio;
    inicio = s1;
    while(*inicio != '\0'){
        inicio++;
    }
    while(*s2 != '\0'){
        *inicio = *s2;
        inicio++;
        s2++;
    }
    inicio = s1;
    return inicio;
}