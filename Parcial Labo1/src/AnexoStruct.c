#include "Generic_Functions.h"
#include "AnexoStruct.h"

int ListarMenu(eAlbum listaAlbum[], int tam, eArtista listaArtistas[], eGenero listaGeneros[], int tamArtistaTipos, eTipoArtista listaTipos[], int tamGen)
{
    int continuar;
    int index;
	int anio;

	do
	{
		system("cls");
	    printf("\n#### Menu Listar ###\n");
		printf("1-Todos los generos.\n");
		printf("2-Todos los tipos de artistas musicales.\n");
		printf("3-Todos los artistas.\n");
		printf("4-Todos los albumes.\n");
		printf("5-Listado de albumes por Importe(descendente)/Titulo(ascendente).\n");
        printf("6-Todos los albumes posteriores a 01/01/2000.\n");
        printf("7-Todos los albumes superiores al promedio de importes.\n");
        printf("8-Todos los albumes de cada artista.\n");
        printf("9-Todos los albumes de un año en especifico.\n");
        printf("10-El/los albumes mas caros.\n");
		printf("11-Salir.\n");
		continuar = GetIntRange("\nIngrese una opcion: ", "Usted ha ingresado una opcion invalida: \n", 1, 11);

			switch(continuar)
				{
				    case 1:
				    system("cls");
					printf("Listado de generos encontrados\n");
					printf("\n%5s %15s", "Codigo", "Descripcion\n");
					PrintGenero(listaGeneros, tamArtistaTipos);
					system("pause");
					system("cls");
					break;

					case 2:
				    system("cls");
					printf("Listado de tipos de artistas encontrados\n");
					printf("\n%5s %14s", "Codigo", "Descripcion\n");
					PrintTipoArtista(listaTipos, tamGen);
					system("pause");
					system("cls");
					break;

					case 3:
				    system("cls");
					printf("Listado de de artistas encontrados\n");
					printf("\n%5s %15s", "Codigo", "Nombre\n");
					PrintArtista(listaArtistas, tamArtistaTipos);
					system("pause");
					system("cls");
					break;

					case 4:
				    system("cls");
					printf("Listado de albumes encontrados\n");
					printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
					PrintAlbum(listaAlbum, T);
					system("pause");
					system("cls");
					break;

					case 5:
				    system("cls");
		            printf("Listado de albumes por Importe(descendente)/Titulo(ascendente).\n");
                    printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
                    OrdenarAlbumsXImporteTitulo(listaAlbum, T);
                    system("pause");
					system("cls");
					break;

					case 6:
				    system("cls");
					printf("Todos los albumes posteriores a 01/01/2000.\n");
					printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
					MostrarAlbumesMenorFecha(listaAlbum, T);
                    system("pause");
			    	system("cls");
					break;

					case 7:
				    system("cls");
					printf("Todos los albumes superiores al promedio de importes.\n");
                	printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
                    MostrarAlbumesMaxImporte(listaAlbum, T);
					system("pause");
					system("cls");
					break;

					case 8:
				    system("cls");
					printf("Todos los albumes correspondientes a los artistas.\n");
					printf("%12s %18s %12s %12s %12s", "Nombre", "CodigoAlbum", "Titulo", "Fecha", "Importe");
					PrintArtistaAlbumes(listaArtistas, tamArtistaTipos, listaAlbum, T);
					system("pause");
					system("cls");
					break;

					case 9:
					system("cls");
					anio = GetIntRange("\nIngrese el anio de publicacion del album (valores entre 1900-2022): ", "Reingrese el anio (solo caracteres numericos y valores entre 1900-2022): ", 1900, 2022);
                    printf("Todos los albumes del año: %d\n\n", anio);
                    printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
					MostrarAlbumesPorAnio(listaAlbum, T, anio);
                    system("pause");
					system("cls");
					break;

					case 10:
					system("cls");
					index = BuscarImporteMasCaro(listaAlbum, T);
			        printf("-El/los albumes mas caros.\n");
                    printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
			        PrintOneAlbum(listaAlbum[index]);
			        system("pause");
			        system("cls");

					break;
				}

	}while(continuar !=11);

	if(continuar == 3 || continuar > 3)
	{
			continuar = -1;
	}
	return continuar;
}

void HardcodearArtista(eArtista listaArtista[], int tamArtista, int *idIncrementalArtista, eAlbum listaAlbumes[], int tamAlbumes)
{
	char Desc[][L]={"Freddy Mercury", "Michael Jackson", "Gustavo Cerati", "Pato Fontaner"};

	for(int i=0; i<tamArtista; i++)
	{
		//for(int j=0; j<tamAlbumes; j++)
		//{
			if(listaArtista[i].isEmpty == TRUE && listaAlbumes[i].IsEmpty == FALSE)
			{
				listaArtista[i].IdArtista = eGen_ObtenerID(*idIncrementalArtista);
				strcpy(listaArtista[i].nombre, Desc[i]);
				listaArtista[i].IdAlbum = listaAlbumes[i].IdAlbum;
				listaArtista[i].isEmpty = FALSE;
				*idIncrementalArtista = listaArtista[i].IdArtista;
			}
		//}
	}
}

void PrintArtistaAlbumes(eArtista listaArtista[], int tamArtist, eAlbum listaAlbumes[], int tamAlbum)
{
	for(int i=0; i<tamArtist; i++)
		{
			for(int j=0; j<tamAlbum; j++)
			{
				if(listaArtista[i].isEmpty == FALSE && listaAlbumes[j].IsEmpty == FALSE)
				{
					if(listaArtista[i].IdAlbum == listaAlbumes[j].IdAlbum)
					{
						printf("\n\n%10s %12d %15s %8d/%d/%4d %10.2f$\n", listaArtista[i].nombre
															 	      , listaAlbumes[i].IdAlbum
																      , listaAlbumes[i].titulo
																      , listaAlbumes[i].fecha.dia
																      , listaAlbumes[i].fecha.mes
																      , listaAlbumes[i].fecha.anio
																      , listaAlbumes[i].importe);
					}
				}
			}
		}
}
