#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int leftMax = A[0], m = A[0],idx = 0;
        for(int i = 1; i < A.size(); i++){
            m = max(m,A[i]);
            if(A[i] < leftMax){
                leftMax = m;
                idx = i;
            }
        }
        return idx + 1;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
