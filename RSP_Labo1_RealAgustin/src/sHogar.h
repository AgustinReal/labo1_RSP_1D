/*
 * eHogar.h
 *
 *  Created on: 1 dic. 2021
 *      Author: Usuario
 */

#ifndef SHOGAR_H_
#define SHOGAR_H_

#include "sPerritoConHogar.h"

typedef struct
{
	int id;
	char direccion[35];

}sHogar;


sHogar* sHogar_new();

sHogar* sHogar_newParametros(char* idStr, char* direccionStr);

void sHogar_delete();

int sHogar_setId(sHogar* this,int id);

int sHogar_getId(sHogar* this,int* id);

int sHogar_setDireccion(sHogar* this, char* direccion);

int sHogar_getDireccion(sHogar* this, char* direccion);


#endif /* SHOGAR_H_ */
