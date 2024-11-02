#include<iostream>
#include<ctype.h>

using namespace std; 

/*
1) Count number of upper(65-90) and lower(97-122)
2) if upper> lower, then decrease 32 from every ascii more than 97. ( Make lower case function)
3) add 32 to make it upper case. (make a upper case function)
4) if equal, make it lower case. 
*/


int main() {

    string s;
    int upper=0,lower=0;
    cin>>s;
    for(int i=0; i<(s.length());i++){
        if(isupper(s[i])){
            upper++;
        }
        if(islower(s[i])){
            lower++;
        }
    }
    if(upper>lower){
        //convert to upper
         for(int i=0; i<(s.length());i++){
            s[i]=toupper(s[i]);
         }
    }
    if(upper<=lower){
        //convert to upper
         for(int i=0; i<(s.length());i++){
            s[i]=tolower(s[i]);
         }
    }
   // cout<<ns;
    cout<<s;
    
    return 0; 
}