#include "Ticket.h"

Ticket::Ticket()
{
	this->eventName = "";
	this->rowNumber = 0;
	this->seatNumber = 0;
	this->password = "";
	this->notes = "";
	this->state = FREE;
}

Ticket::Ticket(const size_t rowNumberParam, const size_t seatNumberParam, const State& stateParam)
{
	this->rowNumber = rowNumberParam;
	this->seatNumber = seatNumberParam;
	this->state = stateParam;
}

bool Ticket::isFree() const
{
	return this->state == FREE;
}

bool Ticket::isReserved() const
{
	return this->state == RESERVED;
}

bool Ticket::isBought() const
{
	return this->state == BOUGHT;
}

void Ticket::reserve()
{
	this->state = RESERVED;
	std::cout << "Successful reservation!\n";
	return;

}

void Ticket::buy(const String& passwordParam, const String& notesParam)
{
	if (this->state == FREE)
	{
		this->state = BOUGHT;
		std::cout << "You successfully bought the ticket!\n";

		return;
	}

	if (this->state == RESERVED && this->password == passwordParam && this->notes == notesParam) {
		this->state = BOUGHT;
		std::cout << "You successfully bought the ticket !\n";
		return;
	}
	std::cout << "You failed to buy the ticket!\n";
}

void Ticket::cancelReservation(const String& passwordParam, const String& notesParam)
{
	if (this->state == RESERVED && this->password == passwordParam && this->notes == notesParam) {
		this->state = FREE;
		std::cout << "You successfully freed the ticket!\n";
		return;
	}
	std::cout << "You failed to free the ticket!\n";
}

void Ticket::setPassword(const String& passwordParam)
{
	this->password = passwordParam;
}

void Ticket::setNotes(const String& notesParam)
{
	this->notes = notesParam;
}

void Ticket::printSeat() const
{
	std::cout << this->seatNumber << " ";
}

std::ostream& operator<<(std::ostream& out, const Ticket& t)
{
	out <<"Event: "<< t.eventName << "\nRow: " << t.rowNumber <<"\nSeat: " << t.seatNumber;
	return out;
}
