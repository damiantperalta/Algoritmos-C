#include <stdio.h>
#include <stdlib.h>
#define tema 7

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	void carga(int *);
	void premio(int *, int *);
	void menorventa(int *);
	
 main() {
 	int *pago1[tema]={0}, *pago2[tema]={0};
 	int y;
 	
 	puts("Cajera 1");
 	carga(pago1);
 	puts("Cajera 2");
 	carga(pago2);
 	premio(pago1, pago2);
 	puts("Cajera 1");
 	menorventa(pago1);
 	puts("Cajera 2");
 	menorventa(pago2);
}

void carga(int *v){
	int i, numero;
	for(i=0;i<tema;i=i+1){
		printf("ingrese el total de la cajera del dia %i\n", i+1);
		fflush(stdin);
		scanf("%d", &numero);
		*(v+i)=numero;
	}
}

void premio(int *z, int *x){
	int total1=0, total2=0;
	int i, max;
	for(i=0;i<tema;i++){
		total1=total1+*(z+i);
		total2=total2+*(x+i);
	}
	if (total2<total1){
		puts("La cajera 1 se lleva el premio");
	}
	else{
		puts("La cajera 2 se lleva el premio");
	}
	
}

void menorventa(int *p1){
	int minimo, pmin;
	int y;
	for(y=0;y<tema;y++){
		if(minimo>*(p1+y)){
			minimo=*(p1+y);
			pmin=y;
		}
	}
	printf("El dia de menor venta fue %d\n", pmin+1);
}
