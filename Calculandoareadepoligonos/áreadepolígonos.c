#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Ponto;

double calcularAreaTriangulo(Ponto a, Ponto b, Ponto c) {
    double det = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return fabs(det / 2.0);
}

double calcularAreaPoligono(Ponto pontos[], int n) {
    double areaTotal = 0.0;
    for (int i = 1; i < n - 1; i++) {
        areaTotal += calcularAreaTriangulo(pontos[0], pontos[i], pontos[i + 1]);
    }
    return areaTotal;
}
int main() {
    printf("Iniciando o programa\n");

    FILE *file = fopen("C:/Users/pedro/Desktop/Atividades/Calculandoareadepoligonos", "r");
    if (file == NULL) {
        perror("Falha ao tentar o arquivo");
        return 1;
    }

    int n;
    if (fscanf(file, "%d", &n) != 1) {
        fprintf(stderr, " erro de leitura no número de pontos de arquivo\n");
        fclose(file);
        return 1;
    }

    Ponto *pontos = malloc(n * sizeof(Ponto));
    if (pontos == NULL) {
        perror("Problema ao alocar memória");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%lf %lf", &pontos[i].x, &pontos[i].y) != 2) {
            fprintf(stderr, "Falha ao ler as coordenadas do ponto %d\n", i);
            free(pontos);
            fclose(file);
            return 1;
        }
    }

    double area = calcularAreaPoligono(pontos, n);
    printf("Area do poligono: %lf\n", area);

    free(pontos);
    fclose(file);

    printf("Programa Finalizando\n");
    return 0;
}

