#include<iostream>
using namespace std;


/*
1) Get the string
2) Iterate the string. 
2A-> If G, Do nothing. 
2B-> If B, then see the next string. if it is G, then swap else continue to next. 
3) Loop this x number of times which is the time. 
*/
int main() {
    int n=0, x=0;
    string q; 
    cin>>n;
    cin>>x;
    cin>>q;
    for( int i=0; i<x; i++) {
        for(int j=0; j<n; j++ ){
            if(q[j]=='G') {
                // do nothing
                continue;
            }
            if(q[j]=='B') {
                //check next sting if it is a G, then Swap
                if(q[j+1]=='G') {
                    //swap
                    char z = q[j];
                    q[j] = q[j + 1];
                    q[j + 1] = z;
                    j++;
                } else{
                    continue;
                }
            }
        }
    }

    cout<<q<<endl;
    return 0;
}