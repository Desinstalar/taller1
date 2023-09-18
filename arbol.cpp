#include <iostream>

class Nodo {
public:
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : valor(val), izquierdo(nullptr), derecho(nullptr) {}
};

class ArbolBinario {
private:
    Nodo* raiz;

    Nodo* insertar(Nodo* nodo, int val) {
        if (nodo == nullptr) {
            return new Nodo(val);
        }

        if (val < nodo->valor) {
            nodo->izquierdo = insertar(nodo->izquierdo, val);
        } else if (val > nodo->valor) {
            nodo->derecho = insertar(nodo->derecho, val);
        }

        return nodo;
    }

    void imprimirEnOrden(Nodo* nodo) {
        if (nodo != nullptr) {
            imprimirEnOrden(nodo->izquierdo);
            std::cout << nodo->valor << " ";
            imprimirEnOrden(nodo->derecho);
        }
    }

public:
    ArbolBinario() : raiz(nullptr) {}

    void insertar(int val) {
        raiz = insertar(raiz, val);
    }

    void imprimirEnOrden() {
        imprimirEnOrden(raiz);
        std::cout << std::endl;
    }
};

int main() {
    ArbolBinario arbol;

    
    arbol.insertar(5);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(2);
    arbol.insertar(4);
    arbol.insertar(6);
    arbol.insertar(8);

    
    std::cout << "Árbol en orden:" << std::endl;
    arbol.imprimirEnOrden();

    return 0;
}
