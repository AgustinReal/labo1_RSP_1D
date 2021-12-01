/*
 * ePerritoConHogar.h
 *
 *  Created on: 1 dic. 2021
 *      Author: Usuario
 */

#ifndef SPERRITOCONHOGAR_H_
#define SPERRITOCONHOGAR_H_


#include "sHogar.h"

typedef struct
{
    int id;
    char nombre[35];
    float peso;
    int edad;
    char raza[35];
    float cantidadComidaRacion;
    int idDireccion;


}sPerritoConHogar;

/**
 * @fn Employee employee_new*()
 * @brief Esta funcion: Se encarga de agregar un nuevo empleado y guardarlo en
 * la memoria dinamica, es un contructor sin parametros.
 *
 * @return Retorna el puntero del empleado asignado en la memoria.
 */
sPerritoConHogar* sPerritoConHogar_new();
/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Esta funcion: Se encarga de agregar un nuevo empleado y guardarlo en
 * la memoria dinamica, es un contructor con parametros.
 *
 * @param idStr: En este apartado se le asigna la Id del empleado en forma de array de chars
 * y la transformas mediante la funcion atoi.
 * @param nombreStr: En este apartado se le asigna el Nombre del empleado en forma de array de chars
 * y la transformas mediante la funcion atoi.
 * @param horasTrabajadasStr: En este apartado se le asigna las horas trabajadas del empleado en forma de array de chars
 * y la tranformas mediante la funcion atoi.
 * @param sueldoStr: En este apartado se le asigna el sueldo del empleado en forma de array de chars
 * y la tranformas mediante la funcion atoi.
 *
 * @return Retorna el puntero del empleado asignado en la memoria.
 */
sPerritoConHogar* sPerritoConHogar_newParametros(char* idStr, char* nombreStr, char* edadStr, char* razaStr, char* pesoStr, char* idDireccionStr);
/**
 * @fn void employee_delete(Employee*)
 * @brief Esta funcion: Se encarga de eliminar a un	empleado en la memoria dinamica.
 *
 *
 * @param this: Es el empleado a eliminar.
 */
void sPerritoConHogar_delete();
/**
 * @fn int employee_setId(Employee*, int)
 * @brief Esta funcion: Se encarga de colocar el Id del empleado en la lista general.
 *
 * @param this: Esta es  la lista.
 * @param id: El id a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int sPerritoConHogar_setId(sPerritoConHogar* this,int id);
/**
 * @fn int employee_getId(Employee*, int)
 * @brief Esta funcion: Se encarga de obtener el Id del empleado en la lista general.
 *
 * @param this: Esta es  la lista.
 * @param id: El id a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int sPerritoConHogar_getId(sPerritoConHogar* this,int* id);
int sPerritoConHogar_setIdDireccion(sPerritoConHogar* this, int idDireccion);

int sPerritoConHogar_getIdDireccion(sPerritoConHogar* this,int* idDireccion);
/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Esta funcion: Se encarga de colocar el nombre del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param nombre: El nombre a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int sPerritoConHogar_setNombre(sPerritoConHogar* this,char* nombre);
/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Esta funcion: Se encarga de obtener el nombre del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param nombre: El nombre a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int sPerritoConHogar_getNombre(sPerritoConHogar* this,char* nombre);
/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief Esta funcion: Se encarga de colocar las horas trabajadas del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param horasTrabajadas: Las horas trabajadas a colocar en la lista.
 * @return Retorna 1 o -1: 1 si se puedo cargar o -1 si no se pudo cargar.
 */
int sPerritoConHogar_setEdad(sPerritoConHogar* this,int edad);
/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief Esta funcion: Se encarga de obtener las horas trabajadas del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param horasTrabajadas: Las horas trabajadas a obtener en la lista.
 * @return Retorna 1 o -1: 1 si se puedo cargar o -1 si no se pudo cargar.
 */
int sPerritoConHogar_getEdad(sPerritoConHogar* this,int* edad);
/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief Esta funcion: Se encarga de colocar el sueldo del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param sueldo: El sueldo a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int sPerritoConHogar_setRaza(sPerritoConHogar* this, char* raza);
/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief Esta funcion: Se encarga de obtener el sueldo del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param sueldo: El sueldo a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int sPerritoConHogar_getRaza(sPerritoConHogar* this, char* raza);

int sPerritoConHogar_setPeso(sPerritoConHogar* this, float peso);
int sPerritoConHogar_getPeso(sPerritoConHogar* this, float* peso);
int sPerritoConHogar_setSexo(sPerritoConHogar* this,char* sexo);
int sPerritoConHogar_getSexo(sPerritoConHogar* this,char* sexo);
int sPerritoConHogar_setcantidadComidaRacion(sPerritoConHogar* this, float cantidadComidaRacion);
int sPerritoConHogar_getcantidadComidaRacion(sPerritoConHogar* this, float* cantidadComidaRacion);


//int imprimirPerrosConHogar(linkedlist* listaPerrosConHogar, linkedlist* lista hogares);
/*
int sPerrito_ordenarEdad(void* punteroUno, void* punteroDos);

int sPerrito_ordenarPorId(void* punteroUno, void* punteroDos);

int sPerrito_ordenarRaza(void* punteroUno, void* punteroDos);
int sPerrito_ordenarPeso(void* punteroUno, void* punteroDos);
int sPerrito_ordenarSexo(void* punteroUno, void* punteroDos);
int sPerrito_ordenarPeso(void* punteroUno, void* punteroDos);

int sPerrito_filtro_PerroPeso(void* this, float pesoGuia);

int Perrito_filtro_Comparacion(void* this, void* guia);
//int Perrito_filtroHembra(void* this);
int sPerrito_filtroRazaRiver(void* this);
int sPerrito_filtroPorEdad(void* this);
int sPerrito_filtroSeLLamaKaile(void* this);
int sPerrito_laQueMapea(void*);
int sPerrito_laQueFiltra(void*);
void sPerrito_printDatacantidadComidaRacion(sPerrito* this);
//int Perrito_filtroMaleMenorCinco(void* this);
*/





#endif /* SPERRITOCONHOGAR_H_ */
