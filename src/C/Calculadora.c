#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Calculadora
Se solicita efectuar un programa para una máquina calculadora.
La máquina calculadora puede efectuar las siguientes operaciones: suma, resta,
multiplicación y división de dos operandos.
Para cada operación, el operador debe ingresar los siguientes datos:
Operando1: un número real.
Operando2: un número real.
Tipo de operación: suma, resta, multiplicación y división. Cada operación puede ser
representada por un carácter. Por ejemplo la suma puede indicarse a través del carácter 's',
la resta a través del carácter 'r', la multiplicación a través del carácter ´m´ y la división a
través del carácter ´d´.
Se ingresan operaciones mientras el operador indique “SI” a la pregunta: “Desea seguir
ingresando operaciones SI/NO?
Se pide informar:
Por cada operación: calcular el resultado de la misma e informarlo por pantalla: Para ello se
deberá diseñar una función, que reciba como parámetros los dos operandos y el carácter
correspondiente al tipo de operación. La función deberá retornar al programa principal el
resultado. Para informar el resultado en el programa principal, se deberá diseñar otra
función, que tendrá como parámetro el valor resultado, y lo mostrará por pantalla.*/
float calcular(float a, char operador, float b){
	float Resultado;
	switch(operador){
		case '-' :
		Resultado = a-b;
	    break;
	    case '+' : 
	    Resultado = a+b;
	    break; 
	    case '/' :	
	    Resultado = a/b;
	    break;
	    case '*' :	
	    Resultado = a*b;
	    break; 
	}
	return Resultado;
}
void Mostrar(float Cartel){

printf ("El resultado es: %.2f\n", Cartel);
}
int sintax(char operador){
	int Aprobar;
	switch(operador){
		case '-' :
		Aprobar=1;
	    break;
	    case '+' : 
	    Aprobar=1;
	    break; 
	    case '/' :	
	    Aprobar=1;
	    break;
	    case '*' :	
	    Aprobar=1;
	    break; 
	    default:
	    Aprobar=0;
	    break;
	}
return Aprobar;
	}

main() {
	float n1, n2, Resultado;
	char ope, RTA [2];
	int error;
	char Si[2] = "Si";
	printf("Desea ingresar una operacion? (Si/No) \n");
	fflush(stdin);
	scanf("%s", &RTA);
	
	while (!strcmp (RTA, Si) != 0){
	
	
	
	printf("Ingrese la operacion matematica: \n");
	fflush(stdin);
	scanf("%f %c %f", &n1, &ope, &n2);
	
	error=sintax(ope);
	if(sintax(ope)-1==0){
	
	
	
	Resultado=calcular(n1, ope, n2);
	Mostrar(Resultado);
	printf("Desea seguir ingresando operaciones Si/No?\n");
	fflush(stdin);
	scanf("%s", &RTA);}
	
	else{
		puts ("ERROR DE SINTAXIS\n");
		printf("Desea seguir ingresando operaciones Si/No?\n");
	fflush(stdin);
	scanf("%s", &RTA);}
	}
}
