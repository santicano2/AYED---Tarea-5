#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct NodoE;

typedef struct NodoE * NodoPtr;
typedef void * DatoPtr;

// CONSTRUCTORES
NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);

// GET Y SET
DatoPtr getNodoDato(NodoPtr nodo);
NodoPtr getNodoSiguiente(NodoPtr nodo);

void setNodoDato(NodoPtr nodo, DatoPtr nuevoDato);
void setNodoSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente);

// MOSTRAR
void mostrarNodo(NodoPtr nodo);
void mostrarNodoChar(NodoPtr nodo);
void mostrarNodoFloat(NodoPtr nodo);

// DESTRUCTOR
void liberarNodo(NodoPtr nodo);

#endif // NODO_H_INCLUDED
