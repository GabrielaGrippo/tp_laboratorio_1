/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Gaby.h"

int main(void) {
	setbuf(stdout,NULL);


	    int operandoA;
	    int operandoB;
	    int salir=0;
	    int flagOperandoA=0;
	    int flagOperandoB=0;
	    int resultadoSuma;
	    int resultadoResta;
	    float resultadoDivision;
	    int resultadoMultiplicacion;
	    int resultadoFactorialA;
	    int resultadofactorialB;
	    int opcion;
	    int flagMenu1 =0;
	    int flagMenu2=0;


	    do
	    {

	       // system("cls");
	        printf("----Menu de opciones----\n");
	        printf("----  Calculadora  ----\n");
	        if(flagMenu1==0 && flagOperandoA ==1)
	        {
	            printf("1_Ingrese el primer operando:  (A=%d) \n",operandoA);
	        }
	        else
	        {
	            printf("1_Ingrese el primer operando:  (A=x) \n");
	        }

	        if(flagMenu2==0 && flagOperandoB ==1)
	        {
	            printf("1_Ingrese el segundo operando:  (B=%d) \n",operandoB);
	        }
	        else
	        {
	            printf("1_Ingrese el segundo operando:  (B=y) \n");
	        }
	        printf("3_calcular todas las operaciones:\n");
	        printf("a)Calcular la suma (A+B) \n ");
	        printf("c)Calcular la division (A/B) \n");
	        printf("d)Calcular la multiplicacion (A*B) \n");
	        printf("e)Calcular el factorial (A!) \n");
	        printf("4_Calcular resultados\n");
	        printf("5_Salir\n\n");
	        printf("Ingrese una opcion: ");
	        fflush(stdin);
	        scanf("%d",&opcion);




	        switch (opcion)
	        {
	        case 1:

	            printf("Ingresa el primer operando: ") ;
	            flagOperandoA=1;
	            fflush(stdin);
	            scanf("%d",&operandoA);
	            system("pause");
	            break;

	        case 2:
	            if(flagOperandoA)
	            {
	                printf("Ingresa el segundo operando:");
	                flagOperandoB=1;
	                fflush(stdin);
	                scanf("%d",&operandoB);
	            }

	            else
	            {
	                printf("Antes de ingresar el segundo operando debe ingresar el primero\n");
	            }
	            system("pause");
	            break;
	        case 3:
	            if(flagOperandoA && !flagOperandoB)
	            {
	                printf("Te falta ingresar el segundo operando para realizar las operaciones\n");
	            }

	            else if (!flagOperandoA && flagOperandoB)
	            {
	                printf("Te falta ingresar el primer operando para realizar las operaciones\n");
	            }
	            else if(!flagOperandoA && !flagOperandoB)
	            {
	                printf("Te faltan ingresar los 2 operandos para realizar las operaciones\n");
	            }
	            else if(flagOperandoA && flagOperandoB)
	            {
	                printf("Calculando operaciones\n");
	                resultadoSuma=suma(operandoA,operandoB);
	                resultadoResta=resta(operandoA,operandoB);
	                resultadoDivision=division(operandoA,operandoB);
	                resultadoMultiplicacion=multiplicacion(operandoA,operandoB);
	                resultadoFactorialA=factorial(operandoA);
	                resultadofactorialB=factorial(operandoB);

	            }

	             system("pause");
	             break;

	        case 4:
	            printf("A_El resultado de la sumas es: %d\n",resultadoSuma);
	            printf("B_El resultado de la resta es: %d\n",resultadoResta);
	            if(operandoB==0)
	                printf("C_No se puede dividir por 0\n");
	            else
	            {
	                printf("C_El resultado de la division es: %.2f\n",resultadoDivision);
	            }
	            printf("D_El resultado de la multiplicacion es: %d\n",resultadoMultiplicacion);
	            printf("E_El factorial de A es: %d y el factorial B es: %d\n",resultadoFactorialA,resultadofactorialB);

	           flagOperandoA=0;
	           flagOperandoB=0;

	             system("pause");
	             break;
	        case 5:
	             salir=5;
	             break;
	        }
	    }
	    while(salir==0);


	    return opcion;
	}




