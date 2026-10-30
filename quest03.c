#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void normalizar(int *vetor, float *normalizado, int tamanho);

int main(void){
    int tamanho;
    int *pTamanho = &tamanho;
    int *vetor;
    float *normalizado;

    srand(time(NULL));

    puts("Digite o tamanho do vetor: ");
    scanf("%d", pTamanho);

    if(*pTamanho <= 0){
        puts("Erro! Digite um tamanho positivo!");
        return 1;
    }

    vetor = malloc(*pTamanho * sizeof(*vetor));
    normalizado = malloc(*pTamanho * sizeof(*normalizado));

    if(vetor == NULL || normalizado == NULL){
        puts("Erro ao alocar memoria!");
        free(vetor);
        free(normalizado);
        return 1;
    }

    for(int i = 0; i < *pTamanho; i++){
        *(vetor + i) = rand() % 100;
        printf("Vetor X%d: %d\n", i + 1, *(vetor + i));
    }

    normalizar(vetor, normalizado, *pTamanho);

    if(normalizado != NULL){
        puts("\nVetor Normalizado: ");

        for(int i = 0; i < *pTamanho; i++){
            printf("%.2f\t", *(normalizado + i));
        }

        printf("\n");
    }
    else{
        puts("Erro! Todos os elementos possuem o mesmo valor!");
    }

    free(vetor);
    free(normalizado);

    return 0;
}

void normalizar(int *vetor, float *normalizado, int tamanho){
    int maior = *vetor;
    int menor = *vetor;

    for(int i = 1; i < tamanho; i++){
        if(*(vetor + i) > maior){
            maior = *(vetor + i);
        }

        if(*(vetor + i) < menor){
            menor = *(vetor + i);
        }
    }

    if(maior == menor){
        return;
    }

    for(int i = 0; i < tamanho; i++){
        *(normalizado + i) = (float)(*(vetor + i) - menor) / (maior - menor);
    }
}