/*
 * ePerritoConHogar.c
 *
 *  Created on: 1 dic. 2021
 *      Author: Usuario
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sHogar.h"
#include "sPerritoConHogar.h"

sPerritoConHogar* sPerritoConHogar_new()
{
	sPerritoConHogar* perritoRetorno=NULL;
	perritoRetorno=(sPerritoConHogar*)malloc(sizeof(sPerritoConHogar));
	return perritoRetorno;
}
sPerritoConHogar* sPerritoConHogar_newParametros(char* idStr, char* nombreStr, char* pesoStr, char* edadStr, char* razaStr, char* idDireccionStr)
{
	sPerritoConHogar* perritoRetorno = NULL;
	perritoRetorno = sPerritoConHogar_new();

	if(perritoRetorno != NULL)
	{
		sPerritoConHogar_setId(perritoRetorno, atoi(idStr));
		sPerritoConHogar_setNombre(perritoRetorno, nombreStr);
		sPerritoConHogar_setEdad(perritoRetorno, atoi(edadStr));
		sPerritoConHogar_setRaza(perritoRetorno, razaStr);
		sPerritoConHogar_setPeso(perritoRetorno, atof(pesoStr));
		sPerritoConHogar_setIdDireccion(perritoRetorno, atoi(idDireccionStr));
	}
	return perritoRetorno;
}
void sPerritoConHogar_delete(sPerritoConHogar* this)
{
	if(this != NULL)
	{
		free(this);
		this=NULL;
	}
}
int sPerritoConHogar_setId(sPerritoConHogar* this, int id)
{
	int seCargo=0;
	if(this!=NULL)
	{
		this->id=id;
		seCargo=1;
	}
	return seCargo;
}
int sPerritoConHogar_getId(sPerritoConHogar* this,int* id)
{
	int retorno=-1;

	if(this != NULL )
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}
int sPerritoConHogar_setIdDireccion(sPerritoConHogar* this, int idDireccion)
{
	int seCargo=0;
	if(this!=NULL)
	{
		this->idDireccion=idDireccion;
		seCargo=1;
	}
	return seCargo;
}
int sPerritoConHogar_getIdDireccion(sPerritoConHogar* this,int* idDireccion)
{
	int retorno=-1;

	if(this != NULL )
	{
		*idDireccion=this->idDireccion;
		retorno=1;
	}
	return retorno;
}
int sPerritoConHogar_setNombre(sPerritoConHogar* this, char* nombre)
{
	int seCargo = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		seCargo = 1;
	}
	return seCargo;
}
int sPerritoConHogar_getNombre(sPerritoConHogar* this, char* nombre)
{

	int retorno=-1;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno=1;
	}
	return retorno;
}
int sPerritoConHogar_setEdad(sPerritoConHogar* this, int edad)
{
	int seCargo = 0;
	if(this != NULL )
	{
		this->edad=edad;
		seCargo = 1;
	}
	return seCargo;
}
int sPerritoConHogar_getEdad(sPerritoConHogar* this,int* edad)
{
	int retorno=-1;

	if(this != NULL )
	{
		*edad=this->edad;
		retorno=1;
	}
	return retorno;
}
int sPerritoConHogar_setRaza(sPerritoConHogar* this, char* raza)
{
	int seCargo = 0;
	if(this != NULL )
	{
		strcpy(this->raza, raza);
		seCargo = 1;
	}
	return seCargo;
}
int sPerritoConHogar_getRaza(sPerritoConHogar* this, char* raza)
{
	int retorno=-1;

	if(this != NULL && raza!=NULL)
	{
		strcpy(raza, this->raza);
		retorno=1;
	}
	return retorno;
}
int sPerritoConHogar_setPeso(sPerritoConHogar* this, float peso)
{
	int seCargo = 0;
		if(this != NULL )
		{
			this->peso=peso;
			seCargo = 1;
		}
		return seCargo;
}
int sPerritoConHogar_getPeso(sPerritoConHogar* this, float* peso)
{
	int retorno=-1;

		if(this != NULL )
		{
			*peso=this->peso;
			retorno=1;
		}
		return retorno;
}
int sPerritoConHogar_setcantidadComidaRacion(sPerritoConHogar* this, float cantidadComidaRacion)
{
	int seCargo = 0;
		if(this != NULL )
		{
			this->cantidadComidaRacion=cantidadComidaRacion;
			seCargo = 1;
		}
		return seCargo;
}
int sPerritoConHogar_getcantidadComidaRacion(sPerritoConHogar* this, float* cantidadComidaRacion)
{
	int retorno=-1;

		if(this != NULL )
		{
			*cantidadComidaRacion=this->cantidadComidaRacion;
			retorno=1;
		}
		return retorno;
}
int sPerrito_ordenarDireccion(void* punteroUno, void* punteroDos)
{
    int retorno=0;
    char direccionUno[30];
    char direccionDos[30];
    sPerritoConHogar* auxPerrito = (sPerritoConHogar*)punteroUno;
    sPerritoConHogar* auxPerritoDos = (sPerritoConHogar*)punteroDos;
    sHogar_getDireccion(auxPerrito, direccionUno);
    sHogar_getDireccion(auxPerritoDos, direccionDos);

    retorno=strcmp(direccionUno,direccionDos);

    auxPerrito =NULL;
    auxPerritoDos=NULL;
    	    return retorno;
}
/*int sPerrito_setSexo(sPerrito* this,char* sexo)
{
	int seCargo = 0;
	if(this != NULL )
	{
		strcpy(this->sexo, sexo);
		seCargo = 1;
	}
	return seCargo;
}
int sPerrito_getSexo(sPerrito* this,char* sexo)
{
	int retorno=-1;

		if(this != NULL && sexo!=NULL)
		{
			strcpy(sexo, this->sexo);
			retorno=1;
		}
		return retorno;
}*/
void sPerritoConHogar_printDatacantidadComidaRacion(sPerritoConHogar* this)
{
    int id; //Variable donde se almacena el id utilizando getId();
    char nombre[35]; //Variable donde se almacena el nombre utilizando getNobre();
    int edad; //Variable donde se almacenan las horas trabajadas utilizando getHorasTrabajadas();
    char raza[35]; //Variable donde se almacena el sueldo utilizando getId();
    float peso;
    float cantidadComidaRacion;
    sPerritoConHogar_getId(this, &id); //Obtengo el Id del empleado
    sPerritoConHogar_getNombre(this, nombre); //Obtengo el nombre del empleado
    sPerritoConHogar_getEdad(this, &edad); //Obtengo las horas trabajadas del empelado
    sPerritoConHogar_getRaza(this, raza); //Obtengo el sueldo del empleado
    sPerritoConHogar_getPeso(this, &peso);
    sPerritoConHogar_getcantidadComidaRacion(this, &cantidadComidaRacion);

    printf("%d %15s %15.2f %15d %15s %15.2f\n", id, nombre, peso, edad, raza, cantidadComidaRacion); //Muestro los datos del empleado
}
void sPerritoConHogar_printDatacantidadComidaRacionConDireccion(sPerritoConHogar* this)
{
    int id; //Variable donde se almacena el id utilizando getId();
    char nombre[35]; //Variable donde se almacena el nombre utilizando getNobre();
    int edad; //Variable donde se almacenan las horas trabajadas utilizando getHorasTrabajadas();
    char raza[35]; //Variable donde se almacena el sueldo utilizando getId();
    float peso;
    float cantidadComidaRacion;
    sPerritoConHogar_getId(this, &id); //Obtengo el Id del empleado
    sPerritoConHogar_getNombre(this, nombre); //Obtengo el nombre del empleado
    sPerritoConHogar_getEdad(this, &edad); //Obtengo las horas trabajadas del empelado
    sPerritoConHogar_getRaza(this, raza); //Obtengo el sueldo del empleado
    sPerritoConHogar_getPeso(this, &peso);
    sPerritoConHogar_getcantidadComidaRacion(this, &cantidadComidaRacion);

    printf("%d %15s %15.2f %15d %15s %15.2f\n", id, nombre, peso, edad, raza, cantidadComidaRacion); //Muestro los datos del empleado
}
void sPerritoConHogar_printData(sPerritoConHogar* this, sHogar* this2)
{
    int id; //Variable donde se almacena el id utilizando getId();
    char nombre[35]; //Variable donde se almacena el nombre utilizando getNobre();
    int edad; //Variable donde se almacenan las horas trabajadas utilizando getHorasTrabajadas();
    char raza[35]; //Variable donde se almacena el sueldo utilizando getId();
    float peso;
    int idDireccion;
    char direccion[35];
    sPerritoConHogar_getId(this, &id); //Obtengo el Id del empleado
    sPerritoConHogar_getNombre(this, nombre); //Obtengo el nombre del empleado
    sPerritoConHogar_getEdad(this, &edad); //Obtengo las horas trabajadas del empelado
    sPerritoConHogar_getRaza(this, raza); //Obtengo el sueldo del empleado
    sPerritoConHogar_getPeso(this, &peso);
    sHogar_getId(this2, &idDireccion);
    sHogar_getDireccion(this2, direccion);

    printf("%d %15s %15.2f %15d %15s %15d %15s\n", id, nombre, peso, edad, raza, idDireccion, direccion); //Muestro los datos del empleado
}
/*int sPerrito_ordenarPorNombre(void* punteroUno, void* punteroDos)
{

	int retorno=-2;
	    char auxNombreUno[128];
	    char auxNombreDos[128];
	    sPerrito* auxEmpleado = (sPerrito*)punteroUno;
	    sPerrito* auxEmpleadoDos = (sPerrito*)punteroDos;
	    sPerrito_getNombre(auxEmpleado,auxNombreUno);
	    sPerrito_getNombre(auxEmpleadoDos,auxNombreDos);

	    retorno=strcmp(auxNombreUno,auxNombreDos);

	    auxEmpleado =NULL;
	    auxEmpleadoDos=NULL;
	    return retorno;

}
int sPerrito_ordenarEdad(void* punteroUno, void* punteroDos)
{
    int retorno=0;
    int horasUno;
    int horasDos;
    sPerrito* auxPerrito = (sPerrito*)punteroUno;
    sPerrito* auxPerritoDos = (sPerrito*)punteroDos;
    sPerrito_getEdad(auxPerrito,&horasUno);
    sPerrito_getEdad(auxPerritoDos,&horasDos);

    if(horasUno>horasDos)
    {
        retorno=1;
    }
    else if(horasUno<horasDos)
    {
        retorno=-1;
    }
    auxPerrito =NULL;
    auxPerritoDos=NULL;
    return retorno;
}
int sPerrito_ordenarPorId(void* punteroUno, void* punteroDos)
{
    int retorno=0;
    int idUno;
    int idDos;
    sPerrito* auxPerrito = (sPerrito*)punteroUno;
    sPerrito* auxPerritoDos = (sPerrito*)punteroDos;
    sPerrito_getId(auxPerrito,&idUno);
    sPerrito_getId(auxPerritoDos,&idDos);

    if(idUno>idDos)
    {
        retorno=1;
    }
    else if(idUno<idDos)
    {
        retorno=-1;
    }
    auxPerrito=NULL;
    auxPerritoDos=NULL;
    return retorno;
}

int sPerrito_ordenarRaza(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	if(punteroUno!=NULL&&punteroDos!=NULL)
	{
		retorno=0;
		char auxNombreUno[128];
		char auxNombreDos[128];
		sPerrito* auxPerrito = (sPerrito*)punteroUno;
		sPerrito* auxPerritoDos = (sPerrito*)punteroDos;
		sPerrito_getRaza(auxPerrito,auxNombreUno);
		sPerrito_getRaza(auxPerritoDos,auxNombreDos);

		retorno=stricmp(auxNombreUno,auxNombreDos);

		auxPerrito =NULL;
		auxPerritoDos=NULL;
	}

	return retorno;
}
int sPerrito_ordenarPeso(void* punteroUno, void* punteroDos)
{
	int retorno=0;
	float idUno;
	float idDos;
	sPerrito* auxPerrito = (sPerrito*)punteroUno;
	sPerrito* auxPerritoDos = (sPerrito*)punteroDos;
	sPerrito_getPeso(auxPerrito,&idUno);
	sPerrito_getPeso(auxPerritoDos,&idDos);

	if(idUno>idDos)
	{
		retorno=1;
	}
	else if(idUno<idDos)
	{
		retorno=-1;
	}
	auxPerrito=NULL;
	auxPerritoDos=NULL;
	return retorno;
}



int sPerrito_filtro_PerroMasPesados(void* this)
{
    int retorno=-1;

    float pesoActual;
    float pesoPesadoGuia=80;

    if(this!=NULL)
    {
        this = (sPerrito*) this;
        sPerrito_getPeso(this, &pesoActual);
        if(pesoActual>=pesoPesadoGuia)
        {
            retorno= 0;
        }
    }

    return retorno;
}

int sPerrito_filtro_PerroPeso(void* this, float pesoGuia)
{
    int retorno=-1;

    float pesoActual;

    if(this!=NULL)
    {
        this = (sPerrito*) this;
        sPerrito_getPeso(this, &pesoActual);
        if(pesoActual>=pesoGuia)
        {
            retorno= 0;
        }
    }

    return retorno;
}

int sPerrito_filtro_Comparacion(void* this, void* guia)
{
    int retorno=-1;

    if(this!=NULL&& guia!=NULL)
    {
        this = (sPerrito*) this;
        guia = (sPerrito*) guia;
        if(this==guia)
        {
            retorno= 0;
        }
    }

    return retorno;
}


int sPerrito_filtroSeLLamaKaile(void* this)// guarda a todos los que sean hembras
{
	int retorno=0;
	char auxNombre[35];


	if(this!=NULL)
	{

		sPerrito_getNombre((sPerrito*)this , auxNombre);
		if(!stricmp(auxNombre, "Kaile"))
		{
			retorno=1;
		}
	}

	return retorno;
}
int sPerrito_filtroRazaRiver(void* this)// guarda a todos los que sean Raza River.
{
	int retorno=0;
	char auxRaza[35];
	sPerrito* auxPerrito=NULL;

	if(this!=NULL)
	{
		auxPerrito=(sPerrito*) this;
		sPerrito_getRaza(auxPerrito, auxRaza);
		if(!stricmp(auxRaza, "River"))
		{
			retorno=1;
		}
	}

	return retorno;
}
int sPerrito_filtroPorEdad(void* this) //muestra los perros mayores a 20
{
	int retorno=0;
	if(this!=NULL)
	{
		sPerrito* auxPerrito=NULL;
		auxPerrito=(sPerrito*) this;
		if(auxPerrito->edad>20)
		{
			retorno=1;
		}
	}
	 return retorno;
}
int sPerrito_laQueMapea(void* this)
{
	int retorno=0;
	float cantidadComidaRacion;
	sPerrito* auxPerrito=NULL;
	if(this!=NULL)
	{
		auxPerrito=(sPerrito*) this;

		cantidadComidaRacion=auxPerrito->peso*23;

		sPerrito_setcantidadComidaRacion(this, cantidadComidaRacion);

		retorno =1;
	}
	return retorno;

}
int sPerrito_laQueFiltra(void* this)
{
	int retorno=0;
	char auxRaza[35];
	int auxEdad;
	float auxCantidadRacion;
	if(this!=NULL)
	{

		sPerrito_getRaza((sPerrito*)this , auxRaza);
		sPerrito_getEdad(this, &auxEdad);
		sPerrito_getcantidadComidaRacion(this, &auxCantidadRacion);
		if(!stricmp(auxRaza, "Galgo") && auxEdad>=10 && auxCantidadRacion<200)
		{
			retorno=1;
		}
	}
	return retorno;

}*/





