#ifndef __STRING_H
#define __STRING_H

#include <iostream>
#define DEFAULT_CAPACITY 8

class String
{
private:
	char* data;
	size_t capacity;

	void copy(const char* dataParam, size_t capacityParam);
	void resize();
	void del();
public:
	String();
	String(const String& other);
	String(const char* other);
	String& operator=(const String& other);
	~String();


	size_t getSize() const;
	size_t getCapacity() const;
	String& append(const String& other);
	String& append(const char* other);
	void pushBack(char c);
	bool isEmpty() const;
	String& swap(String& other);

	void print()const;

	String& operator+=(const String& other);


	char operator[](size_t index) const;
	char& operator[](size_t index);

	bool operator!=(const String& other);
	bool operator==(const String& other);

	friend std::istream& operator>> (std::istream& in, String& s);
	friend std::ostream& operator<< (std::ostream& out,const String& s);
};

#endif