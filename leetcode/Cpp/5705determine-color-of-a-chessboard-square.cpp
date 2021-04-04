#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0]-'a')%2==0&&(coordinates[1]-'0')%2==0)||((coordinates[0]-'a')%2==1&&(coordinates[1]-'0')%2==1);
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
