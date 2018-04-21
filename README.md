# Taller-5--AMN
Taller #5 de AMN


#13.
#implementamos el método de la potencia para el ejercicio numero 1,
#al iterar el ejemplo 2 del libro 200 veces notamos que existia una
#aparente convergencia a 4, pero al revisar las ultimas iteraciones
#vimos que el radio daba un salto y al final convergi a 6, esto se 
#puede dar por varias razones, una de ellas es que la matriz sea inestable,
#para ello verificamos el número de condición de la matriz, hallamos que era 12,
#lo cual es un número de condición (utilizando norma infinita) bastante alto
#para una matriz 3x3. Otro motivo que encontramos para que esto sucediera 
#es que el vector inicial [1,2,3] esta mas cerca del valor propio 4 que del valor propio 6 .