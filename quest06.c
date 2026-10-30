#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float calcularMSE(float *vetorA, float *vetorB, int tamanho);

int main(void){
    int tamanho;
    int *pTamanho = &tamanho;
    float *vetorA, *vetorB;
    float mse;

    srand(time(NULL));

    puts("Digite o tamanho dos vetores: ");
    scanf("%d", pTamanho);

    if(*pTamanho <= 0){
        puts("Erro! Digite um tamanho positivo!");
        return 1;
    }

    vetorA = malloc(*pTamanho * sizeof(*vetorA));
    vetorB = malloc(*pTamanho * sizeof(*vetorB));

    if(vetorA == NULL || vetorB == NULL){
        puts("Erro ao alocar memoria!");
        free(vetorA);
        free(vetorB);
        return 1;
    }

    puts("\nVetores Gerados: ");

    for(int i = 0; i < *pTamanho; i++){
        *(vetorA + i) = rand() % 100;
        *(vetorB + i) = rand() % 100;

        printf("Vetor A%d: %.2f\t", i + 1, *(vetorA + i));
        printf("Vetor B%d: %.2f\n", i + 1, *(vetorB + i));
    }

    mse = calcularMSE(vetorA, vetorB, *pTamanho);

    printf("\nErro Medio Quadratico: %.2f\n", mse);

    free(vetorA);
    free(vetorB);

    return 0;
}

float calcularMSE(float *vetorA, float *vetorB, int tamanho){
    float soma = 0;

    for(int i = 0; i < tamanho; i++){
        soma += (*(vetorA + i) - *(vetorB + i)) * (*(vetorA + i) - *(vetorB + i));
    }

    return soma / tamanho;
}