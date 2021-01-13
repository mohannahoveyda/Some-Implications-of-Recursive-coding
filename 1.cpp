#include <iostream>
#include <string>
using namespace std;
string deleteCharacterNumberJ(string m,int j){
  string s1=m.substr(0,j);
  string s2=m.substr(j+1,m.size());
  m=s1+s2;
  return m;
}
string deleteDup(string s,int i){

if(i==s.size()){

return s;
}
if(s[i]==s[i+1]){
s=deleteCharacterNumberJ(s,i);

s=deleteDup(s,i);
}
else if(s[i]!=s[i+1]){
s=deleteDup(s,i+1);
}

return s;
}


int main(){
string s;

getline(cin,s);

s=deleteDup(s,0);

cout<<"\n"<< s;
}
