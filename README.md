# Área Académica de Ingeniería en Computadores
## Algoritmos y Estructuras de Datos II
### Profesor:
#### Antonio González Torres
### Estudiantes:
#### Anthony Montero
#### Juan Peña

## Proyecto III: TECFS - SI 2021
## Acerca del servidor
El servidor interpreta las solicitudes provenientes del cliente según como se van solicitando queries desde las distintas aplicaciones. Sus tareas se dividen en: <br/>
### Almacenar libros
Recibe y guarda los archivos que manda la aplicación cliente en sus distintas formas según la estructura del libro, por ejemplo, el contenido del libro va escrito en un archivo .txt, la metadata en un archivo .json y el archivo comprimido en un .huf. <br/>
### Enviar resultados de búsqueda
Recibe palabras clave sobre el título de un libro, procede con la búsqueda de coincidencias en los archivos .json y manda la lista de archivos .txt que coinciden con la palabra clave.
### Uso de algoritmo de Huffman para comprimir archivos
El servidor realiza la descompresión de archivos que .huf que contienen la información binaria del libro y procede a guardarlo en el directorio de archivos .txt. Además, cuando se hacen queries de búsqueda de libros, envía los resultados comprimidos con Huffman al cliente. 

## Bibliotecas necesarias 
Este proyecto fue realizado en Ubuntu(Linux) en el lenguaje C++
Primero se necesita una biblioteca de manejo de archivos JSON. Se puede instalar con los siguientes comandos:

`apt-get update` <br/>
`sudo apt-get install nlohmann-json3-dev`
