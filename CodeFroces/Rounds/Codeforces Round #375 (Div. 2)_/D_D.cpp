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
ST Map[100] ;
int n,m,k ;
bool visit[100][100] ;
int dx[][5]={{0,-1},{0,1},{1,0},{-1,0}} ;
vector<pii>components[1000000],temp ;
inline int OK(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m || visit[i][j]==1 || Map[i][j]=='*') return 0 ;
   // if(Map[i][j]=='c') return -1 ;
    return 1 ;
}
void DFS(int I,int J){
	
    rep(i,0,4){
            int X = dx[i][0]+I ;
            int Y = dx[i][1]+J ;
            int ret  = OK(X,Y) ;
            if(ret==1){
          //      cout<<I<<" "<<J<<" To "<<X<<" "<<Y<<endl ;
                temp.pb(mp(X,Y)) ;
                visit[X][Y]=1 ;
                DFS(X,Y) ;
            }
        //}
    }
}

int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;

    ST str ="",boundary="";
    cin>>n>>m>>k ;
    rep(i,0,m+2){
        boundary.pb('c') ;
    }
    
    Map[0]=boundary ;
    rep(i,1,n+1){
        cin>>str ;
        str="c"+str+"c" ;
        Map[i]=str ;
    }
    
    Map[n+1]=boundary ;
    n+=2 ;
    m+=2 ;
  //  rep(i,0,n) cout<<Map[i]<<endl ;
  //  cout<<n<<" "<<m<<endl ;
    int nG=0 ;
    rep(i,0,n){
        rep(j,0,m){
            if(!visit[i][j] && Map[i][j]=='.'){
                visit[i][j]=1 ;
               // cout<<i<<" "<<j<<endl ;
                temp.clear() ;            
                temp.pb(mp(i,j)) ;
                DFS(i,j) ;
                bool yes=1 ;
                rep(k,0,sz(temp)){
                  //  cout<<temp[i].first<<" "<<temp[i].second<<endl ;
                    if(Map[temp[k].first][temp[k].second]=='c'){
                        yes=0 ;
                        break ;
                    }
                }
                if(yes && !temp.empty()) components[nG++] = temp ;
            }
        }
    }
    int changes=0 ;
    int K =nG ;
    while(K-->k){
        int siz = 100000000 ;
        int idx=-1 ;
        /*
        rep(i,0,nG){
            cout<<components[i]<<endl ;
        }
        * */
        rep(i,0,nG){
            if(!components[i].empty() && sz(components[i])<siz){
                siz= sz(components[i]) ;
                idx=i ;
            }
        }
      //  cout<<siz<<endl ;
        changes+=siz ;
        rep(i,0,sz(components[idx])){
            Map[components[idx][i].first][components[idx][i].second]='*' ;
        }
        components[idx].clear() ;
        
    }
    cout<<changes<<endl ;
    
    rep(i,1,n-1){
        rep(j,1,m-1){
            cout<<Map[i][j] ;
        }
        cout<<endl ;
    }
    return 0 ;
}

