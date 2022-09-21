/*Esquema: asigne n/p filas de A a un procesador. 
Con esto: cada procesador necesita acceder a n/p filas de A y X,
 pero a todo Y. Cada procesador calculará n^2/p elementos de A realizando n^3/p o
 peraciones de multiplicación y suma para hacerlo.
Mientras que el tiempo de cálculo disminuye en proporción a p, el costo de comunicación
 (número total de errores de caché) aumenta en proporción a p, porque Y debe cargarse en su 
 totalidad en la memoria caché de cada procesador. El número total de errores de caché es n^2/c + p*n^2/c.*/
#include <iostream>
using namespace std;

void mulMatBloq(int **mat1, int **mat2, int lenMatrix, int **result){
  int ii,jj,kk,i,j,k;
  int blocksz=lenMatrix;
  for (ii = 0; ii < lenMatrix; ii+=blocksz) {
    for (jj = 0; jj < lenMatrix; jj+=blocksz) {
      for (kk = 0; kk < lenMatrix; kk+=blocksz) {
        for (i = ii; i < ii+blocksz; i++) {
          for (j = jj; j < jj+blocksz; j++) {
            for (k = kk; k < kk+blocksz; k++) {
              result[i,j] += mat1[i,k]*mat2[k,j];
            }
          }
        }
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