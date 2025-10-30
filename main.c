// main.c (inicio)


// gcc main.c menu.c inicio_seccion.c jugadores_registrados.c buscar_por_id.c math_fast.c math_jump.c math_run.c math_logic.c math_lucky.c utils.c score.c compat.c escribir_con_tiempo.c funciones.h -o mathgames.exe -lwinmm
// .\mathgames.exe

#include "./inicio_seccion.h" // Actualizacion...
#include "./utils.h"
#include "./score.h" 

#include "./funciones.h"

int main(void)
{
	configurar_consola();
	srand(time(NULL));
	
	short total = 0;
	short *resultado_total = &total;
	char tecla_presionada = '\0';

	//const char *inicio_seccion(void);
	const char *id_jugador = inicio_seccion();
	const char *nombre_jugador = buscar_por_id(id_jugador);
	esperar_enter();

	do
	{
		menu_principal(nombre_jugador);
		tecla_presionada = leer_tecla();
		if (tecla_presionada == '\n') {
			tecla_presionada = leer_tecla();
		}
		
		switch(tecla_presionada)
		{
				
		case '1':
			limpiar_pantalla();
			
			printf("%s=================================================%s\n", 
				   CYAN, RESET);
			printf("%s|               M A T H - R U N                   |%s\n", 
				   GREEN, RESET);
			printf("%s=================================================%s\n", 
				   CYAN, RESET);
			
			printf("\n%sOBJETIVO:%s Recordar los numeros revelados para sumarlos.%s\n",
				   YELLOW, GREEN, RESET);
			printf("%sREGLAS:%s Se revelaran los terminos individualmente por segundos.%s\n",
				   YELLOW, GREEN, RESET);
			
			printf("\n%s-------------------------------------------------%s\n", BLUE, RESET);
			printf("\n%sENTER%s = CONTINUAR%s", BLUE, GREEN, RESET);
			printf("\n%sv %s= VOLVER AL MENU PRINCIPAL%s", YELLOW, GREEN, RESET);
			printf("\n%s-> %s", BLUE, RESET);
			
			tecla_presionada = leer_tecla();
		
			if (tecla_presionada == 'v')
			{
				break;
			}
			else if (tecla_presionada == '\n') {
				limpiar_pantalla();
				math_run();
			}
			else
			{
				printf("Opción inválida.\n");
				esperar_enter();
			}
			break;
			
	
			
		case '2':
			limpiar_pantalla();
			
			printf("%s=================================================%s\n", 
				   CYAN, RESET);
			printf("%s|                M A T H - J U M P                 |%s\n", 
				   GREEN, RESET);
			printf("%s=================================================%s\n", 
				   CYAN, RESET);
			
			printf("\n%sOBJETIVO:%s Resolver la ecuacion antes de que el tiempo termine.%s\n",
				   YELLOW, GREEN, RESET);
			printf("%sPUNTAJE:%s Cada acierto vale 5 puntos.%s\n",
				   YELLOW, GREEN, RESET);
			
			printf("\n%s-------------------------------------------------%s\n", BLUE, RESET);
			printf("\n%sENTER%s = CONTINUAR%s", BLUE, GREEN, RESET);
			printf("\n%sv %s= VOLVER AL MENU PRINCIPAL%s", YELLOW, GREEN, RESET);
			printf("\n%s-> %s", BLUE, RESET);
			
			tecla_presionada = leer_tecla();

			if (tecla_presionada == 'v')
			{
				break;
			}			

			else if (tecla_presionada == '\n') {
				limpiar_pantalla();
				math_jump(resultado_total); 
				escribir_con_tiempo(total);
				
				if (total > 0) {
					save_score_to_file(nombre_jugador, total);
				
					printf("\n%s¡Puntaje %d guardado en el historial de scores!%s\n", 
						   CYAN, total, RESET);
				} else {
					
					printf("\n%sNo se guarda el puntaje (es 0 o menos).%s\n", 
						   RED, RESET);
				}
			}
			else
			{
				printf("Opción inválida.\n");
				esperar_enter();
			}
			break;
			
			
		case '3':
			limpiar_pantalla();
			
			printf("%s=================================================%s\n", 
				   CYAN, RESET);
			printf("%s|               M A T H - F A S T                  |%s\n", 
				   GREEN, RESET);
			printf("%s=================================================%s\n", 
				   CYAN, RESET);
			
			printf("\n%sOBJETIVO:%s Resolver la mayor cantidad de ejercicios posible.%s\n",
				   YELLOW, GREEN, RESET);
			printf("%sREGLAS:%s El juego termina al fallar o acabarse el tiempo limite.%s\n",
				   YELLOW, GREEN, RESET);
			
			printf("\n%s-------------------------------------------------%s\n", BLUE, RESET);
			printf("\n%sENTER%s = CONTINUAR%s", BLUE, GREEN, RESET);
			printf("\n%sv %s= VOLVER AL MENU PRINCIPAL%s", YELLOW, GREEN, RESET);
			printf("\n%s-> %s", BLUE, RESET);
			
			tecla_presionada = leer_tecla();

			if (tecla_presionada == 'v')
			{
				break;
			}
			else if (tecla_presionada == '\n') {
				limpiar_pantalla();
				math_fast(nombre_jugador); 
			}
			else
			{
				printf("Opción inválida.\n");
				esperar_enter();
			}
			break;
		
		case '4': 
			limpiar_pantalla();
			printf("%s=================================================%s\n", 
				   CYAN, RESET);
			printf("%s|               M A T H - L O G I C                 |%s\n", 
				   GREEN, RESET);
			printf("%s=================================================%s\n", 
				   CYAN, RESET);
			
			printf("\n%sOBJETIVO:%s Responder con la opción correcta.%s\n",
				   YELLOW, GREEN,RESET);
			printf("%sREGLAS:%s Trendrás que resolver el acertijo correctamente.%s\n",
				   YELLOW, GREEN, RESET);
			
			printf("\n%s-------------------------------------------------%s\n", BLUE, RESET);
			printf("\n%sENTER%s = CONTINUAR%s", BLUE, GREEN, RESET);
			printf("\n%sv %s= VOLVER AL MENU PRINCIPAL%s", YELLOW, GREEN, RESET);
			printf("\n%s-> %s", BLUE, RESET);
			tecla_presionada = leer_tecla();

			if (tecla_presionada == 'v')
			{
				break;
			}
			else if (tecla_presionada == '\n') {
				limpiar_pantalla();
				math_logic(); 
			}
			else
			{
				printf("Opción inválida.\n");
				esperar_enter();
			}
			break;

		case '5': 
				limpiar_pantalla();
				printf("%s=================================================%s\n", 
					   CYAN, RESET);
				printf("%s|               M A T H - L U C K Y                 |%s\n", 
					   GREEN, RESET);
				printf("%s=================================================%s\n", 
					   CYAN, RESET);
				
				printf("\n%sOBJETIVO:%s Acertar los numeros aleatorios.%s\n",
					   YELLOW, GREEN,RESET);
				printf("%sREGLAS:%s Tienes que tener mucha suerte.%s\n",
					   YELLOW, GREEN, RESET);
				
				printf("\n%s-------------------------------------------------%s\n", BLUE, RESET);
				printf("\n%sENTER%s = CONTINUAR%s", BLUE, GREEN, RESET);
				printf("\n%sv %s= VOLVER AL MENU PRINCIPAL%s", YELLOW, GREEN, RESET);
				printf("\n%s-> %s", BLUE, RESET);
				tecla_presionada = leer_tecla();

				if (tecla_presionada == 'v')
				{
					break;
				}
				else if (tecla_presionada == '\n') {
					limpiar_pantalla();
					math_lucky(); 
				}
				else
				{
					printf("Opción inválida.\n");
					esperar_enter();
				}
			break;
			
	    case 'r':		
			limpiar_pantalla();
			printf("\nScores segun usuario\n");
			printf("\n%s-------------------------------------------------%s\n", BLUE, RESET);
			printf("\n%sENTER%s = CONTINUAR%s", BLUE, GREEN, RESET);
			printf("\n%sv %s= VOLVER AL MENU PRINCIPAL%s", YELLOW, GREEN, RESET);
			printf("\n%s-> %s", BLUE, RESET);
			
			tecla_presionada = leer_tecla();
			if (tecla_presionada == 'v')
			{
				break;
			}
			else if (tecla_presionada == '\n') {
				limpiar_pantalla();
				display_leaderboard(); 
			}
			else
			{
				printf("%sOpción inválida.%s\n", YELLOW, RESET);
				esperar_enter();
			}
			break;
		
		case 'h': //secreto de desarrolladores. Por eso, no aparece como opcion.
			limpiar_pantalla();
			printf("\nRegistro de usuarios\n");
			printf("\n%s-------------------------------------------------%s\n", BLUE, RESET);
			printf("\n%sENTER%s = CONTINUAR%s", BLUE, GREEN, RESET);
			printf("\n%sv %s= VOLVER AL MENU PRINCIPAL%s", YELLOW, GREEN, RESET);
			printf("\n%s-> %s", BLUE, RESET);

			tecla_presionada = leer_tecla();
			if (tecla_presionada == 'v')
			{
				break;
			}
			else if (tecla_presionada == '\n') {
				limpiar_pantalla();
				jugadores_registrados(); 
			}
			else
			{
				printf("%sOpción inválida.%s\n", YELLOW, RESET);
				esperar_enter();
			}
			break;
			
		case 'x':
			limpiar_pantalla();
			printf("\n\n%sGracias por probar el programa! Que tenga un buen día :)%s\n\n", GREEN, RESET);
			break;
			
		default:
			printf("\n%sEscriba solo las opciones validas, porfavor%s\n", YELLOW, RESET);
			esperar_enter();
			break;
		}
	} while (tecla_presionada != 'x');
	
	return 0;
}
