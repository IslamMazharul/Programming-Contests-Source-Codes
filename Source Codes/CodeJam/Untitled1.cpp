#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#include <cmath>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
using namespace std ;
#define MAXN 222
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
#define LL long long
#define inf 10000000
struct ELE{
    int pos,val ;
    bool operator <(const ELE &p)const{
        return val>p.val ;
    }
};


ELE ele[MAXN] ;

int main(int argc, char **argv){
    #ifdef unlucky_13
        freopen("C:\\Users\\Mazharul Islam\\Documents\\in.txt","r",stdin) ;
    #endif
    int n,k,arr[MAXN],res ;

    while(cin>>n>>k){
        res = -inf ;
        FOR(i,0,n-1){
            cin>>arr[i] ;
            ele[i].pos = i ;
            ele[i].val = arr[i] ;
        }

        sort(ele,ele+n) ;
      //  FOR(i,0,n-1) cout<<ele[i].val<<endl ;
        vector<int>temp ;
        FOR(i,0,n-1){

            int tot = 0 ;
            FOR(j,i,n-1){
                tot+=arr[j] ;
                temp.clear() ;
                FOR(m,i,j) temp.push_back(arr[m]) ; // WAS GETINNG WA FOR NOT USING VECTOR
                int cnt = 0 ,temptot = 0;
                FOR(m,0,n-1){

                    if(ele[m].pos>=i && ele[m].pos<=j) continue ;
                    //if(ele[m].val<0) continue ;
                    cnt++ ;
                    temp.push_back(ele[m].val) ;
                   // temptot+=ele[m].val ;
                    if(cnt==k) break ;
                }

             //   cout<<"normal sum "<<i<<" "<<j<<" is "<<tot<<endl ;
                sort(temp.begin(),temp.end()) ;

                FOR(m,cnt,temp.size()-1){
                    temptot+=temp[m] ; // getting rid of the lowest values
                }
                res = max(res,temptot) ;
            }
        }

        cout<<res<<"\n" ;
    }
    return 0 ;
}
