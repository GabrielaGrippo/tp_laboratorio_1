/*
 ============================================================================
 Name        : Tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
//#include"Datawarehouse.h"
#include"ArrayEmployees.h"
#define LEN 9


int main(void) {
	setbuf(stdout,NULL);








    char salir='n';

    int nextId=2000;
    eEmployee nomina[LEN];
    initEmployeesializarEmployees(nomina,LEN);
    //hardcodearEmployees(nomina,LEN,10,&nextId);

    do
    {
        switch (menu())
        {
        case 1:
            addEmployee(nomina,LEN,&nextId);
             system("pause");


            break;
        case 2:
            modificarEmpleado(nomina,LEN);
             system("pause");


            break;
        case 3:
            removeEmployee(nomina,LEN,&nextId);
             system("pause");

            break;
        case 4:
            sortEmployees(nomina,LEN);
            printEmployees(nomina,LEN);

            system("pause");

            break;
        case 5:
            printf("Confirma salir?:");
            fflush(stdin);
            scanf("%c",&salir);
            printf("\n\n");

            break;

        }
    }
    while(salir=='n');
    return EXIT_SUCCESS;
}









