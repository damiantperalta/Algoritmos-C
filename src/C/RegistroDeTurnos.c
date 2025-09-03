#include<stdio.h>
#include<stdlib.h>				
#include<conio.h>
#include<math.h>
#include<string.h>
#define tam 25

void registro(int*, int*, int*, int);
void vcarga(int, int, int, int*, int*, int*, int);
int turno(int, int*);
int menu();

main()
{
	int ndni, codesp, opcion = 0, vturnos[4]={5,5,5,5}, validacion = 0, social = 1000, part = 5000, vdni[tam]={0}, vcodesp[tam]={0}, vmonto[tam]={0}, i=0;
	char tcob;
	
	opcion = menu();
		
	while(opcion!=2) 
	{
		switch(opcion)
		{
			case 1:
				printf("INGRESE EL NUMERO DE DNI: ");
				fflush(stdin);
				scanf("%d",&ndni);
				printf("INGRESE EL CODIGO DE ESPECIALIDAD (1 AL 4): ");
				fflush(stdin);
				scanf("%d",&codesp);
				printf("INGRESE EL TIPO DE COBERTURA:\n'O' = OBRA SOCIAL \n'P' = PARTICULAR \nOPCION SELECCIONADA: ");
				fflush(stdin);
				scanf("%c",&tcob);
				
				validacion = turno(codesp,vturnos);
				
				if(validacion == 0)
				{
					if(tcob == 'O')
					{
						printf("\n\nEL MONTO A  ABONAR ES : %d",social);
						
						vcarga(ndni,codesp,social,vdni,vcodesp,vmonto,i);
							
						i++;
						break;		
					}
					else if(tcob == 'P')
					{
						printf("\n\nEL MONTO A  ABONAR ES : %d",part);
			
						vcarga(ndni,codesp,social,vdni,vcodesp,vmonto,i);
							
						i++;
						break;
					}
					
				}
				else if(validacion == 1)
				{
					printf("\n\n! TURNO NO ASIGNADO !\n\n");
					system("pause");
					system("cls");
					break;
				}
				
		    case 2:
			opcion = 2;
			break;
		}
		opcion = menu();
	}
	registro(vdni, vcodesp, vmonto, i);	
}

int menu()
{
    int inicio;
    
   	printf("\n*********MENU************");
    printf("\n1-REGISTRAR UNA SOLICITUD DE TURNO\n");
    printf("2-SALIR\n");
    printf("OPCION SELECCIONADA: ");
    scanf("%d",&inicio);
    
    return (inicio);
    system("cls");
}

int turno(int esp,int *vturnos)
{
//	int resul=10;   /*LE PONGO 10 PARA QUE NO SE CONFUNDA CON "0" = SI HAY TURNOS "1"= NO HAY TURNOS*/
	int resul;
	
	switch(esp)
	{
		case 1:
			
				/* 5,4,3,2,1,0 */
			if(*(vturnos+0) <= 5 && *(vturnos+0) > 0)
			{	
				*(vturnos+0) = *(vturnos+0) - 1;
				
				resul = 0;
				
				return(resul);
				break;
			}
			else 
			{
				resul = 1;
				return(resul);
				break;
			}
			
		case 2:
			
			if(*(vturnos+1) <= 5 && *(vturnos+1) > 0)
			{			
				*(vturnos+1) = *(vturnos+1) - 1;
				
				resul = 0;
				
				return (resul);
				break;	
			}
			else 
			{
				resul = 1;
				return(resul);
				break;
			}			
			
		case 3:
				
			if(*(vturnos+2) <= 5 && *(vturnos+2) > 0)
			{
				*(vturnos+2) = *(vturnos+2) - 1;	
				
				resul = 0;
				
				return (resul);
				break;
			}
			else 
			{
				resul = 1;
				return(resul);
				break;
			}
			
		case 4:
			
			if(*(vturnos+3)<=5&&*(vturnos+3) >0)
			{
				*(vturnos+3) = *(vturnos+3) - 1;
				
				resul = 0;
				
				return (resul);
				break;
			}
			else 
			{
				resul = 1;
				return(resul);break;
			}	
	}
}

void vcarga(int x, int y, int z, int *vdni, int *vcodesp, int *vmonto, int j)
{
	*(vdni+j) = x;
	*(vcodesp+j) = y;
	*(vmonto+j) = z;
	
	printf("\n\n! TURNO ASIGNADO !\n\n");
	system("pause");
	system("cls");
}

void registro(int *vdni,int *vcodesp,int *vmonto,int j)
{
	int s = 0;
	
	system("cls");
	
	for(s=0;s<j;s++)
	{
		printf("\n*************TURNO N%d*******************\n",s);
		printf("\nDNI: %d",*(vdni+s));
		printf("\nCODIGO DE ESPECIALIDAD: %d",*(vcodesp+s));
		printf("\nMONTO A PAGAR: %d\n\n",*(vmonto+s));
	}
	system("pause");
}

