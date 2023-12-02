#include <stdio.h>

char *invertirPalabra(char *s);

int main(){
    char palabraAInvertir[] = {"Hello world"};
    printf("Frase invertida: %s\n", invertirPalabra(palabraAInvertir));
    return 0;
}

char *invertirPalabra(char *s){
    char *inicio, *fin;
    char aux;
    inicio = s;
    while(*inicio != '\0'){
        inicio++;
    }
    fin = inicio - 1;
    inicio = s;
    while(inicio < fin){
        aux = *inicio;
        *inicio = *fin;
        *fin = aux;
        inicio++;
        fin--;
    }
    inicio = s;
    return inicio;
}