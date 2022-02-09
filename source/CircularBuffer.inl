#include "CircularBuffer.hpp"

template<class Data>
CircularBuffer<Data>::CircularBuffer(const std::initializer_list<Data>& list):
	m_start(nullptr),
	m_end(nullptr),
	m_size(list.size()),
	m_max_size(list.size())
{
	m_data = std::make_unique<Data[]>(m_max_size);

	for (size_t i = 0; i < m_max_size; i++)
		m_data[i] = *(list.begin() + i);

	m_start = m_data.get();
	m_end = m_data.get() + m_max_size;
}

template<class Data>
CircularBuffer<Data>::~CircularBuffer()
{
	clear();
}

template<class Data>
void CircularBuffer<Data>::push_front(const Data& data)
{
	if (auto first = m_start; data != *first)
	{
		for (auto it = m_end - 1; it != first; it--)
			*it = *(it - 1);

		*first = data;
	}
}

template<class Data>
void CircularBuffer<Data>::pop_front()
{
	m_start = m_start + 1;
	m_size--;
}

template<class Data>
void CircularBuffer<Data>::push_back(const Data& data)
{
	if (auto last = m_end - 1; data != *last)
	{
		for (auto it = m_start; it != last; it++)
			*it = *(it + 1);

		*last = data;
	}
}

template<class Data>
Data* CircularBuffer<Data>::begin() const
{
	return m_start;
}

template<class Data>
Data* CircularBuffer<Data>::end() const
{
	return m_end;
}

template<class Data>
std::size_t CircularBuffer<Data>::size() const
{
	return m_size;
}

template<class Data>
std::size_t CircularBuffer<Data>::max_size() const
{
	return m_max_size;
}

template<class Data>
void CircularBuffer<Data>::clear()
{
	m_data.reset();
	m_size = 0;
	m_max_size = 0;
	m_start = nullptr;
	m_end = nullptr;
}