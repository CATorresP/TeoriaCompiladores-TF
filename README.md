INFORME DEL TRABAJO FINAL

Ciencias de la Computación 

Carrera de Ciencias de la Computaciòn

Sección: CC61




Alumnos:
Código
Nombres y apellidos
u202020065
Quispe Ayala Diego Juan Pablo
u20211c828
Ramirez Sarmiento Joseph Rafael
u201615124
Torres Paniagua César Augusto




Noviembre 2023


ÍNDICE


1.Resumen
2.Objetivo
3.Marco Teórico 
4.Metodología
5.Comunicación
7.Conclusiones


Introducción:
La implementación de una shell es un componente esencial en los sistemas operativos, proporcionando a los usuarios y otras aplicaciones una interfaz para interactuar con la capa de servicios del sistema a través de comandos. Este proyecto se centra en el diseño y desarrollo de una shell que cumple con diversas funcionalidades clave, utilizando ANTLR4 para el análisis léxico y sintáctico de los comandos ingresados.
Para este trabajo, se exploraron características adicionales como el manejo de rutas, la implementación de un visitor, la ejecución de comandos externos, y la inclusión de expresiones regulares para el manejo de wildcards. La estructura del proyecto involucra el uso de archivos cpp y .h, destacando la importancia de la programación modular para un desarrollo eficiente.
Este informe detalla la estructura y funcionalidades clave de la shell implementada, resaltando aspectos específicos del código fuente y proporcionando ejemplos de uso. Además, se discutirán posibles expansiones y mejoras para futuras versiones de la shell, brindando una visión integral del proceso de desarrollo y las consideraciones teóricas y prácticas que lo respaldan.
 
Objetivos:
Se ha propuesto diseñar e implementar una shell con las siguientes características:
Lenguaje básico de scripting
Posibilidad de ejecutar en modo “headless” un script 
Tratamiento de variables de entorno, acceso y definición
Modo Interactivo, el cual permite mostrar un PROMPT definido en la variable PS1
Una característica adicional a su criterio, extensión de lenguaje, características interactivas, etc.
A si mismo para la realización  del trabajo se dividió en los siguientes apartados:
Crear un github para hacer commits del proyecto
Instalar todas las dependencias necesarias para el proyecto 
Hacer la gramática en ANTLR
Realizar el Parser y el Lexer
Realizar el visitor 
El shell.h
E a.out para el resultado




