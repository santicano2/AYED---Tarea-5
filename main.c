#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void probarListaEnteros() {
    printf("\n======== PRUEBA DE LISTA CON ENTEROS ========\n");

    ListaPtr listaInt = crearLista();

    // NUMEROS
    int n1 = 4, n2 = 11, n3 = 109, n4 = 21, n5 = 35, n6 = 42;

    printf("\n-- INSERTANDO ELEMENTOS EN LA LISTA --\n");
    insertarPrimero(listaInt, &n1);
    insertarPrimero(listaInt, &n2);
    insertarUltimo(listaInt, &n3);
    insertarPrimero(listaInt, &n4);
    insertarPosicion(listaInt, &n5, 2);
    insertarUltimo(listaInt, &n6);

    printf("\n-- LISTA DE ENTEROS DESPUES DE INSERTAR --\n");
    mostrarLista(listaInt);

    printf("\n-- ORDENANDO LISTA DE ENTEROS --\n");
    ordenarListaEnteros(listaInt);
    mostrarLista(listaInt);

    // BUSCAR ELEMENTOS
    int buscar1 = 109;
    int buscar2 = 35;

    int pos1 = buscarElementoEntero(listaInt, buscar1);
    int pos2 = buscarElementoEntero(listaInt, buscar2);

    printf("\n-- RESULTADOS DE BUSQUEDA EN ENTEROS --\n");
    printf("POSICION DE %d: %d\n", buscar1, pos1);
    printf("POSICION DE %d: %d\n", buscar2, pos2);

    // ELEMENTOS
    int *primero = (int *)obtenerPrimero(listaInt);
    int *ultimo = (int *)obtenerUltimo(listaInt);
    int *posicion2 = (int *)obtenerPosicion(listaInt, 2);

    printf("\n-- OBTENIENDO ELEMENTOS --\n");
    printf("PRIMER ELEMENTO: %d\n", *primero);
    printf("ULTIMO ELEMENTO: %d\n", *ultimo);
    printf("ELEMENTO EN POSICION 2: %d\n", *posicion2);

    // ELIMINAR ELEMENTOS
    int *eliminado1 = (int *)eliminarPrimero(listaInt);
    printf("\n-- ELIMINANDO ELEMENTOS --\n");
    printf("ELEMENTO ELIMINADO DEL PRINCIPIO: %d\n", *eliminado1);
    mostrarLista(listaInt);

    int *eliminado2 = (int *)eliminarUltimo(listaInt);
    printf("ELEMENTO ELIMINADO DEL FINAL: %d\n", *eliminado2);
    mostrarLista(listaInt);

    int *eliminado3 = (int *)eliminarPosicion(listaInt, 1);
    printf("ELEMENTO ELIMINADO DE LA POSICION 1: %d\n", *eliminado3);
    mostrarLista(listaInt);

    // DUPLICAR
    ListaPtr duplicada = duplicarLista(listaInt);
    printf("\n-- LISTA DUPLICADA --\n");
    mostrarLista(duplicada);

    // LIBERAR
    liberarLista(listaInt);
    liberarLista(duplicada);
}

void probarListaStrings() {
    printf("\n\n\n======== PRUEBA DE LISTA CON STRINGS ========\n");

    ListaPtr listaStr = crearLista();

    // VARIABLES
    char *nom1 = "nico";
    char *nom2 = "brenda";
    char *nom3 = "walter";
    char *nom4 = "flor";
    char *nom5 = "juan";

    printf("\n-- INSERTANDO ELEMENTOS EN LA LISTA --\n");
    insertarPrimero(listaStr, nom1);
    insertarPrimero(listaStr, nom2);
    insertarUltimo(listaStr, nom3);
    insertarPrimero(listaStr, nom4);
    insertarPosicion(listaStr, nom5, 2);

    printf("\n-- LISTA DE STRINGS DESPUES DE INSERTAR --\n");
    mostrarListaChar(listaStr);

    printf("\n-- ORDENANDO LISTA DE STRINGS --\n");
    ordenarListaStrings(listaStr);
    mostrarListaChar(listaStr);

    // BUSCAR ELEMENTOS
    char *buscar1 = "brenda";
    char *buscar2 = "juan";

    int pos1 = buscarElementoString(listaStr, buscar1);
    int pos2 = buscarElementoString(listaStr, buscar2);

    printf("\n-- RESULTADOS DE BUSQUEDA EN STRINGS --\n");
    printf("POSICION DE %s: %d\n", buscar1, pos1);
    printf("POSICION DE %s: %d\n", buscar2, pos2);

    // ELEMENTOS
    char *primero = (char *)obtenerPrimero(listaStr);
    char *ultimo = (char *)obtenerUltimo(listaStr);
    char *posicion2 = (char *)obtenerPosicion(listaStr, 2);

    printf("\n-- OBTENIENDO ELEMENTOS --\n");
    printf("PRIMER ELEMENTO: %s\n", primero);
    printf("ULTIMO ELEMENTO: %s\n", ultimo);
    printf("ELEMENTO EN POSICION 2: %s\n", posicion2);

    // ELIMINAR ELEMENTOS
    char *eliminado1 = (char *)eliminarPrimero(listaStr);
    printf("\n-- ELIMINANDO ELEMENTOS --\n");
    printf("ELEMENTO ELIMINADO DEL PRINCIPIO: %s\n", eliminado1);
    mostrarListaChar(listaStr);

    char *eliminado2 = (char *)eliminarUltimo(listaStr);
    printf("ELEMENTO ELIMINADO DEL FINAL: %s\n", eliminado2);
    mostrarListaChar(listaStr);

    char *eliminado3 = (char *)eliminarPosicion(listaStr, 1);
    printf("ELEMENTO ELIMINADO DE LA POSICION 1: %s\n", eliminado3);
    mostrarListaChar(listaStr);

    // DUPLICAR
    ListaPtr duplicada = duplicarLista(listaStr);
    printf("\n-- LISTA DUPLICADA --\n");
    mostrarListaChar(duplicada);

    // LIBERAR
    liberarLista(listaStr);
    liberarLista(duplicada);
}

