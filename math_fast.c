#include "./juegos.h"
#include "./utils.h" 
#include "./score.h"
#include <time.h> 

void math_fast(const char *nombre_jugador )
{
	short aciertos = 0;
	short termino1, termino2, respuesta_jugador;
	short total = 0;
	short tiempo_restante = TIEMPO; 
	short tiempo_recorrido;
	short se_ingreso_respuesta = 0;
	
	
	time_t guarda_tiempo = time(NULL);
	
	
	printf("\n%s\t### NVL 1 ###%s\n", CYAN, RESET);
	
	
	while (tiempo_restante > 0)
	{
		total = 0;
		termino1 = (rand() % 101) - 50;
		termino2 = (rand() % 101) - 50;
		total += termino1 + termino2;
		se_ingreso_respuesta = 0;
		
		
		printf("\n\n%s-----------------------------------------------------%s", 
			   BLUE, RESET);
		printf("\n#1 --> (%hd) + (%hd) \n\n", termino1, termino2);
		
		
		while (tiempo_restante > 0)
		{
			tiempo_recorrido = (short)(time(NULL) - guarda_tiempo);
			tiempo_restante = TIEMPO - tiempo_recorrido;
			
			
			printf("\rTiempo restante >> %s%hd%s >> resultado -> ", 
				   YELLOW, tiempo_restante, RESET);
			fflush(stdout);
			
			
			if (_kbhit())
			{
				se_ingreso_respuesta = 1;
				break;
			}
		}
		
	
		if (se_ingreso_respuesta)
		{
			if (tiempo_restante <= 0)
			{
				printf("\n%sSe acabo el tiempo..%s", RED, RESET);
				play_sound_error(); 
				break;
			}
			printf("\n\nIngrese su resultado --> ");
			scanf(" %hd", &respuesta_jugador);
			
			
			if (respuesta_jugador == total)
			{
				// Acierto
				aciertos++;
				printf("\n%s¡Acierto!%s", GREEN, RESET);
		
				play_sound_correct(); 
			}
			else
			{
				printf("\n%sResultado incorrecto, era -> %hd%s\n", 
					   RED, total, RESET);
				play_sound_error(); 
				break;
			}
		}
		else
		{
			printf("\n%sSe acabo el tiempo..%s", RED, RESET);
			play_sound_error(); 
			break;
		}
	}
	
	printf("\n\n%s-----------------------------------------------------%s", BLUE, RESET);
	
	printf("\nTotal de aciertos: %s%hd%s\n", GREEN, aciertos, RESET);
	
	short puntaje_final = aciertos * 5; 

	
	printf("Puntaje total (%d puntos por acierto): %s%hd%s\n",5 , YELLOW, puntaje_final, RESET);

	if (puntaje_final > 0) {
		save_score_to_file(nombre_jugador, puntaje_final);
		printf("\n%s¡Puntaje %hd guardado en el Ranking!%s\n", CYAN, puntaje_final, RESET);
	} else {
		printf("\nNo se guarda el puntaje (es 0).\n");
	}
	esperar_enter();
}

