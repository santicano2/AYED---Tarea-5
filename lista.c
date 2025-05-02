#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct ListaE{
    NodoPtr primero;
};

// CONSTRUCTORES
ListaPtr crearLista(){
    ListaPtr lista = (ListaPtr) malloc(sizeof(struct ListaE));

    if (lista == NULL) {
        printf("\ERROR: No se pudo asignar memoria para la lista.");
        exit(-1);
    }

    lista->primero = NULL;

    return lista;
};

// GET Y SET
NodoPtr getPrimero(ListaPtr lista) {
    if (lista == NULL) {
        printf("\ERROR: Intentando acceder al primer nodo de una lista NULL.");
        return NULL;
    }
    return lista->primero;
}

void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero) {
    if (lista == NULL) {
        printf("\ERROR: Intentando modificar el primer nodo de una lista NULL.");
        return;
    }
    lista->primero = nuevoPrimero;
}

// MOSTRAR
void mostrarLista(ListaPtr lista){
    if (lista == NULL) {
        printf("\n<LISTA NULA>\n");
        return;
    }

    printf("\n<LISTA> TAM: %d \n", obtenerTamanio(lista));
    NodoPtr actual = getPrimero(lista);

    while (actual!=NULL){
        mostrarNodo(actual);
        actual = getNodoSiguiente(actual);
    }

    printf("\n\n");
};

void mostrarListaChar(ListaPtr lista) {
    if (lista == NULL) {
        printf("\n<LISTA NULA>\n");
        return;
    }

    printf("\n<LISTA> TAM: %d \n", obtenerTamanio(lista));
    NodoPtr actual = getPrimero(lista);

    while (actual != NULL) {
        mostrarNodoChar(actual);
        actual = getNodoSiguiente(actual);
    }
    printf("\n\n");
}

void mostrarListaFloat(ListaPtr lista) {
    if (lista == NULL) {
        printf("\n<LISTA NULA>\n");
        return;
    }

    printf("\n<LISTA> TAM: %d \n", obtenerTamanio(lista));
    NodoPtr actual = getPrimero(lista);

    while (actual != NULL) {
        mostrarNodoFloat(actual);
        actual = getNodoSiguiente(actual);
    }
    printf("\n\n");
}

// DESTRUCTOR
void liberarLista(ListaPtr lista) {
    if (lista == NULL) return;

    NodoPtr actual = getPrimero(lista);

    while (actual!=NULL){
        NodoPtr aux = actual;

        actual = getNodoSiguiente(actual);
        liberarNodo(aux);
    };

    free(lista);
}

// OPERACIONES
void insertarPrimero(ListaPtr lista, DatoPtr dato){
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return;
    }

    NodoPtr nuevoNodo = crearNodo(dato, getPrimero(lista));

    setPrimero(lista, nuevoNodo);

};

void insertarUltimo(ListaPtr lista, DatoPtr dato){
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return;
    }

    NodoPtr actual = getPrimero(lista);

    if (actual == NULL){ /// Lista no tiene nodos
        insertarPrimero(lista, dato);
        return;
    }

    /// Recorrer hasta ultimo nodo
    while (getNodoSiguiente(actual) != NULL) {
        actual = getNodoSiguiente(actual);
    }

    setNodoSiguiente(actual, crearNodo(dato, NULL));

};

void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion){
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return;
    }

    int tam = obtenerTamanio(lista);

    if (posicion < 0) {
        printf("\nERROR: No se puede insertar en posiciones negativas");
        return;
    }

    if (posicion > tam) {
        printf("\nERROR: No se puede insertar en una posicion que no existe");
        return;
    }

    if (posicion == 0) {
        insertarPrimero(lista, dato);
        return;
    }

    if (posicion == tam) {
        insertarUltimo(lista, dato);
        return;
    }

    /// INSERTAR
    NodoPtr actual = getPrimero(lista);
    for (int i = 0; i < posicion - 1; i++) {
        actual = getNodoSiguiente(actual);
    }

    setNodoSiguiente(actual, crearNodo(dato, getNodoSiguiente(actual)));

};

