#include <stdio.h>
#define x 50

/* */

int menu();
void carga(int *, int *, char *, int, int, char, int);
void informa(int *, int *, char *, int);

main() {
	char destino[x]={0}, d;
	int cantidad[x]={0}, pack[x]={0}, c, p, rta, i=0;
	
	
	do {
	rta=menu();
	
	switch(rta){
		case 1:
			puts("Ingrese destino(F=fin de anio/R=rio/M=Montevideo)");
			fflush(stdin);
			scanf("%c", &d);
				puts("Ingrese cantidad de pasajeros");
			fflush(stdin);
			scanf("%i", &c);
				puts("Incluye pack de bebidas?(1=Si/2=No)");
			fflush(stdin);
			scanf("%i", &p);
			
			carga(cantidad, pack, destino, c, p, d, i);
			i++;
			system("cls");
			break;
		case 2:
			informa(cantidad, pack, destino, i);
			system("pause");
			system("cls");
			break;
	}}
	while(rta!=3);
	puts("Saliendo...");
	
}

int menu(){
	int rta;
		puts("1-Ingresar datos.");
	puts("2-Informar Costos del viaje.");
	puts("3-Salir.");
	fflush(stdin);
	scanf("%i", &rta);
	system("cls");
	return rta;
}

void carga(int *a, int *b, char *c, int aa, int bb, char cc, int i){
	*(a+i)=aa;
	*(b+i)=bb;
	*(c+i)=cc;
}

void informa(int *a, int *b, char *c, int i){
	int y, Total=0, Costo=0, Adicional=0, Pasajeros=0, F=0, M=0, R=0;
	char dest;
	for(y=0;y<i;y++){
		dest=*(c+y);
		switch(dest){
			case 'F':
				Pasajeros=*(a+y);
				Costo=2240*Pasajeros;
			break;
			case 'R':
				Pasajeros=*(a+y);
				Costo=908*Pasajeros;
			break;
			case 'M':
				Pasajeros=*(a+y);
				Costo=1240*Pasajeros;
			break;
		}
		
		if(*(b+y)==1){
			Adicional=300*Pasajeros;
			Costo=Costo+Adicional;
		}
		
		printf("El costo del mismo es: %i U$D\n", Costo);
		printf("La cantidad de pasajes solicitados: %i\n", *(a+y));
		if(*(c+y)=='F'){
			puts("Destino: 8 noches Crucero Fin De Anio.\n\n");
			F=F+*(a+y);
		}
	else	if(*(c+y)=='R'){
			puts("Destino: 8 noches Rio de Janeiro, Buzios, Ihlabela.\n\n");
				R=R+*(a+y);
		}
		else{
			puts("Destino: 8 noches Rio de Janeiro, Montevideo.\n\n");
				M=M+*(a+y);
		}
		Total=Total+Costo;
	}
	printf("El costo total de los pasajes: %i U$D\n", Total);
	printf("La cantidad total de pasajes solicitados para Fin de Anio: %i\n", F);
	printf("La cantidad total de pasajes solicitados para Rio de Janeiro, Buzios: %i\n", R);
	printf("La cantidad total de pasajes solicitados para Rio de Janeiro, Montevideo: %i\n", M);
}
