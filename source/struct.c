/*--------------------------------------------------------------|
|  Autor: Diego Alonso Rubí Salas.                              | 
|  Fecha: 20/Abr/2020                                           | 
|---------------------------------------------------------------| 
|  Descripción del programa:                                    | 
|                                                               |
|       Archivo de codigo fuente que almacena todos los metodos |
|   necesarios para la creacion de una lista simple enlazada.   |
|       La difirencia de esta lista, es que se utiliza un       |
|   puntero triple para el menejo y control de los datos.       |
|---------------------------------------------------------------|
| Archivo: structs.c                               Versión: 1.0 |
| --------------------------------------------------------------*/

#include "./struct.h"

/**
 * Metodo que crea el nodo para ingresar el numero a la lista.
 */
NUMERO * NuevoNumero(int n)
{
    NUMERO *n_nodo; //Se crea una nueva estructura.
    n_nodo = (NUMERO *) malloc(sizeof(NUMERO)); //Se crea el espacio de memoria.
    n_nodo->num = n; //Se almacena el numero dentro de la estructura.
    n_nodo->next = NULL; //Se indica deja el siguiente nodo como nulo.
    return n_nodo; //Se retorna la estructura creada.
}

/**
 * Este metodo inserta items a la lista de forma ordenada.
 * Para este caso se ordenara segun el valor de num.
 */
boolean InsertaNumero(NUMERO **inicio, NUMERO * np)
{
    NUMERO ** tmp = inicio; //Creamos un nodo temporal que nos ayudara a recorer la lista.
    if(!ExisteNumero(inicio, np->num)){
        while((*tmp != NULL) && (*tmp)->num < np->num ) //Mientras el nodo temporal no sea nulo, y el dato a ingresar sea mayor 
        { 
            tmp = &(*tmp)->next; //Ahora el nodo temporal es igual al siguiente nodo.
        }
        np->next = *tmp; //Se indica como el siguiente nodo al resto de la lista.
        *tmp = np; //Se indica el nuevo inicio de la lista.
        return TRUE;
    }
    return FALSE;
}

/**
 * Metodo que recorre la lista en bsuqueda de el dato solicitado.
 */
boolean ExisteNumero(NUMERO ** inicio, int n)
{
    NUMERO ** tmp = inicio; //Creamos un nodo temporal que nos ayudara a recorer la lista.
    int Existe = FALSE;
    while (*tmp != NULL)
    {
        if((*tmp)->num == n){
            Existe = TRUE;
            break;
        }
        tmp = &(*tmp)->next;
    }
    return Existe;
}

/**
 * Metodo que recorre la lista para eliminar el dato deseado.
 */
boolean EliminaNumero(NUMERO **inicio, int n)
{
    NUMERO ** tmp = inicio;
    NUMERO * aux;
    int Existe = FALSE;
    while (*tmp != NULL)
    {
        if((*tmp)->num == n)
        {
            aux = *tmp;
            *tmp = (*tmp)->next;
            free(aux);
            Existe = TRUE;
        }
        tmp = &(*tmp)->next; //Ahora el nodo temporal es igual al siguiente nodo.
    }
    return Existe;
}

boolean ModificaNumero(NUMERO ** inicio, int a_num, int n_num)
{
    NUMERO ** tmp = inicio; //Se crea un puntero con el inicio de la lista.
    NUMERO ** aux = &(*tmp);
    boolean Existe = FALSE;
    /*
        Al moficar el numero contenido por la estructura NUMERO, solo se modificara
        el dato que posee, pero esto no significa que su posición tambien lo haga.
        Por lo que en este metodo se utlilizaran los metodos ya implementados.
    */
   while ((*tmp) != NULL)
   {
       if((*tmp)->num == a_num){
           Existe = TRUE;
           EliminaNumero(&(*tmp), a_num);
           InsertaNumero(&(*aux), NuevoNumero(n_num));
       }
       tmp = &(*tmp)->next;
   }
    return Existe;
}

/**
 * Imprime todos los valores almacenados en la lista.
 */
void ImprimeLista(NUMERO **inicio)
{
    NUMERO ** tmp = inicio;//Creamos un puntero temporal del puntero que indica el inicio de la lista.
    if (*tmp == NULL) //En caso de estar vacio, muestra un mensaje de error.
    {
        printf("¡Lista Vacia!\n");
    } else {
        int i = 0; //Contador de elementos de la lista.
        while(*tmp != NULL) //Mientras el puntero no sea nulo.
        {
            printf("#%d -> %d\n", i, (*tmp)->num);//Mostramos el dato almacenado dentro del puntero al que señala el nodo temporal.
            tmp = &(*tmp)->next; //Ahora el nodo temporal es igual al siguiente nodo.
            i++;
        }
    }
}
