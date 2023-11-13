Práctica 4

Objetivo:

Implementar un MEF para trabajar con anti-rebotes por software. 


Punto 1

Crear un nuevo proyecto como copia del proyecto realizado para la práctica 3.

Implementar una MEF anti-rebote que permita leer el estado del pulsador de la placa NUCLEO-F4 y generar acciones o eventos ante un flanco descendente o ascendente, de acuerdo al diagrama de estados del enunciado

Punto 2

Implementar un programa que cambie la frecuencia de parpadeo del LED entre 100 ms y 500 ms cada vez que se presione la tecla.  El programa debe usar las funciones anti-rebote del módulo API_debounce y los retardos no bloqueantes del módulo API_delay y la función readKey.

Aclaración: no se usó la función readKey ya que se trabajó con punteros al estado de debounce.

