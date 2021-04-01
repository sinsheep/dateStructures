#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int clumsy(int N) {
        stack<int> s;
        int t = 0,f;
        s.push(N);
        for(int i = N - 1;i>=1;i--){
            switch(t++%4){
                case 0:
                    f=s.top();
                    s.pop();
                    s.push(f*i);
                    break;
                case 1:
                    f=s.top();
                    s.pop();
                    s.push(f/i);
                    break;
                case 2:
                    s.push(i);
                    break;
                case 3:
                    s.push(-i);
                    break;
            }
        }
        int ans = 0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
