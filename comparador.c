// comparador.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

double extraer_tiempo(const char* comando, const char* clave) {
    char buffer[256];
    FILE* fp = popen(comando, "r");
    if (!fp) {
        perror("popen");
        exit(1);
    }

    double tiempo = 0.0;
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, clave)) {
            sscanf(buffer, "%*[^:]: %lf", &tiempo);
            break;
        }
    }
    pclose(fp);
    return tiempo;
}

int main() {
    double total_bison = 0.0, total_cyk = 0.0;

    for (int i = 0; i < N; i++) {
        total_bison += extraer_tiempo("./bison_calc", "Tiempo Bison");
        total_cyk += extraer_tiempo("./cyk_parser", "Tiempo CYK");
    }

    double promedio_bison = total_bison / N;
    double promedio_cyk = total_cyk / N;

    printf("Promedio Bison: %.6f segundos\n", promedio_bison);
    printf("Promedio CYK: %.6f segundos\n", promedio_cyk);

    FILE* f = fopen("tiempos.csv", "w");
    fprintf(f, "Parser,TiempoPromedio\n");
    fprintf(f, "Bison,%.6f\n", promedio_bison);
    fprintf(f, "CYK,%.6f\n", promedio_cyk);
    fclose(f);

    return 0;
}
