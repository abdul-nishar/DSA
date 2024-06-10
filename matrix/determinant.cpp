#include <iostream>
#include <vector>
using namespace std;

void swapRow(vector<vector <int>>& arr, int N, int row1, int row2){
    for(int i=0;i<N;i++) swap(arr[row1][i],arr[row2][i]);
}

int gcd(int x, int y){
    int greatestdivisor;
    int smallerNumber = (x<y) ? x : y;
    for(int i=1;i<=smallerNumber;i++){
        if(x%i==0 && y%i==0){
            greatestdivisor = i;
        }
    }
    return greatestdivisor;
}

long long lcm(int x, int y){
    long long product = x * y;
    return product/gcd(x,y);
}

int determinant(vector<vector<int> >& A, int N) {
    long long int det = 1,total = 1;

    int temp[N + 1];

    for(int i = 0; i < N; i++){
        int pivot = i;

        while (pivot < N && A[pivot][i] == 0) pivot++;
	
		if (pivot == N) continue;

        if(pivot != i){
            swapRow(A,N, pivot, i);
            det = det * pow(-1, pivot - i);
        }

        for (int j = 0; j < N; j++) temp[j] = A[i][j];

        for(int j = i + 1; j < N; j++){
            if(A[j][i] == 0) continue;
            long long commonDiv = lcm(A[i][i], A[j][i]);
            int curRowFactor = commonDiv / A[j][i];
            int diagonalFactor = commonDiv / A[i][i];

            for(int k = i; k < N; k++){
                A[j][k]= (temp[i] * A[j][k]) - (A[j][i] * temp[k]);
            }

            total *= temp[i];
        }
    }

    for(int i = 0; i < N; i++){
         det = det * A[i][i];
    }
    return det/total;
}

int main(){
    vector<vector <int>> arr1 = {{8,1,2,-8,-6},{-2,8,-9,-8,10},{-2,-4,2,2,6},{-1,-2,8,10,-1},{3,7,0,4,4}};
    cout << determinant(arr1,5);
    return 0;
} 