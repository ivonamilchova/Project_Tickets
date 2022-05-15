#ifndef __EVENT
#define __EVENT
#include "String.h"
#include "Date.h"
#include "Vector.h"
#include "Ticket.h"
#include "Auditorium.h"

class Event {
private:
	Date date;
	String eventName;
	size_t auditoriumNumber;
	Vector<Vector<Ticket>> tickets;

public:
	Event();
	Event(const Date& dateParam, const String& eventNameParam, const size_t& auditoriumNumberParam, const Auditorium& audit);
	String getName() const;
	Ticket& getTicket(const size_t rowNumber, const size_t seat);
	Date getEventDate()const;
	size_t getAuditNumber()const;
	void freeSeats()const;
	void reportForReservedTicketSaveToFile(const char* fileName);
	size_t boughtTickets() const;

	friend std::ostream& operator<< (std::ostream& out,const Event & e);

};
#endif // !__EVENT
