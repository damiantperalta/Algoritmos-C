
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

		//PROTOTIPO DE FUNCIONES
int FAVE (int);
int FRES (int);
int FCERDO(int);
float DESCUENTO(float);
void MASKGVENDIDO(float, float, float);
void MENORCORTEVENDIDO(int, char[]);


void main (){
	
	float Peso, Importe, TotalVenta, Descuento, TotalDescuentos = 0, TotalDia = 0, SubTotal = 0;
	int Corte, ContArticulo, TipoAve = 0, TipoRes = 0, TipoCerdo = 0, PrecioCorte;
	int Band = 0, MenorCorte;
    char Rta[3], Carne[6], MenorCarne[6];
	
	printf("Buenos dias desea abrir caja? (Si/No): ");
	fflush(stdin);
	scanf("%s", Rta);
	strlwr(Rta);	//Convierte la cadena en minúsculas.
	
	while(strcmp(Rta,"si") == 0){		//Ciclo día laboral
		
		printf (" \n Si inicia una venta? ingrese un articulo (Si/No): ");
		fflush(stdin);
		scanf("%s", Rta);
		strlwr(Rta);	//Convierte la cadena en minúsculas.
		
		ContArticulo = 0;
		TotalVenta = 0;
		
		while(strcmp(Rta, "si") == 0){		//Ciclo por venta
	
			printf("\n Ingrese tipo de carne (Ave/Cerdo/Res):  ");
			fflush(stdin);
			scanf("%s", Carne);
			strlwr(Carne);	//Convierte la cadena en minúsculas.
	
			/* pase el ingreso de kilos entro de cada condicion*/
	
			if(strcmp(Carne,"ave") == 0){
		
	 			printf("\n Ingrese tipo de corte: \n\n Mila(1), Trozado(2), Pata y muslo(3) y Alitas(4): ");
				fflush(stdin);
				scanf("%i", &Corte);
				
				printf("\n Ingrese el peso en kg:  ");
				fflush(stdin);
				scanf("%f", &Peso);
			
				TipoAve += Peso;				// Acumula Kg por Tipo de carne
				PrecioCorte = FAVE(Corte);		//Devuelve el precio segun corte elegido
				Importe = PrecioCorte * Peso;	//Calcula importe de ese pedido
	
			} 
			else if(strcmp(Carne, "cerdo" )== 0){
		
					printf("\n Ingrese tipo de corte: \n\n Bondiola(1), Pechito(2), Paleta(3) y Costilla(4):   ");
					fflush(stdin);
					scanf("%i", &Corte);
					
					printf("\n Ingrese el peso en kg:  ");
					fflush(stdin);
					scanf("%f", &Peso);
					
					TipoCerdo += Peso;				// Acumula Kg por Tipo de carne
					PrecioCorte = FCERDO(Corte);	//Devuelve el precio segun corte elegido
					Importe = PrecioCorte * Peso;	//Calcula importe de ese pedido
					
	
				}
				else if(strcmp(Carne,"res")==0){
						
						printf("\n Ingrese tipo de corte: \n\n Vacio(1), Asado(2), Bola de Lomo(3) y Picada(4): ");
						fflush(stdin);
						scanf("%i", &Corte);
						
						printf("\n Ingrese el peso en kg:  ");
						fflush(stdin);
						scanf("%f", &Peso);
						
						TipoRes += Peso;				// Acumula Kg por Tipo de carne
						PrecioCorte = FRES(Corte);		//Devuelve el precio segun corte elegido
						Importe = PrecioCorte * Peso;	//Calcula importe de ese pedido
			
					}
					
			if (Band == 0){
				MenorCorte = PrecioCorte;
				strcpy(MenorCarne, Carne);
				Band = 1;
			}
			else if (PrecioCorte < MenorCorte){		//Buscamos el precio del menor corte vendido
				MenorCorte = PrecioCorte;	//Retiene el nuevo precio menor
				strcpy(MenorCarne, Carne);	//Retiene el tipo de carne
				}
					
			ContArticulo ++;		//Contador cantidad de articulos vendidos de una venta
			TotalVenta += Importe;	//Acumula el total de una venta
					
			printf ("\n Va a ingresar otro articulo? Si/No): ");	//Condicion de cierre solo de esa venta
			fflush(stdin);
			scanf("%s", Rta);
			strlwr(Rta);	//Convierte la cadena en minúsculas.
					
		}	//fin while venta
		
		Descuento = DESCUENTO(TotalVenta);	//Calcula el descuento sobre la compra y lo asigna
		TotalDescuentos += Descuento; 		//Acumula los descuentos de todo el dia
		SubTotal = TotalVenta;				
		TotalVenta -= Descuento;	//Total venta menos el descuento
		TotalDia += TotalVenta;		//Acumula las ventas de todo el dia
		
		printf("\n Cantidad de articulos: %i \n El Subtotal es: $%.2f \n El Descuento es: $%.2f \n Importe a cobra: $%.2f \n", ContArticulo, SubTotal, Descuento, TotalVenta);
		
		printf("\n Desea mantener la caja abierta? Si/No): ");	//Condicion de cierre de todo el dia
		fflush(stdin);
		scanf("%s", Rta);
		strlwr(Rta);	//Convierte la cadena en minúsculas.
	
	}//Fin while caja/Dia
	
	if (Band != 0){
		
		MASKGVENDIDO(TipoAve, TipoRes, TipoCerdo);	//Selecciona y Muestra el Tipo de carne mas vendida
		printf("\n El corte mas economico vendido fue: ");
		MENORCORTEVENDIDO(MenorCorte, MenorCarne);				//Selecciona y muestra el menor corte vendido
	
		printf("\n Importe total de todas las ventas (con descuentos si los hubo): $%.2f", TotalDia);
		printf("\n Importe total de todos los descuentos: $%.2f \n\n", TotalDescuentos);
	}
	else printf("\n No se realizaron ventas.\n\n");
		system("pause");
	
}	// Fin main

