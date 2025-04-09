%{
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int yylex(void);
int yyerror(const char* s);
extern FILE* yyin;
%}

%token NUM
%left '+' '*'
%start expr

%%

expr: expr '+' expr    { }
    | expr '*' expr    { }
    | '(' expr ')'     { }
    | NUM              { }
    ;

%%

int main() {
    FILE* input = fopen("bison_read.txt", "r");
    if (!input) {
        perror("No se pudo abrir 'bison_read.txt'");
        return 1;
    }
    yyin = input;

    clock_t start = clock();
    int result = yyparse();
    clock_t end = clock();
    fclose(input);

    if (result == 0) {
        printf("Bison: Cadena válida\n");
    } else {
        printf("Bison: Cadena inválida\n");
    }

    printf("Tiempo Bison: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

int yyerror(const char* s) {
    return 1;
}
