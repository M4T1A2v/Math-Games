# MathGames en C

Un programa de consola en C que pone a prueba la memoria y rapidez mental del jugador mediante minijuegos matemáticos.  
Diseñado para ejecutarse tanto en Windows como en Linux/macOS, usando técnicas de control de consola y detección de teclas en tiempo real.

## OBJETIVO DEL PROGRAMA

El propósito de esta aplicación es practicar y evaluar la agilidad mental del usuario mediante operaciones aritméticas simples y control de tiempo.  
Además, busca demostrar el uso de:
- Entrada de teclado no bloqueante (_kbhit() y getchar())
- Control de tiempo con la librería time.h
- Compatibilidad multiplataforma
- Limpieza de pantalla y pausas adaptadas al sistema operativo
- Programación modular en C
- Uso de arvhivos binarios y de texto

## JUEGOS INCLUIDOS

### 1. MathRun - "Memoriza y suma"
Se muestran varios números durante unos segundos.  
El jugador debe recordar y escribir su suma total.

- **Dificultad**: Baja  
- **Habilidades**: memoria y concentración  
- **Tiempo entre números**: 3 segundos  

### 2. MathJump - "Resuelve antes de que acabe el tiempo"
El programa muestra una ecuación (tres sumandos).  
El jugador debe escribir el resultado antes de que se acabe el tiempo (20 segundos).  
La entrada se procesa en tiempo real, sin detener el cronómetro.

- **Dificultad**: Media  
- **Habilidades**: cálculo rápido, manejo de presión  
- **Tiempo total**: 20 segundos  

### 3. MathFast - "Calculo veloz"
Durante 20 segundos, el jugador debe resolver la mayor cantidad posible de operaciones simples.  
Si se equivoca, el juego termina.

- **Dificultad**: Media-alta  
- **Habilidades**: velocidad, precisión, atención  
- **Condición de fin**: error o tiempo agotado  

## ESTRUCTURA DEL CODIGO (Modular)

El programa está organizado en módulos separados para mejor mantenibilidad:

```
/mathgames
  /headers
    ├── compat.h      # Compatibilidad entre sistemas
    ├── juegos.h      # Prototipos de los juegos
    ├── menu.h        # Funciones del menu
    └── utils.h       # Utilidades generales
  
  /sources
    ├── main.c               # Punto de entrada principal
    ├── compat.c             # Implementacion compatibilidad
    ├── menu.c               # Logica del menu
    ├── math_run.c           # Juego 1: Memoria y suma
    ├── math_jump.c          # Juego 2: Contra reloj
    ├── math_fast.c          # Juego 3: Velocidad
    └── escribir_con_tiempo.c # Entrada con temporizador
  /Others README.md           # Archivo con descripcion de la app
```

### FUNCIONES PRINCIPALES POR MODULO

| Modulo | Funciones principales |
|--------|----------------------|
| main | Controla el flujo general del programa |
| compat | leer_tecla(), _kbhit(), pausa(), esperar_enter() |
| menu | menu_principal() |
| math_run | math_run() - Juego de memoria |
| math_jump | math_jump() - Genera ecuaciones |
| math_fast | math_fast() - Juego de velocidad |
| escribir_con_tiempo | escribir_con_tiempo() - Entrada con tiempo |

## COMPATIBILIDAD

El programa fue diseñado para funcionar correctamente en:

- **Windows** (usa conio.h, windows.h, y comando cls)
- **Linux / macOS** (usa termios, unistd.h, y comando clear)

Se manejan condicionales con #ifdef _WIN32 para adaptar las funciones de:
- Limpieza de pantalla (CLEAR)
- Pausa (Sleep() / sleep())
- Lectura no bloqueante (_kbhit())

## COMPILACION Y EJECUCION

### Compilacion manual

#### En Linux o macOS:
```bash
gcc -Iheaders sources/*.c -o math_games -std=c99 -Wall
```

#### En Windows:
```bash
gcc -Iheaders sources/*.c -o math_games.exe -std=c99 -Wall
```

### Usando Makefile (recomendado):
```bash
make          # Compilar
./math_games  # Ejecutar
make clean    # Limpiar archivos compilados
```

## USO RAPIDO

1. Ejecuta el programa
2. Escribe tu nombre (maximo 20 caracteres)
3. Elige una opcion del menu:
   - `1` -> MathRun (memoriza y suma)
   - `2` -> MathJump (resuelve antes del tiempo)
   - `3` -> MathFast (resuelve la mayor cantidad posible)
   - `x` -> salir del programa
4. Sigue las instrucciones en pantalla
5. Presiona ENTER cuando te lo indique para volver al menu

**CONSEJO**: El programa muestra y borra números dinámicamente, así que presta atencion -no hay segundas oportunidades.

## CONCEPTOS TECNICOS UTILIZADOS

- **E/S no bloqueante**: permite detectar teclas sin detener el flujo del programa
- **Temporizadores con time_t**: para medir segundos y limitar tiempo de juego
- **ANSI escape codes**: para limpiar lineas en pantalla sin borrar todo (\033[2K\r)
- **Semillas aleatorias** (srand(time(NULL))): generan operaciones diferentes cada vez
- **Punteros**: usados para pasar resultados entre funciones
- **Programacion modular**: separacion clara de responsabilidades
- **Headers protectores**: evitan inclusion multiple con #ifndef

## PROXIMAS MEJORAS PLANEADAS

- Guardar puntajes en archivo binario Listo!!!
- Crear historial por jugador  Listooo!!!!
- Implementar niveles de dificultad progresiva <<<<-----Aun por hacer!!!!
- Agregar sistema de ranking o top 10 Listoooo!!!
- Mostrar resultados con colores en consola Listoooo!!!!!
- Mas juegos matematicos: porcentajes, logica, acertijos <<<<-----Aun por hacer!!!!
- Sistema de registro de usuarios persistente Listoooo!!!!!

---

Desarrollado como práctica de programación en C,  
con enfoque en control de tiempo, E/S en consola, programacion modular y logica de juegos.


Se está desarrollando para el guardado del score:
Archivo,Acción,Propósito
score.h,NUEVO,"Contiene la definición de la estructura UserScore, las constantes y la declaración (prototipo) de las funciones."
score.c,NUEVO,Contiene la implementación (código) de las funciones save_score_to_file y display_leaderboard.
main.c,Modificación,"Contiene la función main(), incluye score.h y llama a las funciones de guardar y mostrar el ranking."



Se desarrollo implementacion de colores...

Se desarrollo implementacion de sonido de exito o de fracaso en otros proy hay que implementar la config para que funcione correctamente.
#### Configuración del Enlazador (Linker) en Red Panda 
Este es el paso más importante si usas MinGW/Red Panda. Necesitas decirle al compilador que use la librería winmm.lib que subiste (o, de forma más estándar, usar su flag).

Abre la configuración de tu proyecto en Red Panda (Archivo .dev).

Busca las Linker Options o Bibliotecas Adicionales.

Asegúrate de que la flag -lwinmm esté incluida en las opciones del enlazador.

Si usas el archivo makefile.win que subiste, este ya debería estar configurado. Si usas las opciones del IDE:

Acción en Red Panda: Ve a Project Options -> Compiler Settings -> Linker. En el campo donde se agregan las librerías, añade -lwinmm.
