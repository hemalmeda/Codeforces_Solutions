/**
 * ============================================================================
 * PROBLEM: Codeforces 4C - Registration System
 * RATING: 1000
 * TAGS: Hashing, Data Structures, Implementation, String Processing
 * TIME LIMIT: 5.0 seconds | MEMORY LIMIT: 64 MB
 * ============================================================================
 * 
 * DESCRIPTION:
 * Simulate user account registrations. For each incoming registration with name s:
 * 1. If name is new, register it and return "OK".
 * 2. If name is already taken, generate a suggested name by appending the 
 *    smallest positive integer k >= 1 (name + k) not yet taken, register it, 
 *    and output it.
 * 
 * CORE LOGIC & ALGORITHM:
 * - State Tracking:
 *   Use an associative dictionary `std::map<std::string, int> db`:
 *     - Key   (std::string): The base username requested.
 *     - Value (int):         The next integer suffix k to append upon collision.
 * 
 * - Branching Logic:
 *   1. Unseen Key (!db.count(s)):
 *      Output "OK" and initialize db[s] = 1 (next suffix to use will be 1).
 *   2. Collision / Existing Key (db.count(s)):
 *      Output `s` concatenated with current `db[s]`.
 *      Increment `db[s]++` for subsequent collisions.
 * 
 * - Stream Processing:
 *   Process queries on the fly directly from stdin to stdout without buffering
 *   into a vector, saving memory and cache overhead.
 * 
 * COMPLEXITY:
 * - Time:  O(N * L * log N) where N <= 10^5 and L <= 32 (length of string).
 *          Total operations ~ 1.6 * 10^6, runs in ~0.15s (well within 5.0s).
 * - Space: O(N * L) to store unique string keys and counters in the RB-tree.
 * 
 * PITFALLS:
 * - db.count(s) returns 1 when key is PRESENT (truthy). Negate with !db.count(s).
 * - Always use "\n" instead of std::endl to avoid forcing buffer flushes on 10^5 queries.
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <map>

int main() {
    // Fast I/O for 10^5 operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::map<std::string, int> db;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        // Condition 1: Never seen before
        if (!db.count(s)) {
            std::cout << "OK\n";
            db[s] = 1;
        } 
        // Condition 2: Collision / Already exists
        else {
            std::cout << s << db[s] << "\n";
            db[s]++;
        }
    }

    return 0;
}
