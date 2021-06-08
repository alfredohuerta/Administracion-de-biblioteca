# TC1030 Administracion-de-biblioteca
El presente proyecto busca representar el manejo de los recursos básico de una biblioteca, los cuales se dividen en los libreros, las mesas, escritorios y la recepción junto
con las personas que la manejan. La profundidad en los detalles llega hasta las fichas bibliográficas de los libros, la dispondibilidad de tanto mesas como escritorios así como la necesidad de los mismo de limpiarse.
# Funcionalidad
Permite el apartado de mesas, escritorios y computadoras. Permite visualizar los libros, revistas y sus datos, además de cambiar sus estados a apartado, también crea bibliotecarios que pueden cambiar de ubicación, pueden ser llamados y regresados a la recepción.
La disponibilidad del equipo de la biblioteca está subordinada a valores booleanos que pueden modificarse mediante los métodos.
No permite crear nuevos objetos de los que ya están en el código
# Correcciones
Se implementó herencia en Libro.h con la nueva clase Revista.\
Se aplicó sobreescritura de métodos en Libro.h en la clase Revista en el método setPrestado.\
Se aplicaron clases abstractas en Escritorio.h, Fila.h, Librero.h y Recepcion.h
