#ifndef __VECTOR_H
#define __VECTOR_H

#include <iostream>

#define DEFAULT_CAPACITY 8

template <typename T>
class Vector
{
private:
	T* data;
	size_t size;
	size_t capacity;

	void resize(const size_t newSizeParam);
	void copy(const T* dataParam, const size_t sizeParam, const size_t capacityParam);
	void del();
public:
	Vector();
	Vector(size_t capacityParam);

	Vector(const Vector<T>& other);
	Vector(Vector<T>&& other) noexcept;

	Vector<T>& operator=(const Vector<T>& other);
	Vector<T>& operator=(Vector<T>&& other);
	~Vector();

	size_t getCapacity() const;
	size_t getSize() const;
	T getAt(size_t index) const;
	T& getAt(size_t index);

	bool isEmpty() const;

	T getFirst() const;
	T getLast() const;

	void assign(const size_t n, const T& x);
	void pushBack(const T& x);
	void popBack();
	void removeAt(size_t index);
	bool operator==(const Vector<T>& other) const;
	Vector<T> operator+(const Vector<T>& other);

	T& operator[](size_t index);
	T operator[](size_t index) const;

	template<typename U>
	friend std::ostream& operator<<(std::ostream& out, const Vector<U>& other);

	template<typename U>
	friend std::istream& operator>>(std::istream& in, Vector<U>& other);
};



#include "Vector.inl"

#endif

