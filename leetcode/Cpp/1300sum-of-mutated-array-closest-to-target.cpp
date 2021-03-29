#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int check(vector<int>& arr,int x){
        int s = 0;
        for(int i = 0; i < arr.size(); i++){
            s+= arr[i]>x? x:arr[i];
        }
        return s;
    }
public:
    int findBestValue(vector<int>& arr, int target) {
        int m = 0;
        for(int i = 0; i < arr.size(); i++){
            m=max(arr[i],m);
        }
        int l = 1, r = m;
        while(l<r){
            int mid = (l + r) >> 1;
            if(check(arr,mid)<=target){
                l = mid + 1;
            }else{
                r= mid;
            }
        }
        return abs(check(arr,l-1) - target)<=abs(check(arr,l)-target)? l-1:l;
    }

};
int main(){
    Solution* s = new Solution();
    vector<int> arr = { 48772,52931,14253,32289,75263 };
    cout<<s->findBestValue(arr,40876)<<endl;
    return 0;
}
