#pragma once
#include <iostream>
#include "DynamicVector.h"

void test_vector_can_create_vector_positive_size_constructor()
{
	try
	{
		TDynamicVector<int> v1(3);
		std::cout << "OK - test_vector_can_create_vector_positive_size_constructor";
	}
	catch (char c)
	{
		std::cout << "FAIL - test_vector_can_create_vector_positive_size_constructor";
	}
	std::cout << "\n";
}

void test_vector_can_create_vector_negative_size_constructor()
{
	try
	{
		TDynamicVector<int> v1(-3);
		std::cout << "FAIL - test_vector_can_create_vector_negative_size_constructor";
	}
	catch (char c)
	{
		std::cout << "OK - test_vector_can_create_vector_negative_size_constructor";
	}
	std::cout << "\n";
}

void test_vector_ñan_create_vector_pointer_and_positive_size_constructor()
{
	tsize sz = 3;
	int* arr = new int[sz];
	try
	{
		TDynamicVector<int> v1(arr, sz);
		std::cout << "OK - test_vector_can_create_vector_pointer_and_positive_size_constructor";
	}
	catch (char c)
	{
		std::cout << "FAIL - test_vector_can_create_vector_pointer_and_positive_size_constructor";
	}
	std::cout << "\n";
}

void test_vector_ñan_create_vector_pointer_and_nagative_size_constructor()
{
	tsize sz = 3;
	int* arr = new int[sz];
	try
	{
		TDynamicVector<int> v1(arr, -sz);
		std::cout << "FAIL - test_vector_can_create_vector_pointer_and_nagative_size_constructor";
	}
	catch (char c)
	{
		std::cout << "OK - test_vector_can_create_vector_pointer_and_negative_size_constructor";
	}
	std::cout << "\n";
}

void test_vector_ñan_create_vector_null_pointer_and_size_constructor()
{
	try
	{
		TDynamicVector<int> v1(nullptr, 3);
		std::cout << "FAIL - test_vector_ñan_create_vector_null_pointer_and_size_constructor";
	}
	catch (char c)
	{
		std::cout << "OK - test_vector_ñan_create_vector_null_pointer_and_size_constructor";
	}
	std::cout << "\n";
}

