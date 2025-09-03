#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Calculadora
Se solicita efectuar un programa para una m�quina calculadora.
La m�quina calculadora puede efectuar las siguientes operaciones: suma, resta,
multiplicaci�n y divisi�n de dos operandos.
Para cada operaci�n, el operador debe ingresar los siguientes datos:
Operando1: un n�mero real.
Operando2: un n�mero real.
Tipo de operaci�n: suma, resta, multiplicaci�n y divisi�n. Cada operaci�n puede ser
representada por un car�cter. Por ejemplo la suma puede indicarse a trav�s del car�cter 's',
la resta a trav�s del car�cter 'r', la multiplicaci�n a trav�s del car�cter �m� y la divisi�n a
trav�s del car�cter �d�.
Se ingresan operaciones mientras el operador indique �SI� a la pregunta: �Desea seguir
ingresando operaciones SI/NO?
Se pide informar:
Por cada operaci�n: calcular el resultado de la misma e informarlo por pantalla: Para ello se
deber� dise�ar una funci�n, que reciba como par�metros los dos operandos y el car�cter
correspondiente al tipo de operaci�n. La funci�n deber� retornar al programa principal el
resultado. Para informar el resultado en el programa principal, se deber� dise�ar otra
funci�n, que tendr� como par�metro el valor resultado, y lo mostrar� por pantalla.*/
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
