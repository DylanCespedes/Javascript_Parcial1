#ifndef ARRAYTIPO_H_
#define ARRAYTIPO_H__H_
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
	int IdTipo;
	char descripcionTipo[T];
	int isEmpty;

}eTipoArtista;

/**
 * void HardcodearTipoArtista(eTipoArtista listaTipoArtista[], int idIncrementalTipo, int tam)
 *
 * @param listaTipoArtista // Lista del tipo de artistas a la cual se le asignara datos predeterminados.
 * @param idIncrementalTipo // ID incremental a ser asignada en la lista.
 * @param tam // Tamanio de la lista.
 */
void HardcodearTipoArtista(eTipoArtista listaTipoArtista[], int idIncrementalTipo, int tam);

/**
 * void InicializarTipoArtista(eTipoArtista listaTipoArtista[], int tam)
 *
 * @param listaTipoArtista // Inicializa la lista de tipo de artistas.
 * @param tam // Tamanio de la lista.
 */
void InicializarTipoArtista(eTipoArtista listaTipoArtista[], int tam);

/**
 * void PrintTipoArtista(eTipoArtista listaTipoArtista[], int tam)
 *
 * @param listaTipoArtista // Lista de elementos que a mostrar.
 * @param tam // Tamanio de la lista.
 */
void PrintTipoArtista(eTipoArtista listaTipoArtista[], int tam);


#endif /* ARRAYTIPO_H_ */
