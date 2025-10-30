#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./funciones.h"

//! Faltaria poner lo que el jugador cree que numeros van a aparecer
//! tambien otros premios por si toca justo tres numeros iguale (1 1 1), o los tres numeros en escalertia (1 2 3)


void math_lucky()
{
    srand(time(NULL));
    system(""); // habilita soporte ANSI

    esperar_enter();

    printf("\nTus numeros son...\n\n");

    // Cada cuadro ocupa 5 caracteres -> centramos el número dentro
    int posiciones_x[3] = {2, 8, 14};
    int numero_final[3];
    int detenido[3] = {0, 0, 0};

    // Línea base de los cuadros
    printf("|   |     |   |");

    for (int ciclo = 0; ciclo < 60; ciclo++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (!detenido[i])
            {
                int numero_mostrar = rand() % 10;

                // Mueve el cursor a la posición exacta y dibuja el número
                printf("\033[%dG%d", posiciones_x[i], numero_mostrar);
                fflush(stdout);
            }
        }

        Sleep(80);

        if (ciclo == 20)
        {
            detenido[0] = 1;
            numero_final[0] = rand() % 10;
            printf("\033[%dG%d", posiciones_x[0], numero_final[0]);
            fflush(stdout);
        }
        if (ciclo == 40)
        {
            detenido[1] = 1;
            numero_final[1] = rand() % 10;
            printf("\033[%dG%d", posiciones_x[1], numero_final[1]);
            fflush(stdout);
        }
    }

    detenido[2] = 1;
    numero_final[2] = rand() % 10;
    printf("\033[%dG%d", posiciones_x[2], numero_final[2]);
    fflush(stdout);

    printf("\n\nListo!\n");
    esperar_enter();
}