int FAVE (int corte){	//Selecciona el corte elegido de AVE y devuelve su precio
	
	switch(corte){
		
		case 1: return 300;
		break;
		
		case 2: return 450;
		break;
			
		case 3: return 490;
		break;
		
		case 4: return 220;
		break;
	}//Fin switch
	
}	//Fin Funcion FAVE

int FRES (int corte){	//Selecciona el corte elegido de RES y devuelve su precio
	
	switch(corte){
		
		case 1: return 1600;
		break;
		
		case 2: return 1400;
		break;
			
		case 3: return 1100;
		break;
		
		case 4: return 1000;
		break;
		
	}//Fin switch
	
}	//Fin Funcion FRES

int FCERDO (int corte){	//Selecciona el corte elegido de CERDO y devuelve su precio
	
	switch(corte){
		
		case 1: return 1500;
		break;
		
		case 2: return 1300;
		break;
			
		case 3: return 1200;
		break;
		
		case 4: return 1150;
		break;
		
	}//Fin switch
	
}	//Fin Funcion FCERDO

float DESCUENTO(float subtotal){	//Calcula si hay descuento a aplicar y lo devuelve
	
	float descuento = 0;
	
	if ((subtotal > 5000) && (subtotal <= 10000)) descuento = subtotal * 0.05;
	if (subtotal > 10000) descuento = subtotal * 0.1;
	
	return descuento;
}//Fin funcion DESCUENTO

void MASKGVENDIDO(float ave, float res, float cerdo){	//Selecciona la carne que mas kg vendio y muestra el tipo y los kgs
	
	if (ave > res && ave > cerdo) printf("\n El tipo de carne que mas Kg vendio es: Ave con %.2f Kg", ave);
		else if (res > ave && res > cerdo) printf("\n El tipo de carne que mas Kg vendio es: Res con %.2f Kg", res);
			else printf("\n El tipo de carne que mas Kg vendio es: Cerdo con %.2f Kg", cerdo);
	
}// Fin funcion MASKGVENDIDO

void MENORCORTEVENDIDO(int menorprecio, char menorcarne[6]){	//Muestra el nombre del corte de menor precio vendido
	
	char corte[20];
	
	switch (menorprecio){
		
		case 300: strcpy(corte, "Milanesa ");
		break;
		
		case 220: strcpy(corte, "Alitas ");
		break;
		
		case 450: strcpy(corte, "Trozado ");
		break;
		
		case 490: strcpy(corte, "Pata y Muslo ");
		break;
		
		case 1500: strcpy(corte, "Bondiola ");
		break;
		
		case 1300: strcpy(corte, "Pechito ");
		break;
		
		case 1200: strcpy(corte, "Paleta ");
		break;
		
		case 1150: strcpy(corte, "Costilla ");
		break;
		
		case 1600: strcpy(corte, "Vacio ");
		break;
		
		case 1400: strcpy(corte, "Asado ");
		break;
		
		case 1100: strcpy(corte, "Bola de Lomo ");
		break;
		
		case 1000: strcpy(corte, "Picada ");
		break;
	}//Fin swith
	
	strupr(menorcarne);	//Convierte toda la cadena en mayusculas
	
	strcat(corte, "de "); //Concatena el tipo de corte con de
	strcat(corte, menorcarne);	//Concaten con el tipo de carne
	
	printf("%s a $%i por Kg. ", corte, menorprecio);
	
}	//Fin Funcion MENORCORTEVENDIDO
