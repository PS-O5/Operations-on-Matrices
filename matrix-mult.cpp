#include <stdio.h>
#include <iostream>

double matA[10][10], matB[10][10];
int rowA, colA, rowB, colB;

void matrixEntry();
void matrixPrinter(double inputMatrix[10][10], int rows, int cols);
void matrixMultiplier(double mat1[10][10], int row1, int col1, double mat2[10][10],  int row2, int col2);
int main()
{
	std::cout << "Operations on two Matrices" << std::endl;
	matrixEntry();
	return 0;
}

void matrixEntry()
{
	std::cout << "Enter the rows of matrix A:" << std::endl;
	std::cin >> rowA;
	std::cout << "Enter the columns of matrix A:" << std::endl;
	std::cin >> colA;
	std::cout << "Enter the rows of matrix B:" << std::endl;
	std::cin >> rowB;
	std::cout << "Enter the columns of matrix B:" << std::endl;
	std::cin >> colB;
	for(int i = 0; i < rowA; i++)
	{
		for(int j = 0; j < colA; j++)
		{
			std::cout << "Enter the " << i+1 << j+1 << " element of matrix A: ";
			std::cin >> matA[i][j];
		}	
	}
	for(int i = 0; i < rowB; i++)
	{
		for(int j = 0; j < colB; j++)
		{
			std::cout << "Enter the " << i+1 << j+1 << " element of matrix B: ";
			std::cin >> matB[i][j];
		}
	}
	matrixPrinter(matA, rowA, colA);
	matrixPrinter(matB, rowB, colB);
	std::cout << "What operations would you like to perform on A & B" << std::endl;
	std::cout << "Addition(0), Subtraction(1), Multiplication(2)" << std::endl;
	int buff;
	std::cin >> buff;
	if(buff == 2)
	{
		matrixMultiplier(matA, rowA, colA, matB, rowB, colB);
	}
}

void matrixPrinter(double inputMatrix[10][10], int rows, int cols)
{
	double printMatrix[10][10];
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			printMatrix[i][j] = inputMatrix[i][j];
			std::cout << printMatrix[i][j] << " ";
			if(j+1 == cols)
			{
				std::cout << std::endl;
			}
		}
	
	}
}

void matrixMultiplier(double mat1[10][10], int row1, int col1, double mat2[10][10], int row2, int col2)
{
	double product[10][10];
	if(col1 != row2)
	{
		std::cout << "Multiplication of given matrices is not possible!" << std::endl;
		matrixEntry();
	}
	for(int i = 0; i < row1; i++)
	{
		for(int j= 0; j < col2; j++)
		{
			product[i][j] = 0;	///Important otherwise the initial value will add up in final product
			for(int k = 0; k < col1; k++)	///can be col1 or row2 because both mean same
			{
				product[i][j]  += mat1[i][k] * mat2[k][j];
			}
		}
	}
	std::cout << "Product of A & B :" << std::endl;
	matrixPrinter(product, row1, col2);
}
