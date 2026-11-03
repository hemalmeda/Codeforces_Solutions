/*
# Codeforces 456A: Laptops

A fast, clean C++ solution for [Codeforces 456A - Laptops](https://codeforces.com/problem/456/A) using the Standard Template Library (`std::vector`, `std::pair`, and `std::sort`).

---

## Problem Overview

Alex believes that high price does not always guarantee high quality. Specifically, he claims there exists at least one pair of laptops where a cheaper laptop has strictly higher quality than a more expensive one.

- **Input:**
  - An integer `n` (1 <= n <= 10^5), representing the number of laptops.
  - `n` lines follow, each containing two integers: `a_i` (price) and `b_i` (quality).
  - All prices are pairwise distinct; all qualities are pairwise distinct (1 <= a_i, b_i <= n).
- **Output:**
  - Print `"Happy Alex"` if such a pair exists.
  - Otherwise, print `"Poor Alex"`.

---

## Algorithmic Approach

1. **Composite Storage with `std::pair`:**
   Store each laptop as a pair `(price, quality)` in a `std::vector<std::pair<int, int>>`.
2. **Sorting by Primary Key:**
   Using `std::sort`, the vector is sorted in ascending order of `.first` (price). Because prices are guaranteed distinct, the laptops are strictly arranged from cheapest to most expensive.
3. **Adjacent Monotonicity Check (O(N)):**
   If there exists any pair where a cheaper laptop has higher quality, there must exist at least one adjacent pair in the sorted array where `quality[i] > quality[i + 1]`.
4. **Early Termination:**
   As soon as an adjacent inversion is detected, print `"Happy Alex"` and terminate. If the loop completes without finding any inversion, print `"Poor Alex"`.s

---

## Complexity Analysis

- **Time Complexity:** O(N log N)
  - Input reading: O(N)
  - Sorting N pairs: O(N log N)
  - Single-pass scan: O(N)
- **Space Complexity:** O(N)
  - Contiguous storage for N pairs inside `std::vector`.

*/
#include<iostream>
#include<vector>
#include<algorithm>
int main(){
  int n; 
  if(!(std::cin>>n)) return -1;
  std::vector<std::pair<int,int>>vec;
  for(int i = 0; i<n; i++){
    int pri,qlty;
    std::cin>>pri>>qlty;
    if(pri<=0 && qlty<0){
      continue;
    }
    vec.push_back({pri,qlty});
  }
  sort(vec.begin(),vec.end());
  for(int i = 0; i<n-1; i++){
    if(vec[i].second > vec[i+1].second){
      std::cout<<"Happy Alex\n";
      return 0;
    }
  }
  std::cout<<"Poor Alex";
  return 0;
}
