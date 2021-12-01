#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Perrito.h"



sPerrito* sPerrito_new()
{
	sPerrito* perritoRetorno=NULL;
	perritoRetorno=(sPerrito*)malloc(sizeof(sPerrito));
	return perritoRetorno;
}
sPerrito* sPerrito_newParametros(char* idStr, char* nombreStr, char* pesoStr, char* edadStr, char* razaStr)
{
	sPerrito* perritoRetorno = NULL;
	perritoRetorno = sPerrito_new();

	if(perritoRetorno != NULL)
	{
		sPerrito_setId(perritoRetorno, atoi(idStr));
		sPerrito_setNombre(perritoRetorno, nombreStr);
		sPerrito_setEdad(perritoRetorno, atoi(edadStr));
		sPerrito_setRaza(perritoRetorno, razaStr);
		sPerrito_setPeso(perritoRetorno, atof(pesoStr));

	}
	return perritoRetorno;
}
void sPerrito_delete(sPerrito* this)
{
	if(this != NULL)
	{
		free(this);
		this=NULL;
	}
}
int sPerrito_setId(sPerrito* this, int id)
{
	int seCargo=0;
	if(this!=NULL)
	{
		this->id=id;
		seCargo=1;
	}
	return seCargo;
}
int sPerrito_getId(sPerrito* this,int* id)
{
	int retorno=-1;

	if(this != NULL )
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}
int sPerrito_setNombre(sPerrito* this, char* nombre)
{
	int seCargo = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		seCargo = 1;
	}
	return seCargo;
}
int sPerrito_getNombre(sPerrito* this, char* nombre)
{

	int retorno=-1;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno=1;
	}
	return retorno;
}
int sPerrito_setEdad(sPerrito* this, int edad)
{
	int seCargo = 0;
	if(this != NULL )
	{
		this->edad=edad;
		seCargo = 1;
	}
	return seCargo;
}
int sPerrito_getEdad(sPerrito* this,int* edad)
{
	int retorno=-1;

	if(this != NULL )
	{
		*edad=this->edad;
		retorno=1;
	}
	return retorno;
}
int sPerrito_setRaza(sPerrito* this, char* raza)
{
	int seCargo = 0;
	if(this != NULL )
	{
		strcpy(this->raza, raza);
		seCargo = 1;
	}
	return seCargo;
}
int sPerrito_getRaza(sPerrito* this, char* raza)
{
	int retorno=-1;

	if(this != NULL && raza!=NULL)
	{
		strcpy(raza, this->raza);
		retorno=1;
	}
	return retorno;
}
int sPerrito_setPeso(sPerrito* this, float peso)
{
	int seCargo = 0;
		if(this != NULL )
		{
			this->peso=peso;
			seCargo = 1;
		}
		return seCargo;
}
int sPerrito_getPeso(sPerrito* this, float* peso)
{
	int retorno=-1;

		if(this != NULL )
		{
			*peso=this->peso;
			retorno=1;
		}
		return retorno;
}
int sPerrito_setcantidadComidaRacion(sPerrito* this, float cantidadComidaRacion)
{
	int seCargo = 0;
		if(this != NULL )
		{
			this->cantidadComidaRacion=cantidadComidaRacion;
			seCargo = 1;
		}
		return seCargo;
}
int sPerrito_getcantidadComidaRacion(sPerrito* this, float* cantidadComidaRacion)
{
	int retorno=-1;

		if(this != NULL )
		{
			*cantidadComidaRacion=this->cantidadComidaRacion;
			retorno=1;
		}
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
void sPerrito_printDatacantidadComidaRacion(sPerrito* this)
{
    int id; //Variable donde se almacena el id utilizando getId();
    char nombre[35]; //Variable donde se almacena el nombre utilizando getNobre();
    int edad; //Variable donde se almacenan las horas trabajadas utilizando getHorasTrabajadas();
    char raza[35]; //Variable donde se almacena el sueldo utilizando getId();
    float peso;
    float cantidadComidaRacion;
	sPerrito_getId(this, &id); //Obtengo el Id del empleado
    sPerrito_getNombre(this, nombre); //Obtengo el nombre del empleado
    sPerrito_getEdad(this, &edad); //Obtengo las horas trabajadas del empelado
    sPerrito_getRaza(this, raza); //Obtengo el sueldo del empleado
    sPerrito_getPeso(this, &peso);
    sPerrito_getcantidadComidaRacion(this, &cantidadComidaRacion);

    printf("%d %15s %15.2f %15d %15s %15.2f\n", id, nombre, peso, edad, raza, cantidadComidaRacion); //Muestro los datos del empleado
}
void sPerrito_printData(sPerrito* this)
{
    int id; //Variable donde se almacena el id utilizando getId();
    char nombre[35]; //Variable donde se almacena el nombre utilizando getNobre();
    int edad; //Variable donde se almacenan las horas trabajadas utilizando getHorasTrabajadas();
    char raza[35]; //Variable donde se almacena el sueldo utilizando getId();
    float peso;
	sPerrito_getId(this, &id); //Obtengo el Id del empleado
    sPerrito_getNombre(this, nombre); //Obtengo el nombre del empleado
    sPerrito_getEdad(this, &edad); //Obtengo las horas trabajadas del empelado
    sPerrito_getRaza(this, raza); //Obtengo el sueldo del empleado
    sPerrito_getPeso(this, &peso);

    printf("%d %15s %15.2f %15d %15s \n", id, nombre, peso, edad, raza); //Muestro los datos del empleado
}
int sPerrito_ordenarPorNombre(void* punteroUno, void* punteroDos)
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
/*int sPerrito_ordenarSexo(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	if(punteroUno!=NULL&&punteroDos!=NULL)
	{
		retorno=0;
		char auxNombreUno[128];
		char auxNombreDos[128];
		sPerrito* auxPerrito = (sPerrito*)punteroUno;
		sPerrito* auxPerritoDos = (sPerrito*)punteroDos;
		Perrito_getSexo(auxPerrito,auxNombreUno);
		Perrito_getSexo(auxPerritoDos,auxNombreDos);

		retorno=stricmp(auxNombreUno,auxNombreDos);

		auxPerrito=NULL;
		auxPerritoDos=NULL;

	}
	return retorno;
}*/
///////// Filtros

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

/*int Perrito_filtroHembra(void* this)// guarda a todos los que sean hembras
{
	int retorno=0;
	char auxSexo[35];


	if(this!=NULL)
	{

		Perrito_getSexo((sPerrito*)this , auxSexo);
		if(!stricmp(auxSexo, "female"))
		{
			retorno=1;
		}
	}

	return retorno;
}*/
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

}
/*int Perrito_filtroMaleMenorCinco(void* this)
{
	int retorno=0;
	char auxSexo[35];

	if(this!=NULL)
	{

		Perrito_getSexo((sPerrito*)this , auxSexo);
		sPerrito* auxPerrito=NULL;
		auxPerrito=(sPerrito*) this;
		if(!stricmp(auxSexo, "male") && auxPerrito->edad<5)
		{
			retorno=1;
		}
	}
	return retorno;
}*/
