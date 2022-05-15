#include "Auditorium.h"

Auditorium::Auditorium()
{
	this->numberOfAudit = 0;
}

Auditorium::Auditorium(const Vector<size_t>& seatsParam, const size_t numberOfAuditParam)
{
	this->seats = seatsParam;
	this->numberOfAudit = numberOfAuditParam;
}


size_t Auditorium::getSeatsAt(const size_t& index) const
{
	return seats.getAt(index);
}

size_t Auditorium::getSize() const
{
	return this->seats.getSize();
}

size_t Auditorium::getNumber() const
{
	return this->numberOfAudit;
}
