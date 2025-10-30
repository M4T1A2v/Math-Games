#include "./menu.h"
#include "./utils.h" 

void menu_principal(const char *nombre_usuario)
{
	system(CLEAR);
	printf("\n%s===========================================================%s", 
		   BLUE, RESET);
	printf("\n%s|                                                         |%s",
			BLUE, RESET);
	printf("\n%s                [ BIENVENIDO -> %s%s%s <- ]                %s", 
		    BLUE, YELLOW, nombre_usuario, BLUE, RESET);
	printf("\n%s|                                                         |%s",
			BLUE, RESET);
	printf("\n%s===========================================================%s\n\n", 
		   BLUE, RESET);

	
    
	printf(" %s1 = %sMath-Run   (><) %s-->  Memoriza y suma%s\n", GREEN, CYAN, GREEN, RESET);
	printf("%s-------------------------------------------------%s\n", BLUE, RESET);

	printf(" \n%s2 = %sMath-Jump  (^^) %s-->  Resuelve antes de que se acabe el tiempo%s\n", GREEN, CYAN, GREEN, RESET);
	printf("%s-------------------------------------------------%s\n", BLUE, RESET);

	printf(" \n%s3 = %sMath-Fast  (~~) %s-->  Resuelve la mayor cantidad posible%s\n", GREEN, CYAN, GREEN, RESET);
	printf("%s-------------------------------------------------%s\n", BLUE, RESET);

	printf(" \n%s4 = %sMath-Logic (¿?) %s-->  Recesponde el acertijo correctamente%s\n", GREEN, CYAN, GREEN, RESET);
	printf("%s-------------------------------------------------%s\n", BLUE, RESET);

	printf(" \n%s5 = %sMath-Lucky (@@) %s-->  Gana el que tiene suerte.%s\n", GREEN, CYAN, GREEN, RESET);
	printf("%s-------------------------------------------------%s\n", BLUE, RESET);

	printf("\n %sr = Ranking%s  -->  Muestra la tabla de los mejores puntajes%s\n", MAGENTA, GREEN, RESET);
	printf("\n%s-----------------------------------------------------------%s\n", BLUE, RESET);


	printf("\n %sx = Salir  %s--->  Terminar juego%s\n\n", RED, GREEN, RESET);
	printf("%s===========================================================%s\n", BLUE, RESET);
	printf("%s\nSelecciona una opcion -> %s", YELLOW, RESET);
	
}
