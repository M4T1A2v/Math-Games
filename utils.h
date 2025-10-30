#ifndef UTILS_H
#define UTILS_H

// Códigos de Colores ANSI
#define RED      "\x1b[31m"
#define GREEN    "\x1b[32m"
#define YELLOW   "\x1b[33m"
#define BLUE     "\x1b[34m"
#define MAGENTA  "\x1b[35m"
#define CYAN     "\x1b[36m"
#define RESET    "\x1b[0m" // Código para restaurar el color predeterminado

#include "compat.h"

// Funciones utilitarias generales
void limpiar_pantalla(void);
void configurar_consola(void);

// Prototipos de funciones de audio
void play_sound_correct(void);
void play_sound_error(void);
#endif
