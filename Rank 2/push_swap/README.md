*This project has been created as part of the 42 curriculum by
agarcia2.*

# push_swap

push_swap es un proyecto de la escuela 42 cuyo objetivo es ordenar una
lista de números utilizando únicamente dos pilas (`a` y `b`) y un
conjunto limitado de operaciones.\
La meta es generar **la secuencia más corta posible de instrucciones**
para dejar la pila `a` ordenada en orden ascendente.

------------------------------------------------------------------------

## 📌 Descripción

El programa recibe una lista de enteros por argumento, valida su formato
y los introduce en la pila `a`.\
La pila `b` empieza vacía y sirve como apoyo para realizar movimientos.\
El programa debe imprimir por `stdout` la lista de instrucciones
necesarias para ordenar.

Requisitos principales del subject:

-   Ordenar la pila `a` en orden ascendente.
-   La pila `b` debe quedar vacía.
-   Imprimir sólo instrucciones válidas.
-   En caso de error → imprimir **"Error`\n`{=tex}"** en *stderr*.
-   Prohibido usar variables globales.
-   Debe gestionar correctamente:
    -   Valores fuera de rango `int`
    -   Duplicados
    -   Argumentos inválidos
    -   Strings vacíos o sólo espacios

------------------------------------------------------------------------

## 🧩 Conjunto de instrucciones permitidas

### Movimientos sobre las pilas:

  Instrucción   Acción
  ------------- ---------------------------------------
  sa            Intercambia los dos primeros de `a`
  sb            Intercambia los dos primeros de `b`
  ss            `sa` y `sb` a la vez
  pa            Mueve el primer elemento de `b` a `a`
  pb            Mueve el primer elemento de `a` a `b`
  ra            Rota `a` hacia arriba
  rb            Rota `b` hacia arriba
  rr            `ra` y `rb` a la vez
  rra           Rota `a` hacia abajo
  rrb           Rota `b` hacia abajo
  rrr           `rra` y `rrb` a la vez

------------------------------------------------------------------------

## ⚙️ Compilación

El proyecto incluye un **Makefile** obligatorio con las reglas
requeridas:

    make        # Compila push_swap
    make clean  # Borra los .o
    make fclean # Borra .o + binario
    make re     # Limpia y recompila

------------------------------------------------------------------------

## 🚀 Ejecución

Ejemplo básico:

    ./push_swap 2 1 3 6 5 8

Ejemplo de validación con checker (Linux o Mac):

    ARG="4 67 3 87 23"
    ./push_swap $ARG | ./checker_Mac $ARG

Contar número de movimientos:

    ./push_swap $ARG | wc -l

Si no se pasan argumentos:

    ./push_swap
    # No muestra nada

------------------------------------------------------------------------

## 🧠 Algoritmo implementado

Esta implementación utiliza un enfoque híbrido optimizado:

### ✔ Indexación

Convierte los valores originales en índices ordenados para simplificar
comparaciones y acelerar la construcción de la solución.

### ✔ Chunking (división por grupos)

Divide los valores en bloques (chunks) para enviarlos a la pila `b` de
forma estructurada.

### ✔ Inserción por coste

Cada elemento de `b` calcula: - coste para colocarse en su posición
objetivo en `a` - coste de rotación en `b` - coste total - se aplica
siempre el movimiento *más barato*

### ✔ Casos pequeños optimizados

-   2 elementos → swap directo\
-   3 elementos → algoritmo mínimo

------------------------------------------------------------------------

## 📈 Rendimiento esperado (según subject)

Rangos de operaciones típicas para pasar evaluación:

-   **100 números → \<700 movimientos**
-   **500 números → \<5500 movimientos**

------------------------------------------------------------------------

## 🧪 Testing

Probar con números aleatorios:

    ARG=$(shuf -i 1-100 -n 100)
    ./push_swap $ARG | ./checker_Mac $ARG
    ./push_swap $ARG | wc -l

------------------------------------------------------------------------

## 📚 Recursos

-   Enunciado oficial en la intranet de 42\
-   Explicaciones sobre algoritmos de ordenación\
-   Documentación de estructuras de datos\
-   Optimización de coste y rotaciones combinadas

------------------------------------------------------------------------

## 🤖 Uso de IA en este proyecto

IA se utilizó únicamente para: - mejorar documentación (README)\
- reformular explicaciones complejas\
- análisis general del proyecto

El código fue revisado y comprendido completamente antes de integrarse.

------------------------------------------------------------------------

## 🏁 Conclusión

push_swap es un proyecto clave en el cursus que combina optimización,
análisis algorítmico, gestión de memoria y diseño limpio en C.\
Esta implementación sigue fielmente los requisitos del subject y está
preparada para evaluación.
