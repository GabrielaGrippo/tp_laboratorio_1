#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
  int todoOk = 0;
	char buffer[4][1000];

	Employee* newEmployee = NULL;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			if((fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]) == 4) )
			{
				newEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				if(newEmployee != NULL)
				{
					ll_add(pArrayListEmployee, newEmployee);
					todoOk = 1;
				}
			}

		}
	}
    return todoOk;
}



/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
int todoOk = 0;
    Employee* aux = NULL;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
        	aux = employee_new();
            if(aux!=NULL)
            {
                if(fread(aux,sizeof(Employee),1,pFile))
                {
                    ll_add(pArrayListEmployee,aux);
                    todoOk=1;
                }
                else
                {
                    employee_delete(aux);
                }
            }
        }while(!feof(pFile));
    }
    return todoOk;


}
