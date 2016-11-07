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
    freopen("/home/mazharul/in.in","r",stdin) ;
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
#define eps 1e-12
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
#define MAXN 10000000+7
long double DP[MAXN+7] ;
long double get(int val){
  //  /*
    if(val<MAXN){
        return DP[val] ;
    }
    long double val1 = val ;
   // */
    return log(val1)+0.57721566490153286060651+1.00/(2.00*val1)-1.00/(12.00*val1*val1) ;
}

int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    long double res ;
    int W,L,caseno=1 ;
    DP[0]=0 ;
    rep(i,1,MAXN+1){
        DP[i]=DP[i-1]+1.00/i ;
    }
    //cout<<DP[MAXN]-get(MAXN)<<endl ;
   // cout<<get(1)<<endl ;
    while(cin>>W>>L){
            if(!W && !L) break ;
            if(L==0){
                if(W%8==0) res=8 ;
                else res =-1 ;
            }
            else{
                /// min tournament  WWWWWWWL
                int min_t = L ;
                int T = W-min_t*7;
                if(T>0){
                    if(T%8==0) min_t+=T/8 ;
                    else{
                        min_t+=T/8+1 ;
                    }
                }
                int max_t=L ;    /// L L L  L WWWWWL
                max_t+=W/8 ;
                res = ((long double)(W+L))*(get(max_t)-get(min_t-1))/(max_t-min_t+1)+eps ;
        }

        cout<<"Case "<<caseno++<<":\n" ;
        if(res!=-1) cout<<"On Average Bob Reaches Round "<<fixed<<setprecision(2)<<res+eps<<endl ;
        else cout<<"Situation Impossible."<<endl ;
    }
    return 0 ;
}

