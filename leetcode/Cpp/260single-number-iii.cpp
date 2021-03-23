#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = 0;
        for(int i = 0; i < nums.size(); i++){
            n ^= nums[i];
        }
        int q = n, t = 0;
        while(q){
            q >>= 1;
            t++;
            if(q&1){
                break;
            }
        }
        q = n;
        for(int i = 0; i < nums.size(); i++){
            if(isOne(nums[i],t)){
                n ^= nums[i];
            }
        }
        return vector<int>{q^n,n};
    }
    int isOne(int val,int n){
        return  val >> n & 1;
    }
};
