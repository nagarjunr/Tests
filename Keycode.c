#include <stdio.h>
#include <string.h>
// #include <stdlib.h>
//#include <conio.h>


/*
AUTHOR: zobayer
INSTRUCTION:
just make this file a header like "conio.h"
and use the getch() and getche() functions.
*/
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* reads from keypress, doesn't echo */
unsigned char getch(void)
{
   struct termios oldattr, newattr;
   long ch;
   tcgetattr( STDIN_FILENO, &oldattr );
   newattr = oldattr;
   newattr.c_lflag &= ~( ICANON | ECHO );
   tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
   ch = (long)getchar();   //Xuming, no need to set to long.
   tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
   return ch;
}

// unsigned char getch(void)
// {
//    struct termios oldattr, newattr;
//    unsigned long ch;
//    tcgetattr( STDIN_FILENO, &oldattr );
//    newattr = oldattr;
//    newattr.c_lflag &= ~( ICANON | ECHO );
//    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
//    ch = (unsigned long)getchar();
//    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
//    return ch;
// }
 

/* reads from keypress, echoes */
int getche(void)
{
   struct termios oldattr, newattr;
   int ch;
   tcgetattr( STDIN_FILENO, &oldattr );
   newattr = oldattr;
   newattr.c_lflag &= ~( ICANON );
   tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
   ch = getchar();
   tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
   return ch;
}


void gotoxy (int x, int y)
{
printf("%c[%d;%df", 0x1b, y, x);
}

void clrscr (void)
{
system("clear");
}
 
 

// void showMainMenu()
// { 
// 	clrscr();
// 	printf("\n");
// 	printf("\n");
// 	printf("A) Read S)Export D)Import F)Reset  Marlin EEPROM          ID:1234-6789)\n");
// 	printf("P) PID turning (Auto save to EEPROM)                      PW:abcd-efgh)\n");
// 	printf("T) Z-offset adjustment(Tool box)                          T: 185.2/185.0\n");
// 	printf("M) Show details in EEPROM                                 B: 23.4/60\n");
// 	printf("L) LED test.                                              X=66.6\n");
// 	printf("N) Ethernet and  Wifi test.                               Y=55.5\n");
// 	printf("1) 2) 3) 4) 5) 6) 7) 8) 9) 0) Run gCode file (*1)         Z=123.67\n");
// 	printf("G:gCode command  H: Help   Q. Quit                        E=1.234\n");
// 	printf("================================= Press a key  ");
// }

long KeyPressed[20] = {0};

enum KeyPressed{Key1 = 49, Key2 = 50, Key3 = 51, Key4 = 52, Key5 = 53, Key6 = 54, Key7 = 55, Key8 = 56, Key9 = 57,
//			 KeyA = 65, Keya = 97,
//			 KeyB = 66, Keyb = 98,
//			 KeyC = 67, Keyc = 99,
//			 KeyD = 68, Keyd = 100,
			 KeyE = 69, Keye = 101,
			 KeyI = 73, Keyi = 105,
			 KeyP = 80, Keyp = 112,
			 KeyQ = 81, Keyq = 113,
			 KeyR = 82, Keyr = 114,
			 KeyS = 83, Keys = 115,
			 KeyUp = 279165, KeyCtrlUp = 279149595365, KeyShiftUp = 279149595065,
			 KeyDown = 279166, KeyCtrlDown = 279149595366, KeyShiftDown = 279149595066,
			 KeyRight = 279167, KeyCtrlRight = 279149595367, KeyShiftRight = 279149595067,
			 KeyLeft = 279168, KeyCtrlLeft = 279149595368, KeyShiftLeft = 279149595068,
			 KeyNotAvailable =0,
};

unsigned long main(void)
{
	long KeyCode = 0;
	unsigned int keyJustPressed;
	unsigned char keyJustPressedChar[3] = {0};
	// unsigned char final[]
	unsigned char KeyPress[20] = {0};
	int index = 0;
	int loop = 0;

	while (1)
	{
	// 	//showMainMenu();
	// 	// printf("Last key is  %ld \n", keyCode);
		// strcpy(keyCode,getch());
		// printf("%ld\n", keyCode);
 
	// }

	// 	while (1)
	// {
		// printf("index : %d\n",index);
		// &KeyPress[index] = keyCode;

		keyJustPressed = getch();
		sprintf(keyJustPressedChar,"%d\0",keyJustPressed);
		strncat(&KeyPress[index],&keyJustPressedChar,strlen(keyJustPressedChar));
		printf("keyJustPressedChar : %s\n",KeyPress);


		// printf("keyJustPressed : %ld\n",keyJustPressed);

		// strcpy(KeyPress,keyJustPressed,2);
		index = index+strlen(keyJustPressedChar);

		// for (int i = 0; i < 20 ; i++)
		// {
		// 	printf("Keypress[%d] : %c\n",i, KeyPress[i]);
		// }
		// printf("KeyPress[0]: %c Keypress[1] : %c")
		// KeyPress[strlen(KeyPress)] = '\0';
		// index = strlen(KeyPress);

		

			loop += 1;

		KeyCode = atol(KeyPress);
		if (loop == 1)
		{
			switch (KeyCode)
			{
				case Key1:			return Key1; //1
				case Key2:			return Key2; //2
				case Key3:			return Key3; //3
				case Key4:			return Key4; //4
				case Key5:			return Key5; //5
				case Key6:			return Key6; //6
				case Key7:			return Key7; //7
				case Key8:			return Key8; //8
				case Key9:			return Key9; //9
	//			case KeyA:			return KeyA; //A
	//			case Keya:			return KeyA; //a
	//			case KeyB:			return KeyB;
	//			case Keyb:			return KeyB;
				case KeyE: 			return KeyE;
				case Keye:			return KeyE;
				case KeyI:			return KeyI;
				case Keyi:			return KeyI;
				case KeyP:			return KeyP;
				case Keyp:			return KeyP;
				case KeyQ:			return KeyQ;
				case Keyq:			return KeyQ;
				case KeyR:			return KeyR;
				case Keyr:			return KeyR;
				case KeyS:			return KeyS;
				case Keys:			return KeyS;
				if (KeyCode == 27)
				{
					continue;
				}
				else
				{
					return KeyNotAvailable;
				}
			}
			//Check First two digits
		}
		if (loop == 2)
		{
			if (KeyCode == 2791)
				{
					continue;
				}
				else
				{
					return KeyNotAvailable;
				}
			//Check First four digits
		}
		if (loop == 3)
		{
			switch (KeyCode)
			{
				case KeyUp:			return KeyUp;
				case KeyDown:		return KeyDown;

				if (KeyCode == 279149)
				{
					continue;
				}
				else
				{
					return KeyNotAvailable;
				}
			}
			//Check First six digits
		}
		if (loop == 4)
		{
			if (KeyCode == 27914959)
				{
					continue;
				}
				else
				{
					return KeyNotAvailable;
				}
			//Check 8 digits
		}
		if (loop == 5)
		{
			if (KeyCode == 2791495950 || KeyCode == 2791495953)
				{
					continue;
				}
				else
				{
					return KeyNotAvailable;
				}
			//Check 10 digits
		}
		if (loop == 6)
		{
			switch (KeyCode)
			{
				case KeyCtrlUp:		return KeyCtrlUp;
				case KeyShiftUp:	return KeyShiftUp;
				case KeyCtrlDown:	return KeyCtrlDown;
				case KeyShiftDown:	return KeyShiftDown;
				default:			return KeyNotAvailable;
			}
			//Check 12 digits, if not found return 0
		}

	}
	// printf("The number is %ld \n", keyCode);
 
}