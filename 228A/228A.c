#include <stdio.h>
int main (){
    int a, b, c, d;
    int i=0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(a==b || a==c || a==d)
        i++;
    if(b==c || b==d)
        i++;
    if(c==d)
        i++;
printf("%d\n", i);
return 0;
}