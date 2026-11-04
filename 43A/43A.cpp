/**
 * ============================================================================
 * PROBLEM: Codeforces 43A - Football
 * RATING: 1000
 * TAGS: Strings, Maps, Implementation, Frequency Counting
 * TIME LIMIT: 2.0 seconds | MEMORY LIMIT: 256 MB
 * ============================================================================
 * 
 * DESCRIPTION:
 * A football match log records each goal scored by printing the scoring team's
 * name on a new line. Given n goal events between two teams, determine which 
 * team won the match (the team with strictly more goals).
 * 
 * CORE LOGIC & ALGORITHM:
 * 1. Frequency Map (std::map<std::string, int>):
 *    - Key   (std::string): Team name.
 *    - Value (int):         Cumulative goal count.
 * 
 * 2. In-place Counting with operator[]:
 *    - Executing `logs[s]++` looks up key `s`. If `s` does not exist, the map 
 *      inserts `{s, 0}` via default value-initialization, then increments to 1.
 *    - If `s` exists, it increments the existing integer directly.
 * 
 * 3. Max-Finding Iteration:
 *    - Iterate over key-value pairs using `for (auto const& p : logs)`.
 *    - `p.first` accesses the team name (key), and `p.second` accesses the 
 *      goal tally (value).
 *    - Track and update `winner` whenever `p.second > max_goals`.
 * 
 * COMPLEXITY:
 * - Time:  O(N * L * log K), where N <= 100 is total goals, L <= 10 is max string 
 *          length, and K <= 2 is the number of distinct teams.
 *          Total operations < 10^3, executes in ~15 ms (limit: 2.0 s).
 * - Space: O(K * L) to store at most 2 distinct team names in the map.
 * 
 * PITFALLS:
 * - Always pass loop elements by reference (`const&`) to avoid unnecessary string 
 *   copies during map traversal.
 * ============================================================================
 */

#include <iostream>
#include <map>
#include <string>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::map<std::string, int> logs;

    // Step 1: Read and count goals
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        logs[s]++;
    }

    // Step 2: Determine team with maximum goals
    std::string winner = "";
    int max_goals = -1;

    for (auto const& p : logs) {
        if (p.second > max_goals) {
            max_goals = p.second;
            winner = p.first;
        }
    }

    // Step 3: Output winner
    std::cout << winner << "\n";

    return 0;
}
