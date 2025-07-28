#include <iostream>
#include <string>

using namespace std;

int obtenerMinimoComunMultiplo(int a, int b)
{
    // Un número no puede ser múltiplo de 0
    if (a == 0 || b == 0) {
        return 0;
    }
    
    // lo igualamos al mayor de los dos números
    int mcm = a > b ? a : b;

    while (mcm % a != 0 || mcm % b != 0)
    {   
        mcm++;
    }
    
    return mcm;
}

int obtenerMaximoComunDivisor(int a, int b)
{
    int min = a < b ? a : b;
    int max = a > b ? a : b;
    int mcd = min;

    while (max % mcd != 0 || min % mcd != 0)
    {
        if (min == 1) return 1;
        
        mcd --;
    }
    return mcd;
}

void imprimirFactoresPrimos(int n)
{

    // Primero intentamos dividirlo por 2 todas las veces que sea posible
    while (n % 2 == 0)
    {
        std::cout << 2 << endl;
        n = n / 2;
    }

    // solo buscamos hasta la raíz cuadrada de n
    // y solo números impares, ya que los pares ya fueron tratados
    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            std::cout << i << endl;
            n = n / i;
        }
    }

    // en este punto n es primo o es uno
    if (n > 2)
    {
        std::cout << n << endl;
    }
}

void imprimirResultados(int a, int b, string mensaje, int resultado)
{
    cout << mensaje << resultado << endl;
    cout << "Factores primos de " << a << ": " << endl;
    imprimirFactoresPrimos(a);
    cout << "Factores primos de " << b << ": " << endl;
    imprimirFactoresPrimos(b);
}

int main()
{
    int a, b;
    int opcion;

    cout << "Ingrese 0 para sacar el minimo comun multiplo: " << endl;
    cout << "Ingrese 1 para sacar el maximo comun divisor: " << endl;

    cin >> opcion;

    if(opcion > 1)
    {
        cout << "Opcion no valida." << endl;
    } else {
        if (opcion == 0)
        {
            cout << "Ingrese dos numeros enteros: " << endl;
            cin >> a >> b;
            int mcm = obtenerMinimoComunMultiplo(a, b);
            imprimirResultados(a, b, "Minimo Comun Multiplo: ", mcm);
        }
        else if (opcion == 1)
        {
            cout << "Ingrese dos numeros enteros: " << endl;
            cin >> a >> b;
            int mcd = obtenerMaximoComunDivisor(a, b);
            imprimirResultados(a, b, "Maximo Comun Divisor: ", mcd);
        }
    }
}