DatoPtr obtenerPrimero(ListaPtr lista) {
    if (lista == NULL || getPrimero(lista) == NULL) {
        printf("\nERROR: La lista esta vacia o es NULL");
        return NULL;
    }

    return getNodoDato(getPrimero(lista));
};

DatoPtr obtenerUltimo(ListaPtr lista) {
    if (lista == NULL || getPrimero(lista) == NULL) {
        printf("\nERROR: La lista esta vacia o es NULL");
        return NULL;
    }

    NodoPtr actual = getPrimero(lista);
    while (getNodoSiguiente(actual) != NULL) {
        actual = getNodoSiguiente(actual);
    }

    return getNodoDato(actual);
};

DatoPtr obtenerPosicion(ListaPtr lista, int pos) {
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return NULL;
    }

    int tam = obtenerTamanio(lista);

    if (pos < 0 || pos >= tam) {
        printf("\nERROR: Posicion fuera de rango");
        return NULL;
    }

    NodoPtr actual = getPrimero(lista);
    for (int i = 0; i < pos; i++) {
        actual = getNodoSiguiente(actual);
    }

    return getNodoDato(actual);
};


DatoPtr eliminarPrimero(ListaPtr lista) {
    if (lista == NULL || getPrimero(lista) == NULL) {
        printf("\nERROR: La lista esta vacia o es NULL");
        return NULL;
    }

    NodoPtr nodoEliminar = getPrimero(lista);
    DatoPtr valorRetorno = getNodoDato(nodoEliminar);

    setPrimero(lista, getNodoSiguiente(nodoEliminar));
    liberarNodo(nodoEliminar);

    return valorRetorno;
};

DatoPtr eliminarUltimo(ListaPtr lista) {
    if (lista == NULL || getPrimero(lista) == NULL) {
        printf("\nERROR: La lista esta vacia o es NULL");
        return NULL;
    }

    if (getNodoSiguiente(getPrimero(lista)) == NULL) {
        /// Solo un nodo
        DatoPtr valorRetorno = getNodoDato(getPrimero(lista));
        liberarNodo(getPrimero(lista));
        setPrimero(lista, NULL);
        return valorRetorno;
    }

    /// Mas de un nodo
    NodoPtr actual = getPrimero(lista);
    while (getNodoSiguiente(getNodoSiguiente(actual)) != NULL) {
        actual = getNodoSiguiente(actual);
    }

    DatoPtr valorRetorno = getNodoDato(getNodoSiguiente(actual));
    liberarNodo(getNodoSiguiente(actual));
    setNodoSiguiente(actual, NULL);

    return valorRetorno;
};

DatoPtr eliminarPosicion(ListaPtr lista, int pos) {
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return NULL;
    }

    int tam = obtenerTamanio(lista);

    if (pos < 0 || pos >= tam) {
        printf("\nERROR: Posicion fuera de rango");
        return NULL;
    }

    if (pos == 0) {
        return eliminarPrimero(lista);
    }

    if (pos == tam - 1) {
        return eliminarUltimo(lista);
    }

    /// ELIMINAR
    NodoPtr actual = getPrimero(lista);
    for (int i = 0; i < pos - 1; i++) {
        actual = getNodoSiguiente(actual);
    }

    NodoPtr nodoEliminar = getNodoSiguiente(actual);
    DatoPtr valorRetorno = getNodoDato(nodoEliminar);

    setNodoSiguiente(actual, getNodoSiguiente(nodoEliminar));
    liberarNodo(nodoEliminar);

    return valorRetorno;
};

NodoPtr obtenerPrimeroNodo(ListaPtr lista) {
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return NULL;
    }

    return getPrimero(lista);
};

NodoPtr obtenerUltimoNodo(ListaPtr lista) {
    if (lista == NULL || getPrimero(lista) == NULL) {
        return NULL;
    }

    NodoPtr actual = getPrimero(lista);
    while (getNodoSiguiente(actual) != NULL) {
        actual = getNodoSiguiente(actual);
    }

    return actual;
};

