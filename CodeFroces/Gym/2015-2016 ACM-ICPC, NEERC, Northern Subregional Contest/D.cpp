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
Long n ;
Long Pow(Long base,Long exp){
		if (exp==0) return 1 ;

		else if((exp&1)==1){
			ULong ret = Pow(base,exp-1) ;
			return (ret*base) ;
		}
		else{
			Long ret = Pow(base,exp/2) ;
			return (ret*ret) ;
		}
}
vector<Long>res;
bool found=0 ;
void DFS(Long N,Long I,Long J){
	if(found) return ;
	if(N<0) return ;
	//cout<<N<<endl ;
	if(N==0){
		//cout<<"Found"<<endl ;
	//	cout<<I<<" "<<J<<endl ;
		//cout<<res1<<endl ;
		//cout<<res2<<endl ;
		cout<<sz(res)<<endl  ;
		cout<<res[0] ;
		rep(i,1,sz(res)){
            cout<<" "<<res[i] ;
		}
		cout<<endl ;
		found=1 ;
		return ;
	}

	for(Long i=I;i>=0;i--){
		for(Long j=J; ;j++){

			Long Total = Pow(2,i)*Pow(3,j) ;
		//	cout<<Total<<" "<<i<<" "<<j<<endl ;
			if (Total > N) break ;

			else{
					ULong NN =N-Total ;
					//cout<<I<<" "<<J<<endl ;
					res.pb(Total) ;
					DFS(NN,i-1,j+1) ;
					if(found){
                      //  cout<<i<<" "<<j<<endl ;
					}
					res.pop_back() ;
			}
		}
	}
}
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    freopen("distribution.in","r",stdin) ;
    freopen("distribution.out","w",stdout) ;
	Long year ,N;
	cin>>year ;
	while(year--){
        cin>>N ;
        found=0 ;
        if(N==1) cout<<"1\n1\n" ;
        else{
                //cout<<N<<endl ;
                res.clear() ;
            DFS(N,5,0) ;
        }
	}
    return 0 ;
