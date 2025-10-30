#include "./menu.h"
#include "./utils.h"
#include "./compat.h"

#include <ctype.h>
#include <time.h>

#define FILE_JUGADORES "jugadores.txt"

const char *buscar_por_id(const char *id_buscar)
{
    static char nombre_jugador[21]; // <- persistente fuera de la función
    FILE *archivo = fopen(FILE_JUGADORES, "r");
    if (!archivo)
    {
        printf("Error: no se pudo abrir %s\n", FILE_JUGADORES);
        return NULL;
    }

    char linea[128];
    while (fgets(linea, sizeof(linea), archivo))
    {
        // Buscar el ID dentro de la línea
        char *ptr_inicio = strstr(linea, id_buscar);
        if (ptr_inicio != NULL)
        {
            // Extraer el nombre dentro de las comillas
            char *comilla_inicio = strchr(linea, '"');
            if (comilla_inicio)
            {
                char *comilla_fin = strchr(comilla_inicio + 1, '"');
                if (comilla_fin)
                {
                    size_t len = comilla_fin - comilla_inicio - 1;
                    if (len >= sizeof(nombre_jugador)) len = sizeof(nombre_jugador) - 1;
                    strncpy(nombre_jugador, comilla_inicio + 1, len);
                    nombre_jugador[len] = '\0';
                    fclose(archivo);
                    return nombre_jugador;
                }
            }
        }
    }

    fclose(archivo);
    printf("ERROR en la funcion buscar_por_id()");
    return NULL; // No encontrado
}
