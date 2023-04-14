#include <arrayd/arrayd.hpp>
#include <iostream>


ArrayD::ArrayD(const std::ptrdiff_t n) {
	if (n < 0) {
		throw std::invalid_argument("Invalid argument");
	}
	array_size_ = n;
	start_ = new double[n] {0.0};
	capacity_ = 2 * n;
}

ArrayD::ArrayD(const std::ptrdiff_t n, double to_fill) {
	if (n < 0) {
		throw std::invalid_argument("Invalid argument");
	}
	array_size_ = n;
	start_ = new double[n];
	capacity_ = 2 * n;
	for (int i = 0; i < n; i += 1) {
		start_[i] = to_fill;
	}
}

ArrayD::ArrayD(const ArrayD& arr) noexcept {
	double* new_start = new double[arr.ssize()*2];
	if (new_start != nullptr) {
		for (int i = 0; i < arr.ssize(); i += 1) {

			new_start[i] = arr[i];
		}
		array_size_ = arr.ssize();
		capacity_ = arr.capacity_;
		start_ = new_start;
	}

}



void ArrayD::in_range(const ptrdiff_t& index) const {
	if (index < 0 || index >= array_size_) {
		throw std::out_of_range("Out of range");
	}
}

double& ArrayD::operator[](std::ptrdiff_t i)
{
	in_range(i);
	return *(start_ + i);
}

const double& ArrayD::operator[](const std::ptrdiff_t i) const {
	in_range(i);
	return *(start_ + i);
}


ArrayD& ArrayD::operator=(const ArrayD& arr) noexcept {
	if (&arr != this) {
		double* new_start = new double[arr.ssize()*2];
		if (new_start != nullptr) {
			for (int i = 0; i < arr.ssize(); i += 1) {
				new_start[i] = arr[i];
			}
			array_size_ = arr.ssize();
			capacity_ = arr.capacity_;
			start_ = new_start;
		}
	}
	return *this;
}


void ArrayD::resize(const std::ptrdiff_t new_size) {
	if (new_size <= 0) {
		throw std::invalid_argument("Invalid argument");
	}
	if (new_size <= capacity_) {
		array_size_ = new_size;
		return;
	}
	// ÀËÀÐÌ ÀËÀÐÌ ÀËÀÐÌ
	double* new_start = new double[new_size * 2] {0.0};
	if (new_start != nullptr) {
		for (int i = 0; i < ssize(); i += 1) {
			new_start[i] = start_[i];
		}
		delete[] start_;
		start_ = new_start;
		array_size_ = new_size;
		capacity_ = new_size * 2;
	}
}

void ArrayD::push_back(const double& el) {
	resize(ssize() + 1);
	start_[ssize() - 1] = el;
}

void ArrayD::insert(std::ptrdiff_t index, const double& el) {
	array_size_ += 1;
	in_range(index);
	array_size_ -= 1;
	push_back(el);
	for (int i = ssize() - 1; i >= index + 1; i -= 1) {
		if (i - 1 >= 0) {
			std::swap(start_[i], start_[i - 1]);
		}
		else {
			break;
		}
	}
}
void ArrayD::remove(const std::ptrdiff_t ind) {
	in_range(ind);
	for (int i = ind; i < ssize() - 1; i += 1) {
		std::swap(start_[i], start_[i + 1]);
	}
	array_size_ -= 1;
}

double& ArrayD::back() const {
	return start_[ssize() - 1];
}

bool ArrayD::empty() {
	return ssize() == 0;
}


std::ptrdiff_t ArrayD::ssize() const noexcept {
	return array_size_;
}