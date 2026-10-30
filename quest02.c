#include <stdio.h>
#include <stdlib.h>

void encontrarPares(int *vetor, int tamanho, int **enderecos);

int main(void){
    int tamanho;
    int *pTamanho = &tamanho;
    int *vetor, **enderecos;

    puts("Digite o tamanho do vetor: ");
    scanf("%d", pTamanho);

    if(*pTamanho <= 0){
        puts("Erro! Digite um tamanho positivo!");
        return 1;
    }

    vetor = malloc(*pTamanho * sizeof(*vetor));
    enderecos = calloc(2, sizeof(*enderecos));

    if(vetor == NULL || enderecos == NULL){
        puts("Erro ao alocar memoria!");
        free(vetor);
        free(enderecos);
        return 1;
    }

    for(int i = 0; i < *pTamanho; i++){
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", vetor + i);
    }

    encontrarPares(vetor, *pTamanho, enderecos);

    if(*enderecos != NULL){
        printf("Primeiro PAR: %d\n", **enderecos);
        printf("Endereco: %p\n", (void*)*enderecos);
    }
    else{
        puts("Nenhum elemento PAR encontrado!");
    }

    if(*(enderecos + 1) != NULL){
        printf("Ultimo PAR: %d\n", **(enderecos + 1));
        printf("Endereco: %p\n", (void*)*(enderecos + 1));
    }

    free(vetor);
    free(enderecos);

    return 0;
}

void encontrarPares(int *vetor, int tamanho, int **enderecos){
    for(int i = 0; i < tamanho; i++){
        if(*(vetor + i) % 2 == 0){
            if(*enderecos == NULL){
                *enderecos = vetor + i;
            }

            *(enderecos + 1) = vetor + i;
        }
    }
}