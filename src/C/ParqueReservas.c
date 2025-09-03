#include <stdio.h>
#define x 50
/*  */

int menu();

void carg(int *, int *, char *, int, int, char, int);

void informa(int *, int *, char *, int);

 main() {
int cel[x]={0}, edad[x]={0}, c, e;
char visita[x]={0}, v;
int rta, i=0;

rta=menu();
while(rta!=3){
	
switch(rta){
	
	case 1:
		
		puts("Ingrese el numero de celular");
		fflush(stdin);
		scanf("%i", &c);
		
		puts("Ingrese edad");
		fflush(stdin);
		scanf("%i", &e);
		
		puts("Incluye visita guiada?(S/N)");
		fflush(stdin);
		scanf("%c", &v);
		
		carg(cel, edad, visita, c, e, v, i);
		
		i++;
		system("cls");
		rta=menu();
	break;
	
	case 2:
		
		informa(cel, edad, visita, i);
		system("pause");
		system("cls");
		rta=menu();
		
	break;
	
}
}
puts("Saliendo...");
}

int menu(){
	int rta;
	puts("1-Registrar una reserva de entrada al parque nacional.");
	puts("2-Informar costo de entradas e base a las reservas registradas.");
	puts("3-Salir.");
	fflush(stdin);
	scanf("%i", &rta);
	system("cls");
	return rta;
}

void carg(int *celu, int *edad, char *visi, int c, int e, char v, int i){
	*(celu+i)=c;
	*(edad+i)=e;
	*(visi+i)=v;
}

void informa(int *cel, int *edad, char *visita, int i){
	int y, pre, adicional, Total, cont=0;
	
		for(y=0;y<i;y++){
			Total=0;
			adicional=0;
			
			if(*(edad+y)<18){
				pre=2000;
			}
			else{
				pre=3000;
			}
			if(*(visita+y)=='S'){
				adicional=1500;
				if(*(edad+y)>=18){
				cont++;
			}
			}
			Total=adicional+pre;
			printf("El numero de celular es: %i\n", *(cel+y));
			printf("El costo de la entrada es: %i\n", Total);
		}
		printf("La cantidad de adultos que hicieron pedido de reserva con visita guiada es: %i\n", cont);
}
