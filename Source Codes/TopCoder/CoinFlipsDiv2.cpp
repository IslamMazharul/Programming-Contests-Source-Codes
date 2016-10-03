#include<bits/stdc++.h>
using namespace std;

struct CoinFlipsDiv2{
int countCoins(string state)
{
    int ret=0;
    for(int i=0;i<state.length();i++){
        int c=0;
        if(i>0 && state[i-1]!=state[i]) c++ ;
        if(i+1<state.length() && state[i+1]!=state[i]) c++ ;
        if(c!=0) ret++ ;
    }
    return ret;
}


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
