#include <iostream>
#include <vector>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void ingresarNumeros(vector<int> &numeros, int cantidad)
{
    cout << "Por favor, ingrese " << cantidad << " números de dos dígitos." << endl;

    for (int i = 0; i < cantidad; ++i)
    {
        int numeroIngresado;
        do
        {
            cout << "Número " << i + 1 << ": ";
            cin >> numeroIngresado;

            // Validamos que sea un número y que sea de dos dígitos.
            if (cin.fail() || numeroIngresado < 10 || numeroIngresado > 99)
            {
                cout << "Error: Debe ingresar un número válido de dos dígitos." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                numeroIngresado = 0;
            }
        } while (numeroIngresado == 0);

        numeros.push_back(numeroIngresado);
    }
}

int obtenerDigitoBuscado()
{
    int digito;
    do
    {
        cout << "\nIngrese el dígito (de 0 a 9) que desea buscar: ";
        cin >> digito;

        if (cin.fail() || digito < 0 || digito > 9)
        {
            cout << "Error: Debe ingresar un solo dígito." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            digito = -1;
        }
    } while (digito == -1);

    return digito;
}

int main()
{
    const int CANTIDAD_NUMEROS = 5;
    vector<int> numeros;

    // 1. Ingresamos los números
    ingresarNumeros(numeros, CANTIDAD_NUMEROS);

    // 2. Obtenermos el digito a buscar
    int digitoBuscado = obtenerDigitoBuscado();

    // 3. Lo buscamos
    vector<int> posicionesEncontradas;
    for (int i = 0; i < numeros.size(); ++i)
    {
        int numeroActual = numeros[i];
        int decenas = numeroActual / 10;
        int unidades = numeroActual % 10;

        if (decenas == digitoBuscado || unidades == digitoBuscado)
        {
            posicionesEncontradas.push_back(i);
        }
    }

    if (!posicionesEncontradas.empty())
    {
        cout << "\nEl dígito " << digitoBuscado << " se encontró en la(s) posicion(es) del vector: ";
        for (int posicion : posicionesEncontradas)
        {
            cout << posicion << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "\nEl dígito " << digitoBuscado << " no se encontró en ninguno de los números del vector." << endl;
    }

    return 0;
}