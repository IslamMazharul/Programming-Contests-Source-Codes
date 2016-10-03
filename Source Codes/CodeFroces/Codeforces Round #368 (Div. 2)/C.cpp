#include <bits/stdc++.h>
using namespace std ;
#define Long long long
int main(void){
    Long N ,M=1;
    cin>>N ;
    if(N<=2){
        cout<<"-1"<<endl ;
        return 0 ;
    }
    while((N&1)==0){
        N=N>>1 ;
        M=M<<1 ;
    }
    if(N==1){
        Long A = 3*(M/4) ;
        Long B = 5*(M/4) ;
        cout<<A<<" "<<B<<endl ;
        return 0 ;
    }
  //  cout<<N<<" "<<M<<endl ;
    Long A=(N*N-1)/2 ;
    Long B = (N*N+1)/2 ;
    A *=M ;
    B *=M ;
    cout<<A<<" "<<B<<endl ;
    return 0 ;
}
