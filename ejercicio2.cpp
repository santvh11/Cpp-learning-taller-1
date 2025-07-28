#include <iostream>
#include <string>

using namespace std;

void menorN(int primero, int segundo, int tercero, int cuarto) {
    int numMenor = cuarto * 1000 + tercero * 100 + segundo * 10 + primero;
    cout << "El numero menor es: " << numMenor << endl;
}

void mayorN(int primero, int segundo, int tercero, int cuarto) {
    int numMayor = primero * 1000 + segundo * 100 + tercero * 10 + cuarto;
    cout << "El numero mayor es: " << numMayor << endl;
}

void ordenar_numeros(int a, int b, int c, int d)
{
    int mayorAB = a > b ? a : b;
    int mayorCD = c > d ? c : d;
    int menorAB = a < b ? a : b;
    int menorCD = c < d ? c : d;

    int primero = mayorAB > mayorCD ? mayorAB : mayorCD;
    int segundo = mayorAB < mayorCD ? mayorAB : mayorCD;
    int tercero = menorAB > menorCD ? menorAB : menorCD;
    int cuarto = menorAB < menorCD ? menorAB : menorCD;

    mayorN(primero, segundo, tercero, cuarto);
    menorN(primero, segundo, tercero, cuarto);
}

int main()
{
    int num;

    cout << "Ingrese un numero de cuatro cifras: ";
    cin >> num;

    if (num < 1000 || num > 9999) {
        cout << "El numero debe tener cuatro cifras." << endl;
        return 1;
    }
    {
        int a = num / 1000; // primer digito
        int b = (num / 100) % 10; // segundo digito
        int c = (num / 10) % 10; // tercer digito
        int d = num % 10; // cuarto digito

        ordenar_numeros(a, b, c, d);
    }
    

}