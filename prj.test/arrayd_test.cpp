#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <doctest/doctest.h>
#include <arrayd/arrayd.hpp>


TEST_CASE("construct") {
	ArrayD first;
	ArrayD second(4);
	ArrayD third(3, 6.6);
	ArrayD fourth = third;
	for (int i = 0; i < 3; i += 1) {
		third[i] *= 2 * i;
	}
	CHECK(first.ssize() == 0);
	CHECK(second.ssize() == 4);
	CHECK(third.ssize() == 3);
	CHECK(fourth.ssize() == 3);
	CHECK(third[1] != fourth[1]);
}

TEST_CASE("push_back+insert") {
	ArrayD m;

	m.push_back(0);
	m.push_back(1);
	m.push_back(2);
	m.push_back(3);
	m.push_back(4);
	m.insert(3, 100);
	CHECK(m.ssize() == 6);
	CHECK(m[3] == 100);
	CHECK(m[4] == 3);
}
TEST_CASE("remove") {
	ArrayD m;
	m.push_back(0);
	m.push_back(1);
	m.push_back(2);
	m.push_back(3);
	m.push_back(4);
	for (int i = 0; i < m.ssize(); i += 1) {
		std::cout << m[i] << " ";
	}
	m.remove(3);
	std::cout << "\n";
	for (int i = 0; i < m.ssize(); i += 1) {
		std::cout << m[i] << " ";
	}
	CHECK(m.ssize() == 4);
	CHECK(m[3] == 4);
}
TEST_CASE("struggle") {
	ArrayD m;
	m.push_back(0);
	m.push_back(1);
	m.push_back(2);
	m.push_back(3);
	m.push_back(4);
	CHECK_THROWS(m[5]);
}

TEST_CASE("friend test") {
	ArrayD arr;
	CHECK_THROWS(arr[0]);
	CHECK(arr.ssize() == 0);
	arr.resize(5);
	for (int i = 0; i < arr.ssize(); i++) {
		CHECK(arr[i] == 0.0);
	}
	CHECK_THROWS(arr[7]);
	arr[1] = 56.24;
	CHECK(arr[1] == 56.24);
	ArrayD arr1(arr);
	for (int i = 0; i < arr1.ssize(); i++) {
		CHECK(arr1[i] == arr[i]);
	}
	arr1[1] = 78.25;
	CHECK(arr1[1] != arr[1]);
	arr1 = arr;
	for (int i = 0; i < arr1.ssize(); i++) {
		CHECK(arr1[i] == arr[i]);
	}
	arr.remove(3);
	CHECK(arr[0] == arr1[0]);
	CHECK(arr[1] == arr1[1]);
	CHECK(arr[2] == arr1[3]);
	CHECK(arr[3] == arr1[4]);
	arr.insert(3, 5.5);
	CHECK(arr[0] == arr1[0]);
	CHECK(arr[1] == arr1[1]);
	CHECK(arr[2] == arr1[3]);
	CHECK(arr[3] == 5.5);
	CHECK(arr[4] == arr1[4]);
}