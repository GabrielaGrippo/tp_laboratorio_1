#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Employee.h"
#include "Controller.h"
Employee* employee_new(){
 Employee* nuevoEmpleado;
 nuevoEmpleado = (Employee*) malloc( sizeof(Employee));
    if(nuevoEmpleado != NULL)
    {


        employee_setHorasTrabajadas(nuevoEmpleado, 0);
		employee_setId(nuevoEmpleado, 0);
		employee_setNombre(nuevoEmpleado, " ");
		employee_setSueldo(nuevoEmpleado, 0);
    }
    return nuevoEmpleado;
}



Employee* employee_newParametros(int* id,char* nombre,int* horasTrabajadas,int* sueldo){

Employee* nuevoEmpleado =employee_new();//consigo el espacio en memoria
if(nuevoEmpleado !=NULL)
    {
  //trato de cargarlo
   if(!(employee_setId(nuevoEmpleado,id)&&//si todo esto esta ok va hacer true pero al negarlo va hacer false entonces no entro al if
      employee_setNombre(nuevoEmpleado,nombre)&&//pero si alguno de estos campos fallo esto me va a dar false y negado me va a dar true y va a entrar ahi
      employee_setHorasTrabajadas(nuevoEmpleado,horasTrabajadas)&&
      employee_setSueldo(nuevoEmpleado,sueldo))
      ){
      employee_delete(nuevoEmpleado);//lo libero
      nuevoEmpleado=NULL;
      }
    }
    return nuevoEmpleado;

}
void employee_delete(Employee* p){
    free(p);


}

int employee_setId(Employee* this,int id){

int todoOk=0;
if(this !=NULL && id >0){
    this->id=id;
    todoOk=1;
}
return todoOk;
}
int employee_getId(Employee* this,int* id){
int todoOk=0;
if(this !=NULL && id !=NULL){
    *id=this->id;
    todoOk=1;
}
return todoOk;
}

int employee_setNombre(Employee* this,char* nombre){
 int todoOk = 0;
    if( this != NULL && nombre != NULL )
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre){
int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
int todoOk=0;
if(this != NULL  ){
    this ->horasTrabajadas=horasTrabajadas;
    todoOk=1;
}
return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
 int todoOk = 0;

    if( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo){
int todoOk=0;
if(this !=NULL ){
   this->sueldo=sueldo;
    todoOk=1;
}
return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo){
 int todoOk = 0;

    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;

}
int mostrarEmpleado( Employee* this)
{

    int todoOk=0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(this!=NULL)
	{
		if(employee_getId(this, &id)&&
			employee_getNombre(this,nombre) &&
			employee_getHorasTrabajadas(this, &horasTrabajadas)&&
			employee_getSueldo(this,&sueldo))
		{
			printf("%d     %s       %d         %d\n\n", id,nombre, horasTrabajadas, sueldo);
		}

		todoOk=1;
	}
    return todoOk;

}

int sortByID(Employee* emp1, Employee* emp2){

int retorno = 0;

if(emp1 != NULL && emp2 != NULL){

if(((Employee*)emp1)->id > ((Employee*)emp2)->id)
{
 retorno =  1;
}
if(((Employee*)emp1)->id < ((Employee*)emp2)->id)
{
 retorno =  -1;
}

}else{
    return -2;
}
    return retorno;
}

int sortByName(Employee* emp1, Employee* emp2){


    int retorno;

    if(emp1 != NULL && emp2 != NULL)
    {
        retorno = strcmp(emp1->nombre, emp2->nombre);
    }
    return retorno;
}


int sortByHoras(Employee* emp1, Employee* emp2){

int retorno;

if(emp1 != NULL && emp2 != NULL){

if(((Employee*)emp1)->horasTrabajadas > ((Employee*)emp2)->horasTrabajadas)
{
 retorno =  1;
}
if(((Employee*)emp1)->horasTrabajadas < ((Employee*)emp2)->horasTrabajadas)
{
 retorno =  -1;
}

}else{
    return -2;
}
    return retorno;
}


int sortBySueldo(Employee* emp1, Employee* emp2){
    int retorno = 0;

if(emp1 != NULL && emp2 != NULL){

if(((Employee*)emp1)->sueldo > ((Employee*)emp2)->sueldo)
{
 retorno =  1;
}
if(((Employee*)emp1)->sueldo < ((Employee*)emp2)->sueldo)
{
 retorno =  -1;
}

}else{
    return -2;
}
    return retorno;
}
