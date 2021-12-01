#include <stdio.h>
#include <stdlib.h>
#include "../src/LinkedList.h"
#include "Controller.h"
#include "inputs.h"
#include "Perrito.h"


int main()
{
	setbuf(stdout, NULL);
    int option;
    int banderaPrimerLista=0;

    LinkedList* listaPerritos=ll_newLinkedList();
    LinkedList* listaMapeada=NULL;
    LinkedList* Galgos=NULL;


    int(*pFuncionMapeo)(void*);
    do{

    	pedirEntero(&option,  " _______________________________________________________________________________ \n"
    			              "|                                                                               |\n"
							  "|                                  MENU PERRITOS                                |\n"
    						  "|_______________________________________________________________________________|\n"
								"1.Cargar los datos de los perritos desde el archivo data.csv (modo texto).\n"
								"2.Listar Perritos por nombre ascendente.\n"
    							"3.Calcular y colocar los valores de la comida.\n"
								"4.listar Perritos con sus raciones de comida.\n"
    							"5.calcular filtro Galgo.\n"
								"6.Mostrar el archivo “galgosFlaquitos.csv” (modo texto).\n"
    							"7.Salir.\n"
								"---------------------------------------------------------------------------------\n"
								"Ingrese una opcion: ",

								" _______________________________________________________________________________ \n"
							    "|                                                                               |\n"
							    "|                                  MENU PERRITOS                                |\n"
							    "|_______________________________________________________________________________|\n"
								"1.Cargar los datos de los perritos desde el archivo data.csv (modo texto).\n"
								"2.Listar Perritos por nombre ascendente.\n"
								"3.Calcular y colocar los valores de la comida.\n"
								"4.listar Perritos con sus raciones de comida.\n"
								"5.calcular filtro Galgo.\n"
								"6.Mostrar el archivo “galgosFlaquitos.csv” (modo texto).\n"
								"7.Salir.\n"
								"---------------------------------------------------------------------------------\n"
								"Opcion invalida, reingrese: ",1, 7);



        switch(option)
        {
            case 1:
            	if(!banderaPrimerLista)
            	{
            		controller_loadFromText("perritos.csv",listaPerritos);
            		banderaPrimerLista=1;
            	}
            	else
            	{
            		printf("Ya se accedio a la lista...\n");
            	}
                option=0;
                break;
            case 2:
            	if(ll_len(listaPerritos)!=0)
            	{
            		controller_sortPerritoNombreAscendete(listaPerritos);
            		controller_ListPerrito(listaPerritos);
            		printf("Se ordeno con exitos...\n");
            	}
            	else
            	{
            		printf("No se ingreso ningun perrito a la lista...\n");
            	}
            	option=0;
            	break;
            case 3:
            	if(ll_len(listaPerritos)!=0)
            	{
            		pFuncionMapeo=sPerrito_laQueMapea;
            		listaMapeada=ll_clone(listaPerritos);
            		ll_map(listaMapeada, pFuncionMapeo);
            		printf("Se asignaron los valores de la comida exitosamente..\n");
            	}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}
            	option=0;
            	break;
            case 4:
            	if(ll_len(listaMapeada)!=0 && ll_len(listaPerritos)!=0)
            	{
            		controller_ListPerritoConRacion(listaMapeada);
            	}
            	else
            	{
            		printf("No se ingreso ningun perrito a la lista y no se mapeo la racion de comida...\n");
            	}
            	option=0;
            	break;
            case 5:
            	if(ll_len(listaMapeada)!=0 && ll_len(listaPerritos)!=0)
            	{
            		printf("Se esta filtarndo por Galgo\n");
            		Galgos=ll_filter(listaMapeada, sPerrito_laQueFiltra);
            	}
            	else
            	{
            		printf("No se ingreso ningun perrito a la lista y no se mapeo la racion de comida...\n");
            	}
            	option=0;
            	break;
            case 6:
            	if(ll_len(listaPerritos)!=0)
            	{
            		printf("Se guardo correctamente en modo texto...\n");
            		controller_saveAsText("galgosFlaquitos.csv", Galgos);
            	}
            	else
            	{
            		printf("No se ingreso ningun perrito a la lista y no se mapeo la racion de comida...\n");
            	}
            	option=0;
            	break;
            case 7:
            	ll_deleteLinkedList(listaPerritos);
            	printf("Saliendo del sistema...");
            	break;
        }
        system("pause");
    }while(option != 7);
    return 0;
}



