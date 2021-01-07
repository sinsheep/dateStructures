#include <cmath>
#include <iostream>
#define ll long long
using namespace std;
bool getPrime(ll k){
    for (ll i = 2; i <= sqrt(k); i++) {
        if (k % i == 0)
            return 0;
    }
    return 1;
}
ll GetAns(ll x, ll k){
    if (!getPrime(k))
        return 0;
    ll sum = x / k;
    for (ll i = 0; i <= min(x / k, k - 1); i++) {
        sum -= GetAns(x / k, i);
    }
    return sum;
}
int main()
{
    ll l, r, k;
    cin>>l>>r>>k;
    cout<<GetAns(r, k)-GetAns(l-1, k)<<endl;
    return 0;
}
