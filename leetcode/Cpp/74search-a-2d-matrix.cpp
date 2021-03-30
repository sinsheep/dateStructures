#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0 , r = m -1, mid;
        while(l < r){
            mid = (l+r) >> 1;
            if(matrix[mid][n-1]>=target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        int x = r;
        l  = 0 , r = n-1;
        while(l < r){
            mid = (l+r) >> 1;
            if(matrix[x][mid]>=target){
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        int y = r;
        return matrix[x][y] == target;

    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