NodoPtr obtenerPosicionNodo(ListaPtr lista,int pos) {
   if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return NULL;
    }

    int tam = obtenerTamanio(lista);

    if (pos < 0 || pos >= tam) {
        printf("\nERROR: Posicion fuera de rango");
        return NULL;
    }

    NodoPtr actual = getPrimero(lista);
    for (int i = 0; i < pos; i++) {
        actual = getNodoSiguiente(actual);
    }

    return actual;
};

int obtenerTamanio(ListaPtr lista){
    if (lista == NULL) return 0;

    int i = 0;

    NodoPtr actual = getPrimero(lista);

    while (actual!=NULL) {
        i++;
        actual = getNodoSiguiente(actual);
    }

    return i;

};

// ORDERNAR
void ordenarListaEnteros(ListaPtr lista) {
    if (lista == NULL) return;

    int n = obtenerTamanio(lista);
    if (n <= 1) return;  // NO SE ORDENA

    int intercambio;
    for (int i = 0; i < n; i++) {
        intercambio = 0;
        NodoPtr actual = getPrimero(lista);

        for (int j = 0; j < n - i - 1; j++) {
            if (*(int*)getNodoDato(actual) > *(int*)getNodoDato(getNodoSiguiente(actual))) {
                // INTERCAMBIAR
                DatoPtr temp = getNodoDato(actual);
                setNodoDato(actual, getNodoDato(getNodoSiguiente(actual)));
                setNodoDato(getNodoSiguiente(actual), temp);
                intercambio = 1;
            }
            actual = getNodoSiguiente(actual);
        }

        // YA ORDENADO
        if (intercambio == 0) break;
    }
}

void ordenarListaStrings(ListaPtr lista) {
    if (lista == NULL) return;

    int n = obtenerTamanio(lista);
    if (n <= 1) return;  // NO SE ORDENA

    int intercambio;
    for (int i = 0; i < n; i++) {
        intercambio = 0;
        NodoPtr actual = getPrimero(lista);

        for (int j = 0; j < n - i - 1; j++) {
            // COMPARAR
            if (strcmp((char*)getNodoDato(actual), (char*)getNodoDato(getNodoSiguiente(actual))) > 0) {
                // INTERCAMBIAR
                DatoPtr temp = getNodoDato(actual);
                setNodoDato(actual, getNodoDato(getNodoSiguiente(actual)));
                setNodoDato(getNodoSiguiente(actual), temp);
                intercambio = 1;
            }
            actual = getNodoSiguiente(actual);
        }

        // YA ORDENADO
        if (intercambio == 0) break;
    }
}

void ordenarListaFloats(ListaPtr lista) {
    if (lista == NULL) return;

    int n = obtenerTamanio(lista);
    if (n <= 1) return;  // NO SE ORDENA

    int intercambio;
    for (int i = 0; i < n; i++) {
        intercambio = 0;
        NodoPtr actual = getPrimero(lista);

        for (int j = 0; j < n - i - 1; j++) {
            if (*(float*)getNodoDato(actual) > *(float*)getNodoDato(getNodoSiguiente(actual))) {
                // INTERCAMBIAR
                DatoPtr temp = getNodoDato(actual);
                setNodoDato(actual, getNodoDato(getNodoSiguiente(actual)));
                setNodoDato(getNodoSiguiente(actual), temp);
                intercambio = 1;
            }
            actual = getNodoSiguiente(actual);
        }

        // YA ORDENADO
        if (intercambio == 0) break;
    }
}

ListaPtr ordenarListaCopiaEnteros(ListaPtr lista) {
    if (lista == NULL) return NULL;

    ListaPtr nuevaLista = duplicarLista(lista);
    ordenarListaEnteros(nuevaLista);
    return nuevaLista;
}

ListaPtr ordenarListaCopiaStrings(ListaPtr lista) {
    if (lista == NULL) return NULL;

    ListaPtr nuevaLista = duplicarLista(lista);
    ordenarListaStrings(nuevaLista);
    return nuevaLista;
}

ListaPtr ordenarListaCopiaFloats(ListaPtr lista) {
    if (lista == NULL) return NULL;

    ListaPtr nuevaLista = duplicarLista(lista);
    ordenarListaFloats(nuevaLista);
    return nuevaLista;
}

