#include "Event.h"
#include <fstream>

Event::Event()
{
	this->eventName = "";
	this->auditoriumNumber = 0;
}

Event::Event(const Date& dateParam, const String& eventNameParam, const size_t& auditoriumNumberParam, const Auditorium& audit)
{
	this->date = dateParam;
	this->eventName = eventNameParam;
	this->auditoriumNumber = auditoriumNumberParam;

	for (size_t i = 0; i < audit.getSize(); i++)
	{
		Vector<Ticket> ts;
		for (size_t j = 0; j < audit.getSeatsAt(i); j++)
		{
			Ticket t(i, j, FREE);
			ts.pushBack(t);
		}
		tickets.pushBack(ts);
	}

}

String Event::getName() const
{
	return this->eventName;
}

Ticket& Event::getTicket(const size_t rowNumber, const size_t seat)
{
	return tickets.getAt(rowNumber).getAt(seat);
}

Date Event::getEventDate() const
{
	return this->date;
}

size_t Event::getAuditNumber() const
{
	return this->auditoriumNumber;
}

void Event::freeSeats() const
{
	for (size_t i = 0; i < this->tickets.getSize(); i++)
	{
		std::cout << "Row " << i << ":";
		for (size_t j = 0; j < this->tickets[i].getSize(); j++)
		{
			
			if (this->tickets.getAt(i).getAt(j).isFree()) {
				this->tickets.getAt(i).getAt(j).printSeat();
			}
		}
		std::cout << "\n";
	}
}

void Event::reportForReservedTicketSaveToFile(const char* fileName)
{
	std::ofstream out(fileName);
	if (!out) {
		std::cout << "File is not open.\n";
		return;
	}

	for (size_t i = 0; i < this->tickets.getSize(); i++)
	{
		out << "ROW" << i << ": ";
		for (size_t j = 0; j < this->tickets[i].getSize(); j++) {
			Ticket& t = this->tickets.getAt(i).getAt(j);
			if (t.isReserved()) {
				out << t;
			}
		}
		out << "\n\n";
	}
	out.close();
}

size_t Event::boughtTickets() const
{
	size_t counter = 0;
	for (size_t i = 0; i < tickets.getSize(); i++)
	{
		for (size_t j = 0; j < tickets[j].getSize(); j++) {
			Ticket& t = tickets.getAt(i).getAt(j);
			if (t.isBought()) {
				counter++;
			}
		}
	}

	return counter;
}

std::ostream& operator<<(std::ostream& out, const Event& e)
{
	out << e.eventName << " - " << e.date << " ";
	return out;
}
