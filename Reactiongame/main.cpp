#include <wiringPi.h>
#include "Pi_in.h"
#include "Pi_out.h"
#include "iomanager.h"
#include <vector>
#include <iostream>
#include <string>
#include <random>
// LED-PIN - wiringPi-PIN 0 ist BCM_GPIO 17.
// Wir müssen bei der Initialisierung mit wiringPiSetupSys die BCM-Nummerierung verwenden.
// Wenn Sie eine andere PIN-Nummer wählen, verwenden Sie die BCM-Nummerierung, und
// aktualisieren Sie die Eigenschaftenseiten – Buildereignisse – Remote-Postbuildereignisbefehl 
// der den GPIO-Export für die Einrichtung für wiringPiSetupSys verwendet.
#define	PIN_LED_P1	8
#define	PIN_LED_P2 9
#define PIN_LED_ST 0
#define PIN_B_P1 15
#define PIN_B_P2 16

//By Marc Lampee Baumgartner ad Lukas Lösel

int main(void) // MFA split this in a bunch of shorter methods, 20-30 lines is good. more than 60 is bad
{
	wiringPiSetup();

	Io_manager Io_m_pi;
	Io_manager *TOP;
	TOP = &Io_m_pi;

	Pi_out LED_Player_1(LOW, PIN_LED_P1); 
	Pi_out LED_Player_2(LOW, PIN_LED_P2); 
	Pi_out LED_ST(LOW, PIN_LED_ST);

	Pi_Input Button_P1(*TOP, TRUE, PIN_B_P1);
	Pi_Input Button_P2(*TOP, TRUE, PIN_B_P2);
	//Pi_Input Button_P1(TRUE, PIN_B_P1); 
	//Pi_Input Button_P2(TRUE, PIN_B_P2);

	int rounds = 0;
	int round_counter = 0;

	int wincount_1 = 0;
	int wincount_2 = 0;
	int random_delay = 0;
	int cyclecount = 0;

	std::string player1;
	std::string player2;

	std::cout << "Seas, Spüller 1, schreib dein namen eini! " << std::endl;
	std::cin >> player1;
	std::cout << "\nSeas, Spüller 2, schreib dein namen eini! " << std::endl;
	std::cin >> player2;

	while (rounds <= 0 || rounds > 10)//Damit man nur gültige Zahl eingeben kann
	{
		std::cout << "\nSeas, wie vülle rundn magstn spülln? " << std::endl;
		std::cin >> rounds;
	}

	std::cout << "\nJetzt gehts um!" << std::endl;
	LED_Player_1.set_0();
	LED_Player_2.set_0();

	delay(5000);
	random_delay = rand() % 3001;
	//LED_ST.set_1(); nochmal testen was das hier soll

	while (round_counter<rounds)
	{

		delay(1);
		if (cyclecount >= random_delay)
		{
			LED_ST.set_1();
		}


		if (Button_P1.get_state())
		{
			if(LED_ST.ask_state())
			{
				wincount_1++;
				LED_Player_1.set_1();
				std::cout << "Player 1 wins" << std::endl;
				delay(3000);
				LED_Player_1.set_0();
				LED_ST.set_0();
			}
			else
			{
				wincount_2++;
				std::cout << "Player 2 wins, da 1er war zufria" << std::endl;
				LED_Player_2.set_1();
				delay(3000);
				LED_Player_2.set_0();
				LED_ST.set_0();
			}
			round_counter++;
			cyclecount = 0;
			delay(5000);
			random_delay = rand() % 3001;
		}
		else if (Button_P2.get_state())
		{
			if (LED_ST.ask_state())
			{
				wincount_2++;
				LED_Player_2.set_1();
				std::cout << "Player 2 wins" << std::endl;
				delay(3000);
				LED_Player_2.set_0();
				LED_ST.set_0();
			}
			else
			{
				wincount_1++;
				LED_Player_1.set_1();
				std::cout << "Player 1 wins, da 2er war zufria" << std::endl;
				delay(3000);
				LED_ST.set_0();
				LED_Player_1.set_0();
			}
			round_counter++;
			cyclecount = 0;
			delay(5000);
			random_delay = rand() % 3001;
		}

		cyclecount++;
	}

	std::cout << "\nAuswertung: \n" << std::endl;

	if(wincount_1 > wincount_2)
		std::cout << "\nSpieler 1 gewinnt mit: "<<wincount_1<< " Punkten\n" << std::endl;
	else if(wincount_2 > wincount_1)
		std::cout << "\nSpieler 2 gewinnt mit: " << wincount_2 << " Punkten\n" << std::endl;
	else if(wincount_1 == wincount_2)
		std::cout << "\nUnentschieden" << std::endl;


	return 0;
}