// find prime
#include <stdio.h>
#include <string.h>
int arr[1000005];
int main()
{
    int a, b, i, j, c, f;
    memset(arr, 0, sizeof(arr));
    for (i = 2; i <= 1000000; i++) {
        if (arr[i] == 0) {
            j = i + i;
            while (j <= 1000000) {
                arr[j] = 1;
                j += i;
            }
        }
    }
    while (scanf("%d%d", &a, &b) != EOF) {
        c = 0;
        for (i = a; i <= b; i++) {
            if (arr[i] == 0) {
                if (c % 10 != 0)
                    printf(" ");
                printf("%d", i);
                c++;
                if (c % 10 == 0 && c != 0)
                    putchar('\n');
            }
        }
        printf("\n\n");
    }
}
//url=http://www.tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=3749
