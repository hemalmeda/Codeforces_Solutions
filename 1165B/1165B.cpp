#include<iostream>
#include<vector>
#include<algorithm>
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  if(!(std::cin>>n)) return -1;
  std::vector<int>cont(n);
  for(int i = 0; i<n; i++){
    std::cin>>cont[i];
  }
  int count = 1;
  sort(cont.begin(),cont.end());
   for(int i = 0; i<n; i++){
    if(cont[i]>=count){
      count++;
    }
   }
  std::cout<<count-1;

}
