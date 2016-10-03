#include<bits/stdc++.h>
using namespace std ;
#define rep(i,a,n) for(__typeof(n) i=a; i<(n); i++)
int main(void){
    freopen("/home/mazharul/in.txt","w",stdout) ;
    rep(i,1,100000){
        rep(j,1,i){
            cout<<i<<" "<<j<<endl ;
        }
    }
}
