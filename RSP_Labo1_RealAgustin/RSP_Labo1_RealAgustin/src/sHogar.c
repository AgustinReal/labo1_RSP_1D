/*
 * eHogar.c
 *
 *  Created on: 1 dic. 2021
 *      Author: Usuario
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sHogar.h"
#include"sPerritoConHogar.h"

sHogar* sHogar_new()
{
	sHogar* hogarRetorno=NULL;
	hogarRetorno=(sHogar*)malloc(sizeof(sHogar));
	return hogarRetorno;
}

sHogar* sHogar_newParametros( char* idStr, char* direccionStr)
{
	sHogar* perritoRetorno = NULL;
		perritoRetorno = sHogar_new();

		if(perritoRetorno != NULL)
		{
			sHogar_setId(perritoRetorno, atoi(idStr));
			sHogar_setDireccion(perritoRetorno, direccionStr);

		}
		return perritoRetorno;

}

void sHogar_delete(sHogar* this)
{
	if(this != NULL)
	{
		free(this);
		this=NULL;
	}

}
int sHogar_setId(sHogar* this,int id)
{
	int seCargo=0;
		if(this!=NULL)
		{
			this->id=id;
			seCargo=1;
		}
		return seCargo;
}

int sHogar_getId(sHogar* this,int* id)
{
	int retorno=-1;

		if(this != NULL )
		{
			*id=this->id;
			retorno=1;
		}
		return retorno;

}
int sHogar_setDireccion(sHogar* this, char* direccion)
{
	int seCargo = 0;
	if(this != NULL )
	{
		strcpy(this->direccion, direccion);
		seCargo = 1;
	}
	return seCargo;
}
int sHogar_getDireccion(sHogar* this, char* direccion)
{
	int retorno=-1;

	if(this != NULL && direccion!=NULL)
	{
		strcpy(direccion, this->direccion);
		retorno=1;
	}
	return retorno;
}
