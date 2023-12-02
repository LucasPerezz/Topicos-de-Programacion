#include <stdio.h>

char *normalizarCadena(char *s);
int toUpper(int ch);

int main(){
    char palabraANormalizar[] = {"   hel lo  world"};
    printf("%s\n", normalizarCadena(palabraANormalizar));
    return 0;
}

char *normalizarCadena(char *s){
    char *inicio;
    inicio = s;
    if(*inicio <= 'a' && *inicio >= 'z'){
        toUpper(*inicio);
    }
    while(*inicio != '\0'){
        while(*inicio == ' '){
            inicio++;
            *inicio = toUpper(*inicio);
        }
        inicio++;
    }
    inicio = s;
    return inicio;
}

int toUpper(int ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch - 32;
    } else{
        return ch;
    }
}