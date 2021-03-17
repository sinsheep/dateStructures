#include <bits/stdc++.h>
#define ll long long
#define mset(a) memset(a,0,sizeof(a))
using namespace std;
ll m, n, t, arr[100005], b[100005];
ll abs1(ll a){
    return a>0 ? a:-a;
}
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        map<ll,ll> q;
        mset(b);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            b[arr[i]%m]++;
        }
        ll ans = 0;
        if(b[0])ans++;
        for(int i = 1; i <= m/2; i++){
            if(b[i] && b[m-i] && abs1(b[i]-b[m-i])<=1){
                ans ++;
            }else{
                if(b[i]==0&&b[m-i])ans+=b[m-i];
                if(b[i]&&b[m-i]==0)ans+=b[i];
                if(b[i]&&b[m-i]&& abs1(b[i]-b[m-i])>1)ans+=abs1(b[i]-b[m-i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

