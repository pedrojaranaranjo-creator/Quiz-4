#include <iostream>
using namespace std;

// Mostrar inventario
void mostrarInventario(int oro, int pociones) {
    cout << "Oro: " << oro << " | Pociones: " << pociones << endl;
}

// Comprar poción
bool comprarPocion(int* oro, int* pociones, int precio) {
    if (*oro >= precio) {
        *oro -= precio;
        (*pociones)++;
        return true;
    }
    return false;
}

// Vender poción
void venderPocion(int* oro, int* pociones, int precioVenta) {
    if (*pociones > 0) {
        (*pociones)--;
        *oro += precioVenta;
    } else {
        cout << "No tienes pociones para vender!" << endl;
    }
}

int main() {
    int oro = 100;
    int pociones = 2;
    int precioCompra = 30;
    int precioVenta = 15;

    cout << "=== Inventario Inicial ===" << endl;
    mostrarInventario(oro, pociones);

    // Comprar 3 pociones
    for (int i = 0; i < 3; i++) {
        cout << "Comprando pocion... ";
        if (comprarPocion(&oro, &pociones, precioCompra)) {
            cout << "Exito!" << endl;
        } else {
            cout << "Oro insuficiente!" << endl;
        }
        mostrarInventario(oro, pociones);
    }

    // Vender 1 poción
    cout << "Vendiendo pocion..." << endl;
    venderPocion(&oro, &pociones, precioVenta);
    mostrarInventario(oro, pociones);

    // Intentar comprar otra
    cout << "Comprando pocion... ";
    if (comprarPocion(&oro, &pociones, precioCompra)) {
        cout << "Exito!" << endl;
    } else {
        cout << "Oro insuficiente!" << endl;
    }
    mostrarInventario(oro, pociones);

    return 0;
}
