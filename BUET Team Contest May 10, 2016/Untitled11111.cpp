#include <bits/stdc++.h>
using namespace std ;
unsigned long long call(int nn){
    multiset<unsigned long long>s,ss ;
    int n =nn;
    multiset<unsigned long long>::iterator it ;
    s.insert(n) ;
    while(1){
        unsigned long long cnt= 0 ;
        ss.clear() ;
        for(it=s.begin();it!=s.end();it++){
                cnt++ ;
                if(*it!=1) ss.insert(*it-1) ;
        }
        ss.insert(cnt) ;
        if(s==ss) break ;
        s=ss ;
        /*
        for(it=s.begin();it!=s.end();it++){
            cout<<*it<<" " ;
        }

        cout<<endl ;
        */
    }
    unsigned long long total=0 ;
for(it=s.begin();it!=s.end();it++){
            total+=*it ;
            //cout<<*it<<" " ;
        }

}
int main(void){
    unsigned long long TC,n,CT=1 ;
    cin>>TC ;
    while(TC--){
        cin>>n ;
        unsigned long long lo=0 ,hi=10000000000,mid;
        while(lo<=hi){
             //   cout<<lo<<" "<<hi<<endl ;
            mid = (lo+hi)>>1 ;
            if((mid*(mid+1))/2<=n){
                lo=mid+1 ;
            }else hi=mid-1;
        }
        cout<<"Case #"<<CT++<<": "<<(hi*(hi+1))/2<<endl ;
      //  cout<<hi<<endl ;
    }
    return 0 ;
}
