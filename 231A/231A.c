#include <stdio.h>
int main()
{
    int n, a, b, c, z;
    z=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &a, &b, &c);
        if((a+b+c) >=2){
            z++;
        }
    }
    printf("%d", z);
} 
