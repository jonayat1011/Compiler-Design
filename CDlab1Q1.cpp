#include<iostream>
#include<string.h>

using namespace std;

int main(){
string s;
cout<<"Enter your input : ";
cin>>s;
int n=0;
bool b = false;
for(int i=0; i<s.length();i++){
    if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'|| s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='.'){
       b= true;
        if(s[i]=='.'){
            n++;
            if(n==1&&i<(s.length())-1){
              b= true;

            }
            else{
                   b = false;
                   break;
            }

        }
    }
    else{
        b = false;
        break;
    }

}
if(b==true){
    cout<<"Numeric";
}
else{
    cout<<"Not Numeric";
}
}
