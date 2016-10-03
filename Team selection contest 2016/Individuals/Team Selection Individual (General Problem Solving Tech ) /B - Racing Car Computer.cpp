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
#define MAXN 1507
int a,b,n,DP[MAXN];
struct Car{
    int b,f ;
    bool operator<(const Car &prev)const{
        if(prev.f!=f) return f<prev.f ;
        return b>prev.b ;

    }
} ;
Car  car[MAXN] ;

inline bool valid(int k1,int k2){
    if(car[k2].f>=n-car[k1].b && car[k1].b>=n-car[k2].f && car[k1].b+car[k1].f<n) return 1 ;
    if(car[k1].f==car[k2].f && car[k2].b==car[k2].b && car[k1].b+car[k1].f<n){
        if(n-car[k2].b-car[k2].f>1){
            return 1 ;
        }
    }
    return 0 ;
}
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    int caseno=1 ;
    while(cin>>n && n){
        rep(i,1,n+1){
            cin>>car[i].f>>car[i].b ;
        }
        sort(car+1,car+n+1) ;
        /*
        rep(i,1,n+1){
            cout<<car[i].f<<" "<<car[i].b<<endl ;
        }
        cout<<endl ;
       // */
        DP[0]=0 ;
        rep(i,1,n+1){
            if(car[i].b+car[i].f>=n){
                DP[i]=-1;
                continue ;
            }
            else{
                DP[i]=1 ;
            }
            rep(j,1,i){
                if(valid(j,i)) DP[i]=max(DP[i],DP[j]+1) ;
            }
          //  cout<<i<<" : "<<DP[i]<<endl ;
        }
        int res= 0 ;
        rep(i,1,n+1){
            res=max(res,DP[i]) ;
        }
        cout<<"Case "<<caseno++<<": " ;
        cout<<n-res<<endl ;
    }
    return 0 ;
}

