#include <stdio.h>
#include <stdlib.h>
#define x 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu();
cargo(int, char, int, int *, char *, int *, int i);
primero(int *, char *, int *, int i);

main() {
int pilo, minu, vpilo[x]={0}, vminu[x]={0}, i=0, rta;
char escu, vescu[x]={0};

rta=menu();
	system("cls");
	while(rta!=3){
		switch(rta){
			case 1:
				puts("Ingresa el numero del piloto.");
				fflush(stdin);
				scanf("%d", &pilo);
				
				puts("Escuderia a la que pertenece el auto(M=MacLaren/F=Ferrari/W=Williams)");
				fflush(stdin);
				scanf("%c", &escu);
				
				puts("Ingresa el tiempo en minutos.");
				fflush(stdin);
				scanf("%d", &minu);
				
				cargo(pilo, escu, minu, vpilo, vescu, vminu, i);
				i++;
				system("cls");
				break;
			case 2:
				primero(vpilo, vescu, vminu, i);
				system("cls");
				break;
		}
		rta=menu();
		
	}
	system("cls");
	puts("Saliendo..."); 
}

int menu()
{
    int rta;
    
   	puts("\n--------------MENU--------------");
    puts("\n1-Registrar tiempos de la carrera de los pilotos.");
    puts("2-Emitir listado de pilotos en el podio.");
    puts("3-Salir.\n");
    fflush(stdin);
    scanf("%d",&rta);
    system("cls");
    return rta;
}

cargo(int p, char e, int m, int *pi, char *es, int *mi, int j){
	
	*(pi+j) = p;
	*(es+j) = e;
	*(mi+j) = m;
		system("cls");
}

primero(int *pilo, char *escu, int *minu, int j){
	system("cls");
	int i, ban=0, ban2=0;
	int primermi, primerpi, segundomi, segundopi;
	char primeres, segundoes;
	
	for(i=0;i<j;i++){
		if (ban==0){
			primermi=*(minu+i);
			primeres=*(escu+i);
			primerpi=*(pilo+i);
			ban=1;
		}
		else{
			if(primermi>*(minu+i)){
			primermi=*(minu+i);
			primeres=*(escu+i);
			primerpi=*(pilo+i);	
			}
		}
	}
	
	for(i=0;i<j;i++){
		if(ban2==0){
		
		if(*(minu+i)>primermi){
	segundomi=*(minu+i);
	segundoes=*(escu+i);
	segundopi=*(pilo+i);
			ban2=1;
		}
	}
	
	if(*(minu+i)>primermi){
		if(*(minu+i)<segundomi){
	segundomi=*(minu+i);
	segundoes=*(escu+i);
	segundopi=*(pilo+i);
		}
	}
			
	}
	
	
	printf("El numero del piloto que obtuvo el primer puesto: %d\nLa escuderia: %c\nY el tiempo en minutos: %d\n\n", primerpi, primeres, primermi);
	printf("El numero del piloto que obtuvo el segundo puesto: %d\nLa escuderia: %c\nY el tiempo en minutos: %d\n\n", segundopi, segundoes, segundomi);
		system("pause");
			system("cls");
}
