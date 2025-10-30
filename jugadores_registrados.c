#include "./menu.h"
#include "./utils.h"
#include "./compat.h"
#include "./funciones.h"

#include <ctype.h>
#include <time.h>

#define FILE_JUGADORES "jugadores.txt"


void jugadores_registrados(void)
{
    FILE *archivo_jugadores = fopen(FILE_JUGADORES, "rb");
    if (archivo_jugadores == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char id[9];
    char nombre[21];

    limpiar_pantalla();
    printf("\n=== Usuarios registrados ===\n");

    while (fread(id, sizeof(char), 9, archivo_jugadores) == 9 &&
           fread(nombre, sizeof(char), 21, archivo_jugadores) == 21)
    {
        printf("ID: #%s  |  Nombre: %s\n", id, nombre);
    }

    fclose(archivo_jugadores);
    printf("\n");
    esperar_enter();
}



