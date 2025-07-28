#include <iostream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

int obtenerEnteroValido(const string &mensaje)
{
    int numero;
    cout << mensaje;

    // El bucle se repite mientras la entrada sea inválida
    while (!(cin >> numero))
    {
        cout << "Error: Entrada no valida. Por favor, ingrese solo un numero entero: " << endl
             << mensaje;
        // Limpia el estado de error de cin     
        cin.clear();                       
        // Descarta la línea incorrecta                   
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return numero;
}

double obtenerDoubleValido(const string &mensaje)
{
    double numero;
    cout << mensaje;

    while (!(cin >> numero))
    {
        cout << "Error: Entrada no valida. Por favor, ingrese solo un numero: " << endl
             << mensaje;
        // Limpia el estado de error de cin
        cin.clear();
        // Descarta la línea incorrecta
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return numero;
}

void dividir_numeros()
{
    double num1, num2;
    num1 = obtenerDoubleValido("Ingrese el primer numero: ");
    num2 = obtenerDoubleValido("Ingrese el segundo numero: ");

    if (num2 == 0)
    {
        cout << "\nERROR: Division por cero no permitida." << endl;
        return;
    }

    double resultado = num1 / num2;
    cout << "\nRESULTADO: " << resultado << endl;
}

void raiz_cuadrada()
{
    int num;
    num = obtenerEnteroValido("Ingrese un numero para calcular su raiz cuadrada: ");

    if (num < 0)
    {
        cout << "\nERROR: No se puede calcular la raiz cuadrada de un numero negativo." << endl;
        return;
    }

    double resultado = sqrt(num);
    cout << "\nRESULTADO: La raiz cuadrada de " << num << " es: " << resultado << endl;
}

void elevar_numero()
{
    int base, exponente;
    base = obtenerEnteroValido("Ingrese la base: ");
    exponente = obtenerEnteroValido("Ingrese el exponente: ");
    
    double resultado = pow(base, exponente);

    cout << "\nRESULTADO:" << base << " elevado a " << exponente << " es " << resultado << endl;
}

void hayar_coseno_seno()
{
    double angulo;
    angulo = obtenerDoubleValido("Ingrese un angulo en grados: ");

    // conversión de grados a radianes
    const double PI = 3.14159265358979323846;
    double radianes = angulo * (PI / 180.0);
    // necesitan como parámetro radianes
    double seno = sin(radianes);
    double coseno = cos(radianes);

    cout << "\nRESULTADO: Seno de " << angulo << " grados es " << seno << endl;
    cout << "\nRESULTADO: Coseno de " << angulo << " grados es " << coseno << endl;
}

void sumar_digitos()
{
    int num;
    num = obtenerEnteroValido("Ingrese un numero: ");

    int suma = 0;
    while (num > 0)
    {
        // Extraemos el último dígito y lo sumamos
        suma += num % 10;
        // Eliminamos el último dígito del número
        num /= 10;
    }

    cout << "\nRESULTADO: La suma de los dígitos es " << suma << endl;
}

void eliminar_pares()
{
    int num, resultado = 0, posicion = 1;
    num = obtenerEnteroValido("Ingrese un numero: ");

    while (num > 0)
    {
        // Extraemos el último dígito
        int ultimo_digito = num % 10;

        // Si es impar agregamos ese ultimo digito al resultado, la posición nos dice si es unidad, decena, centena, etc.
        if (ultimo_digito % 2 != 0)
        {
            resultado += ultimo_digito * posicion;
            posicion *= 10;
        }
        // Eliminamos ese ultimo digito
        num /= 10;
    }

    if (resultado == 0)
    {
        cout << "\nERROR: No hay numeros impares en el numero ingresado." << endl;
        return;
    }

    cout << "\nRESULTADO: el numero sin pares es " << resultado << endl;
}

void eliminar_impares()
{
    int num, resultado = 0, posicion = 1;
    num = obtenerEnteroValido("Ingrese un numero: ");

    while (num > 0)
    {
        // Extraemos el último dígito
        int ultimo_digito = num % 10;

        // Si es par agregamos ese ultimo digito al resultado, la posición nos dice si es unidad, decena, centena, etc.
        if (ultimo_digito % 2 == 0)
        {
            resultado += ultimo_digito * posicion;
            posicion *= 10;
        }
        // Eliminamos ese ultimo digito
        num /= 10;
    }

    cout << "\nRESULTADO: el numero sin impares es " << resultado << endl;
}

void mostrar_menu()
{
    cout << "\n--- CALCULADORA BASICA ---" << endl;
    cout << "1. Dividir 2 numeros" << endl;
    cout << "2. Raiz cuadrada de un numero" << endl;
    cout << "3. Elevar un numero a una potencia" << endl;
    cout << "4. Hallar seno y coseno de un ángulo" << endl;
    cout << "5. Sumar los digitos de un numero" << endl;
    cout << "6. Eliminar digitos pares de un numero" << endl;
    cout << "7. Eliminar digitos impares de un numero" << endl;
    cout << "8. Salir del programa" << endl;
    cout << "Seleccione una opcion: ";
}

int main()
{
    int opcion;

    // Usamos un bucle do-while para repetir el menú hasta que el usuario elija salir.
    do
    {
        mostrar_menu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            dividir_numeros();
            break;
        case 2:
            raiz_cuadrada();
            break;
        case 3:
            elevar_numero();
            break;
        case 4:
            hayar_coseno_seno();
            break;
        case 5:
            sumar_digitos();
            break;
        case 6:
            eliminar_pares();
            break;
        case 7:
            eliminar_impares();
            break;
        case 8:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Por favor, intente nuevamente." << endl;
        }

    } while (opcion != 8);

    // main debe devolver un entero. 0 significa que todo salió bien.
    return 0;
}