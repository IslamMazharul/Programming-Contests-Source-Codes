#include <bits/stdc++.h>
using namespace std ;
#define rep(i,a,n) for(__typeof(n) i=a; i<(n); i++)
int main(void){
    freopen("out.txt","w",stdout) ;
    srand (time(NULL));
    int R =100 ;
    int C=100 ;
    cout<<"100 80"<<endl ;
    cout<<"100"<<endl ;
    rep(i,0,100){
            cout<<rand()%(C+1)<<" "<<rand()%(R+1)<<" "<<rand()%5<<endl ;
    }
    rep(i,0,3){
        cout<<rand()%(C+1)<<" "<<rand()%(R+1)<<endl  ;
    }
    cout<<rand()%(C+1)<<" "<<rand()%(R+1)<<endl  ;
    return 0 ;
}
