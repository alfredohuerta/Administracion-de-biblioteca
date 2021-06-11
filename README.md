# TC1030 Administracion-de-biblioteca
El presente proyecto busca representar el manejo de los recursos básico de una biblioteca, siendo estos los libreros, los cuales pueden generarse, llenarse, manipularse y filtrar usando funciones tanto abstractas como "normales". Además de que el grueso del proyecto está conectado por medio de apuntadores que encadenan los getters y setters que permite, por ejemplo: pedir prestado un libro, cambiando su estatus de disponible a prestado.
# Funcionalidad
Permite la creación de Libreros, filas, libros y revistas, así como su visualización en pantalla. Además se pueden modificar sus atributos para pedirlos prestados. También es posible filtrar los libros y revistas de acuerdo a su tipo de objeto, su disponibilidad o falta de la misma y su ID. Tanto los libreros como las filas que los conforman son completamente personalizables al momento de su creación y para la navegación a través de ellos es necesario conocer su ID ya que se puede interactuar individualmente con ellos.
# Correcciones
Se implementó herencia en Texto.h usando de clase padre a Texto que hereda a Libro y Revista.\
Se aplicó sobreescritura de métodos en Texto.h en la clase padre Texto.\
Se aplicaron clases abstractas en Texto.h\
Se aplicó polimorfismo en Texto.h
