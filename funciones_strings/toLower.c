#include <stdio.h>

int toLower(int ch);

int main(){
    char palabra = 'W';
    printf("%c", toLower(palabra));
    return 0;
}

int toLower(int ch){
    if(ch >= 'A' && ch <= 'Z'){
        return ch + 32;
    } else{
        return ch;
    }
}