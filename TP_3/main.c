#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int menu();
int menuModificar();
int main()
{

    int idNext=1;

    LinkedList* listaEmpleados = ll_newLinkedList();
    char rta='n';


    if( listaEmpleados == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
        exit(1);
    }

    do
    {
        switch(menu())
        {

        case 1:

            if(controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("Archivo cargado con exito\n");
            }


            else
            {
                printf("Hubo un error al cargar el archivo.\n");
            }

            break;
        case 2:


            if(controller_loadFromBinary("data.bin",listaEmpleados))
            {
                printf("Empleados cargados con exito\n");
            }

            else
            {
                printf("No se pudo cargar.\n");
            }
            break;
        case 3:
            if( !controller_addEmployee(listaEmpleados,&idNext))
            {
                printf("\n");
                printf("Empleados cargados con exito.\n");
                printf("\n\n");
            }
            else
            {
                printf("No se pudo cargar al Empleado.\n");
            }


            break;
        case 4:
            system("cls");
            menuModificar();
            controller_editEmployee(listaEmpleados);

            break;
        case 5:

            controller_removeEmployee(listaEmpleados);


            break;
        case 6:

           if( controller_ListEmployee(listaEmpleados)){
            printf("Lista de Empleados");
           }
           else{
            printf("No hay empleados que mostrar\n");

           }


            break;
        case 7:

                //controller_ListEmployee(listaEmpleados);
                controller_sortEmployee(listaEmpleados);
                controller_ListEmployee(listaEmpleados);

            break;
        case 8:

                controller_saveAsText("data.csv",listaEmpleados);

            break;
        case 9:


                controller_saveAsBinary("data.bin",listaEmpleados);


            break;
        case 10:
            printf("Confirma salida? s/n ");
            fflush(stdin);
            rta = getchar();
            break;
        default:
            printf("opcion invalida.\n");
            break;

        }

        system("pause");
        system("cls");

    }
    while(rta != 's');
    return 0;
}
int menu()
{
    int opcion;

    printf("----- Menu de Empleados -----\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int menuModificar()
{

    int opcion;

    printf("--- MENU MODIFICACION ---\n\n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar Horas Trabajadas\n");
    printf("3. Modificar Sueldo\n");
    printf("4. Menu Anterior\n");
    scanf("%d",&opcion);

    return opcion;
}


