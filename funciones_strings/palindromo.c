#include <stdio.h>

int palindromo(char *s);
int toUpper(int ch);

int main(){
    char palabra[] = {"Anita LAVA La    TinA"};
    if(palindromo(palabra)){
        printf("Es palindromo\n");
    }else{
        printf("No es palindromo\n");
    }
    return 0;
}

int palindromo(char *s){
    char *inicio, *fin;
    inicio = s;
    while(*inicio != '\0'){
        inicio++;
    }
    fin = inicio - 1;
    inicio = s;
    while(inicio < fin){
        while(*inicio == ' '){
            inicio++;
        }

        while(*fin == ' '){
            fin--;
        }

        if(toUpper(*inicio) != toUpper(*fin)){
            return 0;
        } else{
            inicio++;
            fin--;
            }
    }
    return 1;
}

int toUpper(int ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch - 32;
    }else{
        return ch;
    }
}