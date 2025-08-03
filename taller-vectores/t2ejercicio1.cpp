#include <iostream>
#include <vector>
#include <numeric> // Para std::accumulate
#include <limits>  // Para std::numeric_limits
#include <string>  // Para std::string

// --- Declaraciones 'using' para mayor comodidad y seguridad ---
// Solo importamos los nombres que usaremos de forma repetida.
using std::accumulate;
using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;
using std::vector;

// --- Declaraciones de funciones ---
// & significa que pasamos el vector por referencia, en vez de crear una copia de este.
void ingresarNotas(vector<vector<float>> &todosLosEstudiantes);
void mostrarMenu(const vector<vector<float>> &todosLosEstudiantes);
void encontrarMejorNota(const vector<vector<float>> &todosLosEstudiantes);
void encontrarMenorNota(const vector<vector<float>> &todosLosEstudiantes);
void calcularPromedioGeneral(const vector<vector<float>> &todosLosEstudiantes);
void contarEstudiantesPorEstado(const vector<vector<float>> &todosLosEstudiantes);
void contarNotasSobrePromedio(const vector<vector<float>> &todosLosEstudiantes);
float obtenerPromedioEstudiante(const vector<float> &notas);
double obtenerNotaValida(const std::string &mensaje);

int main()
{
    // declaramos el vector que contiene los estudiantes
    // cada estudiante es un vector que contiene notas de tipo flotante.
    vector<vector<float>> todosLosEstudiantes;

    ingresarNotas(todosLosEstudiantes);

    if (!todosLosEstudiantes.empty())
    {
        mostrarMenu(todosLosEstudiantes);
    }
    return 0;
}

// --- Implementación de funciones ---

double obtenerNotaValida(const string &mensaje)
{
    double numero;
    while (true)
    {
        cout << mensaje;

        // validar que sea un número.
        while (!(cin >> numero))
        {
            cout << "Error: Entrada no válida. Por favor, ingrese solo un número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << mensaje;
        }

        if ((numero >= 0.0 && numero <= 5.0) || numero == -1)
        {
            return numero;
        }
        else
        {
            cout << "Error: Nota inválida. Debe estar entre 0.0 y 5.0." << endl;
        }
    }
}

