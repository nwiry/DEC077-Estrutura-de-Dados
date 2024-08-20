#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "library_exerc.h"

int main(int argc, char const *argv[])
{
    // Variaveis para armazenar os 3 menores e 3 maiores valores
    int menor1 = INT_MAX, menor2 = INT_MAX, menor3 = INT_MAX;
    int maior1 = INT_MIN, maior2 = INT_MIN, maior3 = INT_MIN;

    int tamanho = 1000; // Tamanho do array setado para 1000 unidades
    // Variáveis que vão armazenar o inicio, fim e tempo total da execução do programa
    clock_t start_t, end_t;
    double exec_t;

    // Tempo de inicio do programa startado
    start_t = clock();

    srand(time(NULL));

    // Aqui alocamos a memória para o array com o tamanho definido
    int *array = alocaArray(tamanho);
    if (array == NULL)
        exit(1);

    // Gera-se os valores aleatórios para o array
    randValoresArray(array, tamanho);
    // Atribui-se para as variáveis correspondentes os menores e os maiores valores.
    defineMenorMaiorArray(array, tamanho, &menor1, &menor2, &menor3, &maior1, &maior2, &maior3);

    // Por fim, imprimimos os 3 menores e maiores valores
    printf("Menores valores: %d, %d, %d\n", menor1, menor2, menor3);
    printf("Maiores valores: %d, %d, %d\n", maior1, maior2, maior3);

    // Libera-se a memória do array criado
    free(array);

    // Finalizamos o tempo da execução e calculamos isso em segundos imprimindo o resultado na tela
    end_t = clock();
    exec_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", exec_t);

    return 0;
}