#pragma once
#ifndef ARRAY_DOUBLE_2023
#define ARRAY_DOUBLE_2023

#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayT {
public:
	ArrayT() = default;
	ArrayT(const std::ptrdiff_t n);
	ArrayT(const std::ptrdiff_t n, T to_fill);
	ArrayT(const ArrayT& arr) noexcept;

	T& operator[](std::ptrdiff_t i);
	const T& operator[](const std::ptrdiff_t i) const;
	ArrayT& operator=(const ArrayT& arr) noexcept;

	void in_range(const ptrdiff_t& index) const;
	void resize(const std::ptrdiff_t new_size);
	void push_back(const T& el);
	void insert(std::ptrdiff_t index, const T& el);
	void remove(const std::ptrdiff_t ind);
	T& back() const;
	bool empty();
	std::ptrdiff_t ssize() const noexcept;

	~ArrayT() {
		delete[] start_;
		start_ = nullptr;
	}

private:
	std::ptrdiff_t array_size_ = { 0 };
	int capacity_ = 0;
	T* start_ = nullptr;
};

#endif