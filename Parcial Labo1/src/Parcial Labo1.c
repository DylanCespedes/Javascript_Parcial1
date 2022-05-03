#include <stdio.h>
#include <stdlib.h>

#include "AnexoStruct.h"
#include "Generic_Functions.h"

int main(void)
{
	setbuf(stdout,NULL);

	int IdIncrementalAlbum = 99;
	int idEmpiezaAlbum = 100;
	int idIncrementalArtista = 2999;
	int idIncrementalGenero = 1999;
	int idIncrementalTipo = 0;
	int seguir;
	int continuar;
	int ControlFlag = 0;
	int* pFlag = &ControlFlag;

	eArtista listaArtista[TAMA];
	eGenero listaGenero[TAMA];
	eTipoArtista listaTipo[TIPOS];
	eAlbum listaAlbum[T];


    InicializarGerneros(listaGenero, TAMA);
    InicializarTipoArtista(listaTipo, TIPOS);
    InicializarArtistas(listaArtista, TAMA);
    InicializarAlbumes(listaAlbum, T);

	HarcodearAlbum(listaAlbum, &IdIncrementalAlbum, TAMA, pFlag);
	HardcodearTipoArtista(listaTipo, idIncrementalTipo, TIPOS);
	HardcodearGenero(listaGenero, idIncrementalGenero, TAMA);
	HardcodearArtista(listaArtista, TAMA, &idIncrementalArtista, listaAlbum, T);

	do
		{
			system("cls");
			printf("#### Menu de Albumes ###");
			printf("\n\n1-Ingresar Album.\n");
			printf("2-Modificar Album.\n");
			printf("3-Baja Album.\n");
			printf("4-Informar Albumes encontrados.\n");
			printf("5-Listar Albumes.\n");
			printf("6-Salir.\n");
			seguir = GetIntRange("\nIngrese una opcion ", "\nUsted ha ingresado una opcion invalida, reingrese ", 1, 6);

			switch(seguir)
			{
				case 1:

					IdIncrementalAlbum++;
					AddOneAlbum(listaAlbum, T, IdIncrementalAlbum);
					ControlFlag = 1;

				    	break;

				case 2:

					if(ControlFlag != 0)
					{
						printf("\n\nListado de albumes encontrados\n");
						printf("\n%5s %10s %10s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
						ModifyAlbum(listaAlbum, idEmpiezaAlbum, idIncrementalGenero, idIncrementalTipo, idIncrementalArtista, T);
						system("cls");
					}
					else
					{
						printf("\nTiene que haber almenos un album cargado para poder acceder a esta opcion.\n\n");
						system("pause");
						system("cls");
					}
				    	break;

				case 3:

					if(ControlFlag != 0)
					{
						system("cls");
						printf("\n\nListado de albumes encontrados\n");
						printf("\n%5s %10s %10s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
						DeleteAlbum(listaAlbum, idEmpiezaAlbum, T);
						idIncrementalArtista--;
						system("cls");
					}
					else
					{
						printf("\nTiene que haber almenos un album cargado para poder acceder a esta opcion.\n\n");
						system("pause");
						system("cls");
					}
				    	break;

				case 4:

				if(ControlFlag != 0)
				{
					continuar = InformarMenu(listaAlbum, T);

					if(continuar == -1)
					{
						printf("\nSera redireccionado al menu principal\n\n");
						system("pause");
						system("cls");
					}
				}
				else
				{
					printf("\nTiene que haber almenos un album cargado para poder acceder a esta opcion.\n\n");
					system("pause");
					system("cls");
				}
			    	break;

				case 5:

				if(ControlFlag != 0)
				{
				    continuar = ListarMenu(listaAlbum, T, listaArtista, listaGenero, TAMA, listaTipo, TIPOS);
				}
				else
				{
					printf("\nTiene que haber almenos un album cargado para poder acceder a esta opcion.\n\n");
					system("pause");
					system("cls");
				}
		            break;
			}
		}while(seguir != 6);
}
