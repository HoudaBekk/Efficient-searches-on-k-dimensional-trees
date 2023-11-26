# proyectoAlgoritmia2023

## Uso del generador y consultador

Primero hacemos el make
```
make generadorKdTree
make queryKdTree
```

Esto nos generara los ejecutables que se usan de la siguiente manera:

### generadorKdTree
Al iniciar el generador, el programa espera por la entrada el N de arboles, el numero de nodos, las dimensiones y el numero de busquedas.
Si queremos tambien podemos pasarle un archivo con los parametros de inicio como en el siguiente ejemplo:
```
./generadorKdTree T k n q
```
### queryKdTree
Este programa es el que se usa para procesar las busquedas, en el generadorKdTree generamos la entrada y la podemos guardar en un fichero para posteriormente pasarsela al queryKdTree.
```
./queryKdTree [STANDART|RELAX|SQUARISH] < input.txt
```
Donde el primer parametro es el discriminante a usar. El queryKdTree devolvera el numero de arboles que se ha consultado, el numero de busquedas y la lista de nodos que estan cerca de esta busqueda junto al coste.





