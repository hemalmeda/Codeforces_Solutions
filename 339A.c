/*
    Codeforces 339A - Helpful Maths
    Language: C

    Approach: Frequency Counting

    Logic:
    1. Read the expression as a string.
    2. Create a frequency array to count occurrences of digits 1, 2 and 3.
    3. Traverse the string and ignore '+' signs.
    4. Convert each digit character into an integer using s[i] - '0'.
    5. Increment the corresponding frequency.
    6. Print the digits in ascending order according to their frequencies,
       placing '+' signs between them.

    Time Complexity: O(n)
    Space Complexity: O(n) (input string)

    Key Concepts:
    - String traversal
    - Frequency counting
    - Character to integer conversion
*/
#include <stdio.h>
int main()
{
    char s[101];
    int i, count[4] = {0};
    scanf("%s", s);
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= '1' && s[i] <= '3')
            count[s[i] - '0']++;
    }
    int first = 1;
    for(i = 1; i <= 3; i++){
        while(count[i] > 0)
        {
            if(!first)
                printf("+");
            printf("%d", i);
            first = 0;
            count[i]--;
        }
    }
    return 0;
}
