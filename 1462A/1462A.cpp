#include<iostream>
#include<vector>
 
int twomain(){
  int k; 
  if(!(std::cin>>k)) return -1;
  std::vector<int>vec(k);
  for(int i = 0; i<k; i++){
    std::cin>>vec[i];
  }
  int left = 0;
  int right = k-1;
  while(left<=right){
    if(left == right){
      std::cout<<vec[left]<<"\n";
      break;
    }
    std::cout<<vec[left]<<" "<<vec[right]<<" ";
    left++;
    right--;
  }
  return 0;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
 
  int n;
  if(!(std::cin>>n)) return -1;
  for(int i = 0; i<n; i++){
    twomain();
  }
}
