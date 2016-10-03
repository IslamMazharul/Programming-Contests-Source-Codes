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
#define MAXN 10247
int arr[16] ;
vector<int>D[MAXN] ;
int C[(1<<16)+1] ;
inline bool check(int mask,int pos){
    return bool(mask & (1<<pos)) ;
}

int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    int caseno=1 ;
    while(cin>>arr[0] && arr[0]){
        rep(i,1,16){
            cin>>arr[i] ;
        }
        sort(arr,arr+16) ;
        mem(C,0) ;
        rep(i,0,MAXN) D[i].clear() ;

        rep(mask,0,(1<<16)){
            if(__builtin_popcount(mask)!=4) continue ;
            vector<int> sequence ;
            rep(pos,0,16){
                if(check(mask,pos)){
                        sequence.pb(arr[pos]) ;
                }
            }
          //  cout<<sequence<<endl ;
            do{
                int sum=0 ;
                rep(k,0,4){
                    sum+=( (k+1)*sequence[k]) ;
                }
                D[sum].pb(mask) ;
            }while(next_permutation(all(sequence))) ;
        }


     //   /*
        rep(i,0,MAXN){
            rep(j,0,sz(D[i])){
                rep(k,j+1,sz(D[i])){
                    int xxor = D[i][j] & D[i][k] ;
                    if(xxor==0){
                        C[D[i][j] | D[i][k]]++ ;
                    }
                }
            }
        }
        Long res=0 ;
        rep(mask,0,(1<<16)){
            if(__builtin_popcount(mask)!=8) continue ;
            res+= C[mask]*C[mask ^ ((1<<16)-1)] ;
        }
        cout<<"Case "<<caseno++<<": " ;
        cout<<res/2<<endl ;
    }
    return 0 ;
}


