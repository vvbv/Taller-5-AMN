# Taller #5

## Presentado por:
#### Grupo #4
* Emily Esmeralda Carvajal Camelo
* Valeria Rivera Muñoz
* Jeison Cardona Gómez

## Instrucciones de compilación y ejecución

### Linux:

> $ chmod 777 build_run.sh<br>
> $ sh build_run.sh

### Windows

Comando equivalente con mingw a:
> $ g++ --std=c++11 src/main.cpp -o build/main.exe<br>
> $ build/main.exe

# Observaciones
### Punto: 13
<p style='text-align: justify;'>
Implementamos el método de la potencia para el ejercicio numero 1, al iterar el ejemplo 2 del libro 200 veces notamos que existia una aparente convergencia a 4, pero al revisar las ultimas iteraciones vimos que el radio daba un salto y al final convergia a 6, esto se puede dar por varias razones, una de ellas es que la matriz sea inestable, para ello verificamos el número de condición de la matriz, hallamos que era 12, lo cual es un número de condición (utilizando norma infinita) bastante alto para una matriz 3x3. Otro motivo que encontramos para que esto sucediera es que el vector inicial [1,2,3] esta mas cerca del valor propio 4 que del valor propio 6.</p>

[ <a href="https://github.com/vvbv/Taller-5-AMN">https://github.com/vvbv/Taller-5-AMN</a> ]