#include "piproxy.h"
#include "Pi_in.h"
#include "Pi_out.h"
#include <iostream>

#include <random>
#include "json.hpp"

extern int rounds;
extern int round_counter;

extern int wincount_1;
extern int wincount_2;
extern int random_delay;
extern int cyclecount;


void buttoncheck(Pi_out LED_Player_1,Pi_out LED_Player_2, Pi_out LED_ST, Pi_Input Button_P1, Pi_Input Button_P2)
{
	if (Button_P1.get_state())
	{
		
		if (LED_ST.ask_state())
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
}
