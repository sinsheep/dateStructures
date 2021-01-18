#include <iostream>
using namespace std;
int main(){
    int a,b,mod;
    cin>>a>>b>>mod;
    //a+b;
    cout<< (( a % mod) + (b%mod))%mod <<endl;
    //a-b;
    cout<< (( a % mod) - (b%mod)+mod)%mod <<endl;
    //a*b
    cout<< (( a % mod) * (b%mod))%mod <<endl;
    
}
