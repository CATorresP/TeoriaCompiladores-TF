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

![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/a18420e4-c628-4f2e-a8e0-ec48edd339b4)


Después de ello se especificó la gramática, la cual se hizo por medio del archivo “ScriptExpr.g4”  y haciendo uso de ANTLR para crear su gramática respectiva la cual a su vez nos da soporte para scripting.

![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/d46928e9-11f0-4ef0-b489-33812cb5b373)


Después de ello se generó la gramática del Lexer y Parser a partir de la gramática mencionada anteriormente.
![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/c723c86b-9abc-4448-8652-fffdd0131f9f)

Visitor Personalizado

Además  de ello  se creó “ScriptExprBaseVisitor” la cual es la clase base para el visitor que se generó automáticamente a partir de la gramática en  ANTLR. Esta clase tiene métodos que se llaman automáticamente durante el recorrido del árbol, y puedes sobrescribir estos métodos para realizar acciones específicas en cada nodo del árbol.
![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/421b53f2-dc51-4fd8-bdf4-10c2390eeb10)

SHELL

Ejecución de Comandos del Sistema Operativo
La shell.h  permite la ejecución de una amplia gama de comandos del sistema operativo. Esto incluye operaciones básicas como cambio de directorio (cd) y ejecución de programas externos, todo esto por medio de la función shell command call


![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/eff585c8-5640-44c0-bdcd-3dc65190ecfd)


Modo “Headless”

Eso se realiza por medio del modo headless seremos capaces de ejecutar los comandos sin necesidad de una interfaz gráfica,  esto por medio de la función Shell::run()

![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/5c7d8444-0c14-4397-9be6-a81b4b8500af)


Manejo de Variables de Entorno

Muestra el prompt interactivo personalizado por medio de Shell::printCurrentPath()

![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/898051da-5543-420d-933e-39c4e69b7aa6)


Gestión de Rutas y WildCards

Esta parte se encarga  de expandir las wildcards y gestionar las rutas por medio de Shell::wildcardToArgs(std::string& wildcard)

![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/a29b51e6-0527-4d84-998a-e78d09351ae3)

Expresiones Regulares y características adicionales

Implementadas en funciones como wildcardToArgs() para la manipulación eficiente de wildcards.

Comunicación:

Para la comunicación en equipo se hicieron reuniones por medio de microsoft teams para coordinar distintos apartados del proyecto. Así mismo, se discutieron distintas partes para la realización del mismo. 


![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/10d7598b-18bd-43f1-9df1-9ba5f651663f)


![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/03ec6497-fcc8-4482-822d-e0452af3082e)


Así mismo se dividieron las tareas por medio de aplicaciones como Trello, las cuales nos ayudaron a organizar el proyecto de mejor manera.

![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/2453c9fe-7d56-4fe9-8a03-b7a92646673b)

Así mismo hay se puede visualizar los  commits que se realizaron al repositorio, el cual también ayuda en la organización del trabajo en equipo

![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/2cf0d476-f3c9-494c-a0b3-fea748297259)


Así mismo hay se puede visualizar los  commits que se realizaron al repositorio, el cual también ayuda en la organización del trabajo en equipo


![image](https://github.com/CATorresP/TeoriaCompiladores-TF/assets/81259737/7bbd61df-0593-4b7b-ab6d-ef1334a31c94)


Conclusiones

El desarrollo de esta shell no solo ha permitido aplicar los conocimientos adquiridos en teoría de compiladores, sino que también ha proporcionado una visión más profunda de los componentes internos de una shell y su papel esencial en el entorno de la informática. La implementación de un lenguaje básico de scripting, el manejo de variables de entorno y la capacidad de ejecutar comandos del sistema operativo amplían significativamente la utilidad de la shell.
La elección de ANTLR como herramienta para el análisis sintáctico ha demostrado ser acertada, facilitando la construcción de un lexer y parser robustos que comprenden la gramática definida. La incorporación del patrón de visitante para analizar la estructura sintáctica proporciona una flexibilidad adicional, permitiendo la implementación de funciones específicas de manera modular.
Por lo que, este proyecto no solo representa un logro en términos de implementación de software, sino que también abre la puerta a posibles expansiones y mejoras en futuras versiones de la shell. El conocimiento adquirido sobre la construcción de compiladores y la implementación de funcionalidades avanzadas en una shell contribuye de manera significativa al desarrollo de habilidades prácticas en el ámbito de la ciencia de la computación.

