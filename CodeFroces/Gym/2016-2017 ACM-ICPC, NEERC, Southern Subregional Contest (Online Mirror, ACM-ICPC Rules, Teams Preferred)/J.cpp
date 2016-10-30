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
    freopen("in.in","r",stdin) ;
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
#define MAXN 107
#define OFFSET 10000
Long soda[MAXN],vol[MAXN] ;
pii DP[MAXN][4*OFFSET] ;
bool f[MAXN][4*OFFSET] ;
Long n ;
pii call(Long cur,Long availVol){

        if(cur==n){
                if(availVol>=OFFSET){
                    return mp(0,0) ;
                }
                return mp(100000000,100000000) ;
        }
    //    cout<<n<<" "<<cur<<endl ;
        if(f[cur][availVol]) return DP[cur][availVol] ;
        f[cur][availVol] = 1 ;
        pii ret ;
        pii ret1 = call(cur+1,availVol-soda[cur]) ; // not talking
        ret1.second+=(soda[cur]) ;

        pii ret2 = call(cur+1,availVol+vol[cur]-soda[cur]) ;                         // taking
        ret2.first++ ;


        if(ret1.first<ret2.first){
    //            cout<<"Not taking "<<endl ;
            ret =  ret1 ;
        }else if(ret1.first==ret2.first && ret1.second<ret2.second){
            ret =  ret1 ;
        }else {
       //     cout<<"taking "<<endl ;
            ret =  ret2 ;
        }

        DP[cur][availVol] = ret ;
       // cout<<cur<<" "<<availVol-OFFSET<<endl ;
        //cout<<ret.first<<" "<<ret.second<<endl ;
        return ret ;
}

int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    cin>>n ;
    rep(i,0,n){
        cin>>soda[i] ;
    }
    rep(i,0,n){
        cin>>vol[i] ;
    }

   pii res =  call(0,OFFSET) ;
   cout<<res.first<<" "<<res.second<<endl ;
   return 0 ;
}
