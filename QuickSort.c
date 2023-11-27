#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    
    const char *ptrs[20];
    for (int i = 0; i < 20; i++) {
        ptrs[i] = arr[i];
    }

    
    qsort(ptrs, 20, sizeof(char *), compare);

    
    int trocas = 0;
    int comparacoes = 0;

    
    printf("Vetor ordenado:\n");
    for (int i = 0; i < 20; i++) {
        printf("%s\n", ptrs[i]);
    }

   
    int meio = 20 / 2;
    printf("Mediana: %s\n", ptrs[meio]);

   
    FILE *arquivo_saida = fopen("saida.txt", "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao abrir arquivo de saída");
        return 1;
    }

    for (int i = 0; i < 20; i++) {
        fprintf(arquivo_saida, "%s\n", ptrs[i]);
    }

    fclose(arquivo_saida);

    return 0;
}
