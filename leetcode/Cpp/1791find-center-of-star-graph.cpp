#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0]==edges[1][0]||edges[0][0]==edges[1][1] ? edges[0][0]:edges[0][1];
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
