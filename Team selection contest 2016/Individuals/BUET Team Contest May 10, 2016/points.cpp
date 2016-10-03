    //
    // Created by User on 6/23/2016.
    //
    /*
     * Mazharul Islam
     * BUET
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
    typedef long long i64;
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
    multiset<i64>Map ;
    multiset<i64>::iterator it ;
    int main(void) {
        freopen("in.txt","r",stdin) ;
        ios_base::sync_with_stdio(0) ; cin.tie(NULL);
        i64 n,x,y,pp ;
        ST str ;
        cin>>n;
        rep(i,0,n){
            cin>>str>>x>>y ;
            pp = x*1000000000+y ;

            if(str[0]=='r'){
                it=Map.find(pp) ;
                cout<<pp<<" remove"<<endl ;
                Map.erase(it) ;
            }

            else if(str[0]=='a'){
                Map.insert(pp) ;
                cout<<pp<<" inserted"<<endl ;
            }

            else{
                pp  = (x+1)*1000000000+y+1 ;
                it = Map.lower_bound(pp) ;
              //  cout<<pp<<" inserted"<<endl ;
                if(it==Map.end()){
                    cout<<"-1"<<endl ;
                }
                else{
                    i64 xx = (*it)/1000000000;
                    i64 yy = (*it)%1000000000 ;
                    cout<<xx<<" "<<yy<<endl ;
                }
            }
        }
    }


