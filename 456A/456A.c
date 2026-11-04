#include <stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    int q[100001];
    for(int i = 0; i < n; ++i){
        int p, x;
        scanf("%d %d", &p, &x);
        q[p]=x;
    }
    for (int p = 1; p < n; ++p){
        if (q[p]> q[p+1]){
            printf("Happy Alex\n");
            return 0;
        }
    }
    printf("Poor Alex\n");
    return 0;
}
