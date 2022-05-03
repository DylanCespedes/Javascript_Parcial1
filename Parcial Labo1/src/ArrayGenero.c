#include "Generic_Functions.h"
#include "ArrayGenero.h"

void HardcodearGenero(eGenero listaGeneros[], int idIncrementalGenero, int tam)
{
	int i;

	char Desc[][L]={"Rock", "Pop", "Euro Dance", "Rock Nacional"};

	for(i=0; i<tam; i++)
	{
	    if(listaGeneros[i].isEmpty == TRUE)
	    {
	    	listaGeneros[i].IdGenero = eGen_ObtenerID(idIncrementalGenero);
		    strcpy(listaGeneros[i].descripcionGen, Desc[i]);
		    listaGeneros[i].isEmpty = FALSE;
		    idIncrementalGenero++;
	    }
	}
}

void InicializarGerneros(eGenero listaGeneros[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		listaGeneros[i].isEmpty = TRUE;
	}
}

void PrintGenero(eGenero listaGeneros[], int tam)
{
	for(int i=0; i<tam; i++)
		{
			if(listaGeneros[i].isEmpty == FALSE)
				{
					printf("\n*%4d %15s\n\n", listaGeneros[i].IdGenero,
										      listaGeneros[i].descripcionGen);
				}
		}
}
