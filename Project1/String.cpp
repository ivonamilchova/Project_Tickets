#include "String.h"
#include <cstring>

void String::copy(const char* dataParam, size_t capacityParam)
{
	this->capacity = capacityParam;
	this->data = new char[this->capacity + 1];
	strcpy_s(this->data, strlen(dataParam) + 1, dataParam);
	this->data[strlen(dataParam)] = 0;

}

void String::resize()
{
	this->capacity *= 2;
	char* dataCopy = new char[this->capacity + 1];
	strcpy_s(dataCopy, strlen(this->data) + 1, this->data);
	dataCopy[strlen(this->data) + 1] = '\0';

	this->data = dataCopy;
	dataCopy = nullptr;
}

void String::del()
{
	delete[] this->data;
}

String::String()
{
	this->capacity = DEFAULT_CAPACITY;
	this->data = new char[DEFAULT_CAPACITY + 1];
	this->data[0] = '\0';
}

String::String(const String& other)
{
	this->copy(other.data, other.capacity);
}

String::String(const char* other)
{
	this->copy(other, strlen(other));
}

String& String::operator=(const String& other)
{
	if (this != &other) {
		this->del();
		this->copy(other.data, other.capacity);
	}
	return *this;
}

String::~String()
{
	this->del();
}

size_t String::getSize() const
{
	return strlen(this->data);
}

size_t String::getCapacity() const
{
	return this->capacity;
}

String& String::append(const String& other)
{
	for (size_t i = 0; i < strlen(other.data) + 1; i++)
	{
		this->pushBack(other.data[i]);
	}
	return *this;
}

String& String::append(const char* other)
{
	for (size_t i = 0; i < strlen(other) + 1; i++)
	{
		this->pushBack(other[i]);
	}
	return *this;
}

void String::pushBack(char c)
{
	if (strlen(this->data) + 1 > this->capacity) {
		this->resize();
	}
	this->data[(strlen(this->data))] = c;

	this->data[(strlen(this->data)) + 1] = 0;
}

bool String::isEmpty() const
{
	return this->data[0] == 0;
}

String& String::swap(String& other)
{
	String tmp;
	strcpy_s(tmp.data, strlen(this->data) + 1, this->data);
	tmp.data[strlen(this->data)] = 0;
	tmp.capacity = this->capacity;


	strcpy_s(this->data, strlen(other.data) + 1, other.data);
	this->data[strlen(other.data)] = 0;
	this->capacity = other.capacity;

	strcpy_s(other.data, strlen(tmp.data) + 1, tmp.data);
	other.data[strlen(tmp.data)] = 0;
	other.capacity = tmp.capacity;
	return *this;

}


void String::print() const
{
	for (size_t i = 0; i < strlen(this->data); i++)
	{
		std::cout << this->data[i];
	}
}

String& String::operator+=(const String& other)
{
	return this->append(other);
}

char String::operator[](size_t index) const
{
	return this->data[index];
}

char& String::operator[](size_t index)
{
	return this->data[index];
}

bool String::operator!=(const String& other)
{
	if (strlen(this->data) != strlen(other.data)) {
		return true;
	}
	if (strlen(this->data) == strlen(other.data) && strcmp(this->data, other.data) != 0) {
		return true;
	}

	return false;
}

bool String::operator==(const String& other)
{
	return !(this->operator!=(other));
}

std::istream& operator>>(std::istream& in, String& s)
{
	in >> s.data;
	return in;
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << s.data;
	return out;
}
