#include <stdio.h>

char *mystrchr(char *s, int c);

int main(){
    char palabra[20] = {"Hello World"};
    printf("%s\n", mystrchr(palabra, 'o'));
    return 0;
}


char *mystrchr(char *s, int c){
    char *inicio, *fin;
    inicio = s;
    while(*inicio != '\0'){
        inicio++;
    }
    fin = inicio - 1;
    inicio = s;
    while(inicio <= fin){
        if(*inicio == c){
            return inicio;
        }
        inicio++;
    }
    return NULL;
}