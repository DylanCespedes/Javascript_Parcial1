#include "Generic_Functions.h"
#include "ArrayAlbum.h"



void InicializarAlbumes(eAlbum listaAlbum[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		listaAlbum[i].IsEmpty = TRUE;
	}
}

void HarcodearAlbum(eAlbum listaAlbum[], int *idIncrementaAlbum, int tam, int *pFlag)
{
	char Titulo[][L] = {"Triller", "Family", "Monster", "Shadow"};
	float importe[] = {250,300,400,350};
	int dia[] = {23,2,10,15};
	int mes[] = {3,7,9,12};
	int anio[] = {1999,2020,1940,2000};

	for(int i=0; i<tam; i++)
	{
	    if(listaAlbum[i].IsEmpty == TRUE && idIncrementaAlbum != NULL)
	    {
	    	listaAlbum[i].IdAlbum = eGen_ObtenerID(*idIncrementaAlbum);
		    strcpy(listaAlbum[i].titulo, Titulo[i]);
		    listaAlbum[i].fecha.dia = dia[i];
		    listaAlbum[i].fecha.mes = mes[i];
		    listaAlbum[i].fecha.anio = anio[i];
		    listaAlbum[i].importe = importe[i];
		    listaAlbum[i].IsEmpty = FALSE;
	    	*idIncrementaAlbum = listaAlbum[i].IdAlbum;
	    }
	}

	*pFlag = 1;
}


int FindFreeIndex(eAlbum listaAlbum[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listaAlbum[i].IsEmpty == TRUE)
		{
			index = i;
			break;
		}
	}
	return index;
}

int FindAlbumById(eAlbum listaAlbum[], int tam, int datoId)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listaAlbum[i].IdAlbum == datoId)
		{
			index = i;
			break;
		}
	}
	return index;
}

void RemoveAlbum(eAlbum listaAlbum[], int tam, int indice, char mensaje[])
{
	int i;

	for(i=0; i<tam; i++)
	{
		if(i == indice)
			{
				printf("%s", mensaje);
				listaAlbum[i].IsEmpty = TRUE;
				break;
			}
	}

}

void AddOneAlbum(eAlbum listaAlbum[], int tam, int IdIncrementalAlbum)
{
	int i;
	i = FindFreeIndex(listaAlbum, tam);

	if(i != -1)
	{
		listaAlbum[i] = AddAlbum(IdIncrementalAlbum);
		if(listaAlbum[i].IsEmpty == FALSE)
		{
			printf("\nDatos cargados con exito!!\n\n");
			system("pause");
			system("cls");
		}
	}
	else
	{
		 printf("\nNo hay espacio para la carga de datos\n\n");
		 system("pause");
		 system("cls");
	}
}

void PrintAlbum(eAlbum listaAlbum[], int tam)
{
	for(int i=0; i<tam; i++)
		{
			if(listaAlbum[i].IsEmpty == FALSE)
				{
					PrintOneAlbum(listaAlbum[i]);
				}
		}
}

void PrintOneAlbum(eAlbum listaAlbum)
{
	printf("\n*%4d %9s %8d/%d/%4d %10.2f$\n", listaAlbum.IdAlbum,
											  listaAlbum.titulo,
											  listaAlbum.fecha.dia,
											  listaAlbum.fecha.mes,
											  listaAlbum.fecha.anio,
											  listaAlbum.importe);
}

eAlbum AddAlbum(int IdIncrementalAlbum)
{
	eAlbum addAlbum;

	Get_OnlyAlphabetStringWithSpaces("\nIngrese el titulo del album: ", "Ingrese el titulo nuevamente(solo caracteres alfabeticos): ", addAlbum.titulo, T);
	addAlbum.fecha.dia = GetIntRange("\nIngrese el dia de publicacion del album (valores entre 1-31) ", "\nReingrese el dia (solo caracteres numericos y valores entre 1-31) ", 0, 31);
	addAlbum.fecha.mes = GetIntRange("\nIngrese el mes de publicacion del album (valores entre 1-12) ", "\nReingrese el mes (solo caracteres numericos y valores entre 1-12) ", 0, 12);
	addAlbum.fecha.anio = GetIntRange("\nIngrese el anio de publicacion del album (valores entre 1900-2022) ", "\nReingrese el anio (solo caracteres numericos y valores entre 1900-2022) ", 1900, 2022);
	addAlbum.importe = GetFloat("\nIngrese el importe del album: ", "\nError, reingrese el importe nuevamente: (solo caracteres numericos positivos) ");
	addAlbum.IdAlbum = IdIncrementalAlbum;
	addAlbum.IsEmpty = FALSE;

	return addAlbum;
}


