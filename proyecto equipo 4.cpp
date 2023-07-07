#include <iostream>
#include<cstdlib>
#include<conio.h>
#ifdef _WIN32
  #include<windows.h>
#endif 

using namespace std;

void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

// Función para calcular el descuento
void descuento() {
    double precio;
    cout << "Ingrese el precio del producto: ";
    cin >> precio;

    double descuento = 0;
    if (precio < 100) {
        descuento = 0;
    } else if (precio >= 100 && precio < 200) {
        descuento = precio * 0.05;
    } else if (precio >= 200) {
        descuento = precio * 0.1;
    }

    double precio_final = precio - descuento;

    cout << "Precio: $" << precio << endl;
    cout << "Descuento: $" << descuento << endl;
    cout << "Precio final: $" << precio_final << endl;
}

// Función para calcular la calificación de un alumno
void calcularCalificacion() {
    int nota;
    cout << "Ingrese la nota del alumno: ";
    cin >> nota;

    string calificacion;
    if (nota < 5) {
        calificacion = "Insuficiente";
    } else if (nota == 5) {
        calificacion = "Suficiente";
    } else if (nota == 6) {
        calificacion = "Bien";
    } else if (nota > 6 && nota < 9) {
        calificacion = "Notable";
    } else if (nota >= 9) {
        calificacion = "Sobresaliente";
    }

    cout << "Calificación: " << calificacion << endl;
}

// Función para contar números positivos, negativos y nulos
void contarNumeros() {
    int numeros[15];
    int positivos = 0, negativos = 0, nulos = 0;

    for (int i = 0; i < 15; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];

        if (numeros[i] > 0) {
            positivos++;
        } else if (numeros[i] < 0) {
            negativos++;
        } else {
            nulos++;
        }
    }

    cout << "Números positivos: " << positivos << endl;
    cout << "Números negativos: " << negativos << endl;
    cout << "Números nulos: " << nulos << endl;
}

// Función para ingresar nombres y mostrarlos concatenados en Camel Case
void ingresarNombres() {
    string nombres[5];

    for (int i = 0; i < 5; i++) {
        cout << "Ingrese el nombre " << i + 1 << ": ";
        cin >> nombres[i];
    }

    string resultado;
    for (int i = 0; i < 5; i++) {
        resultado += nombres[i][0];
        for (int j = 1; j < nombres[i].length(); j++) {
            resultado += tolower(nombres[i][j]);
        }
    }

    cout << "Nombres concatenados: " << resultado << endl;
}

// Función para calcular el índice de masa corporal (IMC)
void calcularIMC() {
    string genero, nombre;
    double estatura, peso;
    cout << "Ingrese el género (M/F): ";
    cin >> genero;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese la estatura en centímetros: ";
    cin >> estatura;
    cout << "Ingrese el peso en kilogramos: ";
    cin >> peso;

    double estatura_metros = estatura / 100;
    double imc = peso / (estatura_metros * estatura_metros);

    cout << "Nombre: " << nombre << endl;
    cout << "IMC: " << imc << endl;

    if (genero == "M") {
        if (imc > 25) {
            cout << "Tiene sobrepeso" << endl;
        } else if (imc > 30) {
            cout << "Tiene obesidad" << endl;
        }
    } else if (genero == "F") {
        if (imc > 24) {
            cout << "Tiene sobrepeso" << endl;
        } else if (imc > 30) {
            cout << "Tiene obesidad" << endl;
        }
    }
}

// Función para contar las vocales en una cadena
void contarVocales() {
    string cadena;
    cout << "Ingrese una cadena de caracteres: ";
    cin.ignore();
    getline(cin, cadena);

    int contador_a = 0, contador_e = 0, contador_i = 0, contador_o = 0, contador_u = 0;

    for (char c : cadena) {
        switch (tolower(c)) {
            case 'a':
                contador_a++;
                break;
            case 'e':
                contador_e++;
                break;
            case 'i':
                contador_i++;
                break;
            case 'o':
                contador_o++;
                break;
            case 'u':
                contador_u++;
                break;
        }
    }

    cout << "Cantidad de 'a': " << contador_a << endl;
    cout << "Cantidad de 'e': " << contador_e << endl;
    cout << "Cantidad de 'i': " << contador_i << endl;
    cout << "Cantidad de 'o': " << contador_o << endl;
    cout << "Cantidad de 'u': " << contador_u << endl;
}

// Función para dibujar un cuadrado
void dibujarCuadrado() {
    int lado;
    cout << "Ingrese el tamaño del lado del cuadrado: ";
    cin >> lado;

    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            if (i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    int opc = 0;
    do {
        limpiar_pantalla();
        cout << "*********************** MENU PRINCIPAL *****************************\n\n\n\n\n";
        cout << "1 Descuento\n";
        cout << "2 Calcular calificación\n";
        cout << "3 Contar números\n";
        cout << "4 Calcular IMC\n";
        cout << "5 Ingresar nombres\n";
        cout << "6 Contar vocales\n";
        cout << "7 Dibujar cuadrado\n";
        cout << "0 Salir\n";
        cout << "\n\n\nSelecciona alguna opción: ";
        cin >> opc;

        switch (opc) {
            case 1:
                descuento();
                break;
            case 2:
                calcularCalificacion();
                break;
            case 3:
                contarNumeros();
                break;
            case 4:
                calcularIMC();
                break;
            case 5:
                ingresarNombres();
                break;
            case 6:
                contarVocales();
                break;
            case 7:
                dibujarCuadrado();
                break;
        }
        cout << "\nPresione enter para continuar...";
        cin.ignore();
        cin.get();
    } while (opc != 0);

    return 0;
}


