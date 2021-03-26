#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPartitions(string n) {
        int m = 0;
        for(int i = 0; i < n.size(); i++){
            if(n[i]-'0' > m){
                m = n[i]-'0';
            }
        }
        return m;
    }
};
