/**
 * Benemérita Universidad Autónoma de Puebla
 * Estructuras de datos
 * 
 * Implementación de la interfaz para mostrar información de un grafo
 * introducido desde un archivo.
 * 
 * Fecha: 14/03/2019
 * 
 * Equipo:
 *   Axel Suárez Polo        201744436
 *   Marisol Huitzil Juárez  201745351
 *   Emmanuel Cortés Rosas   201764328
 *   Jafet Siliceo Luna      201759850
 * 
 */

#include "Color.hpp"
#include "Grafo.hpp"
#include "Utilerias.hpp"

#include <fstream>
#include <iostream>
#include <string>

int main();

Grafo leerGrafo(const std::string &nombreArchivo)
{
  // Crear un flujo de entrada desde el archivo.
  std::ifstream archivo{nombreArchivo};
  // Listas de adyacencia para cada vértice
  Lista<Lista<char>> listas;

  std::string cadena;
  // Descarta la primera cadena "Cardinalidad:"
  archivo >> cadena;

  int cardinalidad;
  archivo >> cardinalidad;

  for (int i = 0; i < cardinalidad; i++)
  {
    // Nueva lista de adyacencias
    Lista<char> nueva;

    // Leer el vértice
    archivo >> cadena;

    // Leer cada vértice adyacente
    archivo >> cadena;
    while (cadena != ".")
    {
      nueva.insertarFinal(cadena[0]);
      archivo >> cadena;
    }

    listas.insertarFinal(nueva);
  }

  return Grafo{listas};
}

int main()
{
  // Lectura de el nombre del archivo
  std::string nombreArchivo;
  std::cout << "Ingrese el  del archivo: " << enNegritas << colorVertice;
  std::cin >> nombreArchivo;
  std::cout << terminarColor;
  Grafo grafo = leerGrafo(nombreArchivo);

  int op;
  do
  {
    limpiarTerminal();

    std::cout << "Menú:\n"
              << "  1. Obtener cardinalidad.\n"
              << "  2. Obtener vértices adyacentes a un vértice.\n"
              << "  3. Hacer recorrido a lo ancho a partir de un vértice.\n"
              << "  4. Hacer recorrido a lo profundo a partir de un vértice.\n"
              << "  5. Salir.\n";
    std::cout << "Opción: ";
    std::cin >> op;
    std::cout << std::endl;

    // Entrar a la selección de opciones.
    char origen, destino;
    switch (op)
    {
    case 1:
      std::cout << "La cardinalidad del grafo es "
                << acentuar << grafo.obtenerCardinalidad() << terminarColor << '.'
                << std::endl;
      std::cout << "Contiene las letras de la "
                << colorVertice << Grafo::obtenerLetra(0) << terminarColor
                << " a la "
                << colorVertice << Grafo::obtenerLetra(grafo.obtenerCardinalidad() - 1) << terminarColor
                << std::endl;
      esperarEnter();
      break;
    case 2:
      char vertice;

      std::cout << "Vértice: " << colorVertice;
      std::cin >> vertice;
      std::cout << terminarColor;

      if (grafo.esLetraValida(vertice))
      {
        Lista<char> adyacentes = grafo.obtenerAdyacentes(vertice);

        if (!adyacentes.estaVacia())
        {
          std::cout << "Adyacentes: " << enNegritas;
          for (char vertice : adyacentes)
          {
            std::cout << vertice << ' ';
          }
          std::cout << terminarColor << std::endl;

          esperarEnter();
        }
        else
        {
          std::cout << acentuar << "El vértice dado no tiene vértices adyacentes." << terminarColor << std::endl;
          esperarEnter();
        }
      }
      else
      {
        std::cout << acentuar << "El vértice dado no está en el grafo." << terminarColor << std::endl;
        esperarEnter();
      }
      break;

    case 3:
      std::cout << "Origen: " << colorVertice;
      std::cin >> origen;
      std::cout << terminarColor;
      if (grafo.esLetraValida(origen))
      {
        Lista<char> recorrido = grafo.busquedaPorAnchura(origen);

        std::cout << "El recorrido es: ";
        std::cout << colorVertice;
        for (char vertice : recorrido)
        {
          std::cout << vertice << ' ';
        }
        std::cout << terminarColor
                  << std::endl;
        esperarEnter();
      }
      else
      {
        std::cout << acentuar << "El vértice dado no está en el grafo." << terminarColor << std::endl;
        esperarEnter();
      }

      break;

    case 4:
      std::cout << "Origen: " << colorVertice;
      std::cin >> origen;
      std::cout << terminarColor;

      if (grafo.esLetraValida(origen))
      {
        Lista<char> recorrido = grafo.busquedaPorProfundidad(origen);

        std::cout << "El recorrido es: ";
        std::cout << colorVertice;
        for (char vertice : recorrido)
        {
          std::cout << vertice << ' ';
        }
        std::cout << terminarColor
                  << std::endl;
        esperarEnter();
      }
      else
      {
        std::cout << acentuar << "El vértice dado no está en el grafo." << terminarColor << std::endl;
        esperarEnter();
      }

      break;

    case 5:
    // Para evitar el siguiente mensaje
    break;

    default:
      std::cout << acentuar << "Opcion invalida." << terminarColor << std::endl;
      esperarEnter();
      break;
    }
  } while (op != 5);
  return 0;
}