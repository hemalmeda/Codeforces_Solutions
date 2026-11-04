#include <stdio.h>
int main()
{
    char c[51];
    int j=0, i, n;
    scanf("%d", &n);
    scanf("%s", c);
    for (i=0; i<n-1; i++)
    {
        if(c[i]==c[i+1])
        {
            j++;
        }
    }
    printf("%d\n", j);
    return 0;
}
