#include <stdio.h>
#include <stdlib.h>
#include "../src/LinkedList.h"
#include "Perrito.h"
#include "sPerritoConHogar.h"
#include "sHogar.h"
int parser_PerritoFromText(FILE* pFile , LinkedList* pArrayListPerrito)
{

	int todoOk = 0;
		sPerrito* Perrito;
		char buffer[5][30];
		int aux;

		if(pFile != NULL && pArrayListPerrito != NULL)
		{
			fscanf(pFile,"%[^,],%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

			while(!feof(pFile))
			{
				aux = fscanf(pFile,"%[^,],%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
				if(aux == 5)
				{
					Perrito = sPerrito_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

					if(Perrito != NULL)
					{
						aux = ll_add(pArrayListPerrito, Perrito);
						if(aux != 0)
						{
							sPerrito_delete(Perrito);
							break;
						}
						else
						{
							todoOk = 1;
						}
					}
				}
				else
				{
					break;
				}
			}
		}
	    return todoOk;
}
int parser_PerritoConHogarFromText(FILE* pFile , LinkedList* listaHogar)
{

	int todoOk = 0;
		sPerritoConHogar* Perrito;
		char buffer[6][30];
		int aux;

		if(pFile != NULL && listaHogar != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],buffer[5]);

			while(!feof(pFile))
			{
				aux = fscanf(pFile,"%[^,],%[^,],%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],buffer[5]);
				if(aux == 6)
				{
					Perrito = sPerritoConHogar_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],buffer[5]);

					if(Perrito != NULL)
					{
						aux = ll_add(listaHogar, Perrito);
						if(aux != 0)
						{
							sPerrito_delete(Perrito);
							break;
						}
						else
						{
							todoOk = 1;
						}
					}
				}
				else
				{
					break;
				}
			}
		}
	    return todoOk;
}
int parser_HogarFromText(FILE* pFile , LinkedList* listaHogar)
{

	int todoOk = 0;
		sHogar* hogar;
		char buffer[2][30];
		int aux;

		if(pFile != NULL && listaHogar != NULL)
		{
			fscanf(pFile,"%[^,],%[^\n]\n",buffer[0], buffer[1]);

			while(!feof(pFile))
			{
				aux = fscanf(pFile,"%[^,],%[^\n]\n",buffer[0], buffer[1]);
				if(aux == 6)
				{
					hogar = sHogar_newParametros(buffer[0], buffer[1]);

					if(hogar != NULL)
					{
						aux = ll_add(listaHogar, hogar);
						if(aux != 0)
						{
							sHogar_delete(hogar);
							break;
						}
						else
						{
							todoOk = 1;
						}
					}
				}
				else
				{
					break;
				}
			}
		}
	    return todoOk;
}
int parser_PerritoFromBinary(FILE* pFile , LinkedList* pArrayListPerrito)
{
	printf("Cargando datos del archivo binario\n");
	int retorno=0;

	if(pFile!=NULL && pArrayListPerrito!=NULL)
	{

		int fin =1;
		sPerrito* auxPerrito=sPerrito_new();
		do
		{
			fin =fread(auxPerrito, sizeof(sPerrito), 1, pFile);
			if(fin)
			{
				ll_add(pArrayListPerrito, auxPerrito);
				auxPerrito=sPerrito_new();
			}
		}while(fin);
		free(auxPerrito);

		fclose(pFile);
		retorno=1;
	}

	return retorno;
}
int guardarComoTexto(char* path, LinkedList* pLista)
{
	FILE* pFile;
	sPerrito* pPerrito;

	int id;
	char nombre[31];
	int edad;
	char raza[31];
	float peso;
	float cantidadComidaRacion;
	int retorno = 0;

	if(pLista!=NULL && path!=NULL)
	{
		pFile= fopen(path, "w");
		if(pFile!=NULL)
		{
			retorno = 1;
			for(int i = 0; i < ll_len(pLista); i++)
			{
				pPerrito = (sPerrito*)ll_get(pLista, i);
				sPerrito_getId(pPerrito, &id); //Obtengo el Id del empleado
				sPerrito_getNombre(pPerrito, nombre); //Obtengo el nombre del empleado
				sPerrito_getEdad(pPerrito, &edad); //Obtengo las horas trabajadas del empelado
				sPerrito_getRaza(pPerrito, raza); //Obtengo el sueldo del empleado
				sPerrito_getPeso(pPerrito, &peso);
				sPerrito_getcantidadComidaRacion(pPerrito, &cantidadComidaRacion);

				fprintf(pFile, "%d,%s,%.2f,%d,%s,%.2f\n", id, nombre, peso, edad, raza, cantidadComidaRacion);


			}

			fclose(pFile);

			printf("Archivo guardado correctamente\n");
		}
		else if(retorno == 0)
		{
			printf("Error\n");
		}
	}

	return retorno;
}
int cargarTexto(char* path , LinkedList* pLista)
{
	FILE* pFile;
	int retorno = 1;

	pFile = fopen(path, "r"); //Abre el archivo para leerlo de texto, si es que existe.

	if(pFile != NULL)
	{
		if(parser_PerritoFromText(pFile, pLista) == 1)
		{
			//Si todo salio bien cambia a 0
			retorno = 0;
			printf("\nLos datos de los perros en modo texto fueron cargados corretamente\n\n");
		}
	}

	fclose(pFile);

	return retorno;

}
