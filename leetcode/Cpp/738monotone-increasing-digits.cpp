#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int arr[10], l = 0;
        while(N){
            arr[l] = N % 10;
            l++;
            N /= 10;
        }
        for(int i = l - 1; i > 0; i --){
            if(arr[i] > arr[i-1]){
                arr[i]--;
                for(int j = i -1; j >= 0; j --){
                    arr[j] = 9;
                }
                arr[i-1] = 9;
                i = l;
            }
        }
        for(int i = l - 1; i >= 0; i--){
            N = N * 10 + arr[i];
        }
        return N;
    }
};