void ModifyAlbum(eAlbum listaAlbum[], int idMinimaAlbum, int idMinimaGenero, int idMinimaTipo, int idMinimaArtista, int tam)
{
	int indexAlbum;
	int idIngresada;
	char auxTitulo[T];
	int dia, mes, anio;
	float auxImporte;
	int opcion;
	int maxId;
	char seguir;

		system("cls");
		printf("\n\nListado de albumes encontrados\n");
		printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
		PrintAlbum(listaAlbum, tam);
		maxId = BuscarIdMaxima(listaAlbum, tam);
		idIngresada = GetIntRange("\n\nIngrese el id a la cual le desea modificar datos: ", "\nReingrese el id: ", idMinimaAlbum, maxId);
		indexAlbum = FindAlbumById(listaAlbum, tam, idIngresada);

		if(indexAlbum != -1)
		{
		  system("cls");
		  printf("\n\nListado de albumes encontrados\n");
		  printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
		  PrintOneAlbum(listaAlbum[indexAlbum]);
		  opcion = GetIntRange("\nSe ha encontrado la Id ingresada !!\n\nQue desea modificar? \n\n1-Titulo\n\n2-Fecha\n\n3-Importe\n\n4-Salir\n\nIngrese una opcion: ", "Usted ha ingresado una opcion incorrecta, reingrese: ", 1, 4);

			switch(opcion)
			{
				case 1:

					Get_OnlyAlphabetStringWithSpaces("Ingrese el nuevo titulo: ", "Error, reingrese el nuevo titulo: ", auxTitulo, T);
					seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Error, reingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
						{
							strcpy(listaAlbum[indexAlbum].titulo, auxTitulo);
							printf("\nTitulo modificado con exito!!\n");
							system("pause");
							system("cls");
						}
						else
							{
								printf("\nSe ha cancelado la modificacion del titulo\n");
								system("pause");
								system("cls");
							}
					break;

				case 2:

					dia = GetIntRange("\n\nIngrese el dia de publicacion del album (valores entre 1-31): ", "Reingrese el dia (solo caracteres numericos y valores entre 1-31): ", 0, 31);
					mes = GetIntRange("\nIngrese el mes de publicacion del album (valores entre 1-12): ", "Reingrese el mes (solo caracteres numericos y valores entre 1-12): ", 0, 12);
					anio = GetIntRange("\nIngrese el anio de publicacion del album (valores entre 1900-2022): ", "Reingrese el anio (solo caracteres numericos y valores entre 1900-2022): ", 1900, 2022);
					seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Error, reingrese 's' para continuar o 'n' para cancelar la modificacion: ");

						if(seguir == 's')
							{
								listaAlbum[indexAlbum].fecha.dia = dia;
								listaAlbum[indexAlbum].fecha.mes = mes;
								listaAlbum[indexAlbum].fecha.anio = anio;
								printf("\nSe ha modificado la fecha con exito!!\n");
								system("pause");
								system("cls");
							}
							else
							{
								printf("\nSe ha cancelado la modificacion de la fecha\n");
								system("pause");
								system("cls");
							}
					break;

				case 3:

					auxImporte = GetFloat("Ingrese el nuevo importe del album: ", "Ingrese el importe nuevamente (solo caracteres numericos positivos): ");
					seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					   if(seguir == 's')
						{
							listaAlbum[indexAlbum].importe = auxImporte;
							printf("\nSe ha modificado el importe con exito!!\n");
							system("pause");
							system("cls");
						}
						else
						{
							printf("\nSe ha cancelado la modificacion del salario\n");
							system("pause");
							system("cls");
						}
					break;

				case 4:
					printf("\nSe ha cancelado la modificacion del Album.\n");
					system("pause");
					system("cls");

					break;
			}
		}
		else
		{
			printf("\nNo se ha encontrado la id ingresada\n");
			system("pause");
			system("cls");
		}
}

