#include <stdio.h>
#include <stdlib.h>


int sumaElementosDiagonalPrincipalSecundaria(int matriz[][4], int cf);

int main(){
    int matriz[4][4] = {{00, 01, 02, 03}, {10, 11, 12, 13}, {20, 21, 22, 23}, {30, 31, 32, 33}};
    printf("Total: %d\n", sumaElementosDiagonalPrincipalSecundaria(matriz, 4));
    return 0;
}

int sumaElementosDiagonalPrincipalSecundaria(int matriz[][4], int cf){
    int sumatoria = 0;
    for(int i = 0; i < cf - 1; i++){
        sumatoria += matriz[i][i + 1];
        sumatoria += matriz[i + 1][cf - 1 -i];
    }

    return sumatoria;
}