#include<bits/stdc++.h>
using namespace std ;
#define MAXN 300007
queue<int>reqQ[MAXN] ;
set<int>s ;
set<int>::iterator it ;
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    int n,q ,type,val,tim=1;
    cin>>n>>q ;
    for(int i=1;i<=n;i++){
        while(!reqQ[i].empty()) reqQ[i].pop() ;
    }
    s.clear() ;
    int res=0 ;
    while(q--){
            cin>>type>>val ;
            if(type==1){
                s.insert(val) ;
                reqQ[val].push(tim) ;
                tim++ ;
                res++ ;
            }
            else if(type==2){
                res-=reqQ[val].size() ;
                while(!reqQ[val].empty()) reqQ[val].pop() ; // all the request proccessed by the appliaction is being read
                it = s.find(val) ;
                if(it!=s.end()) s.erase(it) ;
            }
            else{
                for(it=s.begin();it!=s.end();it++){
                    while(!reqQ[*it].empty() && reqQ[*it].front()<=val){
                        reqQ[*it].pop() ;
                        res-- ;
                    }
                }
            }
            cout<<res<<endl ;

    }
    return 0 ;
}
