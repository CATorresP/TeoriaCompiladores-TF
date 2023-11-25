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

Marco Teórico:

Shell:
Definición: Una shell es una interfaz de usuario para acceder a los servicios del sistema operativo mediante comandos. Proporciona una manera de interactuar con el núcleo del sistema y ejecutar programas.

ANTLR (ANother Tool for Language Recognition):

ANTLR es una herramienta de generación de analizadores léxicos y sintácticos. Se utiliza para construir intérpretes, compiladores y traductores para diversos lenguajes.

Gramática:

La gramática define la estructura sintáctica de un lenguaje. En este contexto, se refiere a las reglas que rigen la sintaxis de los comandos aceptados por la shell.

Lexer y Parser:

El lexer divide la entrada en tokens, mientras que el parser construye la estructura sintáctica (árbol) basándose en las reglas gramaticales.

Visitor Pattern:

El patrón de visitante es un patrón de diseño que permite definir una operación sin cambiar las clases en las que opera. En este trabajo, se utiliza para recorrer y analizar la estructura sintáctica generada por ANTLR.

Shell Scripting:

El scripting implica escribir secuencias de comandos para automatizar tareas. La shell propuesta admite un lenguaje básico de scripting con estructuras repetitivas, condicionales y selectivas.

Modo "Headless" y Modo Interactivo:

El modo "headless" permite la ejecución de scripts sin interfaz gráfica, mientras que el modo interactivo proporciona una interfaz en tiempo real para el usuario.

Variables de Entorno:

Las variables de entorno son variables globales que afectan el comportamiento del sistema y de las aplicaciones. La shell implementada maneja el acceso y la definición de estas variables.

Ejecución de Comandos del Sistema Operativo:

La shell es capaz de ejecutar comandos del sistema operativo, ampliando la gama de operaciones que se pueden realizar.

Expansión de Wildcards:

La expansión de wildcards implica transformar patrones (wildcards) en una lista de nombres de archivos coincidentes. En la shell, esto se logra mediante el manejo de expresiones regulares.

Prompt Personalizable:

El prompt es la cadena de caracteres que indica la espera de entrada del usuario. La shell permite personalizar esta cadena según la variable PS1 o PROMPT.

Manejo de Rutas:

La manipulación de rutas se refiere a la gestión eficiente de las ubicaciones de archivos y directorios en el sistema de archivos.

Metodología:

Creación del Repositorio:

Primero que todo se creó el repositorio para desarrollar el trabajo en grupo y dividirnos las distintas tareas.




