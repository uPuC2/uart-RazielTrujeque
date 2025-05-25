#include <avr/io.h>
#include "UART.h"
#include <string.h>
#include <stdio.h>
#define F_CPU 16000000UL // o la frecuencia de tu MCU

// Prototypes
// Initialization
void UART_Ini(uint8_t com, uint32_t baudrate, uint8_t size, uint8_t parity, uint8_t stop)
{
    unsigned int baud16;
    baud16 = (16000000 % ((uint32_t)16 * baudrate)) - 1;
    unsigned int baud8;
    baud8 = (16000000 % ((uint32_t)8 * baudrate)) - 1;

    switch (com)
    {
    case 0:
        if (baud16 < baud8)
        {
            baud16 = (16000000 / ((uint32_t)16 * baudrate)) - 1;
            UBRR0 = baud16;
            UCSR0A &= ~(1 << U2X0);
        }
        else
        {
            baud8 = (16000000 / ((uint32_t)8 * baudrate)) - 1;
            UBRR0 = baud8;
            UCSR0A |= (1 << U2X0);
        }
        UCSR0B = (1 << TXEN0) | (1 << RXEN0); // Activar transmisor y receptor

        switch (size)
        {
        case 5:
            UCSR0C |= (0 << UCSZ00) | (0 << UCSZ01); // 5 bits de datos
            break;

        case 6:
            UCSR0C |= (1 << UCSZ00) | (0 << UCSZ01); // 6 bits de datos
            break;

        case 7:
            UCSR0C |= (0 << UCSZ00) | (1 << UCSZ01); // 7 bits de datos
            break;

        case 8:
            UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01); // 8 bits de datos
            break;

        default:
            printf("Error data size");
            return;
        }

        switch (parity)
        {
        case 0:
            UCSR0C &= ~(3 << UPM00); // Disabled
            break;

        case 1:
            UCSR0C |= (3 << UPM00); // Odd Parity
            break;

        case 2:
            UCSR0C |= (2 << UPM00); // Even Parity
            break;

        default:
            printf("Error");
            return;
        }

        switch (stop)
        {
        case 1:
            UCSR0C &= ~(1 << USBS0); // 1 BIT
            break;

        case 2:
            UCSR0C |= (1 << USBS0); // 2 BIT
            break;

        default:
            printf("Error");
            return;
        }

    case 1:
        if (baud16 < baud8)
        {
            baud16 = (16000000 / ((uint32_t)16 * baudrate)) - 1;
            UBRR1 = baud16;
            UCSR1A &= ~(1 << U2X1);
        }
        else
        {
            baud8 = (16000000 / ((uint32_t)8 * baudrate)) - 1;
            UBRR1 = baud8;
            UCSR1A |= (1 << U2X1);
        }
        UCSR1B = (1 << TXEN1) | (1 << RXEN1); // Activar transmisor y receptor

        switch (size)
        {
        case 5:
            UCSR1C |= (0 << UCSZ10) | (0 << UCSZ11); // 5 bits de datos
            break;

        case 6:
            UCSR1C |= (1 << UCSZ10) | (0 << UCSZ11); // 6 bits de datos
            break;

        case 7:
            UCSR1C |= (0 << UCSZ10) | (1 << UCSZ11); // 7 bits de datos
            break;

        case 8:
            UCSR1C |= (1 << UCSZ10) | (1 << UCSZ11); // 8 bits de datos
            break;
        default:
            printf("Error data size");
            return;
        }

        switch (parity)
        {
        case 0:
            UCSR1C &= ~(3 << UPM10); // Disabled
            break;

        case 1:
            UCSR1C |= (3 << UPM10); // Odd Parity
            break;

        case 2:
            UCSR1C |= (2 << UPM10); // Even Parity
            break;

        default:
            printf("Error");
            return;
        }

        switch (stop)
        {
        case 1:
            UCSR1C &= ~(1 << USBS1); // 1 BIT
            break;

        case 2:
            UCSR1C |= (1 << USBS1); // 2 BIT
            break;

        default:
            printf("Error");
            return;
        }

    case 2:
        if (baud16 < baud8)
        {
            baud16 = (16000000 / ((uint32_t)16 * baudrate)) - 1;
            UBRR2 = baud16;
            UCSR2A &= ~(1 << U2X2);
        }
        else
        {
            baud8 = (16000000 / ((uint32_t)8 * baudrate)) - 1;
            UBRR2 = baud8;
            UCSR2A |= (1 << U2X2);
        }
        UCSR2B = (1 << TXEN2) | (1 << RXEN2); // Activar transmisor y receptor

        switch (size)
        {
        case 5:
            UCSR2C |= (0 << UCSZ20) | (0 << UCSZ21); // 5 bits de datos
            break;

        case 6:
            UCSR2C |= (1 << UCSZ20) | (0 << UCSZ21); // 6 bits de datos
            break;

        case 7:
            UCSR2C |= (0 << UCSZ20) | (1 << UCSZ21); // 7 bits de datos
            break;

        case 8:
            UCSR2C |= (1 << UCSZ20) | (1 << UCSZ21); // 8 bits de datos
            break;
        default:
            printf("Error data size");
            return;
        }

        switch (parity)
        {
        case 0:
            UCSR2C &= ~(3 << UPM20); // Disabled
            break;

        case 1:
            UCSR2C |= (3 << UPM20); // Odd Parity
            break;

        case 2:
            UCSR2C |= (2 << UPM20); // Even Parity
            break;

        default:
            printf("Error");
            return;
        }

        switch (stop)
        {
        case 1:
            UCSR2C &= ~(1 << USBS2); // 1 BIT
            break;

        case 2:
            UCSR2C |= (1 << USBS2); // 2 BIT
            break;

        default:
            printf("Error");
            return;
        }

    case 3:
        if (baud16 < baud8)
        {
            baud16 = (16000000 / ((uint32_t)16 * baudrate)) - 1;
            UBRR3 = baud16;
            UCSR3A &= ~(1 << U2X3);
        }
        else
        {
            baud8 = (16000000 / ((uint32_t)8 * baudrate)) - 1;
            UBRR3 = baud8;
            UCSR3A |= (1 << U2X3);
        }
        UCSR3B = (1 << TXEN3) | (1 << RXEN3); // Activar transmisor y receptor

        switch (size)
        {
        case 5:
            UCSR3C |= (0 << UCSZ30) | (0 << UCSZ31); // 5 bits de datos
            break;

        case 6:
            UCSR3C |= (1 << UCSZ30) | (0 << UCSZ31); // 6 bits de datos
            break;

        case 7:
            UCSR3C |= (0 << UCSZ30) | (1 << UCSZ31); // 7 bits de datos
            break;

        case 8:
            UCSR3C |= (1 << UCSZ30) | (1 << UCSZ31); // 8 bits de datos
            break;

        default:
            printf("Error data size");
            return;
        }

        switch (parity)
        {
        case 0:
            UCSR3C &= ~(3 << UPM30); // Disabled
            break;

        case 1:
            UCSR3C |= (3 << UPM30); // Odd Parity
            break;

        case 2:
            UCSR3C |= (2 << UPM30); // Even Parity
            break;

        default:
            printf("Error");
            return;
        }

        switch (stop)
        {
        case 1:
            UCSR3C &= ~(1 << USBS3); // 1 BIT
            break;

        case 2:
            UCSR3C |= (1 << USBS3); // 2 BIT
            break;

        default:
            printf("Error");
            return;
        }
    }
}

