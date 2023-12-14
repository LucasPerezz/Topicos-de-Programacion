#include <stdio.h>

int toUpper(int ch);
int toLower(int ch);
char *normalizarCadena(char *cadena);

int main(){
    char prueba1[] = {"   pTE.   saEnZ pEnA  28  A"};
    printf("%s\n", normalizarCadena(prueba1));
    return 0;
}

int toUpper(int ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch - 32;
    } else {
        return ch;
    }
}

int toLower(int ch){
    if(ch >= 'A' && ch <= 'Z'){
        return ch + 32;
    } else {
        return ch;
    }
}

char *normalizarCadena(char *cadena){
    char *inicio = cadena;
    char *destino = cadena;

    int espacioPrevio = 1;

    while (*inicio != '\0') {
        if (*inicio != ' ') {
            if (espacioPrevio && destino != cadena) {
                *destino = ' ';
                destino++;
            }

            *destino = toUpper(*inicio);
            destino++;

            espacioPrevio = 0;
        } else {
            espacioPrevio = 1;
        }

        inicio++;
    }

    *destino = '\0';

    return cadena;
}