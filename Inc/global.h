#define MIN 5
#define SEC 0
#define MSEC 0

#define GPIOKEY GPIOA
#define BUTTON_1 GPIO_PIN_0
#define BUTTON_2 GPIO_PIN_1
#define BUTTON_3 GPIO_PIN_2

#define COLOR Black
#define FON White

extern volatile unsigned short Enable_Player1;
extern volatile unsigned short Enable_Player2;
extern volatile enum {Timer1=0,Timer2=1,Off=2} Timer;
extern volatile unsigned short T1_min,T1_sec,T1_msec,T2_min,T2_sec,T2_msec;


static void ItoC(int x)
{
	switch(x)
	{
		case 0:
		{
			ssd1306_WriteString("0",Font_11x18,COLOR);
			break;
		}
		case 1:
		{
			ssd1306_WriteString("1",Font_11x18,COLOR);
			break;
		}
		case 2:
		{
			ssd1306_WriteString("2",Font_11x18,COLOR);
			break;
		}
		case 3:
		{
			ssd1306_WriteString("3",Font_11x18,COLOR);
			break;
		}
		case 4:
		{
			ssd1306_WriteString("4",Font_11x18,COLOR);
			break;
		}
		case 5:
		{
			ssd1306_WriteString("5",Font_11x18,COLOR);
			break;
		}
		case 6:
		{
			ssd1306_WriteString("6",Font_11x18,COLOR);
			break;
		}
		case 7:
		{
			ssd1306_WriteString("7",Font_11x18,COLOR);
			break;
		}
		case 8:
		{
			ssd1306_WriteString("8",Font_11x18,COLOR);
			break;
		}
		case 9:
		{
			ssd1306_WriteString("9",Font_11x18,COLOR);
			break;
		}
	}
}
