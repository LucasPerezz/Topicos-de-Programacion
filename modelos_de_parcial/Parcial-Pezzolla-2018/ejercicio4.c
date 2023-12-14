#include <stdio.h>
#include <stdlib.h>

void mostrarIzquierdaDiagPrinDiagSec(int matriz[][5], int cf);

int main(){
    int matriz[5][5] = {{00, 01, 02, 03}, {10, 11, 12, 13}, {20, 21, 22, 23}, {30, 31, 32, 33}, {40, 41, 42, 43}};
    mostrarIzquierdaDiagPrinDiagSec(matriz, 4);
    return 0;
}

void mostrarIzquierdaDiagPrinDiagSec(int matriz[][5], int cf){
    for(int i = 0; i < cf; i++){
        printf("%d\t", matriz[i][cf - 1 - i]);
        printf("%d\t", matriz[i + 1][i]);
    }
}

