#pragma once
#include <iostream>
#include "DynamicMatrix.h"

void test_matrix_can_create_matrix_positive_size_constructor()
{
	try
	{
		TDynamicMatrix<int> m1(3);
		std::cout << "OK - test_matrix_can_create_matrix_positive_size_constructor";
	}
	catch (char c)
	{
		std::cout << "FAIL - test_matrix_can_create_matrix_positive_size_constructor";
	}
	std::cout << "\n";
}

void test_matrix_can_create_matrix_negative_size_constructor()
{
	try
	{
		TDynamicMatrix<int> m1(-3);
		std::cout << "FAIL - test_matrix_can_create_matrix_negative_size_constructor";
	}
	catch (char c)
	{
		std::cout << "OK - test_matrix_can_create_matrix_negative_size_constructor";
	}
	std::cout << "\n";
}

void test_matrix_ñan_create_matrix_copy_constructor()
{
	TDynamicMatrix<int> m1(3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 4; m1[1][2] = 6;
	m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;
	TDynamicMatrix<int> m2(m1);
	if (m1 == m2)
	{
		std::cout << "OK - test_matrix_can_create_matrix_copy_constructor";
	}
	else
	{
		std::cout << "FAIL - test_matrix_can_create_matrix_copy_constructor";
	}
	std::cout << "\n";
}

void test_matrix_operator_copy_matrix()
{
	TDynamicMatrix<int> m1(3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 4; m1[1][2] = 6;
	m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;
	TDynamicMatrix<int> m2 = m1;
	if (m1 == m2)
	{
		std::cout << "OK - test_matrix_operator_copy_matrix";
	}
	else
	{
		std::cout << "FAIL - test_matrix_operator_copy_matrix";
	}
	std::cout << "\n";
}

void test_matrix_size_matrix()
{
	tsize sz = 3;
	TDynamicMatrix<int> m1(sz);
	if (m1.size() == sz)
	{
		std::cout << "OK - test_matrix_size_matrix";
	}
	else
	{
		std::cout << "FAIL - test_matrix_size_matrix";
	}
	std::cout << "\n";
}

void test_matrix_operator_positive_index()
{
	TDynamicMatrix<int> m1(3);
	try
	{
		m1[1];
		std::cout << "OK - test_matrix_operator_positive_index";
	}
	catch (char c)
	{
		std::cout << "FAIL - test_matrix_operator_positive_index";
	}
	std::cout << "\n";
}

void test_matrix_operator_negative_index()
{
	TDynamicMatrix<int> m1(3);
	try
	{
		m1[-2];
		std::cout << "FAIL - test_matrix_operator_negative_index";
	}
	catch (char c)
	{
		std::cout << "OK - test_matrix_operator_negative_index";
	}
	std::cout << "\n";
}

void test_matrix_operator_campare()
{
	TDynamicMatrix<int> m1(3), m2(3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 4; m1[1][2] = 6;
	m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;

	m2[0][0] = 1; m2[0][1] = 2; m2[0][2] = 3;
	m2[1][0] = 4; m2[1][1] = 4; m2[1][2] = 6;
	m2[2][0] = 7; m2[2][1] = 8; m2[2][2] = 9;
	if (m1 == m2)
	{
		std::cout << "OK - test_matrix_operator_campare";
	}
	else
	{
		std::cout << "FAIL - test_matrix_operator_campare";
	}
	std::cout << "\n";
}

void test_matrix_operator_negative_campare()
{
	TDynamicMatrix<int> m1(3), m2(3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;
	m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;

	m2[0][0] = 10; m2[0][1] = 11; m2[0][2] = 12;
	m2[1][0] = 13; m2[1][1] = 14; m2[1][2] = 15;
	m2[2][0] = 16; m2[2][1] = 17; m2[2][2] = 18;
	if (m1 != m2)
	{
		std::cout << "OK - test_matrix_operator_negative_campare";
	}
	else
	{
		std::cout << "FAIL - test_matrix_operator_negative_campare";
	}
	std::cout << "\n";
}

void test_matrix_operator_addition_value()
{
	int t = 2;
	TDynamicMatrix<int> m1(3), m2(3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;
	m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;

	m2[0][0] = 1 + t; m2[0][1] = 2 + t; m2[0][2] = 3 + t;
	m2[1][0] = 4 + t; m2[1][1] = 5 + t; m2[1][2] = 6 + t;
	m2[2][0] = 7 + t; m2[2][1] = 8 + t; m2[2][2] = 9 + t;
	if (m1 + t == m2)
	{
		std::cout << "OK - test_matrix_operator_addition_value";
	}
	else
	{
		std::cout << "FAIL - test_matrix_operator_addition_value";
	}
	std::cout << "\n";
}

void test_matrix_operator_subtraction_value()
{
	int t = 2;
	TDynamicMatrix<int> m1(3), m2(3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;
	m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;

	m2[0][0] = 1 - t; m2[0][1] = 2 - t; m2[0][2] = 3 - t;
	m2[1][0] = 4 - t; m2[1][1] = 5 - t; m2[1][2] = 6 - t;
	m2[2][0] = 7 - t; m2[2][1] = 8 - t; m2[2][2] = 9 - t;
	if (m1 - t == m2)
	{
		std::cout << "OK - test_matrix_operator_subtraction_value";
	}
	else
	{
		std::cout << "FAIL - test_matrix_operator_subtraction_value";
	}
	std::cout << "\n";
}

void test_matrix_operator_multiplication_value()
{
	int t = 2;
	TDynamicMatrix<int> m1(3), m2(3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;
	m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;

	m2[0][0] = 1 * t; m2[0][1] = 2 * t; m2[0][2] = 3 * t;
	m2[1][0] = 4 * t; m2[1][1] = 5 * t; m2[1][2] = 6 * t;
	m2[2][0] = 7 * t; m2[2][1] = 8 * t; m2[2][2] = 9 * t;
	if (m1 * t == m2)
	{
		std::cout << "OK - test_matrix_operator_multiplication_value";
	}
	else
	{
		std::cout << "FAIL - test_matrix_operator_multiplication_value";
	}
	std::cout << "\n";
}

void test_matrix_operator_addition_matrix()
{
	TDynamicMatrix<int> m1(3), m2(3), m3(3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;
	m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;

	m2[0][0] = 10; m2[0][1] = 11; m2[0][2] = 12;
	m2[1][0] = 13; m2[1][1] = 14; m2[1][2] = 15;
	m2[2][0] = 16; m2[2][1] = 17; m2[2][2] = 18;

	m3[0][0] = 1 + 10; m3[0][1] = 2 + 11; m3[0][2] = 3 + 12;
	m3[1][0] = 4 + 13; m3[1][1] = 5 + 14; m3[1][2] = 6 + 15;
	m3[2][0] = 7 + 16; m3[2][1] = 8 + 17; m3[2][2] = 9 + 18;
	if (m1 + m2 == m3)
	{
		std::cout << "OK - test_matrix_operator_addition_matrix";
	}
	else
	{
		std::cout << "FAIL - test_matrix_operator_addition_matrix";
	}
	std::cout << "\n";
}

void test_matrix_operator_addition_matrix_different_size()
{
	TDynamicMatrix<int> m1(3), m2(4);
	try
	{
		m1 + m2;
		std::cout << "FAIL - test_matrix_operator_addition_matrix_different_size";
	}
	catch (char c)
	{
		std::cout << "OK - test_matrix_operator_addition_matrix_different_size";
	}
	std::cout << "\n";
}

void test_matrix_operator_subtraction_matrix()
{
	TDynamicMatrix<int> m1(3), m2(3), m3(3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;
	m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;

	m2[0][0] = 10; m2[0][1] = 11; m2[0][2] = 12;
	m2[1][0] = 13; m2[1][1] = 14; m2[1][2] = 15;
	m2[2][0] = 16; m2[2][1] = 17; m2[2][2] = 18;

	m3[0][0] = 1 - 10; m3[0][1] = 2 - 11; m3[0][2] = 3 - 12;
	m3[1][0] = 4 - 13; m3[1][1] = 5 - 14; m3[1][2] = 6 - 15;
	m3[2][0] = 7 - 16; m3[2][1] = 8 - 17; m3[2][2] = 9 - 18;
	if (m1 - m2 == m3)
	{
		std::cout << "OK - test_matrix_operator_subtraction_matrix";
	}
	else
	{
		std::cout << "FAIL - test_matrix_operator_subtraction_matrix";
	}
	std::cout << "\n";
}

void test_matrix_operator_subtraction_matrix_different_size()
{
	TDynamicMatrix<int> m1(3), m2(4);
	try
	{
		m1 - m2;
		std::cout << "FAIL - test_matrix_operator_subtraction_matrix_different_size";
	}
	catch (char c)
	{
		std::cout << "OK - test_matrix_operator_subtraction_matrix_different_size";
	}
	std::cout << "\n";
}

void test_matrix_operator_multiplication_matrix()
{
	TDynamicMatrix<int> m1(3), m2(3), m3(3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;
	m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;

	m2[0][0] = 10; m2[0][1] = 11; m2[0][2] = 12;
	m2[1][0] = 13; m2[1][1] = 14; m2[1][2] = 15;
	m2[2][0] = 16; m2[2][1] = 17; m2[2][2] = 18;

	m3[0][0] = 1 * 10 + 2 * 13 + 3 * 16; m3[0][1] = 1 * 11 + 2 * 14 + 3 * 17; m3[0][2] = 1 * 12 + 2 * 15 + 3 * 18;
	m3[1][0] = 4 * 10 + 5 * 13 + 6 * 16; m3[1][1] = 4 * 11 + 5 * 14 + 6 * 17; m3[1][2] = 4 * 12 + 5 * 15 + 6 * 18;
	m3[2][0] = 7 * 10 + 8 * 13 + 9 * 16; m3[2][1] = 7 * 11 + 8 * 14 + 9 * 17; m3[2][2] = 7 * 12 + 8 * 15 + 9 * 18;
	if (m1 * m2 == m3)
	{
		std::cout << "OK - test_matrix_operator_multiplication_matrix";
	}
	else
	{
		std::cout << "FAIL - test_matrix_operator_multiplication_matrix";
	}
	std::cout << "\n";
}

void test_matrix_operator_multiplication_matrix_different_size()
{
	TDynamicMatrix<int> m1(3), m2(4);
	try
	{
		m1* m2;
		std::cout << "FAIL - test_matrix_operator_multiplication_matrix_different_size";
	}
	catch (char c)
	{
		std::cout << "OK - test_matrix_operator_multiplication_matrix_different_size";
	}
	std::cout << "\n";
}

void run_all_matrix_test()
{
	test_matrix_can_create_matrix_positive_size_constructor();
	test_matrix_can_create_matrix_negative_size_constructor();
	test_matrix_ñan_create_matrix_copy_constructor();
	test_matrix_operator_copy_matrix();
	test_matrix_size_matrix();
	test_matrix_operator_positive_index();
	test_matrix_operator_negative_index();
	test_matrix_operator_campare();
	test_matrix_operator_negative_campare();
	test_matrix_operator_addition_value();
	test_matrix_operator_subtraction_value();
	test_matrix_operator_multiplication_value();
	test_matrix_operator_addition_matrix();
	test_matrix_operator_addition_matrix_different_size();
	test_matrix_operator_subtraction_matrix();
	test_matrix_operator_subtraction_matrix_different_size();
	test_matrix_operator_multiplication_matrix();
	test_matrix_operator_multiplication_matrix_different_size();
}