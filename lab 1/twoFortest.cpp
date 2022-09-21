// #include <iostream>
// #include <ctime>
// #include <cstring>
// using namespace std;

// const int MAX = 1000;

// int main(){

//     double A[MAX][MAX], x[MAX], y[MAX];
//     clock_t start, end;
    
    
//     for(int i=0 ; i<MAX ; i++){
//         for(int j=0; j<MAX; j++){
//             int curr=1+rand()%20;
//             A[i][j] = curr;
//         }
//     }

//     for(int i=0; i<MAX ; i++)
//     {
//         int curr=1+rand()%20;
//         x[i]=curr;
//     }

//     for (int it = 1000; it < 7000; it+=500)
//     {
        
//         cout << "size" << it << endl;

//         start = clock();
//         for ( int i = 0; i < it ; i++)
//             for ( int j = 0; j < it ; j++)
//                 y[i] += A[i][j] * x[j];
//         end = clock();

//         double time0 = (double(end-start)/CLOCKS_PER_SEC);
//         cout << "Block 1: " << time0 << endl;
        
//         start = clock();
//         for ( int j = 0; j < it ; j++)
//             for ( int i = 0; i < it ; i++)
//                 y[i] += A[i][j] * x[j];
//         end = clock();

//         double time1 = (double(end-start)/CLOCKS_PER_SEC);
//         cout << "Block 2: " << time1 << endl;

//     }
    

//     start = clock();
//     for ( int i = 0; i < MAX ; i++)
//         for ( int j = 0; j < MAX ; j++)
//             y[i] += A[i][j] * x[j];
//     end = clock();

//     double time0 = (double(end-start)/CLOCKS_PER_SEC);
//     cout << "Block 1: " << time0 << endl;
    
//     start = clock();
//     for ( int j = 0; j < MAX ; j++)
//         for ( int i = 0; i < MAX ; i++)
//             y[i] += A[i][j] * x[j];
//     end = clock();

//     double time1 = (double(end-start)/CLOCKS_PER_SEC);
//     cout << "Block 2: " << time1 << endl;

//     return 0;
// }




#include <iostream>
#include <ctime>

const int MAX = 10000;

double A[MAX][MAX], x[MAX], y[MAX], time__;

int main() {

    std::clock_t start, end;
    int i, j;

    for (i = 0; i < MAX; ++i) {
        for (j = 0; j < MAX; ++j) {
            A[i][j] = 1;
        }
        x[i] = 1;
    }
    
    for (int k = 1000; k <= 10000; k+=1000) {
        
        std::cout << "size: " << k << '\n';

        start = clock();
        for (i = 0; i < k; ++i) 
            for (j = 0; j < k; ++j)
                y[i] += A[i][j] * x[j];
        end = clock();

        time__ = double(end - start)/CLOCKS_PER_SEC;
        std::cout << "Block 1: " << time__ << '\n';


        start = clock();
        for (j = 0; j < k; ++j) 
            for (i = 0; i < k; ++i)
                y[i] += A[i][j] * x[j];
        end = clock();

        time__ = double(end - start)/CLOCKS_PER_SEC;
        std::cout << "Block 2: " << time__ << '\n';

    }
    
    return 0;
}