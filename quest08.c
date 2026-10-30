#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int somarDiagonal(int *matriz, int tamanho);

int main(void){
    int tamanho;
    int *pTamanho = &tamanho;
    int *matriz;
    int soma;

    srand(time(NULL));

    puts("Digite o tamanho da matriz quadrada: ");
    scanf("%d", pTamanho);

    if(*pTamanho <= 0){
        puts("Erro! Digite um tamanho positivo!");
        return 1;
    }

    matriz = malloc(*pTamanho * *pTamanho * sizeof(*matriz));

    if(matriz == NULL){
        puts("Erro ao alocar memoria!");
        return 1;
    }

    puts("\nMatriz Gerada: ");

    for(int i = 0; i < *pTamanho; i++){
        for(int j = 0; j < *pTamanho; j++){
            *(matriz + i * *pTamanho + j) = rand() % 100;

            printf("%d\t", *(matriz + i * *pTamanho + j));
        }

        printf("\n");
    }

    soma = somarDiagonal(matriz, *pTamanho);

    printf("\nSomatorio da diagonal principal: %d\n", soma);

    if(soma % 2 == 0){
        puts("O somatorio e PAR!");
    }
    else{
        puts("O somatorio e IMPAR!");
    }

    free(matriz);

    return 0;
}

int somarDiagonal(int *matriz, int tamanho){
    int soma = 0;

    for(int i = 0; i < tamanho; i++){
        soma += *(matriz + i * tamanho + i);
    }

    return soma;
}