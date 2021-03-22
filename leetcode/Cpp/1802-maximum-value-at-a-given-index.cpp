#include <bits/stdc++.h>
#define ll long long
#define mset(a) memset(a, 0, sizeof(a))
using namespace std;
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = index, r = index, sum = n, cnt = 1;
        while(sum <= maxSum){
            sum += r - l + 1;
            cnt ++;
            if(l>0) l--;
            if(r<n-1) r++;
            if(l == 0 && r == n -1 && sum < maxSum){
                return cnt + (maxSum - sum) / n;
            }
        }
        return cnt - 1;
    }
};


