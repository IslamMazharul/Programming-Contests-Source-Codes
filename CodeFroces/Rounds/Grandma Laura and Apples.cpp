/*
Mazharul Islam
*/
#include <bits/stdc++.h>
using namespace std ;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define MAXN 5
typedef  long long i64 ;
int main(int argc, char **argv){
	//freopen("in.txt","r",stdin) ;
    i64 n,p,k ;
    k=0;
    string st ;
    cin>>n>>p ;
    rep(i,0,n){
        cin>>st ;
        if(st.length()>4){
            k |=(1LL<<i) ;
        }
    }
  //  cout<<k<<endl ;
    i64 res=0 ;
    while(k>0){
      //  cout<<k<<endl ;
        if(k&1){
            res+=(p*(k/2))+p/2 ;
        }else{
            res+=(p*(k/2)) ;
        }
        k/=2 ;
    }
    cout<<res<<endl ;
	return 0;
}
