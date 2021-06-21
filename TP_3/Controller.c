#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "LinkedList.h"
#include "Employee.h"
#include"parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{

FILE* pFile;
    ll_clear(pArrayListEmployee);
    pFile = fopen(path,"r");

    if(pArrayListEmployee != NULL)
    {
        if(pFile == NULL)
        {
            printf("No se encontro el archivo\n");

        }
        parser_EmployeeFromText(pFile,pArrayListEmployee);
    }
 fclose(pFile);
   return 1;

}





/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
   int todoOk = 0;
		if(path != NULL && pArrayListEmployee != NULL)
		{
			FILE* f = fopen(path, "rb");
			if(f == NULL)
			{
				printf("No se pudo abrir el archivo\n");
			}
			else
			{
				if(parser_EmployeeFromBinary(f, pArrayListEmployee))
				{
					printf("Se realizo la carga del archivo\n");
				}
				else
				{
					printf("No se realizo la carga del archivo\n");
				}
			}
			fclose(f);
		}
	    return todoOk;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id )
{


    int todoOk = 0;
    Employee* pEmpleado;
    pEmpleado = employee_new();
    int idAux;

    printf("--- ALTA EMPLEADO ---       \n\n");

    if(pArrayListEmployee!=NULL && id!=NULL && employee_buscarMayorId(pArrayListEmployee,&idAux))
    {


        printf("\nid %d\n", idAux);

        printf("Ingrese nombre:");
        fflush(stdin);
        scanf("%s",pEmpleado->nombre);

        printf("Ingrese horas trabajadas:");
        fflush(stdin);
        scanf("%d",&pEmpleado->horasTrabajadas);
        while(pEmpleado->horasTrabajadas< 0)
        {
            printf("ERROR. las horas no pueden ser menores a 0 ,Reingrese:");
            fflush(stdin);
            scanf("%d",&pEmpleado->horasTrabajadas);
        }
        printf("Ingrese Sueldo:");
        fflush(stdin);
        scanf("%d",&pEmpleado->sueldo);
        while(pEmpleado->sueldo < 0)
        {
            printf("ERROR. el sueldo no puede ser menor a 0 ,Reingrese:");
            fflush(stdin);
            scanf("%d",&pEmpleado->sueldo);
        }
    }
    pEmpleado->id= idAux;
    if(ll_add(pArrayListEmployee, pEmpleado))
    {
        *id=idAux+1;
        pEmpleado=NULL;
        todoOk=1;
    }


    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int todoOk = 0;
    char buffer[1][20];
    Employee* e = NULL;
    Employee* aux = NULL;
    char flag = 'n';

    char nuevoNombre[20];
    int nuevasHoras;
    int nuevoSueldo;

    if(pArrayListEmployee != NULL)
    {

        printf("  --- MODIFICAR EMPLEADO  ---   \n\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese ID del empleado a modificar:");
        fflush(stdin);
        gets(buffer[0]);
        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            e = (Employee*) ll_get(pArrayListEmployee,i);
            if(e->id == atoi(buffer[0]))
            {
                printf("Id   Nombre   HorasTrabajadas   Sueldo\n\n");
                mostrarEmpleado(e);
                printf("confirma modificar este empleado? \nS/, N\n");
                flag = getchar();
                break;

            }
        }
        if(flag == 's')
        {
            switch(menuModificar())
            {

            case 1:

                printf("Ingrese nuevo Nombre:\n ");
                fflush(stdin);
                gets(nuevoNombre);
                strcpy(e->nombre,nuevoNombre);
                printf("Nombre modificado exitosamente\n ");
                break;
            case 2:
                printf("Ingrese nueva cantidad de horas: \n");
                scanf("%d",&nuevasHoras);
                while(nuevasHoras<0)
                {
                    printf("ERROR. Las horas no pueden ser menores a cero:");
                    scanf("%d",&nuevasHoras);
                }
                e->horasTrabajadas = nuevasHoras;
                printf("Cantidad de horas modificadas exitosamente\n ");
                break;

            case 3:
                printf("Ingrese nuevo Sueldo:\n ");
                scanf("%d",&nuevoSueldo);
                while(nuevoSueldo<0)
                {
                    printf("ERROR. El sueldo no puede ser menor a cero:");
                    scanf("%d",&nuevoSueldo);
                }
                e->sueldo = nuevoSueldo;
                printf("Sueldo modificado exitosamente \n");
                break;

            case 4:
                menu();
                break;

            default:
                printf("Opcion invalida.");
                break;
            }


            return todoOk;
        }
    }
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char buffer[1][20];
    Employee* e = NULL;
    int indice;
    int flag = 0;

    if(pArrayListEmployee != NULL)
    {

        printf("---  BAJA EMPLEADO  ---\n\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese ID del Empleado a dar de baja:");
        fflush(stdin);
        gets(buffer[0]);
        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            e = (Employee*) ll_get(pArrayListEmployee,i);
            if(e->id == atoi(buffer[0]))
            {
                printf("confirma? \n 1: si \n 2:no ");
                scanf("%d",&flag);
                indice = i;
                break;

            }
        }
        if(flag == 1)
        {
            ll_remove(pArrayListEmployee,indice);
            printf("Empleado dado de baja exitosamente\n\n");
        }
        else
        {
            printf("La baja fue cancelada\n\n");
        }
        todoOk = 1;

    }



    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{


    int todoOk=0;
    int tam;
    Employee* aux=NULL;

    tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL && tam>0)
    {
        printf("Id Nombre  HsTrabajadas Sueldo \n");
       // printf("\n");

        for(int i=0; i<tam; i++)
        {
            aux=(Employee*) ll_get(pArrayListEmployee, i);
            mostrarEmpleado(aux);

        }
         printf("\n\n");
        todoOk=1;
    }




    return todoOk;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int opcion;
    char rta = 'n';
    int orden;

    if(pArrayListEmployee != NULL)
    {

        printf(" --- ORDENAR EMPLEADOS ---  \n\n\n");
        printf("1. Ordenar por ID\n");
        printf("2. Ordenar por Nombre\n");
        printf("3. Ordenar por Horas Trabajadas\n");
        printf("4. Ordenar por Sueldo\n");
        printf("5. Volver al menu principal\n");
        scanf("%d",&opcion);

        switch(opcion)
        {

        case 1:
            printf("Ordena de forma descendente o ascendente?\n 1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListEmployee,sortByID,orden);
            todoOk=1;
            break;

        case 2:
            printf("Ordena de forma descendente o ascendente?\n1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListEmployee,sortByName,orden);
            todoOk=1;
            break;

        case 3:
            printf("Ordena de forma descendente o ascendente?\n1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListEmployee,sortByHoras,orden);
            break;

            break;
        case 4:
            printf("Ordena de forma descendente o ascendente?\n1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListEmployee,sortBySueldo,orden);
            break;

        case 5:
            printf("Confirma? s/n ");
            fflush(stdin);
            rta = getchar();
            if(rta == 's')
            {
                break;
            }


        default:
            printf("Opcion incorrecta.\n");
            system("pause");
            break;
        }

        todoOk = 1;
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

 int todoOk = 0;
	int tam = 0;
	int id = 0;
	char nombre[128];
	int horasTrabajadas = 0;
	int sueldo = 0;

	Employee* aux = NULL;
	FILE* f = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path, "w");
		if(f == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			tam = ll_len(pArrayListEmployee);
			fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
			for(int i = 0; i < tam; i++)
			{
				aux = (Employee*)ll_get(pArrayListEmployee, i);
				if(aux != NULL)
				{
					if((employee_getHorasTrabajadas(aux, &horasTrabajadas) &&
					   employee_getId(aux, &id) &&
					   employee_getNombre(aux, nombre) &&
					   employee_getSueldo(aux, &sueldo)))
					{
						fprintf(f,"%d, %s, %d, %d\n", id, nombre, horasTrabajadas, sueldo);
						todoOk = 1;

					}
				}
			}
			if(todoOk == 1)
			{
				printf("Guardado con exito\n");
			}
		}
		fclose(f);
	}
	return todoOk;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
int todoOk = 0;
	int tam = 0;
	Employee* aux = NULL;
	FILE* f = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path, "wb");
		if(f == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			tam = ll_len(pArrayListEmployee);
			for(int i = 0; i < tam; i++)
			{
				aux = (Employee*)ll_get(pArrayListEmployee, i);
				if(aux != NULL)
				{
					fwrite(aux, sizeof(Employee), 1, f);
					todoOk = 1;
				}
			}
			if(todoOk == 1)
			{
				printf("Guardado con exito\n");
			}
		}
	}
	return todoOk;



}

int employee_buscarMayorId(LinkedList* pArrayListEmployee, int* id)
{
    int todoOk=0;
    Employee* aux;
    int mayor=0;




    if(pArrayListEmployee!=NULL && id!=NULL)// tam>=0 &&
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            aux=(Employee*)ll_get(pArrayListEmployee, i);
            if(i==0 || aux->id > mayor)
            {
                mayor=aux->id;
            }
        }

        *id=mayor+1;
        todoOk=1;
    }

    return todoOk;
}


