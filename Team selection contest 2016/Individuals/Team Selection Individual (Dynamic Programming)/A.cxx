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
#define inf 100000000000
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
#define MAXN 2007
pii score[MAXN] ;
bool F[MAXN][MAXN] ;
pii DP[MAXN][MAXN] ;
int n ;
ST name ;
bool compare(pii &p,pii &q){
    if(p.ff==q.ff){
        return p.ss<q.ss ;
    }
    return p.ff>q.ff ;
}
pii call(int cur,int taken){

    if(taken>(cur+1)/2){
        return mp(-inf,0) ;
    }
    if(cur==n){
       // cout<<(n+1)/2<<" "<<taken<<endl ;
        if(taken==(n+1)/2) return mp(0,0) ;
        return mp(-inf,0) ;
    }
    if(F[cur][taken]) return DP[cur][taken] ;

    pii ret1,ret2 ,res;
    ret1 = call(cur+1,taken) ; // doesn't take the current element
    ret1.ss+=score[cur].ff ; // petra takes it

    ret2=call(cur+1,taken+1) ; // jan takes the current element
    ret2.ff+=score[cur].ss ;

    if(ret1.ff>ret2.ff){
        res=ret1 ;
    }
    else if(ret1.ff==ret2.ff && ret1.ss>ret2.ss){
        res=ret1 ;
    }
    else res=ret2 ;
    F[cur][taken]=1 ;
    DP[cur][taken]=res ;
    return DP[cur][taken] ;
}

int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    int testcases ;
    cin>>testcases ;
    while(testcases--){
        mem(F,0) ;
        cin>>n>>name ;
        rep(i,0,n){
            cin>>score[i].ff>>score[i].ss ;
        }
        sort(score,score+n,compare) ;
        /*
        rep(i,0,n){
            cout<<score[i].ff<<" "<<score[i].ss<<endl ;
        }
        */
        Long keep = 0  ;
        if(name=="Petra"){
            keep+=score[0].ff ;
            rep(i,0,n-1){
                score[i]=score[i+1] ;
            }
            n-- ;
        }
        /*
        rep(i,0,n){
            cout<<score[i].ff<<" "<<score[i].ss<<endl ;
        }
        /*/
        pii res=call(0,0) ;
        cout<<res.ss+keep<<" "<<res.ff<<endl ;
    }
}

