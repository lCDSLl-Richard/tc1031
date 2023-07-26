//////////////////////////////////////
// Implementación de un ADT Arreglo //
// Estructura de Datos              //
//////////////////////////////////////

#include <iostream>
#include <fstream> // manejo de archivos

using namespace std;

#define MAX 50 // máximo total del arreglo

class Arreglo
{
private:
  /* data */
  int datos[MAX];
  int tam = 0;

public:
  // recibe un dato entero y lo coloca al final del arreglo
  void insertar(int dato)
  {
    if (tam < MAX)
    {
      datos[tam] = dato;
      tam++; // se incrementa en 1 el tamaño del arreglo
    }
    else
    {
      cout << "El arreglo está lleno, no se puede insertar el dato" << endl;
    }
  }

  int borrar()
  {
    int dato;
    if (tam > 0)
    {
      dato = datos[tam - 1];
      tam--;
    }
    else
    {
      cout << "El arreglo está vacío, no se puede borrar un elemento" << endl;
      dato = -1;
    }
    return dato;
  }

  // imprime el contenido del arreglo
  void imprimir()
  {
    for (int i = 0; i < tam; i++)
    {
      cout << datos[i] << " ";
    }
    cout << endl;
  }

  // Lee un archivo de números enteros para colocarlos en el arreglo
  // El archivo tiene en el primer renglón el número de valores para tam
  // Los siguientes tam renglones contienen un valor por renglón
  void leer(string archivo)
  {
    int n, numero;
    fstream miArchivo(archivo);
    if (miArchivo.is_open())
    {
      miArchivo >> n;
      for (int i = 0; i < n; i++)
      {
        miArchivo >> numero;
        insertar(numero);
      }
      miArchivo.close();
    }
    else
      cout << "No se puede abrir el archivo";
  }

  void cambiar(int a, int b)
  {
    if (a > tam || b > tam)
    {
      return;
    }
    int temp = datos[a];
    datos[a] = datos[b];
    datos[b] = temp;
  }
};