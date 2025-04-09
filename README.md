# 🧠 Comparación de Algoritmos: CYK vs Bison

Este proyecto presenta una comparación práctica entre el algoritmo **CYK** y un parser generado con **Bison**, evaluando su rendimiento y aplicabilidad al analizar expresiones aritméticas.

## 🎯 Objetivos

- Implementar un analizador sintáctico usando el **algoritmo CYK** en C.
- Implementar un analizador equivalente usando **Flex y Bison**.
- Comparar el **rendimiento y tiempo de ejecución** de ambos analizadores.
- Validar expresiones aritméticas simples con operadores `+`, `*`, paréntesis y números.

## 📚 Descripción del trabajo

Se consideran expresiones aritméticas del tipo:

```plaintext
n+n*n
(n+n)*n
n*(n+n+n)
