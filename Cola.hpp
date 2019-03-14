/**
 * Benemérita Universidad Autónoma de Puebla
 * Estructuras de datos
 * 
 * TDA Cola
 * 
 * En este archivo se implementan las operaciones básicas de un TDA de cola
 * basada en una lista enlazada.
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
#if !defined(_COLA_HPP_)
#define _COLA_HPP_

#include "Lista.hpp"

template <typename T>
class Cola : public Lista<T>
{
public:
  /**
   * Constructor de la cola.
   * 
   * @param _maximo la máxima cantidad de elementos que puede tener la lista.
   */
  Cola() {}

  /*
  *  Inserta el valor al final de la cola.
  */
  void encolar(T valor)
  {
    Lista<T>::insertarFinal(valor);
  }

  /*
   * Obtiene el primer elemento y lo elimina de la cola
   */
  T desencolar()
  {
    T valor = Lista<T>::operator[](0);
    Lista<T>::eliminarInicio();
    return valor;
  }
};

#endif // _COLA_HPP_