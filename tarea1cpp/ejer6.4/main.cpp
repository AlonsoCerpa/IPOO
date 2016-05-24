/*
No se puede retornar un arreglo de 2 dimensiones habiendolo creado dentro
de la función ya que para retornarlo se tendria que retornar un puntero a
puntero que se igualaria a la matriz, y como solo se puede retornar arreglos
de 1 dimension, lo que se retornaria seria un puntero a la primera direccion
de memoria de las filas de la matriz, entonces al acabar la funcion, se elimina
la matriz creada y todos sus elementos, de tal manera que lo retornado serian
punteros a basura, porque la memoria donde apuntaban ya ha sido liberada.
*/

int main(){
    return 0;
}