void DeleteAlbum(eAlbum listaAlbum[], int idMinimaAlbum, int tam)
{
	int idEliminar;
	int index;
	int idMax;
	char seguir;

	printf("\n\nListado de albumes encontrados\n");
	printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
	PrintAlbum(listaAlbum, tam);

	idMax = BuscarIdMaxima(listaAlbum, tam);

	idEliminar = GetIntRange("\n\nIngrese la id la cual desea eliminar: ", "\nReingrese id (solo ids pertenecientes a la lista): ", idMinimaAlbum, idMax);
	index = FindAlbumById(listaAlbum, tam, idEliminar);

		if(index != -1)
			{
				system("cls");

				printf("\n\nListado de albumes encontrados\n");
				printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
				PrintOneAlbum(listaAlbum[index]);

				seguir = getChar("\nSe ha encontrado la id ingresada, esta seguro de querer continuar? Ingrese s(si) o n(no): ", "\nReingrese s(si) o n(no): ");

				if(seguir == 's')
					{
						RemoveAlbum(listaAlbum, tam, index, "\nSe ha eliminado el album con exito!!!\n");
						system("pause");
					}
					else
					{
						printf("\nUsted ha cancelado la baja del album\n");
						system("pause");
						system("cls");
					}
			}
			else
			{
				printf("\nNo se ha encontrado la id ingresada\n");
				system("pause");
				system("cls");
			}
}

int InformarMenu(eAlbum listaAlbum[], int tam)
{
	int continuar;
	do
		{
			system("cls");
			printf("\n#### Menu Mostrar ###");
			printf("\n\n1-Listado del total y promedio de importes (muestra los albumes que superan el promedio).\n");
			printf("2-Cantidad de albumes con fecha de publicacion posterior a 1/1/2000.\n");
			printf("3-Salir.\n");
			continuar = GetIntRange("\nIngrese una opcion: ", "Usted ha ingresado una opcion invalida: \n", 1, 3);

				switch(continuar)
					{
						case 1:
						printf("\n\nListado de albumes encontrados\n");
						printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
						PrintAlbum(listaAlbum, tam);
						printf("\n\n*El total del Importe de todos los albumes es: %.2f$\n", SumImportes(listaAlbum, tam));
						printf("\n*El promedio de todos los importes de los albumes es: %.2f$\n", PromedioImporte(listaAlbum, tam));
						printf("\n*La cantidad de albumes que supera el salario promedio es: %d\n\n", AlbumesMaxImporte(listaAlbum, tam));
						system("pause");
						system("cls");
						break;

						case 2:
						printf("\n\nListado de albumes encontrados\n");
						printf("\n%5s %10s %12s %12s", "Codigo", "Titulo", "Fecha", "Importe\n");
						PrintAlbum(listaAlbum, tam);
						printf("\n\n*La cantidad de albumes anteriores a la fecha 01/01/2000 son: %d\n", AlbumesSuperanFecha(listaAlbum, tam));
						system("pause");
						break;
					}

		}while(continuar !=3);

		if(continuar == 3 || continuar > 3)
		{
			continuar = -1;
		}
		return continuar;
}

float SumImportes(eAlbum listaAlbum[], int tam)
{
    float acumularImportes = 0;

    for(int i=0; i<tam; i++)
    {
        if(listaAlbum[i].IsEmpty == FALSE)
        {
        	acumularImportes += listaAlbum[i].importe;
        }
    }
    return acumularImportes;
}
float PromedioImporte(eAlbum listaAlbum[], int tam)
{
    float importePromedio = 0;

    for(int i=0; i<tam; i++)
    {
        if(listaAlbum[i].IsEmpty == FALSE)
        {
        	importePromedio = SumImportes(listaAlbum, tam) / ContarAlbumes(listaAlbum, tam);
        }
    }
    return importePromedio;
}

