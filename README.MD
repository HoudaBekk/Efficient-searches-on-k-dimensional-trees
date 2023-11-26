# Búsquedas eficientes sobre árboles k-dimensionales

## Uso del generador y consultador

Primero hacemos el make
```
make generadorKdTree
make queryKdTree
```

Esto genera los siguientes ejecutables que requerirán los parámetros especificados a continuación:

### generadorKdTree
Al iniciar el generador, el programa espera recibir por la entrada el número de árboles T, el numero de nodos n, la dimensionalidad de los nodos del árbol k y el número de búsquedas q.
Si queremos tambien podemos pasarle un archivo con los parametros de inicio como en el siguiente ejemplo:
```
./generadorKdTree T k n q
```
### queryKdTree
Este programa es el que procesa las búsquedas. En el generadorKdTree generamos la entrada y la podemos guardar en un fichero para posteriormente pasársela al queryKdTree.
```
./queryKdTree [STANDARD|RELAXED|SQUARISH] < input.txt
```
Donde el primer parametro es el tipo de discriminante a utilizar en la construcción del árbol. El queryKdTree devuelve el número de arboles sobre los que se han realizado consultas del vecino más cercano, el número de consultas por árbol y una lista con los resultados de todas las búsquedas de los nodos más cercanos al nodo consultado, junto al coste de la consulta.