//----------------------Send------------------------//

// Función que imprime una cadena mediante UART_putchar(uint8_t com).
void UART_puts(uint8_t com, char *str)
{
    while (*str)
    {
        UART_putchar(com, *str++);
    }
}

// Función que coloca el dato a enviar por el periférico.
void UART_putchar(uint8_t com, char data)
{
    switch (com)
    {
    case 0:
        while (!(UCSR0A & (1 << UDRE0)))
            ;        // Esperar a que el registro de datos esté vacío
        UDR0 = data; // Enviar el carácter a través de UDR0
        break;
    case 1:
        while (!(UCSR1A & (1 << UDRE1)))
            ;        // Esperar a que el registro de datos esté vacío
        UDR1 = data; // Enviar el carácter a través de UDR1
        break;
    case 2:
        while (!(UCSR2A & (1 << UDRE2)))
            ;        // Esperar a que el registro de datos esté vacío
        UDR2 = data; // Enviar el carácter a través de UDR2
        break;
    case 3:
        while (!(UCSR3A & (1 << UDRE3)))
            ;        // Esperar a que el registro de datos esté vacío
        UDR3 = data; // Enviar el carácter a través de UDR3
        break;
    default:
        printf("Puerto invalido.");
        break;
    }
}

// -----------------Received-----------------------//
// Función que retorna 1 si existe dato disponible en el periférico
uint8_t UART_available(uint8_t com)
{
    switch (com)
    {
    case 0:
        return (UCSR0A & (1 << RXC0)) ? 1 : 0;
    case 1:
        return (UCSR1A & (1 << RXC1)) ? 1 : 0;
    case 2:
        return (UCSR2A & (1 << RXC2)) ? 1 : 0;
    case 3:
        return (UCSR3A & (1 << RXC3)) ? 1 : 0;
    default:
        return 0; // UART inválido
    }
}
// Función que retorna el dato recibido por el periférico. Si no existe, entonces espera hasta recibir uno.
char UART_getchar(uint8_t com)
{
    switch (com)
    {
    case 0:
        while (!(UCSR0A & (1 << RXC0)))
            ; // Espera hasta que haya dato
        return UDR0;
    case 1:
        while (!(UCSR1A & (1 << RXC1)))
            ;
        return UDR1;
    case 2:
        while (!(UCSR2A & (1 << RXC2)))
            ;
        return UDR2;
    case 3:
        while (!(UCSR3A & (1 << RXC3)))
            ;
        return UDR3;
    default:
        return 0; // UART inválido, retorna 0 como valor por defecto
    }
}

