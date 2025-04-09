#!/bin/bash

echo "🛠 Compilando Bison + Flex..."
bison -d calc.y
flex calc.l
gcc calc.tab.c lex.yy.c -o bison_calc

echo "🛠 Compilando CYK..."
gcc cyk.c -o cyk_parser

echo "🛠 Compilando Comparador..."
gcc comparador.c -o comparador

echo "🚀 Ejecutando Comparador (100 repeticiones)..."
./comparador

echo "📊 Generando gráfica..."
python3 graficar.py

echo "✅ Listo. Revisa 'comparacion_tiempos.png' para la gráfica."
