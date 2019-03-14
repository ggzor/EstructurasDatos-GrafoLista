/**
 * Benemérita Universidad Autónoma de Puebla
 * Estructuras de datos
 * 
 * Clase grafo que representa un grafo con una lista de adyacencias.
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

#if !defined(_GRAFO_HPP_)
#define _GRAFO_HPP_

#include "Cola.hpp"
#include "Lista.hpp"

class Grafo
{
private:
  Lista<Lista<char>> adyacencias;

public:
  Grafo(const Lista<Lista<char>> &lista) : adyacencias{lista} {}

  /**
   * Convierte una letra en su índice correspondiente.
   */
  static int obtenerIndice(char letra)
  {
    return letra - 'a';
  }

  /**
   * Obtiene la letra que representa el índice correspondiente.
   */
  static char obtenerLetra(int indice)
  {
    return (char)(indice + 'a');
  }

  /**
   * Obtiene la cardinalidad del grafo.
   */
  int obtenerCardinalidad() const
  {
    return adyacencias.obtenerLongitud();
  }

  /**
   * Verifica que la letra esté en el grafo.
   */
  bool esLetraValida(char letra) const
  {
    int indice = obtenerIndice(letra);
    return 0 <= indice && indice < obtenerCardinalidad();
  }

  /**
   * Obtiene la lista de adyacentes a un vértice dado.
   * 
   * @param vertice la letra que representa el vértice.
  */
  const Lista<char> &obtenerAdyacentes(char vertice) const
  {
    return adyacencias[obtenerIndice(vertice)];
  }

  /**
   * Realiza el rocorrido por anchura del grafo a partir de un vertice inicial.
   * 
   * @param vertice el vertice de inicio
   */
  Lista<char> busquedaPorAnchura(char vertice) const
  {
    Lista<char> recorrido;
    Cola<char> cola;

    int cardinalidad = obtenerCardinalidad();
    bool marca[cardinalidad];
    // Inicializar los valores en false
    for (int i = 0; i < cardinalidad; i++)
      marca[i] = false;

    cola.encolar(vertice);
    marca[obtenerIndice(vertice)] = true;

    while (!cola.estaVacia())
    {
      // Obtener nuevo nodo
      char actual = cola.desencolar();
      recorrido.insertarFinal(actual);

      // Visitar adyacentes
      Lista<char> adyacentes = obtenerAdyacentes(actual);
      for (char adyacente : adyacentes)
      {
        if (marca[obtenerIndice(adyacente)] == false)
        {
          marca[obtenerIndice(adyacente)] = true;
          cola.encolar(adyacente);
        }
      }
    }

    return recorrido;
  }

  /**
   * Realiza el rocorrido por profundidad del grafo a partir de un vertice inicial.
   * 
   * @param vertice el vertice de inicio
   */
  Lista<char> busquedaPorProfundidad(char vertice) const
  {
    Lista<char> recorrido;

    int cardinalidad = obtenerCardinalidad();

    bool marca[cardinalidad];
    // Inicializar valores en false
    for (int i = 0; i < cardinalidad; i++)
    {
      marca[i] = false;
    }

    // Colocamos nodo de partida y llamamos a la funcion recursiva
    if (marca[obtenerIndice(vertice)] == false)
    {
      busquedapp(vertice, marca, recorrido);
    }

    return recorrido;
  }

private:
  /**
   * Función recursiva para la búsqueda por profundidad.
   */
  void busquedapp(char vertice, bool marca[], Lista<char> &recorrido) const
  {
    marca[obtenerIndice(vertice)] = true;
    recorrido.insertarFinal(vertice);

    for (char adyacente : obtenerAdyacentes(vertice))
    {
      if (marca[obtenerIndice(adyacente)] == false)
      {
        busquedapp(adyacente, marca, recorrido);
      }
    }
  }
};
#endif // _GRAFO_HPP_