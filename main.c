//MARTA RETANA DDVJ 1.4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>//AÑADO LA FUNCION STRING.H PARA USAR LAS FUNCIONES STRCAT, STRLEN Y STRCMP
//MARTA RETANA DDVJ 1.4

int menu(){
	
	int opc = 3;
	
	do{//INICIO DEL CONTROL ERRORES
		
		
		system("cls");
		
		if(opc < 1 || opc > 3){ //EN CASO DE ERROR
			
			printf("ERROR: EL NUMERO INTRODUCIDO DEBE ESTAR ENTRE 1 y 3\n\n");
			
		}	
			
		printf("Bienvenido, que deseas hacer?\n\n");
		printf("1.- Introducir lista de correos\n");
		printf("2.- Generar lista de correos\n");
		printf("3.- Salir\n\n");
		printf("Escoge una opcion:	");
		fflush(stdin); scanf("%i", &opc);
		
	}while(opc < 1 || opc > 3); //INICIO DEL CONTROL DE ERRORES
	
	return opc; //DEVUELVO AL MAIN LA OPCION ESCOGIDA.
	
}

int control_igual(int emails_introducidos, char email[29][255]){
	
	int i;
	int error = 0;
	
	for(i = (emails_introducidos - 1) ; i >= 0; i--){//BUCLE PARA COMPARAR LOS EMAILS YA INTRODUCIDOS, VA DESDE EL NUMERO DE EMAILS INTRODUCIDOS - 1 (PARA QUE NO SE COMPARE EL MISMO EMAIL) HASTA 0
		
			if( strcmp(email[emails_introducidos], email[i]) == 0 ){//USO LA FUNCION STRCMP PARA VER SI LAS CADENAS DE TEXTO SON IGUALES, SI SON IGUALES LA FUNCION DEVUELVE EL VALOR 0
				
				error++;
				i = 0;//FUERZO LA SALIDA DEL BUCLE
				
			}
			
	}
		
	return error; // DEVUELVO EL ERROR
	
}

int control_punto(int emails_introducidos, char email[29][255]){
	
	int error = 0;
	int longitud;
	
	longitud = strlen(email[emails_introducidos]);//CALCULO CON STRLEN LA LONGITUD DE LA CADENA
	
	if(email[emails_introducidos][longitud - 3] != '.' && email[emails_introducidos][longitud - 4] != '.'){//COMPRUEBLO QUE EN LA LONGITUD - 3 O -4, HAY ALGUN PUNTO, SINO ERROR
		
		error++;
			
	}
		
	return error;//DEVUELVO EL ERROR
	
}

int control_arroba(int emails_introducidos, char email[29][255]){
	
	int error = 0;
	int i;
	int correcto = 0;
	int longitud;
	
	longitud = strlen(email[emails_introducidos]);//CALCULO LA LONGITUD DE LA CADENA
	
	for(i = 0; i <= longitud; i++){//BUCLE QUE RECORRE TODOS LOS CARACTERES DE LA CADENA DE TEXTO
	
		if(email[emails_introducidos][i] == '@'){//SI ENCUENTRA EL CARACTER '@', AÑADE 1 A LA VARIABLE CORRECTO
			
			correcto ++;
			
		}
		
	}
	
	if (correcto == 1){//SI HAY SOLAMENTE UN '@' NO HAY ERROR
		
		error = 0;
		
	} else {//SI HAY MAS DE UN '@' EXISTE UN ERROR
		
		error = 1;
		
	}
		
		
	return error;
	
}

void introducir_emails(char email[29][255]){
	
	int emails_introducidos; //CREO UNA VARIABLE PARA LLEVAR LA CUENTA DE LOS EMAILS INTRODUCIDOS
	int error;
	
	
	for(emails_introducidos = 0	; emails_introducidos <= 29; emails_introducidos++){ //BUCLE PARA INTRODUCIR UNO A UNO TODOS LOS EMAILS
		
		do{//BUCLE PARA CONTROLAR LOS ERRORES
			
			error = 0;
			
			printf("Introduce el email numero %i: ", emails_introducidos + 1);
			fflush(stdin); gets(email[emails_introducidos]);//INTRODUCE EL EMAIL CORRESPONDIENTE
			
			error = error + control_igual(emails_introducidos, email);//CONTROL DE ERRORES, AÑADO EL VALOR DE LA FUNCION, A LA VARIABLE ERROR
			error = error + control_punto(emails_introducidos, email);//CONTROL DE ERRORES, AÑADO EL VALOR DE LA FUNCION, A LA VARIABLE ERROR
			error = error + control_arroba(emails_introducidos, email);//CONTROL DE ERRORES, AÑADO EL VALOR DE LA FUNCION, A LA VARIABLE ERROR
			
			
		}while(error != 0);//SI HAY ALGUN ERROR, REPITE EL EMAIL
		
	}
	
}
	
void unir_emails(char email[29][255]){
	
	char lista[7395];//CREO UNA SOLA LISTA DE 7395 CARACTERES (29 * 255)
	int i;
	
	for(i = 0; i <= 29; i++){
		
		
		strcat( lista, email[i] );//AÑADO EN LA CADENA LISTA, EL EMAIL CORRESPONDIENTE
		strcat( lista, "," );//AÑANDO UNA ',' DESPUES
		
	}
	
	
	system("cls");
	
	printf("%s", lista);//PINTO TODA LA LISTA
	
	printf("\n\n");
	
	system("pause");
	
}
			
int main(int argc, char *argv[]) {
	
	char email [29][255]; //DECLARO UN ARRAY DE CADENAS PARA ALMACENAR TODOS LOS EMAILS
	int opc;
	
	
	
	do{
		
		opc = menu(); //LLAMO A LA FUNCION MENU, PARA ESCOJER UNA OPCION
	
		switch (opc) {
			
			case 1:
				
				introducir_emails(email); //llAMO A LA FUNCION introducir_emails, Y LE PASO TODO EL ARRAY COMPLETO
				break;
				
			case 2: 
			
				unir_emails(email); //llAMO A LA FUNCION unir_emails, Y LE PASO TODO EL ARRAY COMPLETO
				break;
			
		}
		
		
	}while(opc != 3); //SI ES UN 3 SE ACABA EL PROGRAMA
	
	
	
	
	return 0;
}
