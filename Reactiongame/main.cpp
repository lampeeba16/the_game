#include <wiringPi.h>
#include "Pi_in.h"
#include "Pi_out.h"
#include "iomanager.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "json.hpp"
#include "buttoncheck.h"

// LED-PIN - wiringPi-PIN 0 ist BCM_GPIO 17.
// Wir müssen bei der Initialisierung mit wiringPiSetupSys die BCM-Nummerierung verwenden.
// Wenn Sie eine andere PIN-Nummer wählen, verwenden Sie die BCM-Nummerierung, und
// aktualisieren Sie die Eigenschaftenseiten – Buildereignisse – Remote-Postbuildereignisbefehl 
// der den GPIO-Export für die Einrichtung für wiringPiSetupSys verwendet.


//By Marc Lampee Baumgartner ad Lukas Lösel

int main(void) // MFA split this in a bunch of shorter methods, 20-30 lines is good. more than 60 is bad
{

	using json = nlohmann::json;
	//json file lesen
	std::ifstream i("pins.json");
	json j;
	i >> j;

	wiringPiSetup();

	Io_manager Io_m_pi;

	Pi_out LED_Player_1(Io_m_pi, LOW, j["p1_led"].get<int>());
	Pi_out LED_Player_2(Io_m_pi, LOW, j["p2_led"].get<int>());
	Pi_out LED_ST(Io_m_pi, LOW, j["state"].get<int>());

	Pi_Input Button_P1(Io_m_pi, TRUE, j["p1_button"].get<int>());
	Pi_Input Button_P2(Io_m_pi, TRUE, j["p2_button"].get<int>());

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

	while (round_counter<rounds)
	{

		delay(1);
		if (cyclecount >= random_delay)
		{
			LED_ST.set_1();
		}

		buttoncheck(LED_Player_1,LED_Player_2,LED_ST,Button_P1, Button_P2);
		
		cyclecount++;
	}

	std::cout << "\nAuswertung: \n" << std::endl;

	if(wincount_1 > wincount_2)
		std::cout << "\n" << player1<< " gewinnt mit: "<<wincount_1<< " Punkten\n" << std::endl;
	else if(wincount_2 > wincount_1)
		std::cout << "\n" << player2 << " gewinnt mit: " << wincount_2 << " Punkten\n" << std::endl;
	else if(wincount_1 == wincount_2)
		std::cout << "\nUnentschieden" << std::endl;


	return 0;
}