#include "Cinema.h"
#include <iostream>
#include <fstream>
void Cinema::setAudits()
{
	size_t size;
	std::cout << "Input number of the auditoriums: ";
	std::cin >> size;


	for (size_t i = 0; i < size; i++)
	{
		Vector<size_t> tmp;
		size_t numberOfAudit;
		std::cout << "---------------------------------------------------------\n";
		std::cout << "Input number of the auditorium:";
		std::cin >> numberOfAudit;

		size_t sizeRows;
		std::cout << "Input number of rows in the auditorium: ";
		std::cin >> sizeRows;

		for (size_t i = 0; i < sizeRows; i++)
		{
			size_t tmpSeats;
			std::cout << "Input number of seats of row " << i <<": ";
			std::cin >> tmpSeats;
			tmp.pushBack(tmpSeats);
		}
		std::cout << "---------------------------------------------------------\n";
		Auditorium a(tmp, numberOfAudit);
		this->audits.pushBack(a);
	}
}

void Cinema::setEvents()
{
	size_t size;
	std::cout << "Input number of the events: ";
	std::cin >> size;

	for (size_t i = 0; i < size; i++)
	{
		Date d;
		d.init();

		String eventName;
		std::cout << "Input the name of event: ";
		std::cin >> eventName;

		size_t auditNumber;
		std::cout << "Input the number of the auditorium of the event: ";
		std::cin >> auditNumber;

		for (size_t i = 0; i < audits.getSize(); i++)
		{
			if (auditNumber == audits[i].getNumber()) {
				Event e(d, eventName, auditNumber, audits[i]);
				this->events.pushBack(e);
				break;
			}
		}
	}

}

Cinema::Cinema()
{
	this->setAudits();
}

void Cinema::addEvent()
{
	Date d;
	d.init();

	String eventName;
	std::cout << "Input the name of event: ";
	std::cin >> eventName;

	size_t auditNumber;
	std::cout << "Input the number of the auditorium of the event: ";
	std::cin >> auditNumber;

	for (size_t i = 0; i < audits.getSize(); i++)
	{
		if (auditNumber == audits[i].getNumber()) {
			Event e(d, eventName, auditNumber, audits[i]);
			this->events.pushBack(e);
			break;
		}
	}
}

void Cinema::buyTicket()
{
	std::cout << "Input the name of event: ";
	String eventName;
	std::cin >> eventName;

	size_t rowNumber;
	std::cout << "Input row: ";
	std::cin >> rowNumber;

	size_t seatNumber;
	std::cout << "Input seat: ";
	std::cin >> seatNumber;

	size_t eventSize = events.getSize();
	for (size_t i = 0; i < eventSize; i++)
	{
		if (eventName == events[i].getName()) {
			Ticket& t = events[i].getTicket(rowNumber, seatNumber);
			if (t.isFree()) {
				t.buy("", "");
			}
			else if (t.isReserved()) {
				std::cout << "Input the password: ";
				String password;
				std::cin >> password;

				std::cout << "Input the notes: ";
				String notes;
				std::cin >> notes;

				t.buy(password, notes);
			}
			break;
		}
	}


}

void Cinema::reserveTicket()
{
	std::cout << "Input the name of event: ";
	String eventName;
	std::cin >> eventName;

	size_t rowNumber;
	std::cout << "Input row: ";
	std::cin >> rowNumber;

	size_t seatNumber;
	std::cout << "Input seat: ";
	std::cin >> seatNumber;

	size_t eventSize = events.getSize();
	for (size_t i = 0; i < eventSize; i++)
	{
		if (eventName == events[i].getName()) {
			Ticket& t = events[i].getTicket(rowNumber, seatNumber);
			if (t.isFree()) {
				std::cout << "Enter the password: ";
				String password;
				std::cin >> password;

				std::cout << "Enter the notes: ";
				String notes;
				std::cin >> notes;
				t.setPassword(password);
				t.setNotes(notes);
				t.reserve();
			}
			else
			{
				std::cout << "Unuccessful reservation!\nThe ticket is not free.\n";
			}
			break;
		}
		
	}
}

void Cinema::cancelTicket()
{
	std::cout << "Input the name of event: ";
	String eventName;
	std::cin >> eventName;

	size_t rowNumber;
	std::cout << "Input row: ";
	std::cin >> rowNumber;

	size_t seatNumber;
	std::cout << "Input seat: ";
	std::cin >> seatNumber;

	size_t eventSize = events.getSize();
	for (size_t i = 0; i < eventSize; i++)
	{
		if (eventName == events[i].getName()) {
			Ticket& t = events[i].getTicket(rowNumber, seatNumber);
			if (t.isReserved()) {
				std::cout << "Enter the password: ";
				String password;
				std::cin >> password;

				std::cout << "Enter the notes: ";
				String notes;
				std::cin >> notes;
				t.cancelReservation(password, notes);
			}
			break;
		}

	}
}

void Cinema::reportFreeSeats()
{
	std::cout << "Input the name of event: ";
	String eventName;
	std::cin >> eventName;

	std::cout << "Input date: ";
	Date date;
	date.init();

	
	size_t eventSize = events.getSize();
	for (size_t i = 0; i < eventSize; i++)
	{
		if (eventName == events[i].getName() && date == events[i].getEventDate()) {
			events[i].freeSeats();	
		}

	}
	
}

void Cinema::saveToFileReportForReservations()
{
	std::cout << "Input the name of event: ";
	String eventName;
	std::cin >> eventName;

	std::cout << "Input the date of event: ";
	std::cout << "1.If you want to input date.\n";
	std::cout << "2.If you want to input ALL.\n";
	char c;
	std::cin >> c;

	Date date;
	String dateAll;
	if (c == '1') {
		date.init();
	}
	else if (c == '2') {
		std::cout << "Input ALL";
		std::cin >> dateAll;
	}

	if (eventName == "ALL" || dateAll == "ALL") {
		for (size_t i = 0; i < events.getSize(); i++)
		{
			char fileName[2048];
			strcpy_s(fileName, strlen("report-")+1, "report-");
			

			events[i].reportForReservedTicketSaveToFile(fileName);
		}
	}
	else 
	{
		for (size_t i = 0; i < events.getSize(); i++)
		{
			if (events[i].getName() == eventName && events[i].getEventDate() == date) {
				char fileName[2048];
				strcpy_s(fileName, strlen("report-") + 1, "report-");


				events[i].reportForReservedTicketSaveToFile(fileName);
				break;
			}
		}
	}
	
	
}

void Cinema::reportForBoughtTickets()
{
	std::cout << "From date: ";
	Date from;
	from.init();

	std::cout << "To date: ";
	Date to;
	to.init();

	std::cout << "Input auditorium number: ";
	size_t auditNumber;
	std::cin >> auditNumber;
	for (size_t i = 0; i < events.getSize(); i++)
	{
		if (events[i].getEventDate() >= from && events[i].getEventDate() <= to && events[i].getAuditNumber() == auditNumber) {
			std::cout << events[i] <<" -> " << events[i].boughtTickets();
		}
	}
}