int ContarAlbumes(eAlbum listaAlbum[], int tam)
{
    int ContadorAlbumes = 0;

    for(int i=0; i<tam; i++)
    {
        if(listaAlbum[i].IsEmpty == FALSE)
        {
        	ContadorAlbumes++;
        }
    }
    return ContadorAlbumes;
}

int AlbumesMaxImporte(eAlbum listaAlbum[], int tam)
{
    float Promedio;
    int albumesSuperanProm = 0;
    Promedio = PromedioImporte(listaAlbum, tam);

    for(int i=0; i<tam; i++)
    {
        if(listaAlbum[i].IsEmpty == FALSE && listaAlbum[i].importe > Promedio)
        {
        	albumesSuperanProm++;
        }
    }
    return albumesSuperanProm;
}

int AlbumesSuperanFecha(eAlbum listaAlbum[], int tam)
{
    int ContadorAlbumes = 0;

    for(int i=0; i<tam; i++)
    {
        if(listaAlbum[i].IsEmpty == FALSE && listaAlbum[i].fecha.anio < 2000)
        {
        	ContadorAlbumes++;
        }
    }
    return ContadorAlbumes;
}

int BuscarIdMaxima(eAlbum listaAlbum[], int tam)
{
	int idMaxima;

	if(tam>0)
	{
		for(int i = 0; i<tam; i++)
		{
			if(listaAlbum[i].IsEmpty != TRUE )
			{
				idMaxima = listaAlbum[i].IdAlbum;
			}
		}
	}
	return idMaxima;
}

//1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
void OrdenarAlbumsXImporteTitulo(eAlbum listaAlbum[], int tam)
{
	eAlbum aux;
	int i;
	int j;
//*Importe(descendente) y Titulo(ascendente)
	for(i=0; i<tam-1; i++)
	{
		for(j=i+1; j<tam; j++)
		{
			if(strcmp(listaAlbum[i].titulo, listaAlbum[j].titulo)>0)
			{
				aux = listaAlbum[i];
				listaAlbum[i] = listaAlbum[j];
				listaAlbum[j] = aux;
			}
			else
			{
				if((strcmp(listaAlbum[i].titulo, listaAlbum[j].titulo)>0) && (listaAlbum[i].importe < listaAlbum[j].importe))
				{
					{
						aux = listaAlbum[i];
						listaAlbum[i] = listaAlbum[j];
						listaAlbum[j] = aux;
					}
				}
			}
		}
	}
	PrintAlbum(listaAlbum, tam);
}

void MostrarAlbumesMenorFecha(eAlbum listaAlbumes[], int tam)
{
     for(int i=0; i<tam; i++)
     {
         //contador++;
         if(listaAlbumes[i].IsEmpty == FALSE && listaAlbumes[i].fecha.anio < 2000)
         {
             PrintOneAlbum(listaAlbumes[i]);
         }
     }
}

void MostrarAlbumesMaxImporte(eAlbum listaAlbum[], int tam)
{
    float Promedio;
    Promedio = PromedioImporte(listaAlbum, tam);

    for(int i=0; i<tam; i++)
    {
        if(listaAlbum[i].IsEmpty == FALSE && listaAlbum[i].importe > Promedio)
        {
        	PrintOneAlbum(listaAlbum[i]);
        }
    }
	printf("\n*El promedio de todos los importes de los albumes es: %.2f$\n\n", Promedio);
}

void MostrarAlbumesPorAnio(eAlbum listaAlbum[], int tam, int anio)
{
    for(int i=0; i<tam; i++)
    {
        if(listaAlbum[i].IsEmpty == FALSE && listaAlbum[i].fecha.anio == anio)
        {
        	PrintOneAlbum(listaAlbum[i]);
        }
    }
}

int BuscarImporteMasCaro(eAlbum listaAlbum[], int tam)
{
	int highest = 0;
	int max;
	int flag = 0;

	for(int i=0; i<tam-1; i++)
	{
		 if(listaAlbum[i].IsEmpty == FALSE)
		 {
			 if(flag == 0)
			 {
				 max = listaAlbum[i].importe;
				 flag = 1;
			 }
			 else if(max < listaAlbum[i].importe)
			 {
				 max = listaAlbum[i].importe;
				 highest = i;
			 }
		 }
	}
	return highest;
}


