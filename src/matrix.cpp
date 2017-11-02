#include <matrix.h>
#include <stdio.h>
#include <stdlib.h>  
#include <iostream>
matrix::matrix()
{
	/*
		This constructor (the default constructor) creates a matrix with all zero elements
	*/

	e00 = e01 = e10 = e11 = 0;
}

matrix::matrix(double a)
{
	/*
		This constructor should create a diagonal matrix with the diagonal elements equal to a and
		the other elements equal to zero.
		*/
	e00 = a;
	e01 = e10 = e11 = 0;
	//printf ("%.3f %.3f \n%.3f %.3f", a, e01, e10, e11); // prints a 2x2 matrix with element 10 as a, and all other numbers as 0


}

matrix::matrix(double a, double b, double c, double d)
{
	/*
		This constructor should set the elements the values of the elements using the
		parameters a,b,c,d

	*/
	e00 = a;
	e01 = b;
	e10 = c;
	e11 = d;
	//printf ("%.3f %.3f \n%.3f %.3f", a, b, c, d); // prints a 2x2 matrix with elements a, b, c, d as e00, e01, e10, and e11 respectively
}

matrix::matrix(const matrix& a)
{
	/*
		This is the copy constructor: it takes a matrix and makes a new one with the same element values
	*/

	e00 = a.e00;
	e01 = a.e01;
	e10 = a.e10;
	e11 = a.e11;
}

matrix& matrix::add(matrix& a)
{
	/*
		The add member function adds the elements of matrix 'a' to this matrix. 
		[A]+[B] = [A+B]
	*/

	e00 = e00 + a.e00;
	e01 = e01 + a.e01;
	e10 = e10 + a.e10;
	e11 = e11 + a.e11;

	return *this;
}

matrix& matrix::multiply(double x)
{
	/*
		The multiply member function multplies the elements of this matrix by a scalar. x*[M]=[xM]
	*/
	double b00, b01, b10, b11;
	b00 = e00*x;
	b01 = e01*x;
	b10 = e10*x;
	b11 = e11*x;
	printf("\nThe scalar multiplied matrix is:");
	printf("\n|%.3f %.3f| \n|%.3f %.3f|\n", b00, b01, b10, b11); // prints a 2x2 matrix with elements a, b, c, d as e00, e01, e10, and e11 respectively

	return *this;
}


matrix& matrix::multiply(matrix& a)
{
	/*
		This function multiplies the matrix M by the matrix a ie [M]*[A]=[MA]
	*/
	double new00, new01, new10, new11;
	new00 = (e00*a.e00) + (e01*a.e10);
	new01 = (e00*a.e01) + (e01*a.e11);
	new10 = (e10*a.e00)+(e11*a.e10);
	new11 = (e10*a.e01)+(e11*a.e11);

printf("\nThe resultant matrix multiplied matrix is:");
	printf ("\n|%.3f %.3f| \n|%.3f %.3f|\n", new00, new01, new10, new11); // prints a 2x2 matrix with elements a, b, c, d as e00, e01, e10, and e11 respectively

	return *this;
}

//This function is used to determine the element of the target matrix with input of row, column
double matrix::element(int row,int column)
{
	int a, b;
	a = row;
	b = column;
	printf("\n\nThe matrix element with row = %i, and column = %i\n", a,b);
	if(a == 0 && b == 0)
	{
		printf("\n%.3f", e00);
	}

	if(a == 0 && b == 1)
	{
		printf("\n%.3f", e01);
	}
	if(a == 1 && b == 0)
	{
		printf ("\n%.3f", e10);
	}
	if(a == 1 && b == 1)
	{
		printf("\n%.3f", e11);
	}
}

//This function is used to determine the determinant of the target matrix
double matrix::determinant()
{
	double determinant = (e00*e11)-(e01*e10);
	printf("\n");
	printf("The determinant of the matrix is:\n");
	printf("%.2f", determinant);
	return determinant;
}

//This function is used to determine the inverse of the target matrix
matrix& matrix::inverse()
{
	double inverseDeterminant = 1/((e00*e11)-(e01*e10));
	//printf("\nInverse Determinant is:%.2f", inverseDeterminant);
	int a = 0;
	a = e00;
	double c00, c01, c10, c11;
	c00 = e11*inverseDeterminant;
	c11 = a*inverseDeterminant;
	c01 = -e01*inverseDeterminant;
	c10 = -e10*inverseDeterminant;
	printf("\n\nThe inverse of Matrix M is:\n|%.3f %.3f| \n|%.3f %.3f|\n", c00, c01, c10, c11);
	return *this;
}

//this function will print the matrix
void matrix::print()
{
	printf("\nThe matrix requested is:");
	printf ("\n|%.3f %.3f| \n|%.3f %.3f|\n", e00, e01, e10, e11);
}