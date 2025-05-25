#ifndef UART_H
#define UART_H

#include <stdint.h>

// Prototipos de funciones de inicialización
void UART_Ini(uint8_t com, uint32_t baudrate, uint8_t size, uint8_t parity, uint8_t stop);

// Prototipos de funciones de envío
void UART_puts(uint8_t com, char *str);
void UART_putchar(uint8_t com, char data);

// Prototipos de funciones de recepción
uint8_t UART_available(uint8_t com);
char UART_getchar(uint8_t com);
void UART_gets(uint8_t com, char *str);

// Prototipos de funciones con secuencias de escape
void UART_clrscr(uint8_t com);            // Limpia la terminal
void UART_setColor(uint8_t com, uint8_t color); // Configura el color del texto
void UART_gotoxy(uint8_t com, uint8_t x, uint8_t y); // Posiciona el cursor

// Definiciones de colores (puedes agregarlos según lo que necesites)
#define BLACK   0
#define RED     1
#define GREEN   2
#define YELLOW  3
#define BLUE    4
#define MAGENTA 5
#define CYAN    6
#define WHITE   7


// Prototipos de funciones auxiliares
void itoa(uint16_t number, char* str, uint8_t base); // Convierte entero a cadena
uint16_t atoi(char *str); // Convierte cadena a entero

#endif // UART_H
