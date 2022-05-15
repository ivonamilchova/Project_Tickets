#include "Vector.h"

template<typename T>
void Vector<T>::resize(const size_t newSizeParam)
{

	if (newSizeParam * 2 > this->capacity) {

		this->capacity = 2 * newSizeParam;

		T* dataCopy = new T[this->capacity];

		for (size_t i = 0; i < this->size; i++)
		{
			dataCopy[i] = this->data[i];
		}
		delete[] this->data;
		this->data = dataCopy;
	}

	if (newSizeParam < this->capacity / 2) {
		this->capacity /= 2;

		T* dataCopy = new T[this->capacity];

		for (size_t i = 0; i < this->size; i++)
		{
			dataCopy[i] = this->data[i];
		}

		delete[] this->data;
		this->data = dataCopy;
	}
}

template<typename T>
void Vector<T>::copy(const T* dataParam, const size_t sizeParam, const size_t capacityParam)
{
	this->size = sizeParam;
	this->capacity = capacityParam;

	this->data = new T[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		this->data[i] = dataParam[i];
	}
}

template<typename T>
void Vector<T>::del()
{
	delete[] this->data;
}

template<typename T>
Vector<T>::Vector() : size(0), capacity(DEFAULT_CAPACITY)
{
	this->data = new T[this->capacity];
}

template<typename T>
Vector<T>::Vector(size_t capacityParam) :size(0), capacity(capacityParam)
{
	this->data = new T[this->capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->copy(other.data, other.size, other.capacity);
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = other.data;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other) {
		this->del();
		this->copy(other.data, other.size, other.capacity);
	}
	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other)
{
	if (this != &other) {
		this->del();

		this->size = other.size;
		this->capacity = other.capacity;
		this->data = other.data;

		other.data = nullptr;
		other.size = 0;
		other.capacity = 0;
	}
	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	this->del();
}

template<typename T>
size_t Vector<T>::getCapacity() const
{
	return this->capacity;
}

template<typename T>
size_t Vector<T>::getSize() const
{
	return this->size;
}

template<typename T>
T Vector<T>::getAt(size_t index) const
{
	if (index >= this->size) {
		throw "The index is out of bounds";
	}
	return this->data[index];
}

template<typename T>
T& Vector<T>::getAt(size_t index)
{
	if (index >= this->size) {
		throw "The index is out of bounds\n";
	}
	return this->data[index];
}

template<typename T>
bool Vector<T>::isEmpty() const
{

	return this->size == 0;
}

template<typename T>
T Vector<T>::getFirst() const
{
	if (this->size == 0)
	{
		throw "Data is empty.\n";
	}
	return this->data[0];
}

template<typename T>
T Vector<T>::getLast() const
{
	if (size == 0) {
		throw "There is no last element\n";
	}
	return this->data[size - 1];
}

template<typename T>
void Vector<T>::assign(const size_t n, const T& x)
{
	this->size = n;
	this->resize(n);

	for (size_t i = 0; i < this->size; i++)
	{
		this->data[i] = x;
	}


}

template<typename T>
void Vector<T>::pushBack(const T& x)
{
	this->size++;
	this->resize(this->size);
	this->data[size - 1] = x;
}

template<typename T>
void Vector<T>::popBack()
{
	this->size--;
	this->resize(this->size);
}

template<typename T>
void Vector<T>::removeAt(size_t index)
{
	if (index >= this->size) {
		throw "The index is out of bounds\n";
	}

	for (size_t i = index; i < this->size - 1; i++)
	{
		this->data[i] = this->data[i + 1];
	}
	this->size--;
	this->resize();
}

template<typename T>
bool Vector<T>::operator==(const Vector<T>& other) const
{
	if (this->size == other.size && this->capacity == other.capacity) {
		for (size_t i = 0; i < this->size; i++)
		{
			if (this->data[i] != other.data[i]) {
				return false;
			}
		}
		return true;
	}

	return false;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other)
{
	Vector<T> newData(*this);
	for (size_t i = 0; i < other.size; i++)
	{
		newData.pushBack(other.data[i]);
	}
	return newData;

}

template<typename T>
T& Vector<T>::operator[](size_t index)
{
	if (index >= this->size) {
		throw "The index is out of bounds\n";
	}
	return this->data[index];
}

template<typename T>
T Vector<T>::operator[](size_t index) const
{
	if (index >= this->size) {
		throw "The index is out of bounds\n";
	}
	return this->data[index];
}

template<typename U>
std::ostream& operator<<(std::ostream& out, const Vector<U>& other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		out << other.data[i] << " ";
	}
	return out;
}

template<typename U>
std::istream& operator>>(std::istream& in, Vector<U>& other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		in >> other.data[i];
	}
	return in;
}