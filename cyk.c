#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LEN 100
#define MAX_RULES 30

typedef struct {
    char left;
    char right1;
    char right2;
    char terminal;
    int is_terminal;
} Rule;

Rule rules[MAX_RULES];
int num_rules = 0;

void add_rule(char left, char right1, char right2) {
    rules[num_rules++] = (Rule){left, right1, right2, 0, 0};
}

void add_terminal_rule(char left, char terminal) {
    rules[num_rules++] = (Rule){left, 0, 0, terminal, 1};
}

// Preprocesa la cadena: reemplaza números por 'n' y elimina espacios
void preprocess_input(char* src, char* dest) {
    int i = 0, j = 0;
    while (src[i]) {
        if (isdigit(src[i])) {
            dest[j++] = 'n';
            while (isdigit(src[i])) i++; // saltar dígitos
        } else if (src[i] == '+' || src[i] == '*' || src[i] == '(' || src[i] == ')') {
            dest[j++] = src[i++];
        } else {
            i++; // ignorar otros caracteres (espacios, etc.)
        }
    }
    dest[j] = '\0';
}

int cyk(char* input) {
    int n = strlen(input);
    char*** table = malloc(n * sizeof(char**));
    for (int i = 0; i < n; i++) {
        table[i] = malloc(n * sizeof(char*));
        for (int j = 0; j < n; j++) {
            table[i][j] = calloc(26, sizeof(char));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int r = 0; r < num_rules; r++) {
            if (rules[r].is_terminal && rules[r].terminal == input[i]) {
                table[i][i][rules[r].left - 'A'] = 1;
            }
        }
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++) {
                for (int r = 0; r < num_rules; r++) {
                    if (!rules[r].is_terminal) {
                        if (table[i][k][rules[r].right1 - 'A'] &&
                            table[k + 1][j][rules[r].right2 - 'A']) {
                            table[i][j][rules[r].left - 'A'] = 1;
                        }
                    }
                }
            }
        }
    }

    int result = table[0][n - 1]['E' - 'A'];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            free(table[i][j]);
        }
        free(table[i]);
    }
    free(table);

    return result;
}

int main() {
    // Gramática CNF que acepta expresiones con +, *, paréntesis y números (como '3+5*(2+1)')
    add_terminal_rule('N', 'n');
    add_terminal_rule('P', '+');
    add_terminal_rule('P', '*');
    add_terminal_rule('L', '(');
    add_terminal_rule('R', ')');

    add_rule('E', 'E', 'A');
    add_rule('A', 'P', 'E');
    add_rule('E', 'L', 'B');
    add_rule('B', 'E', 'R');
    add_rule('E', 'N', ' ');  // E -> N (número terminal)

    char raw_input[MAX_LEN];
    char input[MAX_LEN];

    FILE* f = fopen("cyk_read.txt", "r");
    if (!f) {
        perror("No se pudo abrir 'cyk_read.txt'");
        return 1;
    }
    fgets(raw_input, MAX_LEN, f);
    fclose(f);

    preprocess_input(raw_input, input);

    clock_t start = clock();
    int accepted = cyk(input);
    clock_t end = clock();

    printf("CYK: %s\n", accepted ? "Cadena válida" : "Cadena inválida");
    printf("Tiempo CYK: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
