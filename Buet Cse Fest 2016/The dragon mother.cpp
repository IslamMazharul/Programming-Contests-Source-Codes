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
#define MAXN 10000
bool vis[MAXN][MAXN],DP[MAXN][MAXN];
int R,C ,N,pos[MAXN][3];
Long sqr_distance(int i,int j,int k,int l){

     Long dx = (i-k) ;
     Long dy = (j-l) ;
     return dx*dx+dy*dy ;
}

int dr[] = {-1,0,1,0} ;
int dc[] = {0,1,0,-1} ;

int valid(int r,int c){
	return r >= 0 && r <= R && c >= 0 && c <= C && vis[r][c]==0 && DP[r][c]==0 ;
	/// you may also want to check if this cell is empty
}

int main(void){
  //  ios_base::sync_with_stdio(0) ; cin.tie(0);
 //  read() ;
    int testcases ,x,y,cx,cy,caseno=1;
    cin>>testcases ;
   // cout<<testcases<<endl ;
    while(testcases--){
        mem(vis,0) ;
        mem(DP,0) ;
        cin>>C>>R>>N ;

        rep(i,0,N){
            cin>>pos[i][0]>>pos[i][1]>>pos[i][2] ;
        }

        rep(i,0,R+1){
            rep(j,0,C+1){
                rep(k,0,N){
                    if(sqr_distance(i,j,pos[k][0],pos[k][1])<= pos[k][2]*pos[k][2]){
                        DP[i][j]=1 ;
                    }

                }
            }
        }
        queue<pii>q ;
        rep(i,0,3){
            cin>>x>>y ;
            if(!DP[x][y]){
                  //  cout<<x<<" "<<y<<endl ;
                vis[x][y]=1 ;
                q.push(mp(x,y)) ;
            }
        }
      //  cout<<DP[6][4]<<endl ;
        while(!q.empty()){
                pii now = q.front() ; q.pop() ;
                rep(i,0,4){
                    int X  = now.first+dr[i] ;
                    int Y  = now.second+dc[i] ;
                    if(valid(X,Y)){
                      //  cout<<"From "<<now.first<<" "<<now.second<<" To "<<X<<" "<<Y<<endl ;
                        q.push(mp(X,Y)) ;
                        vis[X][Y]=1 ;
                    }
                }
        }
        cin>>cx>>cy ;
       // cout<<cx<<" "<<cy<<endl ;
        cout<<"Case No "<<caseno++<<" : " ;
        if(vis[cx][cy] && !DP[cx][cy]) cout<<"YES\n" ;
        else cout<<"NO\n" ;
    }
    return 0 ;
}

/// duita array use korse kina
/// R and C er boundary check
/// equal to checking

