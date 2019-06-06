#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

struct Hold
{
  char ch; 
  unsigned short grade;
};

const string grade_1="ETAOIN SHRDLU";
const string grade_2="etao shrdlu";
const char Hex_Table[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

int get_Me_the_hex_of_the_char_(char ch);
string hex_string_to_asci(string hex);
string xoring_hex_and_char(string some_string,char ch);
unsigned short checker(char ch);
unsigned short grader(string some_string);
void sort(Hold holder[],int size);
void swap(Hold&,Hold&);


int main(int argc, char** argv){

string input_string=argv[1];
string main_string="";

Hold holder[96];
for(int index =0 ; index <96; index++)
holder[index].ch=(char)index+32,holder[index].grade=grader(hex_string_to_asci(xoring_hex_and_char(input_string,index+32)));


for (size_t i = 95; i>=0; i--)
{
  cout<<holder[i].ch<<"\t"<<holder[i].grade
  <<hex_string_to_asci(xoring_hex_and_char(main_string,holder[i].ch))
  <<endl;
}
return 0;
}

int its_hex(char ch){ 
    if((int)ch>58) return (int)ch-87; 
    else return (int)ch - 48;
}

string hex_string_to_asci(string hex)
{

    string here="";
    for (size_t i = 0; i < hex.length(); i+=2)
    here+=(char)(its_hex(hex[i])*16 + its_hex(hex[i+1]));
    return here;

} 


string xoring_hex_and_char(string some_string, char chy)
{
      
    stringstream asci_("");
    char ch[2];
    string temp_hex="";
    asci_<<hex<<chy;
    asci_>>ch[0];
    asci_>>ch[1];
    for(int index =0 ; index <some_string.length(); index++)
    temp_hex+=Hex_Table[(its_hex(some_string[index]))^its_hex((index%2==0) ? ch[0]:ch[1])];
    return temp_hex;
}

unsigned short grader(string some_string){
  unsigned short counter =0;
for (size_t i = 0; i < some_string.length(); i++)
    counter+=checker(some_string[i]);

  return counter;
}

unsigned short checker(char ch){

  for (size_t i=grade_1.length()-1; i >=0; i--)
    if(ch == grade_1[i] || ch == grade_2[i]) return i+1;
  return 0;
 
}


void sort(Hold holder[],int size){
  Hold *p;
  for (size_t i = 0; i < size; i++)
  {
    p=&holder[i];
    for (size_t t = i; t < size; t++)
    {
      p=(p->grade)>holder[t].grade ? &holder[t]:p;
    }
    swap(holder[i],*p);
    
  }
}


void swap(Hold& v1,Hold& v2){
Hold temp=v2;
v2=v1;
v1=temp;

}
