#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#include <cmath>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
using namespace std ;
#define MAXN 101
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
#define LL  long long
int L ;
inline LL convert(string s){
    LL ret = 0 ;

    FOR(i,0,L-1){
        if(s[i]=='1') ret = ret | (1<<(L-i-1)) ;
    }

    return ret ;
}

inline LL count_bits(LL n){
    int ret = 0 ;
    while(n>0){
        if(n%2==1) ret++ ;
        n/=2 ;
    }

    return ret ;
}

int main(int argc, char **argv){

    #ifdef unlucky_13
        freopen("C:\\Users\\Mazharul Islam\\Documents\\A-large-practice.in","r",stdin) ;
        freopen("C:\\Users\\Mazharul Islam\\Documents\\A-large-practice.txt","w",stdout) ;

    #endif
    string val ;
    vector<LL>sw ;
    map<LL,int>mp ;
    int CT = 1 ;
    LL T ,N;
    cin>>T ;

    //cout<<count_bits(3)<<endl ;
    while(T--){

        cin>>N>>L ;

        sw.clear() ;
        mp.clear() ;
        FOR(i,0,N-1){
            cin>>val ;
            sw.push_back(convert(val)) ;
            //cout<<sw[i]<<endl ;
        }

        FOR(i,0,N-1){
            cin>>val ;
            mp[convert(val)] = 1 ;
        }
       // cout<<"\n" ;

        LL res = 10000 ;
        map<LL,int>::iterator it ;
        LL up = pow(2,L) ;
        FOR(i,0,up){
           // cout<<i<<" : " ;
            FOR(j,0,N-1){
                LL mask = (sw[j] ^ i ) ;

                it = mp.find(mask) ;
                if(it==mp.end()){
             //       cout<<mask<<endl ;
                    break ;
                }
                if(j==N-1){
                    res = min(res,count_bits(i)) ;
                }
            }
        }
        cout<<"Case #"<<CT++<<": " ;
        if(res==10000) cout<<"NOT POSSIBLE\n" ;
        else cout<<res<<"\n" ;
    }

    return 0 ;
}
