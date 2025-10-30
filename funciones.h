
// === ALMACEN DE LOS PROTOTIPOS DE LAS FUNCIONES === //

#ifndef FUNCIONES_H

#define FUNCIONES_H
// Códigos de Colores ANSI
#define RED      "\x1b[31m"
#define GREEN    "\x1b[32m"
#define YELLOW   "\x1b[33m"
#define BLUE     "\x1b[34m"
#define MAGENTA  "\x1b[35m"
#define CYAN     "\x1b[36m"
#define RESET    "\x1b[0m" // Código para restaurar el color predeterminado

#include "./compat.h"
#include "./menu.h"
#include "./utils.h"
#include "./compat.h"

// Funciones utilitarias generales
void limpiar_pantalla(void);
void configurar_consola(void);

// Prototipos de funciones de audio
void play_sound_correct(void);
void play_sound_error(void);

// --------------------

// Prototipos de funciones del menú
void menu_principal(const char *);

//----------------------
// Prototipos de funciones de juegos
void math_run(void);
void math_jump(short *resultado_total);
void math_fast(const char *nombre_ususaio); // <-- Nuevo: Recibe el nombre
void math_logic(void);
void math_lucky(void);

void escribir_con_tiempo(short resultado_total);

//----------------------
// Prototipos de funciones del inicio de seccion
void generar_id_unico( char *id_buffer );
const char* inicio_seccion(void);

//----------------------
//Informacion de Jugadores
void jugadores_registrados(void);
const char *buscar_por_id( const char *id_jbuscar);
void guardar_progreso(const char *id_usuario, const char *nombre_juego, short nivel);


#endif

