#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// int numberOfLinesInFile(ifstream wordsFile ){
//   string lines;
//   int count=0
//   while(getline(wordsFile,lines)){
//     count++;
//   }
//   cout<< "\nCount is:\n"<< count;
//   return count;
// }



 int binarySearchForMeaningfulWords(vector <string> words,int from,int to,string key){
  if(words.size()==0){
    return -1;
  }
  if(from>to){
    return -1;
  }
  if (from==to ) {
    if (words[to]!=key) {
      return -1;
    }
    else{
      return to;
    }
  }

  int mid=(from+to)/2;
  if (words[mid]== key) {
    return mid;
  }
  else if(words[mid]<key){
    return binarySearchForMeaningfulWords(words,mid+1,to,key);
  }
  else{
    return binarySearchForMeaningfulWords(words,from,mid-1,key);
  }


}

void printMeaningfulWords(string prefix,string sentence,vector <string> words){
int i;
 string aWord;

  if (sentence=="." ) {
    cout<<"\n"<< prefix<<"\n";
    return ;
  }

  for (i =0;  i < sentence.size(); i++) {
    aWord=sentence.substr(0,i);

    if (binarySearchForMeaningfulWords(words,0,words.size()-1,aWord)!=-1) {
      if (i== sentence.size()) {
        cout<< prefix<< " "<< aWord;
        return;
      }
      else{
      printMeaningfulWords(prefix+" "+aWord,sentence.substr(i,sentence.size()),words);
    }}

  }}


int main(){
  string s;
  ifstream wordsFile;
  vector <string> words;
  wordsFile.open("words.txt");
  string null="";
  int i;
  string inputLine;

  if(!wordsFile){
  cerr << "Error: words.text could not be opened"<<endl;
  exit(1);
  }
  for ( i = 1; i < 3353; i++) {
    getline(wordsFile,s);
  words.push_back(s);
  }
  while(cin>> inputLine){
  inputLine=inputLine+".";
  printMeaningfulWords(null,inputLine,words);
  cout<<"\n***\n\n";
}


   }
