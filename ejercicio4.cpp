#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int sumad(int n){
    int suma = 0;
    while (n > 0) {
        // Sumar el último dígito
        suma += n % 10;
        // Eliminar el último dígito
        n /= 10;
    }
    return suma;
}

int generarNumeroAleatorio() {
    return rand() % 9999 + 1;
}

int main() {
    int i = 0, numSumaMayor = 0;

    cout <<"\nRESPUESTA Los números son: " << endl;

    while (i < 5)
    {
        int numGenerado = generarNumeroAleatorio();
        cout<< numGenerado << endl;

        if (sumad(numGenerado) > numSumaMayor) {
            numSumaMayor = numGenerado;
        }
        
        i++;
    }

    cout << "\nRESPUESTA El número con la suma de dígitos mayor es: " << numSumaMayor << endl;

    return 0;
};