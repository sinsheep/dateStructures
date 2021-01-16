#include <iostream>
using namespace std;
int main(){
    int n,arr[1005];
    cin>>n;
    int q=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        q=arr[i]^q;
    }
    cout<<q<<endl;
    return 0;
}
