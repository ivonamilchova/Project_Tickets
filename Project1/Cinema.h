#ifndef __CINEMA
#define __CINEMA
#include "Vector.h"
#include "Event.h"
#include "Auditorium.h"


class Cinema {
private:
	Vector<Event> events;
	Vector<Auditorium> audits;

public:
	void setAudits();
	void setEvents();
	Cinema();
	void addEvent();
	void buyTicket();
	void reserveTicket();
	void cancelTicket();
	void reportFreeSeats();
	void saveToFileReportForReservations();
	void reportForBoughtTickets();

};
#endif // !__CINEMA