void ingresarNotas(vector<vector<float>> &todosLosEstudiantes)
{
    char continuarEstudiante = 's';
    int numeroEstudiante = 1;

    while (continuarEstudiante == 's' || continuarEstudiante == 'S')
    {
        vector<float> notasEstudiante;
        float nota;

        cout << "\n--- ESTE PROGRAMA PERMITE INGRESAR INDEFINIDAS NOTAS PARA INDEFINIDOS ESTUDIANTES " << endl;

        cout << "\n--- Ingresando notas para el Estudiante " << numeroEstudiante << " ---" << endl;

        while (true)
        {
            nota = obtenerNotaValida("Ingrese una nota (entre 0.0 y 5.0) o -1 para finalizar: ");

            if (nota == -1)
            {
                cout << "Terminando notas para este estudiante." << endl;
                break;
            }

            notasEstudiante.push_back(nota);
        }

        if (!notasEstudiante.empty())
        {
            todosLosEstudiantes.push_back(notasEstudiante);
            numeroEstudiante++;
        }

        cout << "\n¿Desea agregar otro estudiante? (s/n): ";
        cin >> continuarEstudiante;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void mostrarMenu(const vector<vector<float>> &todosLosEstudiantes)
{
    int opcion;
    do
    {
        cout << "\n--- MENÚ DE OPCIONES ---" << endl;
        cout << "1. Mostrar la mejor nota de todas." << endl;
        cout << "2. Mostrar la menor nota de todas." << endl;
        cout << "3. Calcular el promedio de todas las notas." << endl;
        cout << "4. Contar cuántos estudiantes perdieron." << endl;
        cout << "5. Contar cuántos estudiantes ganaron." << endl;
        cout << "6. Contar cuántas notas están por encima del promedio general." << endl;
        cout << "0. Salir." << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail())
        {
            cout << "Opción inválida. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion)
        {
        case 1:
            encontrarMejorNota(todosLosEstudiantes);
            break;
        case 2:
            encontrarMenorNota(todosLosEstudiantes);
            break;
        case 3:
            calcularPromedioGeneral(todosLosEstudiantes);
            break;
        case 4:
        case 5:
            contarEstudiantesPorEstado(todosLosEstudiantes);
            break;
        case 6:
            contarNotasSobrePromedio(todosLosEstudiantes);
            break;
        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);
}

void encontrarMejorNota(const vector<vector<float>> &todosLosEstudiantes)
{
    float mejorNota = 0.0;

    // auto asigna el tipo de dato automáticamente.
    for (const auto &notasEstudiante : todosLosEstudiantes)
    {
        for (float nota : notasEstudiante)
        {
            if (nota > mejorNota)
            {
                mejorNota = nota;
            }
        }
    }
    cout << "\n-> La mejor nota de todas es: " << mejorNota << endl;
}

void encontrarMenorNota(const vector<vector<float>> &todosLosEstudiantes)
{
    float menorNota;

    if (!todosLosEstudiantes.empty() && !todosLosEstudiantes[0].empty())
    {
        menorNota = todosLosEstudiantes[0][0];
    }
    else
    {
        cout << "\n-> No hay notas para evaluar." << endl;
        return;
    }

    for (const auto &notasEstudiante : todosLosEstudiantes)
    {
        for (float nota : notasEstudiante)
        {
            if (nota < menorNota)
            {
                menorNota = nota;
            }
        }
    }
    cout << "\n-> La menor nota de todas es: " << menorNota << endl;
}

void calcularPromedioGeneral(const vector<vector<float>> &todosLosEstudiantes)
{
    float sumaTotal = 0;
    int contadorNotas = 0;
    for (const auto &notasEstudiante : todosLosEstudiantes)
    {
        // acumulaate suma las notas de cada estudiante.
        // El tercer parámetro es el valor inicial de la suma. f indica que es un float.
        sumaTotal += accumulate(notasEstudiante.begin(), notasEstudiante.end(), 0.0f);
        contadorNotas += notasEstudiante.size();
    }

    if (contadorNotas > 0)
    {
        float promedio = sumaTotal / contadorNotas;
        cout << "\n-> El promedio de todas las notas es: " << promedio << endl;
    }
    else
    {
        cout << "\n-> No hay notas para calcular el promedio." << endl;
    }
}

float obtenerPromedioEstudiante(const vector<float> &notas)
{
    if (notas.empty())
    {
        return 0.0;
    }
    float suma = accumulate(notas.begin(), notas.end(), 0.0f);
    return suma / notas.size();
}

void contarEstudiantesPorEstado(const vector<vector<float>> &todosLosEstudiantes)
{
    int ganaron = 0;
    int perdieron = 0;
    const float notaAprobatoria = 3.0;

    for (const auto &notasEstudiante : todosLosEstudiantes)
    {
        if (obtenerPromedioEstudiante(notasEstudiante) >= notaAprobatoria)
        {
            ganaron++;
        }
        else
        {
            perdieron++;
        }
    }
    cout << "\n-> Estudiantes que ganaron (promedio >= 3.0): " << ganaron << endl;
    cout << "-> Estudiantes que perdieron (promedio < 3.0): " << perdieron << endl;
}

void contarNotasSobrePromedio(const vector<vector<float>> &todosLosEstudiantes)
{
    float sumaTotal = 0;
    int contadorNotas = 0;
    for (const auto &notasEstudiante : todosLosEstudiantes)
    {
        sumaTotal += accumulate(notasEstudiante.begin(), notasEstudiante.end(), 0.0f);
        contadorNotas += notasEstudiante.size();
    }

    if (contadorNotas == 0)
    {
        cout << "\n-> No hay notas para comparar." << endl;
        return;
    }

    float promedioGeneral = sumaTotal / contadorNotas;
    int notasSobrePromedio = 0;

    for (const auto &notasEstudiante : todosLosEstudiantes)
    {
        for (float nota : notasEstudiante)
        {
            if (nota > promedioGeneral)
            {
                notasSobrePromedio++;
            }
        }
    }
    cout << "\n-> El promedio general es: " << promedioGeneral << endl;
    cout << "-> Cantidad de notas por encima del promedio: " << notasSobrePromedio << endl;
}