/*
 * albunes.h
 *
 *  Created on: 1 may. 2022
 *      Author: nicoC
 */

#ifndef ARRAYALBUM_H_
#define ARRAYALBUM_H_
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
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct
{
	int IdAlbum;
	char titulo[T];
	eFecha fecha;
	float importe;
	int generoId;
	int tipoId;
	int artistaId;
	int IsEmpty;
}eAlbum;

/**
 * int FindAlbumById(eAlbum listaAlbum[], int tam, int datoId)
 *
 * @param listaAlbum // Lista de albumes a recorres.
 * @param tam // Tamanio de la lista.
 * @param datoId // ID a buscar en la lista.
 * @return // Retorna a -1, si no lo encuentra y en caso de que lo encuentre retorna el indice de la lista.
 */
int FindAlbumById(eAlbum listaAlbum[], int tam, int datoId);

/**
 * void InicializarAlbumes(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Inicializa la lista de albums
 * @param tam // Tamanio de la lista a inicializar.
 */
void InicializarAlbumes(eAlbum listaAlbum[], int tam);

/**
 * void HarcodearAlbum(eAlbum listaAlbum[], int *idncrementalAlbum, int tam, int *pFlag)
 *
 * @param listaAlbum // Lista de albumes a hardcodear.
 * @param idncrementalAlbum // Direccion de memoria de la variable que inicializa el ID de albumes.
 * @param tam // Tamanio de la lista.
 * @param pFlag // Direccion de memoria de la bandera de control de las opciones.
 */
void HarcodearAlbum(eAlbum listaAlbum[], int *idncrementalAlbum, int tam, int *pFlag);

/**
 * void AddOneAlbum(eAlbum listaAlbum[], int tam, int IdIncrementalAlbum)
 *
 * @param listaAlbum // Lista de albumes a la cual agregarle un indice.
 * @param tam // tamanio de la lista de album.
 * @param IdIncrementalAlbum // ID generada a agregar.
 */
void AddOneAlbum(eAlbum listaAlbum[], int tam, int IdIncrementalAlbum);

/**
 * void PrintAlbum(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Lista de albumes a mostrar.
 * @param tam // tamanio de la lista de album.
 */
void PrintAlbum(eAlbum listaAlbum[], int tam);

/**
 * void PrintOneAlbum(eAlbum listaAlbum)
 *
 * @param listaAlbum // Album a mostrar, solo imprime uno.
 */
void PrintOneAlbum(eAlbum listaAlbum);

/**
 * eAlbum AddAlbum(int IdIncrementalAlbum)
 *
 * @param IdIncrementalAlbum // ID generada a asignar.
 * @return // retorna la estructura cargada con los datos pedidos al usuario.
 */
eAlbum AddAlbum(int IdIncrementalAlbum);

/**
 * void ModifyAlbum(eAlbum listaAlbum[], int idMinimaAlbum, int idMinimaGenero, int idMinimaTipo, int idMinimaArtista, int tam)
 *
 * @param listaAlbum // Lista de albumes a recorrer para modificar.
 * @param idMinimaAlbum // ID minima asignada a la lista de albumes.
 * @param idMinimaGenero // ID minima asignada a un genero musical.
 * @param idMinimaTipo // ID minima asignada a un tipo.
 * @param idMinimaArtista // ID minima asignada a un artista.
 * @param tam // Tamanio de la lista a recorrer.
 */
void ModifyAlbum(eAlbum listaAlbum[], int idMinimaAlbum, int idMinimaGenero, int idMinimaTipo, int idMinimaArtista, int tam);

/**
 * int BuscarIdMaxima(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Lista de albumes a la cual buscar la ID de mayor valor asignada.
 * @param tam // Tamanio de la lista.
 * @return // Retorna del mayor ID encontrado en la lista.
 */
int BuscarIdMaxima(eAlbum listaAlbum[], int tam);

/**
 * void DeleteAlbum(eAlbum listaAlbum[], int idMinimaAlbum, int tam)
 *
 * @param listaAlbum // Lista a la cual eliminar un album por ID.
 * @param idMinimaAlbum // ID minima a la cual empezar a buscar en la lista de album.
 * @param tam // Tamanio de la lista de album.
 */
