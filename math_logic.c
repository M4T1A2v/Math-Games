#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./funciones.h"

#define FILE_RESPUESTAS "respuestas.bin"
#define CANTIDAD_CONSIGNAS 1

struct preguna_acertijo
{
    char pregunta[300];
    char respuesta[100];
};

// --- Mostrar un acertijo con opciones ---
void math_logic()
{
    FILE *respuestas;

    short nivel = 0;
    short indice_pregunta = 1;
    char respuesta = 0;
    char respuesta_jugador;


    if ( indice_pregunta == 1 )
    {
        printf("\n\n¿Como es el color magenta en rgb?");
        printf("\nRGB: terminoligia usada por el software para imprimir color.");
        printf("\nR de red, G de green, B de Blue. La intesidad del color se configura en hexadecimal, pj: azul = #009\n");
        
        printf("\nopciones:");
        printf("\na) #f00");
        printf("\nb) #0f0");
        printf("\nc) #00f");
        printf("\nd) #f0f");
        respuesta = 'd';
    }

    printf("\n-->");
    respuesta_jugador = leer_tecla();

    if ( respuesta_jugador == respuesta )
    {
        printf("\n\n✔ Correcto!\n");
    }
    else
    {
        printf("\n\n✘ Incorrecto.\n");
    }

    esperar_enter();
    // for (short i = 0; i < CANTIDAD_CONSIGNAS; i++ )
    // {
    //     indice = rand() % 1;
    // }

}


//! ejecua el acertijo segun el nivel: 
    // FILE *archivo_id = fopen("id_usuarios.bin", "rb");
    // if (archivo_id != NULL) 
    // {
    //     while (fread(id, sizeof(char), 9, archivo_id) == 9 &&
    //            fread(nombre, sizeof(char), 21, archivo_id) == 21)
    //     {
    //         guardar_progreso()
    //     }
    // }  
    // else 
    // {
    //     printf("No se pudo abrir el archivo.\n");
    //     return;
    // }  


