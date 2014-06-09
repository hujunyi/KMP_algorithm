#include<iostream>
#include<vector>
using namespace std;
void prefix_function(string P,vector<int>& next){
  int length = P.size();
  int j=0,k=-1;
  next[0] = -1;
  while(j<length-1){
    if(k==-1||P[j]==P[k]){
      j++;
      k++;
      next[j] = k;
    } else 
      k = next[k];
  }
}
int find_substring(string S,string P,vector<int> next){
  int i=0,j=0;
  while(j<S.size()){
    if(S[j] == P[i]){
      i++;
      j++;
    } else if(next[i]!=-1){
      i = next[i];
    } else {
      i = 0;
    }
    if(i==P.size()){
      return j-P.size();
    }
  }
  return -1;
}

template<typename T>
void print(vector<T> input){
  for(int i=0;i<input.size();i++){
    cout<<input[i]<<" ";
  }
  cout<<endl;
}
int main(){
  string P = "ababac";
  string S = "abababac";
  vector<int> Prefix(P.size());
  prefix_function(P,Prefix);
  cout<<find_substring(S,P,Prefix)<<endl;
  return 0;
}
  


