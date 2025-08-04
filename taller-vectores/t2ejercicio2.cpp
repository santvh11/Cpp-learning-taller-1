// Esta vez si trabajaremos con arreglos fijos

#include <iostream>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

int sumaDeDigitos(int numero)
{
    // La división entera (numero / 10) nos da el primer dígito.
    // El módulo (numero % 10) nos da el segundo dígito.
    return (numero / 10) + (numero % 10);
}

int main()
{
    const int CANTIDAD_DE_NUMEROS = 5;
    int numeros[CANTIDAD_DE_NUMEROS];

    cout << "Por favor, ingrese " << CANTIDAD_DE_NUMEROS << " números enteros de dos dígitos." << endl;

    // Bucle para pedir los 5 números al usuario
    for (int i = 0; i < CANTIDAD_DE_NUMEROS; ++i)
    {
        int numeroIngresado;
        do
        {
            cout << "Número " << i + 1 << ": ";
            cin >> numeroIngresado;

            if (cin.fail() || numeroIngresado < 10 || numeroIngresado > 99)
            {
                cout << "Error: Debe ingresar un número válido de dos dígitos." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                numeroIngresado = 0;
            }
        } while (numeroIngresado == 0);

        numeros[i] = numeroIngresado;
    }

    // El primer parametro es desde donde comienza
    // El segundo es desde donde termina
    std::sort(numeros, numeros + CANTIDAD_DE_NUMEROS,
              // El tercer es una función lambda que define la regla de ordenamiento.
              // En este caso, ordenamos de mayor a menor según la suma de los dígitos.
              // [] significa que no usamos variables externas.
              [](int a, int b)
              {
                  return sumaDeDigitos(a) > sumaDeDigitos(b);
              });

    cout << "\nLos números organizados de mayor a menor según la suma de sus dígitos son:" << endl;

    for (int numero : numeros)
    {
        cout << numero << " ";
    }
    cout << endl;

    return 0;
}