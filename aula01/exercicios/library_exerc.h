
/* mylibrary.h */
#ifndef LIBRARY_EXERC_H
#define LIBRARY_EXERC_H

int *alocaArray(int);
void randValoresArray(int *, int);

#endif

int *alocaArray(int tamanho)
{
    int *array = NULL;
    array = (int *)malloc(tamanho * sizeof(int));
    if (array == NULL)
    {
        printf("Erro: não foi possível alocar memória.\n");
        return NULL;
    }

    return array;
}

void randValoresArray(int *array, int tamanho)
{
    int i = 0;
    for (i = 0; i < tamanho; i++)
        array[i] = rand() % (tamanho + 1);
}

void defineMenorMaiorArray(int *array, int tamanho, int *menor1, int *menor2, int *menor3, int *maior1, int *maior2, int *maior3)
{
    for (int i = 0; i < tamanho; i++)
    {
        int temp = array[i];

        if (temp < *menor1)
        {
            *menor3 = *menor2;
            *menor2 = *menor1;
            *menor1 = temp;
        }
        else if (temp < *menor2)
        {
            *menor3 = *menor2;
            *menor2 = temp;
        }
        else if (temp < *menor3)
            *menor3 = temp;

        if (temp > *maior1)
        {
            *maior3 = *maior2;
            *maior2 = *maior1;
            *maior1 = temp;
        }
        else if (temp > *maior2)
        {
            *maior3 = *maior2;
            *maior2 = temp;
        }
        else if (temp > *maior3)
            *maior3 = temp;
    }
}

void ordenaValoresArray(int *array, int tamanho)
{
    int i;
    for (i = 0; i < tamanho - 1; i++)
    {
        int posicao = i, j;
        for (j = i + 1; j < tamanho; j++)
            if (array[j] < array[posicao])
                posicao = j;

        int temp = array[posicao];
        array[posicao] = array[i];
        array[i] = temp;
    }
}