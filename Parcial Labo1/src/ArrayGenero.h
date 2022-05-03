#ifndef ARRAYGENERO_H_
#define ARRAYGENERO_H__H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define T 51
#define TRUE 1
#define FALSE 0
#define TAMA 4
#define TIPOS 2

typedef struct
{
	int IdGenero;
	char descripcionGen[T];
	int isEmpty;
}eGenero;

/**
 * void HardcodearGenero(eGenero listaGeneros[], int idIncrementalGenero, int tam)
 *
 * @param listaGeneros // Lista de generos a la cual se le asignara 2 valores predeterminados.
 * @param idIncrementalGenero // ID incremental de asignar.
 * @param tam // Tamanio de la lista de generos.
 */
void HardcodearGenero(eGenero listaGeneros[], int idIncrementalGenero, int tam);

/**
 * void InicializarGerneros(eGenero listaGeneros[], int tam)
 *
 * @param listaGeneros // Lista de generos a la cual inicializa sus elementos.
 * @param tam // Tamanio de la lista de generos.
 */
void InicializarGerneros(eGenero listaGeneros[], int tam);

/**
 * void PrintGenero(eGenero listaGeneros[], int tam)
 *
 * @param listaGeneros // Lisa de generos a mostrar el usuario.
 * @param tam // Tamanio de la lista de generos.
 */
void PrintGenero(eGenero listaGeneros[], int tam);

#endif /* ARRAYGENERO_H_ */
