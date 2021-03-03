#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, c[35][35], tmp[35][35], A[35][35];
void copyArr() {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tmp[i][j] = c[i][j];
        }
    }
}
int main(){

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
            A[i][j] = c[i][j];
        }
    }
    copyArr();
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i == j)
                c[i][j] = 1;
                else
                c[i][j] = 0;
          }
        }
    } else {
        for (int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int p = 0; p < n; p++){
                    int s=0;
                    for(int k = 0; k < n; k++){
                        s += tmp[j][k] * A[k][p];
                    }
                    c[j][p] = s;
                }
            }
            copyArr();
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

