#ifndef __TICKET
#define __TICKET
#include "String.h"
#include "Vector.h"
#include "Ticket.h"
enum State
{
	FREE,
	BOUGHT,
	RESERVED,
};

class Ticket {
private:
	String eventName;
	size_t rowNumber;
	size_t seatNumber;
	String password;
	String notes;
	State state;

public:
	Ticket();
	Ticket(const size_t rowNumberParam, const size_t seatNumberParam, const State& stateParam);

	bool isFree()const;
	bool isReserved()const;
	bool isBought()const;
	void reserve();
	void buy(const String& passwordParam, const String& notesParam);
	void cancelReservation(const String& passwordParam, const String& notesParam);
	void setPassword(const String &passwordParam);
	void setNotes(const String& notesParam);
	void printSeat()const;

	friend std::ostream& operator<< (std::ostream& out, const Ticket& t);

};
#endif // !__TICKET

