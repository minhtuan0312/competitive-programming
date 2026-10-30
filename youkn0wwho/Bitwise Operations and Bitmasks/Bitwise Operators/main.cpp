#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int res1 = 0, res2 = 0, res3 = 0;
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int op1 = i & j;
            int op2 = i | j;
            int op3 = i ^ j;
            if(op1 < k && res1 < op1) res1 = op1;
            if(op2 < k && res2 < op2) res2 = op2;
            if(op3 < k && res3 < op3) res3 = op3;
        }
    }
    printf("%d\n%d\n%d\n", res1, res2, res3);
}
