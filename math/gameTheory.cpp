#include <iostream>
using namespace std;
int main(){
    int N, num, limit;
    cin >> N;
    while(N--){
        cin >> num >> limit;
        if(num % (limit + 1) != 0)
            cout << "Win\n";
        else 
            cout << "Lose\n";
    }
    return 0;
}
// bash Game
// 有num个牌 最多一次能那limit个 看谁能拿到最后一张牌
