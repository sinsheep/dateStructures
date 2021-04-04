#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        map<int,set<int>> m;
        for(int i = 0; i < logs.size();i++){
            m[logs[i][0]].insert(logs[i][1]);
        }
        for(auto c:m){
            ans[c.second.size()-1]++;
        }
        return ans;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
