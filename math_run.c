#include "./juegos.h"
#include "./utils.h" // Necesario para colores, pausa(), y funciones de audio

void math_run(void)
{
	short numero = 0;
	short total = 0;
	short veces = 3;
	short respuesta_jugador = 0;
	short i;
	
	// Titulo del Nivel con Color
	printf("\n%s\t### NIVEL 1 ###%s\n", CYAN, RESET);
	printf("-----------------------------------------\n");
	
	
	for (i = 0; i < veces; i++)
	{
		numero = (rand() % 201) - 100;
		total += numero;
		
		// Muestra el numero destacado
		printf("%sTERMINO %hd: %s%hd%s", 
			   YELLOW, i + 1, GREEN, numero, RESET);
		fflush(stdout);
		pausa();
		
		// Limpia la linea para el siguiente termino
		printf("\033[2K\r");
	}
	
	// Linea final antes de pedir la respuesta
	printf("\n%s=========================================%s\n", 
		   BLUE, RESET);
	
	printf("Resultado total -> ");
	scanf(" %hd", &respuesta_jugador);
	
	
	if (respuesta_jugador == total)
	{
		// Respuesta Correcta: Color Verde y Sonido de Éxito
		printf("\n%s>>> %hd es CORRECTO! Felicitaciones! <<<%s\n", 
			   GREEN, respuesta_jugador, RESET);
		play_sound_correct(); 
	}
	else
	{
		// Respuesta Incorrecta: Color Rojo y Sonido de Error
		printf("\n%s>>> %hd es INCORRECTO. El total era -> %hd%s\n", 
			   RED, respuesta_jugador, total, RESET);
		play_sound_error();
	}
	
	esperar_enter();
}