ListaPtr duplicarLista(ListaPtr lista) {
    if (lista == NULL) return NULL;

    ListaPtr nuevaLista = crearLista();

    NodoPtr actual = getPrimero(lista);
    while (actual != NULL) {
        insertarUltimo(nuevaLista, getNodoDato(actual));
        actual = getNodoSiguiente(actual);
    }

    return nuevaLista;
};

// BUSQUEDA
int buscarElementoEntero(ListaPtr lista, int datoBuscado) {
    if (lista == NULL) return -1;

    NodoPtr actual = getPrimero(lista);
    int posicion = 0;

    while (actual != NULL) {
        if (*(int*)getNodoDato(actual) == datoBuscado) {
            return posicion;
        }
        actual = getNodoSiguiente(actual);
        posicion++;
    }

    return -1;  // NO SE ENCONTRÓ
}

int buscarElementoString(ListaPtr lista, char* datoBuscado) {
    if (lista == NULL) return -1;

    NodoPtr actual = getPrimero(lista);
    int posicion = 0;

    while (actual != NULL) {
        if (strcmp((char*)getNodoDato(actual), datoBuscado) == 0) {
            return posicion;
        }
        actual = getNodoSiguiente(actual);
        posicion++;
    }

    return -1;  // NO SE ENCONTRÓ
}

int buscarElementoFloat(ListaPtr lista, float datoBuscado) {
    if (lista == NULL) return -1;

    NodoPtr actual = getPrimero(lista);
    int posicion = 0;

    while (actual != NULL) {
        if (*(float*)getNodoDato(actual) == datoBuscado) {
            return posicion;
        }
        actual = getNodoSiguiente(actual);
        posicion++;
    }

    return -1;  // NO SE ENCONTRÓ
}

// INSERTAR EN ORDEN
void insertarEnOrdenEntero(ListaPtr lista, int dato) {
    if (lista == NULL) return;

    int* datoPtr = (int*)malloc(sizeof(int));
    if (datoPtr == NULL) {
        printf("\nERROR: NO SE PUDO ASIGNAR MEMORIA PARA EL DATO.");
        return;
    }
    *datoPtr = dato;

    if (getPrimero(lista) == NULL || *(int*)getNodoDato(getPrimero(lista)) >= dato) {
        insertarPrimero(lista, datoPtr);
        return;
    }

    NodoPtr actual = getPrimero(lista);
    while (getNodoSiguiente(actual) != NULL &&
           *(int*)getNodoDato(getNodoSiguiente(actual)) < dato) {
        actual = getNodoSiguiente(actual);
    }

    setNodoSiguiente(actual, crearNodo(datoPtr, getNodoSiguiente(actual)));
}

void insertarEnOrdenString(ListaPtr lista, char* dato) {
    if (lista == NULL) return;

    if (getPrimero(lista) == NULL || strcmp((char*)getNodoDato(getPrimero(lista)), dato) >= 0) {
        insertarPrimero(lista, dato);
        return;
    }

    NodoPtr actual = getPrimero(lista);
    while (getNodoSiguiente(actual) != NULL &&
           strcmp((char*)getNodoDato(getNodoSiguiente(actual)), dato) < 0) {
        actual = getNodoSiguiente(actual);
    }

    setNodoSiguiente(actual, crearNodo(dato, getNodoSiguiente(actual)));
};

void insertarEnOrdenFloat(ListaPtr lista, float dato) {
    if (lista == NULL) return;

    float* datoPtr = (float*)malloc(sizeof(float));
    if (datoPtr == NULL) {
        printf("\nERROR: NO SE PUDO ASIGNAR MEMORIA PARA EL DATO.");
        return;
    }
    *datoPtr = dato;

    if (getPrimero(lista) == NULL || *(float*)getNodoDato(getPrimero(lista)) >= dato) {
        insertarPrimero(lista, datoPtr);
        return;
    }

    NodoPtr actual = getPrimero(lista);
    while (getNodoSiguiente(actual) != NULL &&
           *(float*)getNodoDato(getNodoSiguiente(actual)) < dato) {
        actual = getNodoSiguiente(actual);
    }

    setNodoSiguiente(actual, crearNodo(datoPtr, getNodoSiguiente(actual)));
};
