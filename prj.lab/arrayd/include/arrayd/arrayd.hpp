#pragma once
#ifndef ARRAY_DOUBLE_2023
#define ARRAY_DOUBLE_2023

#include <cstddef>
#include <iostream>
#include <stdexcept>

class ArrayD {
public:
	ArrayD() = default;
	ArrayD(const std::ptrdiff_t n);
	ArrayD(const std::ptrdiff_t n, double to_fill);
	ArrayD(const ArrayD& arr) noexcept;

	double& operator[](std::ptrdiff_t i);
	const double& operator[](const std::ptrdiff_t i) const;
	ArrayD& operator=(const ArrayD& arr) noexcept;

	void in_range(const ptrdiff_t& index) const;
	void resize(const std::ptrdiff_t new_size);
	void push_back(const double& el);
	void insert(std::ptrdiff_t index, const double& el);
	void remove(const std::ptrdiff_t ind);
	double& back() const;
	bool empty();
	std::ptrdiff_t ssize() const noexcept;

	~ArrayD() {
		delete[] start_;
		start_ = nullptr;
	}

private:
	std::ptrdiff_t array_size_ = { 0 };
	int capacity_ = 0;
	double* start_ = { nullptr };
};

#endif