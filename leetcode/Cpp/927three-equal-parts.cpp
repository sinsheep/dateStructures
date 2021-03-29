#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int s = 0;
        vector<int> ans(2);
        ans[0] = ans[1] = -1;
        for(int i = 0; i < arr.size();i++) s+= arr[i];
        if(s%3) return ans;
        if(!s){
            ans[0]=0;
            ans[1]=arr.size()-1;
            return ans;
        }
        s/=3;
        int l1,r1,l2,r2,l3,r3,tmp=0;
        //l1=r1=l2=r2=l3=r3=-1;
        for(int i = 0; i < arr.size(); i++){
            if(!arr[i]) continue;
            tmp++;
            if(tmp == 1) l1 =i;
            if(tmp == s) r1 = i;
            if(tmp == s+1) l2 =i;
            if(tmp == 2*s) r2 = i;
            if(tmp ==2*s+1) l3=i;
            if(tmp == 3*s) r3=i;
        }
        if(r1-l1 != r2-l2 || r2-l2 != r3-l3){
            return ans;
        }
        int z = arr.size() - 1 - r3;
        if(l2 - r1 - 1  < z || l3 - r2 - 1< z){
            return ans;
        }
        ans[0]=r1 + z;
        ans[1]=r2 + z + 1;
        return ans;
    }
};
int main(){
    Solution* s = new Solution();
    vector<int> arr={ 1,0,1,0,1 };
    vector<int> ans = s->threeEqualParts(arr);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
