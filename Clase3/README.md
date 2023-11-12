Práctica 3: Modularización

-Objetivo:

Implementar un módulo de software para trabajar con retardos no bloqueantes a partir de las funciones creadas en la práctica 2.

--Punto 1
Crear un nuevo proyecto como copia del proyecto realizado para la práctica 2.
Crear una carpeta API dentro de la carpeta Drivers en la estructura de directorios del nuevo proyecto. Crear dentro de la carpeta API, subcarpetas /Src y /Inc.
Encapsular las funciones necesarias para usar retardos no bloqueantes en un archivo fuente API_delay.c con su correspondiente archivo de cabecera API_delay.h, y ubicar estos archivos en la carpeta API creada.

En API_delay.h se deben ubicar los prototipos de las funciones y declaraciones.

En API_delay.c se deben ubicar la implementación de todas las funciones.


--Punto 2
Implementar un programa que utilice retardos no bloqueantes y haga titilar en forma periódica el led de la placa NUCLEO-F4 de acuerdo a una secuencia predeterminada como en la práctica 2.

Cada led debe permanecer encendido 200 ms.  


Para pensar luego de resolver el ejercicio:
¿Es suficientemente clara la consigna 2 o da lugar a implementaciones con distinto comportamiento? ¿Qué pasa con la separación temporal entre encendidos sucesivos, se hace uno a continuación del otro o se espera un tiempo entre encendidos?

La consigna no es clara ya que en momentos parece hablar de 1 led y en otras partes de varios leds. En clase se aclaró que se debe hacer parpadear uno solo.


¿Se pueden cambiar el tiempo de encendido del led fácilmente en un solo lugar del código o éste está hardcodeado? ¿Hay números “mágicos” en el código?

En la línea 81 del main.c está definido el semiperiodo de la señal.


¿Qué bibliotecas estándar se debieron agregar a API_delay.h para que el código compile? Si las funcionalidades de una API propia crecieran, habría que pensar cuál sería el mejor lugar para incluir esas bibliotecas y algunos typedefs que se usan en el ejercicio.

stdio.h y stdbool.h


¿Es adecuado el control de los parámetros pasados por el usuario que se hace en las funciones implementadas? ¿Se controla que sean valores válidos? ¿Se controla que estén dentro de los rangos correctos?

En esta práctica no hay parámetros pasados por el usuario.