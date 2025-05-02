#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <string.h>

#include "nodo.h"

struct ListaE;

typedef struct ListaE * ListaPtr;

// CONSTRUCTORES
ListaPtr crearLista();

// GET Y SET
NodoPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero);

// MOSTRAR
void mostrarLista(ListaPtr lista);
void mostrarListaChar(ListaPtr lista);
void mostrarListaFloat(ListaPtr lista);

// DESTRUCTOR
void liberarLista(ListaPtr lista);

// OPERACIONES
void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);

DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista,int pos);

DatoPtr eliminarPrimero(ListaPtr lista);
DatoPtr eliminarUltimo(ListaPtr lista);
DatoPtr eliminarPosicion(ListaPtr lista, int pos);

NodoPtr obtenerPrimeroNodo(ListaPtr lista);
NodoPtr obtenerUltimoNodo(ListaPtr lista);
NodoPtr obtenerPosicionNodo(ListaPtr lista,int pos);

int obtenerTamanio(ListaPtr lista);

// ORDERNAR
void ordenarListaEnteros(ListaPtr lista);
void ordenarListaStrings(ListaPtr lista);
void ordenarListaFloats(ListaPtr lista);

ListaPtr ordenarListaCopiaEnteros(ListaPtr lista);
ListaPtr ordenarListaCopiaStrings(ListaPtr lista);
ListaPtr ordenarListaCopiaFloats(ListaPtr lista);

ListaPtr duplicarLista(ListaPtr lista);

// BUSQUEDA
int buscarElementoEntero(ListaPtr lista, int datoBuscado);
int buscarElementoString(ListaPtr lista, char* datoBuscado);
int buscarElementoFloat(ListaPtr lista, float datoBuscado);

// INSERTAR EN ORDEN
void insertarEnOrdenEntero(ListaPtr lista, int dato);
void insertarEnOrdenString(ListaPtr lista, char* dato);
void insertarEnOrdenFloat(ListaPtr lista, float dato);

void insertarEnOrden(ListaPtr lista, DatoPtr dato);

#endif // LISTA_H_INCLUDED
