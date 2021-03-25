#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < intervals.size(); ++i) {
            arr.emplace_back(make_pair(intervals[i][0], i));
        }
        sort(arr.begin(),arr.end());
        vector<int> ans;
        for(int i = 0; i < intervals.size(); i++){
            int l = 0, r = arr.size(), q = intervals[i][1];
            while(l<r){
                int mid = l+(r - l)/2;
                if(arr[mid].first>=q){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            if(r == arr.size()){
                ans.push_back(-1);
            }else{
                ans.push_back(arr[l].second);
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}