void probarListaFloats() {
    printf("\n\n\n======== PRUEBA DE LISTA CON FLOATS ========\n");

    ListaPtr listaFloat = crearLista();

    // NUMEROS
    float nf1 = 4.12, nf2 = 11.43, nf3 = 109.009, nf4 = 21.14, nf5 = 35.67;

    printf("\n-- INSERTANDO ELEMENTOS EN LA LISTA --\n");
    insertarPrimero(listaFloat, &nf1);
    insertarPrimero(listaFloat, &nf2);
    insertarUltimo(listaFloat, &nf3);
    insertarPrimero(listaFloat, &nf4);
    insertarPosicion(listaFloat, &nf5, 2);

    printf("\n-- LISTA DE FLOATS DESPUES DE INSERTAR --\n");
    mostrarListaFloat(listaFloat);

    printf("\n-- ORDENANDO LISTA DE FLOATS --\n");
    ordenarListaFloats(listaFloat);
    mostrarListaFloat(listaFloat);

    // BUSCAR ELEMENTOS
    float buscar1 = 21.14;
    float buscar2 = 11.43;

    int pos1 = buscarElementoFloat(listaFloat, buscar1);
    int pos2 = buscarElementoFloat(listaFloat, buscar2);

    printf("\n-- RESULTADOS DE BUSQUEDA EN FLOATS --\n");
    printf("POSICION DE %.1f: %d\n", buscar1, pos1);
    printf("POSICION DE %.1f: %d\n", buscar2, pos2);

    // ELEMENTOS
    float *primero = (float *)obtenerPrimero(listaFloat);
    float *ultimo = (float *)obtenerUltimo(listaFloat);
    float *posicion2 = (float *)obtenerPosicion(listaFloat, 2);

    printf("\n-- OBTENIENDO ELEMENTOS --\n");
    printf("PRIMER ELEMENTO: %.2f\n", *primero);
    printf("ULTIMO ELEMENTO: %.2f\n", *ultimo);
    printf("ELEMENTO EN POSICION 2: %.2f\n", *posicion2);

    // ELIMINAR ELEMENTOS
    float *eliminado1 = (float *)eliminarPrimero(listaFloat);
    printf("\n-- ELIMINANDO ELEMENTOS --\n");
    printf("ELEMENTO ELIMINADO DEL PRINCIPIO: %.2f\n", *eliminado1);
    mostrarListaFloat(listaFloat);

    float *eliminado2 = (float *)eliminarUltimo(listaFloat);
    printf("ELEMENTO ELIMINADO DEL FINAL: %.2f\n", *eliminado2);
    mostrarListaFloat(listaFloat);

    float *eliminado3 = (float *)eliminarPosicion(listaFloat, 1);
    printf("ELEMENTO ELIMINADO DE LA POSICION 1: %.2f\n", *eliminado3);
    mostrarListaFloat(listaFloat);

    // DUPLICAR
    ListaPtr duplicada = duplicarLista(listaFloat);
    printf("\n-- LISTA DUPLICADA --\n");
    mostrarListaFloat(duplicada);

    // LIBERAR
    liberarLista(listaFloat);
    liberarLista(duplicada);
}

int main()
{
    probarListaEnteros();
    probarListaStrings();
    probarListaFloats();

    return 0;
}
