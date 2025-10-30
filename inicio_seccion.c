#include "./menu.h"
#include "./utils.h"
#include "./compat.h"

#include <ctype.h>
#include <time.h>

#define FILE_JUGADORES "jugadores.txt"

void generar_id_unico(char *id_buffer)
{
    short usados[10] = {0};
    for (int i = 0; i < 8; i++)
    {
        short digito;
        do { digito = rand() % 10; } while (usados[digito]);
        usados[digito] = 1;
        id_buffer[i] = '0' + digito;
    }
    id_buffer[8] = '\0';
}

const char* inicio_seccion(void)
{
    srand(time(NULL));
    FILE *archivo_jugadores;
    static char nombre_jugador[21]; // 'static' → persiste después del return
    static char id_jugador[9];      // ← también static, así se puede retornar

    limpiar_pantalla();
    printf("\n\n");	
	printf("%s=================================================%s\n", 
		   BLUE, RESET);
	
	printf("%s|                MATH GAMES V1.0                |%s\n", 
		   CYAN, RESET);
	
	printf("%s=================================================%s\n", 
		   BLUE, RESET);
	
	printf("\n");
	printf("%s>>> %sPone a prueba tu velocidad mental y tus calculos!%s <<<%s\n",
		   BLUE, GREEN, BLUE, RESET);
	
	printf("\n%s-------------------------------------------------%s\n", BLUE, RESET);

    printf("%sIngrese su nombre (20 caracteres max, sin acentos):\n--> %s", GREEN, RESET);
    if (fgets(nombre_jugador, sizeof(nombre_jugador), stdin) == NULL)
    {
        strcpy(nombre_jugador, "Jugador_Anonimo");
        printf("\n%s[!]%s Nombre vacío. Usando nombre por defecto: \"%s%s%s\" %s\n", RED, GREEN, RESET, nombre_jugador, GREEN, RESET);
        return nombre_jugador; // ← termina acá
    }

    // Eliminar salto de línea
    nombre_jugador[strcspn(nombre_jugador, "\n")] = 0;

    // Verificar si el usuario no ingresó nada o escribió caracteres no válidos
    if (strlen(nombre_jugador) == 0)
    {
        strcpy(nombre_jugador, "Jugador_Anonimo");
        printf("\n%s[!]%s Nombre vacío. Usando nombre por defecto: \"%s%s%s\" %s\n", RED, GREEN, RESET, nombre_jugador, GREEN, RESET);
        return nombre_jugador;
    }

    for (int i = 0; nombre_jugador[i]; i++)
    {
        unsigned char c = nombre_jugador[i];
        if (c < 32 || c > 126) // Fuera del rango ASCII visible
        {
            strcpy(nombre_jugador, "Jugador_Anonimo");
            printf("\n%s[!]%s Nombre vacío. Usando nombre por defecto: \"%s%s%s\" %s\n", RED, GREEN, RESET, nombre_jugador, GREEN, RESET);
            return nombre_jugador;
        }
    }

    // Verificar si el nombre ya existe
    archivo_jugadores = fopen(FILE_JUGADORES, "r");
    if (archivo_jugadores != NULL)
    {
        char linea[128];
        while (fgets(linea, sizeof(linea), archivo_jugadores))
        {
            if (strstr(linea, nombre_jugador))
            {
                printf("\n%s[!]%s El usuario \"%s%s%s\" ya está registrado.%s\n", YELLOW, GREEN, RESET, nombre_jugador, GREEN, RESET);
                fclose(archivo_jugadores);
                return nombre_jugador; // No registramos de nuevo
            }
        }
        fclose(archivo_jugadores);
    }

    // Generar nuevo ID
    generar_id_unico(id_jugador);

    // Guardar usuario
    archivo_jugadores = fopen(FILE_JUGADORES, "a");
    if (archivo_jugadores != NULL)
    {
        fprintf(archivo_jugadores, "[#%s] : \"%s\"\n", id_jugador, nombre_jugador);
        fclose(archivo_jugadores);

        printf("\n%s✅ Usuario \"%s%s%s\" registrado: ID %s#%s%s\n", GREEN, RESET, nombre_jugador, GREEN, BLUE, id_jugador, RESET);
    }
    else
    {
        printf("\n%s[ERROR] %sNo se pudo crear \"%s%s%s\" %s\n", RED, GREEN, RESET, FILE_JUGADORES, GREEN, RESET);
    }
    
    return id_jugador;
}

