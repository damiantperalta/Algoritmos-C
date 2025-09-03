#include <stdio.h>
#define x 3

/* La Secretaría de Turismo realiza mensualmente el procesamiento de datos relevados diariamente en relación a la cantidad de turistas que 
ingresan a cada uno de los centros turísticos más importantes del país. Para ello se dispone de la siguiente información:

Los centros turísticos son 3, codificados con ‘a’, ‘b’, ‘c’, respectivamente.

Los datos relevados son:
	Día (entero de 1 a 31).
	Código de centro turístico ( ‘a’, ‘b’ ó ‘c’)
	Vía de acceso (1=Auto, 2=Avión, 3=Micro, 4=Tren).
 	Cantidad de Turistas que ingresaron (valor entero)
El programa tiene un menú con las siguientes opciones:
1 – Ingresar datos
2 – Mostrar resultados.
3 – Salir.
Crear una función menú.
Opción 1 – Ingresar datos
Ingresar los datos relevados por teclado. Por cada ingreso de datos, llamar a una función que reciba los 4 datos relevados ingresados 
por teclado y los guarde en 4 vectores, respectivamente.

Opción 2 – Mostrar resultados
Llamar a una función que reciba los 4 vectores cargados en la opción 1, y los utilice para
informar, dado un código de centro turístico ingresado por teclado, la cantidad de turistas de cada quincena y el total de turistas que 
ingresaron por auto de dicho centro.

Utilizar aritmética de punteros en las funciones de las opciones 1 y 2.

Opción 3 – Salir

No se pueden utilizar variables globales.  Mostrar por pantalla de forma clara y prolija.
 */

int menu();
void ventana(int *, int *, int *, char *, int);
void cargar(int *, int *, int *, char *, int, int, int, char, int i);

main() {
	char zx[x]={0};
	int ax[x]={0}, bx[x]={0}, cx[x]={0}, rta, ban=0, i=0;
	int a, b, c, *pa, *pb, *pc;
	char z, *pz;
	
	while(ban==0){
		
	
	
	rta=menu();
	
	switch(rta){
	
	case 1:
		
		system("cls");
	puts("Ingrese dia (Del 1 a 31)");
	fflush(stdin);
	scanf("%i", &a);
	
	puts("Ingrese codigo de centro turistico(a/b/c)");
	fflush(stdin);
	scanf("%c", &z);
	
	puts("Ingrese via de acceso(1=Auto, 2=Avion, 3=Micro, 4=Tren)");
	fflush(stdin);
	scanf("%i", &b);
	
	puts("Ingrese cantidad de turistas que ingresaron");
	fflush(stdin);
	scanf("%i", &c);
	system("cls");
	
	cargar(ax, bx, cx, zx, a, b, c, z, i);
	i++;
    break;
    
    case 2:
    	system("cls");
    	
    	ventana( ax, bx, cx, zx, i);
    	
    system("cls");
	break;

    case 3:
    	system("cls");
    	ban=1;
	puts("Saliendo...");
	break;
}
}
}

/*
Opción 2 – Mostrar resultados
Llamar a una función que reciba los 4 vectores cargados en la opción 1, y los utilice para
informar, dado un código de centro turístico ingresado por teclado, la cantidad de turistas de cada quincena y el total de turistas que 
ingresaron por auto de dicho centro.
*/
void ventana(int *fdia, int *facces, int *fturistas, char *fturistic, int i){ //inicio ventana
	int q1=0, q2=0;
	int toturauto=0;
	int y=0;
	char centro;
	
	puts("Ingrese centro turistico");
	fflush(stdin);
	scanf("%c", &centro);
	
	for(y=0;y<i;y++){//inicio for
		switch(centro){//inicio switch
			case 'a':
				if(*(fturistic+y)=='a'){ //inicio if 2
				
					if(*(facces+y)==1){
					toturauto++;
				} 
					if(*(fdia+y)>=15){ //if 3
						q1=q1+*(fturistas+y);
					} //fin if 3
					else{ //if 4
						q2=q2+*(fturistas+y);
					} //fin if 4
				} //finalizo if 2
				break;
			case 'b':
					if(*(fturistic+y)=='b'){
						
							if(*(facces+y)==1){
					toturauto++;
				} 
					if(*(fdia+y)>=15){
						q1=q1+*(fturistas+y);
					}
					else{
						q2=q2+*(fturistas+y);
					}
				}
				break;
			case 'c':
			
					if(*(fturistic+y)=='c'){
						
							if(*(facces+y)==1){
					toturauto++;
				} 
					if(*(fdia+y)>=15){
						q1=q1+*(fturistas+y);
					}
					else{
						q2=q2+*(fturistas+y);
					}
				}
				break;
		}
	}
		printf("Centro turistico elegido para mostrar: %c\n", centro);
		printf("La cantidad de turistas de la primera quincena: %i\n", q1);
		printf("La cantidad de turistas de la segunda quincena: %i\n", q2);	
		printf("el total de turistas que ingresaron por auto de dicho centro: %i\n", toturauto);
		system("pause");
	
	}

void cargar(int *pa, int *pb, int *pc, char *pz, int a, int b, int c, char z, int i){ //inicio cargar
	*(pa+i)=a;
	*(pb+i)=b;
	*(pc+i)=c;
	*(pz+i)=z;
}

int menu(){ //inicio menu
	int rta;
puts("1 - Ingresar datos");
puts("2 - Mostrar resultados");
puts("3 - Salir.");
fflush(stdin);
scanf("%i", &rta);
return rta;
}


