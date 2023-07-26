// =================================================================
//
// File: activity.h
// Author: Ricardo Fernández
// Date: 23/08/2022
//
// =================================================================
#ifndef ACTIVITY_H
#define ACTIVITY_H

// =================================================================
// sumaIterativa. Calculate the sum from 1 to n with an iterative
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(n)
// La complejidad del algoritmo es O(n) porque el algoritmo itera
// n veces con un decremento lineal.
// =================================================================
unsigned int sumaIterativa(unsigned int n)
{
	unsigned int suma = 0;

	for (int i = 1; i <= n; i++)
		suma += i;

	return suma;
}

// =================================================================
// sumaRecursiva. Calculate the sum from 1 to n with an recursive
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(n)
// La complejidad del algoritmo es O(n), porque el algoritmo solo se
// llama una vez y este se reduce de manera lineal en la siguiente
// llamada.
// =================================================================
unsigned int sumaRecursiva(unsigned int n)
{
	return n == 1 ? 1 : n + sumaRecursiva(n - 1);
}

// =================================================================
// sumaDirecta. Calculate the sum from 1 to n with a mathematical
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(1)
// La complejidad de este algoritmo es de O(1) ya que solo hace
// una llamada a operaciones matemáticas, independientes del tamaño
// de la entrada.
// =================================================================
unsigned int sumaDirecta(unsigned int n)
{
	return (n * (n + 1)) / 2;
}

#endif /* ACTIVITY_H */
