#ifndef __AUDITORIUM
#define __AUDITORIUM
#include "Vector.h"

class Auditorium {
private:
	Vector<size_t> seats;

	size_t numberOfAudit;

public:
	Auditorium();
	Auditorium(const Vector<size_t>& seatsParam, const size_t numberOfAuditParam);


	size_t getSeatsAt(const size_t& index) const;
	size_t getSize() const;
	size_t getNumber() const;


};

#endif // !__AUDITORIUM

