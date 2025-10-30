#include "./funciones.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char id_usuario[9];
    char nombre_juego[20];
    short nivel;
} progreso_usuario;

void guardar_progreso(const char *id_usuario, const char *nombre_juego, short nivel)
{
    progreso_usuario registro;
    int encontrado = 0;

    FILE *archivo_progreso = fopen("progreso.bin", "ab");
    if (archivo_progreso == NULL) 
    {
        printf("Error al crear progreso.bin\n");
        return;
    }
    

    // Buscar si ya existe un registro para este usuario y juego
    while (fread(&registro, sizeof(progreso_usuario), 1, archivo_progreso) == 1) {
        if (strcmp(registro.id_usuario, id_usuario) == 0 &&
            strcmp(registro.nombre_juego, nombre_juego) == 0)
        {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) 
    {
        // Reemplazar el nivel existente
        fseek(archivo_progreso, -sizeof(progreso_usuario), SEEK_CUR);
        registro.nivel = nivel;
        fwrite(&registro, sizeof(progreso_usuario), 1, archivo_progreso);

        printf("Progreso actualizado correctamente: %s - %s (Nivel %d)\n",
              registro.id_usuario, registro.nombre_juego, registro.nivel);
        esperar_enter();
    } 
    else 
    {
        // Crear nuevo registro
        strcpy(registro.id_usuario, id_usuario);
        strncpy(registro.nombre_juego, nombre_juego, sizeof(registro.nombre_juego));

        registro.nombre_juego[sizeof(registro.nombre_juego)-1] = '\0';
        registro.nivel = nivel;

        fwrite(&registro, sizeof(progreso_usuario), 1, archivo_progreso);
        
        printf("Progreso guardado correctamente: %s - %s (Nivel %d)\n",
               registro.id_usuario, registro.nombre_juego, registro.nivel);
        esperar_enter();
    }

    fclose(archivo_progreso);
}
