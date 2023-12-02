#include <stdio.h>

char *mystrrchr(char *s, int c);

int main(){
    char palabra[20] = {"Hello World"};
    printf("%s\n", mystrrchr(palabra, 'o'));

    return 0;
}

char *mystrrchr(char *s, int c){
    char *inicio, *fin;
    inicio = s;
    while(*inicio != '\0'){
        inicio++;
    }
    fin = inicio - 1;
    inicio = s;
    while(fin >= inicio){
        if(*fin == c){
            return fin;
        }
        fin--;
    }
    return NULL;
}