#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n,s.size()-n) + s.substr(0,n);
    }
};
int main(){
    Solution* s = new Solution();
    cout<<s->reverseLeftWords("abcdefg", 4)<<endl;
    return 0;
}
