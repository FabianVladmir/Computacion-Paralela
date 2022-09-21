#include <iostream>
#include <ctime> 
#include <chrono>

using namespace std;

void mulMat(int **mat1, int **mat2, int lenMatrix, int **result) {
	

	// cout << "Multiplication of given two matrices is:\n" << endl;

	for (int i = 0; i < lenMatrix; i++) {
		for (int j = 0; j < lenMatrix; j++) {		

			for (int k = 0; k < lenMatrix; k++) {
				result[i][j] += mat1[i][k] * mat2[k][j];
			}			
		}		
	}
}

void initialize(int **mat1, int **mat2, int lenMatrix, int **result){

	for(int i=0 ; i<lenMatrix ; i++){
        for(int j=0; j<lenMatrix; j++){
            mat1[i][j]=1+rand()%20;
            mat2[i][j]=1+rand()%20;
            result[i][j]=0;
        }
    }
}




int main(void) {
	
	// int mat1[R1][C1] = {
	// 		{1, 1, 1, 1},
	// 		{2, 2, 2, 2},
	// 		{3, 3, 3, 3},
	// 		{4, 4, 4, 4}
	// };

	// int mat2[R2][C2] = {
	// 		{1, 1, 1, 1},
	// 		{2, 2, 2, 2},
	// 		{3, 3, 3, 3},
	// 		{4, 4, 4, 4}
	// };

	// if (C1 != R2) {
	// 	cout << "The number of columns in Matrix-1 must be equal to the number of rows in "
	// 			"Matrix-2" << endl;
	// 	return 0;
	// }

	int sz;
	cin >> sz;

	int **mat1 = new int *[sz];
	int **mat2 = new int *[sz];
	int **result = new int *[sz];

	for(int i=0;i<sz;i++){
		mat1[i] = new int[sz];
        mat2[i] = new int[sz];
        result[i] = new int[sz];
	}

	
	initialize(mat1,mat2,sz,result);


	auto start = chrono::steady_clock::now();
	mulMat(mat1, mat2,sz,result);
	auto end = chrono::steady_clock::now();

	cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;


	for (int i = 0; i < sz; i++)
	{
		delete[] mat1[i];
        delete[] mat2[i];
        delete[] result[i];
	}
	delete [] mat1;
    delete [] mat2;
    delete [] result;

	return 0;
}


