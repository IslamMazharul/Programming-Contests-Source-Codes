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
    freopen("/home/mazharul_islam/in.txt","r",stdin) ;
#endif
}
#define all(x) x.begin(),x.end()
#define sz(x) ((Long)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define FF first
#define SS second
#define eps 1e-9
#define endl "\n"
#define sc(n) scanf("%lld",&n)
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
Long readInt () {
	bool minus = false;
	Long result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
#define deb(x) cerr << #x << " = " << x << endl;
#define MAXN 1000
Long A[MAXN] ;
mii mapping ;
mii::iterator it ;
vi pos[MAXN] ;
bool seen[MAXN] ;
int main(void){
    Long TC ,N,K,res;
    TC = readInt() ;
    while(TC--){
        mapping.clear() ;
        K=0 ;
        res=0 ;
        N = readInt() ;
        rep(i,0,N){
            A[i]= readInt() ;
            mapping[A[i]]=0 ;
        }
        foreach(it,mapping){
            mapping[it->first]=K++ ;
        }

        rep(i,0,N){
            A[i]=mapping[A[i]] ;
            //cout<<A[i]<<" " ;
            if(!pos[A[i]].empty())pos[A[i]].clear() ;
        }
        rep(i,0,N){
                pos[A[i]].pb(i) ;
        }
        rep(start,0,N){
            mem(seen,0) ;
            si positions ;
            si::iterator IT ;
            Long prev=0 ;
            rep(edd,start,N){
             //   cout<<start<<" "<<edd<<" new interval \n" ;
                if(!seen[A[edd]]){
                    seen[A[edd]]=1 ;
                    int k = upper_bound(all(pos[A[edd]]),edd)-pos[A[edd]].begin() ;
                    while(k<sz(pos[A[edd]])){
                        positions.insert(pos[A[edd]][k]) ;
                        k++ ;
                    }
                    prev=0 ;
             //   deb(positions)
                // compute the result
                int i=edd,j ;
                IT=upper_bound(all(positions),i) ;
                while(IT!=positions.end()){
                        j = *IT-1 ;
                        if(i<j){
                       //     cout<<i+1<<" "<<j<<endl ;
                      //      res+=((j-i)*(j-i+1))/2 ;
                            prev+=((j-i)*(j-i+1))/2 ;
                        }
                        IT++ ;
                        i=j+1 ;

                }
                if(i<N-1){
                  //  cout<<i+1<<" "<<N-1<<endl;
                    //res+=((N-i-1)*(N-i))/2 ;
                    prev+=((N-i-1)*(N-i))/2 ;
                }
                }
                res+=prev ;
            }
        }
        printf("%lld\n",res) ;
    }

    return 0;
}
