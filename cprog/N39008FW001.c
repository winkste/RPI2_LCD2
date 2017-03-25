#include <wiringPi.h>
#include <lcd.h>
#include <stdio.h>
#include <mcp23017.h>

#define AF_RESET        26      // = wiringPi, Port Pin = 32
#define AF_I2C_ADDR     0x25    // R30, R33, R34
#define AF_BASE         100
#define AF_GPA0         (AF_BASE + 0)
#define AF_GPA1         (AF_BASE + 1)
#define AF_GPA2         (AF_BASE + 2)
#define AF_GPA3         (AF_BASE + 3)
#define AF_GPA4         (AF_BASE + 4)
#define AF_GPA5         (AF_BASE + 5)
#define AF_GPA6         (AF_BASE + 6)
#define AF_GPA7         (AF_BASE + 7)
#define AF_GPB0         (AF_BASE + 8)
#define AF_GPB1         (AF_BASE + 9)
#define AF_GPB2         (AF_BASE + 10)
#define AF_GPB3         (AF_BASE + 11)
#define AF_GPB4         (AF_BASE + 12)
#define AF_GPB5         (AF_BASE + 13)
#define AF_GPB6         (AF_BASE + 14)
#define AF_GPB7         (AF_BASE + 15)

#define AF_E	AF_GPA4
#define AF_RW	AF_GPA5
#define AF_RS	AF_GPA6

#define AF_DB4	AF_GPA3
#define AF_DB5	AF_GPA2
#define AF_DB6	AF_GPA1
#define AF_DB7	AF_GPA0
#define AF_LED1	AF_GPB7

int main (void)
{
	int lcd;

	printf("setup wiring pi\n");
        wiringPiSetup();
        printf("setup reset pin of mcp23017\n");
        pinMode(AF_RESET, OUTPUT);
        digitalWrite(AF_RESET, HIGH); 
        printf("setup mcp23017 expecting on address 0x25\n");
        mcp23017Setup(AF_BASE, AF_I2C_ADDR);
        pinMode(AF_LED1, 1);
        pinMode(AF_GPB6, 1);
        pinMode(AF_GPB5, 1);
        pinMode(AF_GPB4, 1);
        printf("set pin at mcp address DB7 to high\n");
        digitalWrite(AF_LED1, 1);
        sleep(1);
        digitalWrite(AF_LED1, 0);
        printf("set pin at mcp address DB7 to low\n");
        printf("set pin at mcp address DB6 to high\n");
        digitalWrite(AF_GPB6, 1);
        sleep(1);
        digitalWrite(AF_GPB6, 0);
        printf("set pin at mcp address DB6 to low\n");
        printf("set pin at mcp address DB5 to high\n");
        digitalWrite(AF_GPB5, 1);
        sleep(1);
        digitalWrite(AF_GPB5, 0);
        printf("set pin at mcp address DB5 to low\n");
        printf("set pin at mcp address DB4 to high\n");
        digitalWrite(AF_GPB4, 1);
        sleep(1);
        digitalWrite(AF_GPB4, 0);
        printf("set pin at mcp address DB4 to low\n");

	pinMode(AF_RW, 1);
	digitalWrite(AF_RW, 0);

	printf("setup lcd");
	lcd = lcdInit(2, 16, 4, AF_RS, AF_E, AF_DB4, AF_DB5, AF_DB6, AF_DB7, 0, 0, 0, 0);
	printf("lcd = %d", lcd);
	lcdPuts(lcd, "Hallo Stephan");
	return(0);
}
