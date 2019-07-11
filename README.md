# lab-unix
Lab Unix - 75.08 Sistemas Operativos

Ejemplo uso: 
```
make ls0
./ls0.o
```

Para eliminar los binarios:
```
make clean
```

## rm0 ☆
rm (remove) es la herramienta unix que permite eliminar archivos y directorios.  
El uso estándar rm <file> permite borrar solo archivos regulares, y arrojará error si se intenta eliminar un directorio.  
Para la implementación de rm0 solo se considerará el caso de archivos regulares.

```
$ ls
archivo1   archivo2   directorio1   rm0
$ ./rm0 archivo1
$ ls
archivo2   directorio1   rm0
```
Se pide: implementar rm0 que elimina un archivo regular.  
Pre-condición: el archivo existe y es regular.  
Syscalls recomendadas: unlink.


## ls0 ☆☆☆
ls (list) lista los contenidos del directorio que se le pase por parámetro. Si no se especifica ningún parámetro, ls muestra el contenido de los archivos en el directorio actual (ver pwd(1)).

El comando ls admite una gran variedad de flags para elegir qué información se mostrará de los archivos, con qué formato y orden. La implementación de ls0 se corresponderá con ls -U1, o lo que es equivalente ls --format=single-column --sort=none, que lista únciamente los nombres de los archivos, sin ningún ordenamiento particular y de a uno por línea.

Por ejemplo:

$ ls
archivo1   archivo2   archivo3   ls0
$ ./ls0
archivo2
archivo1
ls0
archivo3
Se pide: Implementar ls0 que lista todos los archivos en el directorio actual, uno en cada línea. No hay que preocuparse por el orden en que se listen los archivos, con que se muestren todos es suficiente.

Funciones recomendadas: stat(2), opendir(3), readdir(3), closedir(3).



## cat0 ☆
cat (concatenate) es una herramienta unix que permite concatenar archivos y mostrarlos por salida estándar. En este lab se implementará una vesión simplificada de cat, que muestra en pantalla los contenidos de un único archivo.

$ cat ejemplo.txt
Sistemas Operativos, 1er cuatrimestre 2018
Se pide: Implementar cat0 que toma un archivo regular y muestra su contenido por salida estándar.

Pre-condición: solo se pasa un archivo, este archivo existe y se tienen permisos de lectura.

Syscalls recomendadas: open, read, write, close.


## stat0 ☆☆
stat muestra en pantalla los metadatos de un archivo, incluyendo información sobre tipo de archivo, fechas de creación y modificación, permisos, etc.

$ stat README.md
  File: README.md
  Size: 1318        Blocks: 8          IO Block: 4096   regular file
Device: 806h/2054d  Inode: 2753812     Links: 1
Access: (0644/-rw-r--r--)  Uid: ( 1000/    juan)   Gid: ( 1000/    juan)
Access: 2018-03-14 17:36:37.497432618 -0300
Modify: 2018-03-08 23:27:15.765147109 -0300
Change: 2018-03-08 23:27:15.765147109 -0300
 Birth: -
La implementación de stat0 mostrará únicamente el nombre, tipo y tamaño del archivo (en bytes).

$ ./stat0 README.md
Size: 1318
File: README.md
Type: regular file
Se pide: Implementar stat0 que muestra el nombre, tipo y tamaño en bytes de un archivo regular o directorio.

Pre-condición: el archivo existe, y es un directorio o un archivo regular.

Syscalls recomendadas: stat. Se puede consultar también la página de manual inode(7).