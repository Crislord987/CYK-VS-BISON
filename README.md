# Comparador de Parsers: Bison vs CYK

Este proyecto implementa y compara dos analizadores sintácticos (parsers):

- 🐂 **Bison**: Un parser generado a partir de una gramática en BNF.
- 📐 **CYK (Cocke–Younger–Kasami)**: Un parser basado en gramáticas en forma normal de Chomsky (CNF).

## 🎯 Objetivo

Evaluar y comparar el rendimiento de ambos parsers procesando entradas similares. La comparación se basa en:

- Validación de cadenas de entrada (expresiones o números).
- Medición del **tiempo promedio de ejecución** tras **100 ejecuciones** consecutivas.
- Generación de una **gráfica comparativa** del rendimiento.

---

## 📁 Estructura del Proyecto
. ├── bison_read.txt # Entrada para el parser Bison (expresiones como (1+2)*3) ├── calc.y # Archivo Bison (gramática) ├── calc.l # Archivo Flex (tokens) ├── cyk_read.txt # Entrada para el parser CYK (solo números como 12345) ├── cyk.c # Implementación del parser CYK ├── comparador.c # Programa para comparar 100 ejecuciones de cada parser ├── graficar.py # Script Python para graficar resultados ├── run.sh # Script que compila, ejecuta y grafica todo ├── tiempos.csv # (Generado) Datos con tiempos promedio ├── comparacion_tiempos.png # (Generado) Imagen con la gráfica comparativa

---

## 🚀 Cómo usar

### 1. Clona el repositorio

```bash
git clone https://github.com/tu_usuario/tu_repositorio.git
cd tu_repositorio
pip install matplotlib pandas
chmod +x run.sh
./run.sh
