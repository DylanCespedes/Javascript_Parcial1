
#include "Generic_Functions.h"
#include "ArrayTipo.h"

void HardcodearTipoArtista(eTipoArtista listaTipoArtista[], int idIncrementalTipo, int tam)
{
	int i;

	char Desc[][L]={"Solista", "Banda"};

	for(i=0; i<tam; i++)
	{
	    if(listaTipoArtista[i].isEmpty == TRUE)
	    {
	    	listaTipoArtista[i].IdTipo = eGen_ObtenerID(idIncrementalTipo);
	    	strcpy(listaTipoArtista[i].descripcionTipo, Desc[i]);
		    listaTipoArtista[i].isEmpty = FALSE;
		    idIncrementalTipo++;
	    }
	}
}

void InicializarTipoArtista(eTipoArtista listaTipoArtista[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		listaTipoArtista[i].isEmpty = TRUE;
	}
}

void PrintTipoArtista(eTipoArtista listaTipoArtista[], int tam)
{
	for(int i=0; i<tam; i++)
		{
			if(listaTipoArtista[i].isEmpty == FALSE)
				{
					printf("\n*%2d %12s\n\n", listaTipoArtista[i].IdTipo,
										   listaTipoArtista[i].descripcionTipo);
				}
		}
}
