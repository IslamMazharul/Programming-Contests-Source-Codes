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
inline void read() {
#ifdef Mazharul
    freopen("/home/mazharul/in.txt","r",stdin) ;
#endif
}

#define all(x) x.begin(),x.end()
#define sz(x) ((long long)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<62)
#define ins insert
#define ff first
#define ss second
#define eps 1e-9
#define endl "\n"

typedef long long  Long ;
typedef unsigned long long ULong;
typedef string ST;
typedef vector<Long> vi;
typedef vector<ST> vs;
typedef map<Long,Long> mii;
typedef map<ST,Long> msi;
typedef set<Long> si;
typedef set<ST> ss;
typedef pair<Long,Long> pii;
typedef vector<pii> vpii;


/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;
#define MAXN 150007
int r,c ,R[11],C[11],DP[11][(1<<11)];
inline bool checkBit(int N,int pos){
    return bool( N & (1<<pos) ) ;
}
inline int setBit(int N,int pos){
    return (N | (1<<pos));
}
int call(int cur,int mask){
    if(cur==r){
        int ret=0 ;
        rep(i,0,c){
            if(!checkBit(mask,i)){
                ret+=C[i] ;
            }
        }
        return ret;
    }
    if(DP[cur][mask]!=-1) return DP[cur][mask] ;
    int ret = 100000000 ;
    rep(ii,0,c){
        if(checkBit(mask,ii)){
                if(C[ii]>=R[cur]){
                    ret=min(ret,call(cur+1,mask)+R[cur]) ;
                }
        }else{
                if(C[ii]==R[cur]){
                    int newMask = setBit(mask,ii) ;
                    ret=min(ret,call(cur+1,newMask)+R[cur]) ;
                }
                else if(C[ii]>=R[cur]){
                    ret=min(ret,call(cur+1,mask)+R[cur]) ;
                }
        }
    }
    DP[cur][mask]=ret ;
    return ret ;
}
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    while(cin>>r>>c){
        mem(DP,-1) ;
        if(!r && !c) break ;
        rep(i,0,r){
            cin>>R[i] ;
        }
        rep(i,0,c){
            cin>>C[i];
        }
        int res= call(0,0);
        cout<<res<<endl ;
    }
    return 0 ;
}

