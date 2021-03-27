#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0;
        int m =  matrix.size();
        int n =  matrix[0].size();
        vector<vector<int>> vec(m,vector<int>(n,0));
        for(int i = 0; i < n; i++)vec[0][i] = matrix[0][i];
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                vec[i][j] = matrix[i][j] ? vec[i-1][j] + 1:0;
            }
        }
        for(auto tmp:vec){
            sort(tmp.begin(),tmp.end());
            for(int j = 0; j < n; j ++){
                ans = max(ans, tmp[j] * (n - j ));
            }
        }
        return ans;
    }
};
int main(){
    Solution* s = new Solution();
    // vector<vector<int>> matrix={ { 0,0,1 },{ 1,1,1 },{ 1,0,1 } };
    vector<vector<int>> matrix={{ 1,1,0,1 }};
    cout << s->largestSubmatrix(matrix) <<endl;
    return 0;
}
