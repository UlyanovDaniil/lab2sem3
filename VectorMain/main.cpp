#include <iostream>

#include "DynamicVector.h"
#include "DynamicMatrix.h"
#include "VectorIterator.h"
#include "LowTriangleMatrix.h"

#include "DynamicVectorTest.h"
#include "DynamicMatrixTest.h"

int main()
{
	run_all_vector_test();

	std::cout << "\n";

	run_all_matrix_test();

	std::cout << "\n";

  return 0;
}