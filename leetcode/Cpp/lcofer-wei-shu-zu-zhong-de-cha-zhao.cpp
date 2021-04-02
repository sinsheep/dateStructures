#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()){
            return false;
        }
        int x = 0;
        int y = matrix[0].size() -1;
        if(y== - 1)
        return false;
        while(matrix[x][y] != target){
            if(matrix[x][y]>target)y--;
            else x++;
            if(x>=matrix.size()||y<0) return false;
        }
        return true;
    }
    
};
int main(){
    Solution* s = new Solution();
    return 0;
}
