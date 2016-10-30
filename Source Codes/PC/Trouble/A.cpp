#include <bits/stdc++.h>
using namespace std ;
int main(void){
    int f ;
    cin>>f ;
    int tim = 60 ;
    for(int i=f;i<12;i++){
        tim+=45 ;
    }

    if(tim<=5*60) cout<<"YES\n" ;
    else cout<<"NO\n" ;
    return 0 ;
}
