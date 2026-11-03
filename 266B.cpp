/*
 * Problem: Codeforces 266B - Queue at the School
 * 
 * Approach:
 * - We simulate the queue second by second using two nested loops.
 * 
 * 1. Outer Loop (`sec` from 0 to t-1):
 *    - Represents each passing second.
 *    - Runs exactly `t` times to simulate the entire time window.
 * 
 * 2. Inner Loop (`i` from 0 to n-2):
 *    - Scans the queue from front to back during the current second.
 *    - When an adjacent pair "BG" is found at indices `i` and `i + 1`, 
 *      the boy and girl swap places to become "GB".
 *    - After a swap, we increment `i` by 1 (`i++`). This prevents the same 
 *      boy from chaining multiple swaps within the exact same second.
 * 
 * Complexity:
 * - Time: O(t * n), where t <= 50 and n <= 50 (max ~2500 ops, runs in < 1ms).
 * - Space: O(n) to store the queue string.
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    if (!(cin >> n >> t)) return 0;

    string s;
    cin >> s;

    for (int sec = 0; sec < t; sec++) {
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'B' && s[i + 1] == 'G') {
                swap(s[i], s[i + 1]);
                i++; 
            }
        }
    }

    cout << s << "\n";
    return 0;
}
