#include "Vector.h"
#include "String.h"
#include "Event.h"
#include "Cinema.h"
#include <iostream>


void showMenu(char& c)
{
	std::cout << "0. Exit program\n";
	std::cout << "1. Add event\n";
	std::cout << "2. Report for free seats\n";
	std::cout << "3. Reserve ticket\n";
	std::cout << "4. Cancel reservation\n";
	std::cout << "5. Buy ticket\n";
	std::cout << "6. List with reservation\n";
	std::cout << "7. Report for bought tickets\n";

	std::cout << "Your choice: ";
	std::cin >> c;
}

void run(Cinema& c) {
	char function = '1';

	while (function != '0')
	{
		showMenu(function);

		switch (function)
		{
		case '1': {
			c.addEvent();
			break;
		}

		case '2': {
			c.reportFreeSeats();
			break;
		}

		case '3': {
			c.reserveTicket();
			break;
		}
		case '4': {
			c.cancelTicket();
			break;
		}
		case '5': {
			c.buyTicket();

			break;
		}
		case '6': {
			c.saveToFileReportForReservations();
			break;
		}
		case '7': {
			c.reportForBoughtTickets();
			break;
		}

		default:
			break;
		}
	}
}

int main()
{
	Cinema c;
	run(c);

	return 0;
}