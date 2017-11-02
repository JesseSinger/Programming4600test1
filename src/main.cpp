#include <stdio.h> 
#include <stdlib.h>  
#include <matrix.h>


int main(void)  
{  
	//matrix M(4);
	matrix M(2,1,1,2);
	matrix M2(3,3,3,3);
	M.multiply(2);
	M.element(1,0);
	M.determinant();
	M.inverse();
	M.multiply(M2);
   	M.print();
}  