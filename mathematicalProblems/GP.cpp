#include <iostream>
double termOfGP(int A,int B,int N)
    {
        //Your code here
        double ratio = B/double(A);
        std::cout <<ratio << std::endl;
        return A*pow(ratio,N-1);
    }
int main(){
    int a,b,n;
    std::cin >> a >> b >> n;
    std::cout<<termOfGP(a,b,n)<<std::endl;
}