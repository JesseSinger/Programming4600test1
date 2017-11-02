#ifndef __MATRIX_H
#define __MATRIX_H

/*
The matrix class represents a simple 2x2 matrix with elements:

	|  e00  e01  |
	|  e10  e11  |

it contains member functions to add and multiply matrices. it can also find determinants and inverses.


*/

class matrix
{
	double e00;
	double e01;
	double e10;
	double e11;

public:

	matrix();
	matrix(double a); 
	matrix(double a00, double a01, double a10, double a11);
	matrix(const matrix&);

	matrix& add(matrix& a);
	matrix& multiply(double x);  // Multiply the matrix by a scalar
	matrix& multiply(matrix& m);  // Multiply the matrix by another matrix

	double element(int,int); // return the specified element using its column and row number
	double determinant(); // return the determinant of the matrix
	matrix& inverse(); //return the inverse of the matrixs

	void print(); //a function to print out the matrix to the console.
};


#endif