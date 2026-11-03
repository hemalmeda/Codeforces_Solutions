/*
Automatic Deduplication via std::set:
A std::set stores only unique keys in sorted order. Inserting the 4 input values into a std::set<int> automatically discards duplicate colors.

Cardinality Difference:
Let k be the count of unique colors Valera owns (shoe.size()).

If all 4 are distinct (k = 4), he needs 4 - 4 = 0 additional horseshoes.

If 2 share a color (k = 3), he needs 4 - 3 = 1 additional horseshoe.

If all 4 share the same color (k = 1), he needs 4 - 1 = 3 additional horseshoes.

Formula:
Horseshoes to buy = 4 - shoe.size()
*/
#include<iostream>
#include<set>

int main(){
  std::set<int>shoe;
  for(int i = 0; i<4; i++){
    int a;
    std::cin>>a;
    shoe.insert(a);
  }
  std::cout<<(4-shoe.size());
}
