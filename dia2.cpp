#include <iostream>
#include <string>

using namespace std;

struct CuentaBancaria {
    int numeroCuenta;
    string nombreCliente;
    double saldo;
};

// Nodo para almacenar datos
struct Nodo {
    CuentaBancaria cuenta;
    Nodo* siguiente;
};

class ListaEnlazadaSimple {

private:
    Nodo* inicio;

public:
    ListaEnlazadaSimple() {
        inicio = nullptr;
    }

    // Agregar un nodo al final de la lista
    void agregar(Nodo* nuevoNodo) {

        nuevoNodo->siguiente = nullptr; // 🔥 CORRECCIÓN IMPORTANTE

        if (inicio == nullptr) {
            inicio = nuevoNodo;
        } else {
            Nodo* nodoAuxiliar = inicio;

            while (nodoAuxiliar->siguiente != nullptr) {
                nodoAuxiliar = nodoAuxiliar->siguiente;
            }

            nodoAuxiliar->siguiente = nuevoNodo; // 🔥 ESTO FALTABA
        }
    }

    // Buscar una cuenta por número
    Nodo* buscar(int numero) {
        Nodo* aux = inicio;
        while (aux != nullptr) {
            if (aux->cuenta.numeroCuenta == numero)
                return aux;
            aux = aux->siguiente;
        }
        return nullptr;
    }

    // Mostrar todas las cuentas
    void mostrarCuentas() {
        Nodo* aux = inicio;

        if (aux == nullptr) {
            cout << "No hay cuentas registradas." << endl;
            return;
        }

        while (aux != nullptr) {
            cout << "------------------------" << endl;
            cout << "Cuenta: " << aux->cuenta.numeroCuenta << endl;
            cout << "Cliente: " << aux->cuenta.nombreCliente << endl;
            cout << "Saldo: $" << aux->cuenta.saldo << endl;
            aux = aux->siguiente;
        }
        cout << "------------------------" << endl;
    }
};

int main() {

    ListaEnlazadaSimple lista;
    int opcion;

    do {
        cout << "\n====================" << endl;
        cout << "1. Agregar cuenta bancaria" << endl;
        cout << "2. Depositar" << endl;
        cout << "3. Retirar" << endl;
        cout << "4. Mostrar datos de cuenta" << endl;
        cout << "5. Mostrar cuentas" << endl;
        cout << "6. Salir" << endl;
        cout << "====================" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {
            cout << "=== Agregar cuenta ===" << endl;

            Nodo* nuevo = new Nodo();

            cout << "Numero de cuenta: ";
            cin >> nuevo->cuenta.numeroCuenta;

            cout << "Nombre del cliente: ";
            cin.ignore();
            getline(cin, nuevo->cuenta.nombreCliente);

            cout << "Saldo inicial: ";
            cin >> nuevo->cuenta.saldo;

            lista.agregar(nuevo);
            cout << "Cuenta agregada correctamente." << endl;
            break;
        }

        case 2: {
            cout << "=== Depositar ===" << endl;

            int num;
            cout << "Ingrese el numero de cuenta: ";
            cin >> num;

            Nodo* cliente = lista.buscar(num);

            if (cliente == nullptr) {
                cout << "Cuenta no encontrada." << endl;
            } else {
                double monto;
                cout << "Monto a depositar: ";
                cin >> monto;

                cliente->cuenta.saldo += monto;
                cout << "Deposito realizado. Nuevo saldo: $" << cliente->cuenta.saldo << endl;
            }
            break;
        }

        case 3: {
            cout << "=== Retirar ===" << endl;

            int num;
            cout << "Ingrese el numero de cuenta: ";
            cin >> num;

            Nodo* cliente = lista.buscar(num);

            if (cliente == nullptr) {
                cout << "Cuenta no encontrada." << endl;
            } else {
                double monto;
                cout << "Monto a retirar: ";
                cin >> monto;

                if (monto > cliente->cuenta.saldo) {
                    cout << "Saldo insuficiente." << endl;
                } else {
                    cliente->cuenta.saldo -= monto;
                    cout << "Retiro realizado. Nuevo saldo: $" << cliente->cuenta.saldo << endl;
                }
            }
            break;
        }

        case 4: {
            cout << "=== Mostrar datos de cuenta ===" << endl;

            int num;
            cout << "Ingrese el numero de cuenta: ";
            cin >> num;

            Nodo* cliente = lista.buscar(num);

            if (cliente == nullptr) {
                cout << "Cuenta no encontrada." << endl;
            } else {
                cout << "------------------------" << endl;
                cout << "Cuenta: " << cliente->cuenta.numeroCuenta << endl;
                cout << "Cliente: " << cliente->cuenta.nombreCliente << endl;
                cout << "Saldo: $" << cliente->cuenta.saldo << endl;
                cout << "------------------------" << endl;
            }

            break;
        }

        case 5:
            cout << "=== Mostrar todas las cuentas ===" << endl;
            lista.mostrarCuentas();
            break;

        case 6:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion no valida. Digite un numero entre 1 y 6." << endl;
            break;
        }

    } while (opcion != 6);

    return 0;
}