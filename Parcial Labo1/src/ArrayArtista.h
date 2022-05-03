#ifndef ARRAYARTISTA_H_
#define ARRAYARTISTA_H__H_
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
	int IdArtista;
	int IdAlbum;
	char nombre[T];
	int isEmpty;

}eArtista;

/**
 * void InicializarArtistas(eArtista listaArtista[], int tam)
 *
 * @param listaArtistas // Lista de artistas a la cual inicializar.
 * @param tam // Tamanio de la lista.
 */

void InicializarArtistas(eArtista listaArtista[], int tam);

/**
 * void PrintArtista(eArtista listaArtistas[], int tam)
 *
 * @param listaArtistas // Lista de artistas a la cual mostrar.
 * @param tam // Tamanio de la lista de artistas.
 */

void PrintArtista(eArtista listaArtistas[], int tam);

/**
 * void PrintOneArtist(eArtista listaArtista)
 *
 * @param listaArtista // Recibe una estructura de artistas para mostrar por consola.
 */
void PrintOneArtist(eArtista listaArtista);

#endif /* ARRAYARTISTA_H_ */