void DeleteAlbum(eAlbum listaAlbum[], int idMinimaAlbum, int tam);

/**
 * int InformarMenu(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Lista de album preparada para utilizarse en este menu secundario de informes al usuario.
 * @param tam // Tamanio de la lista.
 * @return // Retorna -1 cuando el usuario decide salir del submenu.
 */
int InformarMenu(eAlbum listaAlbum[], int tam);

/**
 * float SumImportes(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Lista de albumes a la cual se le sumaran los importes.
 * @param tam // Tamanio de la lista de albumes.
 * @return // Retorna la suma de todos los importes de la lista.
 */
float SumImportes(eAlbum listaAlbum[], int tam);

/**
 * float PromedioImporte(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Lista de albumes a la cual se le calculara el promedio de sus importes.
 * @param tam // Tamanio de la lista de albumes.
 * @return // Retorna el promedio de todos los importes.
 */
float PromedioImporte(eAlbum listaAlbum[], int tam);

/**
 * int ContarAlbumes(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Lista de albumes a la cual se contara todas sus estructuras.
 * @param tam // Tamanio de la lista de albumes.
 * @return // Retorna la cantidad de elementos encontrados en la lista.
 */
int ContarAlbumes(eAlbum listaAlbum[], int tam);

/**
 * int AlbumesMaxImporte(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Lista de albumes a la cual se le calculara el maximo de sus importes.
 * @param tam // Tamanio de la lista de albumes.
 * @return // Retorna el maximo de los importes de la lista.
 */
int AlbumesMaxImporte(eAlbum listaAlbum[], int tam);

/**
 * int AlbumesSuperanFecha(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Lista de albumes a la cual buscarle los elementos que superen la fecha 01/01/2000.
 * @param tam // Tamanio de la lista de albumes.
 * @return // Retorna la cantidad de albumes que superen la fecha ya mencionada.
 */
int AlbumesSuperanFecha(eAlbum listaAlbum[], int tam);

/**
 * void OrdenarAlbumsXImporteTitulo(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Lista de albumes a la cual utilizando el metodo del burbujeo se ordenara de manera ascendente por la descripcion y importe descendente.
 * @param tam // Tamanio de la lista de albumes.
 */
void OrdenarAlbumsXImporteTitulo(eAlbum listaAlbum[], int tam);

/**
 * void MostrarAlbumesMenorFecha(eAlbum listaAlbumes[], int tam)
 *
 * @param listaAlbumes // Lista de albumes a la cual se recorrera para identificar los elementos que cumplan la condicion de no superar la fecha 01/01/2000.
 * @param tam // Tamanio de la lista de albumes.
 */
void MostrarAlbumesMenorFecha(eAlbum listaAlbumes[], int tam);

/**
 * void MostrarAlbumesMaxImporte(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Lista de albumes a la cual se le buscara cual de sus elementos tienen su mayor importe.
 * @param tam // Tamanio de la lista de albumes.
 */
void MostrarAlbumesMaxImporte(eAlbum listaAlbum[], int tam);

/**
 * int BuscarImporteMasCaro(eAlbum listaAlbum[], int tam)
 *
 * @param listaAlbum // Lista de albumes a la cual se le buscara en sus elementos cual tiene el importe mas caro.
 * @param tam // Tamanio de la lista de albumes.
 * @return // Retorna el imdice del elemento que tiene el importe mas caro.
 */
int BuscarImporteMasCaro(eAlbum listaAlbum[], int tam);

/**
 * void MostrarAlbumesPorAnio(eAlbum listaAlbum[], int tam, int anio)
 *
 * @param listaAlbum // Lista de albumes a la cual se buscara entre sus elementos si alguno o algunos coinciden con el anio ingresado por el usuario.
 * @param tam // Tamanio de la lista de albumes.
 * @param anio // Anio ingresado para su busqueda en la lista.
 */
void MostrarAlbumesPorAnio(eAlbum listaAlbum[], int tam, int anio);

#endif /* ARRAYALBUM_H_ */
