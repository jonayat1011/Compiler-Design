#include<iostream>
#include<string.h>

using namespace std;

int main(){
string s;
cout<<"Enter your input : ";
cin>>s;
cout<<"Output : ";
for(int i=0; i<s.length();i++){
    if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%'||s[i]=='='){
        cout<<s[i];
    }
}
}