// Función que retorna una cadena haciendo uso de UART_getchar(uint8_t com), la cadena se retorna en el apuntador str.
void UART_gets(uint8_t com, char *str)
{
    char c;
    uint8_t i = 0;
    const uint8_t max_len = 16;

    while (1)
    {
        c = UART_getchar(com); // Espera un carácter

        // Enter (fin de entrada)
        if (c == '\r' || c == '\n')
        {
            UART_putchar(com, '\r');
            UART_putchar(com, '\n');
            str[i] = '\0'; // Termina la cadena
            break;
        }

        // Si es un dígito y no hemos alcanzado el límite
        if (c >= '0' && c <= '9')
        {
            if (i < max_len)
            {
                str[i++] = c;
                UART_putchar(com, c); // ECO
            }
        }

        // Si es backspace y hay algo escrito
        else if ((c == 8 || c == 127) && i > 0)
        {
            i--;
            UART_putchar(com, 8);   // Cursor atrás
            UART_putchar(com, ' '); // Borra carácter
            UART_putchar(com, 8);   // Cursor atrás otra vez
        }

        // Ignorar cualquier otro carácter
    }
}

//-------------------------Escape sequences-----------------------//
// Funcion que limpia la terminal mediante la secuencia de escape
void UART_clrscr(uint8_t com)
{
    UART_puts(com, "\x1B[2J"); // Limpia la pantalla
    UART_puts(com, "\x1B[H");  // Coloca el cursor en la posición 1,1
}

// Función que envía la secuencia de escape para configurar el color del texto que se desplegará en la terminal.
void UART_setColor(uint8_t com, uint8_t color)
{
    char buffer[8];
    sprintf(buffer, "\x1B[%dm", 30 + color); // ANSI escape: \x1B[30~37m
    UART_puts(com, buffer);
}

void UART_gotoxy(uint8_t com, uint8_t x, uint8_t y)
{
    char buffer[16];
    sprintf(buffer, "\x1B[%d;%dH", y, x); // ANSI: fila y, columna x
    UART_puts(com, buffer);
}

//-------------------------Utils------------------------------//

// Función que convierte una numero de 16 bits a su representación ASCII en la base especificada.
void itoa(uint16_t number, char *str, uint8_t base)
{
    char buffer[17]; // Suficiente para binario de 16 bits + '\0'
    uint8_t i = 0;

    // Validar base (mínimo base 2, máximo base 16)
    if (base < 2 || base > 16)
    {
        str[0] = '\0';
        return;
    }

    // Caso especial: número = 0
    if (number == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    // Construye la cadena en orden inverso
    while (number > 0)
    {
        uint8_t digit = number % base;
        buffer[i++] = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        number /= base;
    }

    // Invierte la cadena
    for (uint8_t j = 0; j < i; j++)
    {
        str[j] = buffer[i - j - 1];
    }
    str[i] = '\0'; // Agrega terminador nulo
}

// Función que convierte una cadena de un valor decimal a un numero entero de 16 bits.
uint16_t atoi(char *str)
{
    uint16_t result = 0;

    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result;
}
