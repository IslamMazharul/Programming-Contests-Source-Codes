/*
 * Mazharul Islam , BUET
 * Problem Link:
 */
using namespace std;
#include <bits/stdc++.h>

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define rep(i,a,n) for(__typeof(n) i=a; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define write(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define endl "\n"
typedef long long  Long;
typedef unsigned long long uint;
typedef string ST;
typedef vector<int> vi;
typedef vector<ST> vs;
typedef map<int,int> mii;
typedef map<ST,int> msi;
typedef set<int> si;
typedef set<ST> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define deb(x) cerr << #x << " = " << x << endl;
#define MAXN 100000
#define LONG_LONG_MAX 1000000000000
Long DP[MAXN+7][2] ;
ST names[MAXN+7]  ,revnames[MAXN+7];
Long cost[MAXN+7] ;
int n ;
Long call(int cur,int rev){

    if(cur==n){
        return 0 ;
    }
    if(DP[cur][rev]!=-1) return DP[cur][rev] ;
    Long ret=LONG_LONG_MAX ;
    if(rev==0){
        if(names[cur-1]<=names[cur]) ret=min(ret,call(cur+1,0)) ;
        if(names[cur-1]<=revnames[cur]) ret=min(ret,call(cur+1,1)+cost[cur]) ;
    }
    else{
        if(revnames[cur-1]<=names[cur]) ret=min(ret,call(cur+1,0)) ;
        if(revnames[cur-1]<=revnames[cur]) ret=min(ret,call(cur+1,1)+cost[cur]) ;
    }
    DP[cur][rev]=ret ;
    return ret ;
}

int main(void){
    freopen("in.txt","r",stdin) ;
    mem(DP,-1) ;
    cin>>n ;
    rep(i,0,n){
        cin>>cost[i] ;
    }
    rep(i,0,n){
        cin>>names[i] ;
        ST temp="" ;
        for(int j=names[i].length()-1;j>=0;j--){
            temp.push_back(names[i][j]) ;
        }
        revnames[i]=temp ;
       // cout<<temp<<endl ;
    }
    Long res=min(call(1,0),call(1,1)+cost[0]) ;
    if(res==LONG_LONG_MAX) cout<<"-1"<<endl ;
    else cout<<res<<endl ;
    return 0;
}
