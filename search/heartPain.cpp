#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n, l=1, r;
    cin >> n;
    r = n >= 2 ? n: 8;
    ll ans=0;
    while(l <= r){
        ll mid = (l + r) >> 1;
        ll d = int(mid * log10(mid)) + 1;
        if(d >= n){
            ans=mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans;
    
    return 0;
}
