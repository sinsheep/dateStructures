#define ll long long 
ll fastMultiply(ll a, ll b) {
    ll ans = 0;
    while(b != 0) {
	if((b & 1) != 0) {
	    ans += a;
	}
	a += a;
	b >>= 1;
    }
    return ans;
}
int main(){

}
