/*--------------------------------------------------------------|
|  Autor: Diego Alonso Rubí Salas.                              | 
|  Fecha: 20/Abr/2020                                           | 
|---------------------------------------------------------------| 
|  Descripción del archivo:                                     |
|                                                               |
|       En este encabezado se define la estructura que  se va   |
|   a utilizar, los prototipos de las funciones y los macros    |
|   necesarios para el programa.                                |
|---------------------------------------------------------------|
| Archivo: structs.h                               Versión: 1.0 |
| --------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*
 * MACROS
 */

#undef boolean
#undef TRUE
#undef FALSE

#define boolean int //Declaramos un "tipo" de dato para el manejo de los booleanos.
#define TRUE 1
#define FALSE 0


/*
 * ESTRUCTURA
 */

typedef struct _numero
{
    int num;
    struct _numero * next;
} NUMERO;

/*
 * PROTOTIPOS
 */

NUMERO * NuevoNumero(int __NUMERO_A_INGRESAR__);
boolean InsertaNumero(NUMERO **__NODO_INICIAL__, NUMERO * __NUEVO_NODO__);
boolean ExisteNumero(NUMERO ** __NODO_INICIAL__, int __NUMERO_A_BUSCAR__);
boolean EliminaNumero(NUMERO **__NODO_INICIAL__, int __NUMERO_A_ELIMINAR__);
boolean ModificaNumero(NUMERO ** __NODO_INICIAL__, int __NUMERO_ANTIGUO__, int __NUMERO_NUEVO__);
void ImprimeLista(NUMERO **__NODO_INICIAL__);