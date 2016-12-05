#include <bits/stdc++.h>
using namespace std;

struct MultiplicationTable2{
int minimalGoodSet(vector <int> table)
{
    int ret=0;
    int N = sqrt(table.size())+0.5 ;
    for(int i=0;i<=table.size();i++){
            bool yes=1 ;
        for(int j=0;j<=i;j++){
            for(int k=i;k<=i;k++){
                if(table[j*N+k]>i) yes=0 ;
            }
        }
    if(yes) return i+1 ;
    }
    return ret;
}


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