void test_vector_ñan_create_vector_copy_constructor()
{
	TDynamicVector<int> v1(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 3;
	TDynamicVector<int> v2(v1);
	if (v1 == v2)
	{
		std::cout << "OK - test_vector_can_create_vector_copy_constructor";
	}
	else
	{
		std::cout << "FAIL - test_vector_can_create_vector_copy_constructor";
	}
	std::cout << "\n";
}

void test_vector_operator_copy_vector()
{
	TDynamicVector<int> v1(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 3;
	TDynamicVector<int> v2 = v1;
	if (v1 == v2)
	{
		std::cout << "OK - test_vector_operator_copy_vector";
	}
	else
	{
		std::cout << "FAIL - test_vector_operator_copy_vector";
	}
	std::cout << "\n";
}

void test_vector_size_vector()
{
	tsize sz = 3;
	TDynamicVector<int> v1(sz);
	if (v1.size() == sz)
	{
		std::cout << "OK - test_vector_size_vector";
	}
	else
	{
		std::cout << "FAIL - test_vector_size_vector";
	}
	std::cout << "\n";
}

void test_vector_operator_positive_index()
{
	TDynamicVector<int> v1(3);
	try
	{
		v1[1];
		std::cout << "OK - test_vector_operator_positive_index";
	}
	catch (char c)
	{
		std::cout << "FAIL - test_vector_operator_positive_index";
	}
	std::cout << "\n";
}

void test_vector_operator_negative_index()
{
	TDynamicVector<int> v1(3);
	try
	{
		v1[-2];
		std::cout << "FAIL - test_vector_operator_negative_index";
	}
	catch (char c)
	{
		std::cout << "OK - test_vector_operator_negative_index";
	}
	std::cout << "\n";
}

void test_vector_operator_large_positive_index()
{
	TDynamicVector<int> v1(3);
	try
	{
		v1[5];
		std::cout << "FAIL - test_vector_operator_large_positive_index";
	}
	catch (char c)
	{
		std::cout << "OK - test_vector_operator_large_positive_index";
	}
	std::cout << "\n";
}

void test_vector_operator_campare()
{
	TDynamicVector<int> v1(3), v2(3);
	v1[0] = 3; v1[1] = 4; v1[2] = 5;
	v2[0] = 3; v2[1] = 4; v2[2] = 5;
	if (v1 == v2)
	{
		std::cout << "OK - test_vector_operator_campare";
	}
	else
	{
		std::cout << "FAIL - test_vector_operator_campare";
	}
	std::cout << "\n";
}

void test_vector_operator_nagative_campare()
{
	TDynamicVector<int> v1(3), v2(3);
	v1[0] = 3; v1[1] = 4; v1[2] = 5;
	v2[0] = 1; v2[1] = 2; v2[2] = 3;
	if (v1 != v2)
	{
		std::cout << "OK - test_vector_operator_nagative_campare";
	}
	else
	{
		std::cout << "FAIL - test_vector_operator_nagative_campare";
	}
	std::cout << "\n";
}

void test_vector_operator_addition_value()
{
	int t = 2;
	TDynamicVector<int> v1(3), v2(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 3;
	v2[0] = 1 + t; v2[1] = 2 + t; v2[2] = 3 + t;
	if (v1 + t == v2)
	{
		std::cout << "OK - test_vector_operator_addition_value";
	}
	else
	{
		std::cout << "FAIL - test_vector_operator_addition_value";
	}
	std::cout << "\n";
}

void test_vector_operator_subtraction_value()
{
	int t = 2;
	TDynamicVector<int> v1(3), v2(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 3;
	v2[0] = 1 - t; v2[1] = 2 - t; v2[2] = 3 - t;
	if (v1 - t == v2)
	{
		std::cout << "OK - test_vector_operator_subtraction_value";
	}
	else
	{
		std::cout << "FAIL - test_vector_operator_subtraction_value";
	}
	std::cout << "\n";
}

void test_vector_operator_multiplication_value()
{
	int t = 2;
	TDynamicVector<int> v1(3), v2(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 3;
	v2[0] = 1 * t; v2[1] = 2 * t; v2[2] = 3 * t;
	if (v1 * t == v2)
	{
		std::cout << "OK - test_vector_operator_multiplication_value";
	}
	else
	{
		std::cout << "FAIL - test_vector_operator_multiplication_value";
	}
	std::cout << "\n";
}

void test_vector_operator_addition_vector()
{
	TDynamicVector<int> v1(3), v2(3), v3(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 3;
	v2[0] = 3; v2[1] = 4; v2[2] = 5;
	v3[0] = 1 + 3; v3[1] = 2 + 4; v3[2] = 3 + 5;
	if (v1 + v2 == v3)
	{
		std::cout << "OK - test_vector_operator_addition_vector";
	}
	else
	{
		std::cout << "FAIL - test_vector_operator_addition_vector";
	}
	std::cout << "\n";
}

void test_vector_operator_addition_vector_different_size()
{
	TDynamicVector<int> v1(3), v2(4);
	try
	{
		v1 + v2;
		std::cout << "FAIL - test_vector_operator_addition_vector_different_size";
	}
	catch (char c)
	{
		std::cout << "OK - test_vector_operator_addition_vector_different_size";
	}
	std::cout << "\n";
}

void test_vector_operator_subtraction_vector()
{
	TDynamicVector<int> v1(3), v2(3), v3(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 3;
	v2[0] = 3; v2[1] = 4; v2[2] = 5;
	v3[0] = 1 - 3; v3[1] = 2 - 4; v3[2] = 3 - 5;
	if (v1 - v2 == v3)
	{
		std::cout << "OK - test_vector_operator_subtraction_vector";
	}
	else
	{
		std::cout << "FAIL - test_vector_operator_subtraction_vector";
	}
	std::cout << "\n";
}

void test_vector_operator_subtraction_vector_different_size()
{
	TDynamicVector<int> v1(3), v2(4);
	try
	{
		v1 - v2;
		std::cout << "FAIL - test_vector_operator_subtraction_vector_different_size";
	}
	catch (char c)
	{
		std::cout << "OK - test_vector_operator_subtraction_vector_different_size";
	}
	std::cout << "\n";
}

void test_vector_operator_multiplication_vector()
{
	int t = 1 * 3 + 2 * 4 + 3 * 5;
	TDynamicVector<int> v1(3), v2(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 3;
	v2[0] = 3; v2[1] = 4; v2[2] = 5;
	if (v1 * v2 == t)
	{
		std::cout << "OK - test_vector_operator_multiplication_vector";
	}
	else
	{
		std::cout << "FAIL - test_vector_operator_multiplication_vector";
	}
	std::cout << "\n";
}

void test_vector_operator_multiplication_vector_different_size()
{
	TDynamicVector<int> v1(3), v2(4);
	try
	{
		v1 * v2;
		std::cout << "FAIL - test_operator_multiplication_vector_different_size";
	}
	catch (char c)
	{
		std::cout << "OK - test_operator_multiplication_vector_different_size";
	}
	std::cout << "\n";
}

void run_all_vector_test()
{
	test_vector_can_create_vector_positive_size_constructor();
	test_vector_can_create_vector_negative_size_constructor();
	test_vector_ñan_create_vector_pointer_and_positive_size_constructor();
	test_vector_ñan_create_vector_pointer_and_nagative_size_constructor();
	test_vector_ñan_create_vector_null_pointer_and_size_constructor();
	test_vector_ñan_create_vector_copy_constructor();
	test_vector_operator_copy_vector();
	test_vector_size_vector();
	test_vector_operator_positive_index();
	test_vector_operator_negative_index();
	test_vector_operator_large_positive_index();
	test_vector_operator_campare();
	test_vector_operator_nagative_campare();
	test_vector_operator_addition_value();
	test_vector_operator_subtraction_value();
	test_vector_operator_multiplication_value();
	test_vector_operator_addition_vector();
	test_vector_operator_addition_vector_different_size();
	test_vector_operator_subtraction_vector();
	test_vector_operator_subtraction_vector_different_size();
	test_vector_operator_multiplication_vector();
	test_vector_operator_multiplication_vector_different_size();
}