#pragma once

#include <memory>
#include <initializer_list>

template<class Data>
class CircularBuffer
{
public:
	explicit CircularBuffer(const std::initializer_list<Data>& list); // Fixed size
	~CircularBuffer();

	void push_front(const Data& data);
	void pop_front();

	void push_back(const Data& data);	

	Data* begin() const;
	Data* end() const;

	std::size_t size() const;
	std::size_t max_size() const;

	void clear();

private:
	std::unique_ptr<Data[]> m_data;
	Data*                   m_start;
	Data*                   m_end;
	std::size_t             m_size;
	std::size_t             m_max_size;
};

#include "CircularBuffer.inl"
