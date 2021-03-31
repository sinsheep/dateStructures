#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size();
        int row = matrix.size();
        int i = 0, j = col - 1;
        while(matrix[i][j]!=target){
            if(matrix[i][j]<target)i++;
            else
                j--;
            if(i>=row||j<0)return false;
        }
        return true;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
