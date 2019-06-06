#include <iostream>
#include <fstream>
#include <string>


using namespace std;

string original ="49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"; 


int getMe_its_int(char ch){
       
    if (int(ch) > 60) return  (10 + (int(ch) - 97));
    else return ((int(ch) - 48));
}

void int_To_bin_for_hex(char ch[], int size_of_the_array,int number_to_be){
    int temp=0;
    for (int i = 0; i < size_of_the_array; i++){
           temp = number_to_be %2;
       if (temp == 0 )     ch[size_of_the_array-i-1]= '0';
      else                  ch[size_of_the_array-i-1]= '1';
    
        number_to_be/=2;
        
    }
        
}

void write_an_array_to_a_file(char ch[], int size_of_the_array,fstream& file_to){

   for (int i = 0; i< size_of_the_array;i++){
       file_to<<ch[i];
       
    }
}



int main (){
if (original.length()%3 == 0 ){
    char 
}
fstream writter ("/home/guy/Documents/My notes/Cryptopals/Set 1/bin_of_z_Hex.txt", ios::out | ios::in);

if (!writter.is_open()) cout<<"File not open ";
else {

int temp;
int someInt;
char base64[65]{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/','='}; 
int bin_int[6] = {32,16,8,4,2,1};
char Bin_char[6]={'0', '0','0','0','0','0'};
char Bin_char_2[4]={'0', '0','0','0'};
char ch;

temp = (4*original.length())%6;

      if (temp != 0){
          writter.seekp(0,ios::beg);
          while(temp !=0){writter<<'0';temp--;}
     }
writter.seekp(0,ios::cur);

for (int i = 0; i<original.length();i++){
    
    temp = getMe_its_int(original[i]);
    
    int_To_bin_for_hex(Bin_char_2,4,temp);

    write_an_array_to_a_file(Bin_char_2,4,writter);
    cout<<"\n\nFor the char "<<original[i]<< " its int = "<<temp<<" its bin ";
    for (int y = 0; y <4;y++) cout<<Bin_char_2[y];
    
    
}
    
writter.seekp(0,ios::beg);
cout<<"\n\nReading shit\n\n";
temp =someInt=0;
while(!writter.eof()){
   
    writter>>ch;
    Bin_char[temp]=ch;

    if (temp == 5) {  
         
        for (int i = 0; i<6;i++){
       if(Bin_char[i] == '1') someInt+=bin_int[i];
        
        }
        cout<<base64[someInt];
        temp =someInt= 0;
        continue;
          }
    temp++;
    }

}



    return 0;
}

