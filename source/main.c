/*--------------------------------------------------------------|
|  Autor: Diego Alonso Rubí Salas.                              | 
|  Fecha: 20/Abr/2020                                           | 
|---------------------------------------------------------------| 
|  Descripción del programa:                                    | 
|                                                               |
|       Este programa sierve para poder enter mejor el uso de   |
|   los punteros en la creacion de listas simples enlazadas.    |
|                                                               |
|---------------------------------------------------------------|
|   Mas información:                                            |
|                                                               |
|       www.eprg.org/computerphile/tripref.c                    |
|---------------------------------------------------------------|
| Archivo: structs.c                               Versión: 1.0 |
| --------------------------------------------------------------*/

#include "./struct.h"

int main()
{
    NUMERO *inicio = NULL; //Puntero inicial de la lista.

    /* Insertar numeros a la lista */
    InsertaNumero(&inicio, NuevoNumero(1));
    InsertaNumero(&inicio, NuevoNumero(0));
    InsertaNumero(&inicio, NuevoNumero(30));
    InsertaNumero(&inicio, NuevoNumero(10));
    //En el siguiente caso, este numero no será insertado dado a que ya existe en la lista ese numero.
    InsertaNumero(&inicio, NuevoNumero(10));
    InsertaNumero(&inicio, NuevoNumero(-1));

    printf("\nLista inicial:\n");
    ImprimeLista(&inicio);

    printf("\nBusqueda:\n");
    int NumeroABuscar = 30;
    printf("El numero %d -> %s.\n", NumeroABuscar, (ExisteNumero(&inicio, NumeroABuscar) ? "EXISTE" : "NO EXISTE"));

    printf("\nEliminacion de un dato:\n");
    int NumeroAEliminar = 1;
    printf("El numero %d -> %s.\n", NumeroAEliminar, (EliminaNumero(&inicio, NumeroAEliminar) ? "Fue eliminado" : "No fue encontrado"));

    printf("\nLista version #2:\n");
    ImprimeLista(&inicio);

    printf("\nModificar un numero:\n");
    int NumeroAModificar = 10;
    int NumeroAAgregar = -2;
    printf("El numero %d %s.\n", NumeroAModificar, ModificaNumero(&inicio, NumeroAModificar, NumeroAAgregar) ? "Fue modificado" : "No se encontro");

    printf("\nLista version #3:\n");
    ImprimeLista(&inicio);

    return EXIT_SUCCESS;
}