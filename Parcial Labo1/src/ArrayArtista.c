#include "Generic_Functions.h"
#include "ArrayArtista.h"

void InicializarArtistas(eArtista listaArtista[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		listaArtista[i].isEmpty = TRUE;
	}
}

void PrintArtista(eArtista listaArtista[], int tam)
{
	for(int i=0; i<tam; i++)
		{
			if(listaArtista[i].isEmpty == FALSE)
				{
					printf("\n*%4d %20s\n\n", listaArtista[i].IdArtista,
										   listaArtista[i].nombre);
				}
		}
}

void PrintOneArtist(eArtista listaArtista)
{
	printf("\n*%4d %20s\n\n", listaArtista.IdArtista,
							  listaArtista.nombre);
}
