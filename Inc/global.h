#define MIN 0
#define SEC 1
#define MSEC 0

#define GPIOKEY GPIOA
#define BUTTON_1 GPIO_PIN_0
#define BUTTON_2 GPIO_PIN_1
#define BUTTON_3 GPIO_PIN_2

#define COLOR White
#define FON Black

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

static void WriteClock(unsigned short TM,unsigned short TS,unsigned short TmS,int Heigh)
{
  ssd1306_SetCursor(23,Heigh);//?????????? ?????? ???????
  ItoC(TM/10);
  ItoC(TM%10);
  ssd1306_WriteString(":",Font_11x18,COLOR);
  ItoC(TS/10);
  ItoC(TS%10);
  ssd1306_WriteString(":",Font_11x18,COLOR);
  ItoC(TmS);
  //ssd1306_UpdateScreen();
}



static void Reset_State()
{
  Timer=Off;
  T1_min=MIN;
  T1_sec=SEC;
  T1_msec=MSEC;
  T2_min=MIN;
  T2_sec=SEC;
  T2_msec=MSEC;
  Enable_Player1=1;
  Enable_Player2=1;  
}