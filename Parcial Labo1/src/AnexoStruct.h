/*
 * AnexoStruct.h
 *
 *  Created on: 2 may. 2022
 *      Author: nicoC
 */

#ifndef ANEXOSTRUCT_H_
#define ANEXOSTRUCT_H_

#include "ArrayAlbum.h"
#include "ArrayTipo.h"
#include "ArrayArtista.h"
#include "ArrayGenero.h"

/**
 * int ListarMenu(eAlbum listaAlbum[], int tam, eArtista listaArtistas[], eGenero listaGeneros[], int tamArtistaTipos, eTipoArtista listaTipos[], int tamGen)
 *
 * @param listaAlbum // Lista de albumes del menu secundario a listar.
 * @param tam // Tamanio de la lista de albumes.
 * @param listaArtistas // Lista de artistas.
 * @param listaGeneros // Lista de generos.
 * @param tamArtistaTipos // Tamanio de la lista del tipo de artistas.
 * @param listaTipos // Lista de tipos.
 * @param tamGen // Tamanio de la lista de generos que retorna la opcion -1 cuando el usuario sale del submenu.
 * @return
 */
int ListarMenu(eAlbum listaAlbum[], int tam, eArtista listaArtistas[], eGenero listaGeneros[], int tamArtistaTipos, eTipoArtista listaTipos[], int tamGen);

/**
 * void PrintArtistaAlbumes(eArtista listaArtista[], int tamArtist, eAlbum listaAlbumes[], int tamAlbum)
 *
 * @param listaArtista // Lista de artistas a machear con la ID de la lista de albumes.
 * @param tamArtist // Tamanio de la lista de artistas.
 * @param listaAlbumes // Lista de albumes a machear con la ID de la lista de artistas.
 * @param tamAlbum // Tamanio de la lista de albumes.
 */
void PrintArtistaAlbumes(eArtista listaArtista[], int tamArtist, eAlbum listaAlbumes[], int tamAlbum);

/**
 * void HardcodearArtista(eArtista listaArtista[], int tamArtista, int *idIncrementalArtista, eAlbum listaAlbumes[], int tamAlbumes)
 *
 * @param listaArtista // Lista de artistas a la cual se le asignara datos predeterminados y una ID de album.
 * @param tamArtista // Tamanio de la lista de artistas.
 * @param idIncrementalArtista // ID a asignar
 * @param listaAlbumes // Lista de albumes a la cual se asignara a algun elemento de la lista de artistas.
 * @param tamAlbumes // Tamanio de la lista de albumes.
 */
void HardcodearArtista(eArtista listaArtista[], int tamArtista, int *idIncrementalArtista, eAlbum listaAlbumes[], int tamAlbumes);



#endif /* ANEXOSTRUCT_H_ */
