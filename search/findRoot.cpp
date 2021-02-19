#include <iostream>
#include <cmath>
using namespace std;
double calc(double x){
    return 2*pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
}
int main(){
    double l, r, mid;
    cin >> l >> r;
    mid = (l + r) / 2;
    while (fabs(calc(mid)) > 1e-6) {

        if (calc(mid) * calc(l) > 0) {
            l = mid;
        }else {
            r = mid;
        }
        mid = (l + r) / 2;
    }
    printf("%.6lf\n", mid);
    return 0;
}
