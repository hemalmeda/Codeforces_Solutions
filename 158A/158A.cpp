#include<iostream>
#include<vector>
#include<algorithm>
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
 
  int n,k;
  if(!(std::cin>> n >> k)) return -1;
  std::vector<int>vec(n);
  for(int i = 0 ; i<n; i++){
    std::cin>>vec[i];
  }
 int count = 0; 
 for(int i = 0; i<n; i++){
  if(vec[i]>=vec[k-1]&&vec[i]!=0) count++;
 }
 std::cout<<count;
  
}
