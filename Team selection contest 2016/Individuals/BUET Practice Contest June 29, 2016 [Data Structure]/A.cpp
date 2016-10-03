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
#define sz(x) ((int)x.size())
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
typedef int i64;
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
#define MAXN 100001
struct info
{
	i64 prop,sum;
}tree[MAXN*3];
void init(int node,int b,int e){
	if(b==e){
		tree[node]=arr[b];
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=tree[Left]+tree[Right];
}

int query(int node,int b,int e,int i,int j,int carry=0){

	if (i > e || j < b)		return 0;

	if(b>=i and e<=j) return tree[node].sum ;


	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;

    int p1 = query(Left, b,mid,  i, j,);
    int p2 = query(Right, mid+1, e, i, j);

    return  p1+p2;

}

void update(int node,int b,int e,int i,int j,i64 x){

	if (i > e || j < b)	return;
	if (b >= i && e <= j)
	{
		tree[node].sum+=((e-b+1)*x);
		tree[node].prop+=x;
		return;
	}
	int Left=node*2;
	int Right=(node*2)+1;
	int mid=(b+e)/2;
	update(Left,b,mid,i,j,x);
	update(Right,mid+1,e,i,j,x);
	tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;
}
int main(){
    read("in.txt") ;
    return 0;
}


