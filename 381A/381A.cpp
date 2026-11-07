#include<iostream>
#include<vector>

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  if(!(std::cin>>n)) return -1;
  std::vector<int> vec(n);
  int a = 0; 
  int b = 0; 
  for(int i = 0; i<n; i++){
    std::cin>>vec[i];
  }
  
  int left = 0;
  int right = n-1;
  bool aturn = true; 


  while(left <= right){
    int select;
    
    
    if(vec[left] > vec[right]){
      select = vec[left];
      left++; 
    } else {
      select = vec[right];
      right--; 
    }
   
    if(aturn){
      a += select;
      aturn = false; 
    } else {
      b += select;
      aturn = true;  
    }
  }
  
  std::cout << a << " " << b << "\n";
  return 0;
}
