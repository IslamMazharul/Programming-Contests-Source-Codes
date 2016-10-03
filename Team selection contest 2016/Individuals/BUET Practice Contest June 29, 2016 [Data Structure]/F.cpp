/*
 * Mazharul Islam , BUET
 * Problem Link:http://acm.hust.edu.cn/vjudge/contest/view.action?cid=120288#problem/B
 */
using namespace std;
#include <bits/stdc++.h>

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define rep(i,a,n) for(__typeof(n) i=a; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define write(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((i64)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
#define endl "\n"
typedef long long  i64;
typedef unsigned long long ui64;
typedef string ST;
typedef vector<i64> vi;
typedef vector<ST> vs;
typedef map<i64,i64> mii;
typedef map<ST,i64> msi;
typedef set<i64> si;
typedef set<ST> ss;
typedef pair<i64,i64> pii;
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
#define MAXN 300007
struct info
{
	i64 prop,sum;
}tree[MAXN*3];
void init(i64 node,i64 b,i64 e){
	if(b==e){
		//tree[node]=arr[b];
		return;
	}
	i64 Left=node*2;
	i64 Right=node*2+1;
	i64 mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node].sum=tree[Left].sum+tree[Right].sum;
}

i64 query(i64 node,i64 b,i64 e,i64 i,i64 j,i64 carry=0){

	if (i > e || j < b)		return 0;

	if(b>=i and e<=j) return tree[node].sum+carry*(e-b+1);	//সাম এর সাথে যোগ হবে সেই রেঞ্জের সাথে অতিরিক্ত যত যোগ করতে বলেছে সেটা


	i64 Left=node<<1;
	i64 Right=(node<<1)+1;
	i64 mid=(b+e)>>1;

    i64 p1 = query(Left, b,mid,  i, j,   carry+tree[node].prop);
    i64 p2 = query(Right, mid+1, e, i, j,carry+tree[node].prop);

    return  p1+p2;

}

void update(i64 node,i64 b,i64 e,i64 i,i64 j,i64 x){

	if (i > e || j < b)	return;
	if (b >= i && e <= j)
	{
		tree[node].sum+=((e-b+1)*x);
		tree[node].prop+=x;
		return;
	}
	i64 Left=node*2;
	i64 Right=(node*2)+1;
	i64 mid=(b+e)/2;
	update(Left,b,mid,i,j,x);
	update(Right,mid+1,e,i,j,x);
	tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;
}
map<ST,i64>positionArray ;
int main(){
    read("in.txt") ;
    i64 TC ,N;
    ST str ;
    cin>>TC ;
    while(TC--){
        mem(tree,0) ;
        positionArray.clear() ;
        scanf("%lld",&N) ;
        init(1,1,N) ;
        rep(i,0,N){
            cin>>str ;
            positionArray[str]=i ;
        }
        i64 res=0 ;
        rep(i,0,N){
            cin>>str ;
            i64 pos=positionArray[str] ;
            //cout<<query(1,1,N,pos+1,N)<<endl ;
            res += query(1,1,N,pos+1,N) ;
            update(1,1,N,pos,pos,1) ;
        }
        printf("%lld\n",res) ;
    }
    return 0;
}


