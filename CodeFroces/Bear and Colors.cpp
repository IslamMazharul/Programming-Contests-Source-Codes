#include <bits/stdc++.h>
using namespace std ;
struct Data{
    int idx,val ;
    bool operator<(const Data&prev)const{
        if(val!=prev.val) return val>prev.val ;
        return idx<prev.idx ;
    }
};
Data temp ;
#define MAXN 5000+7
int arr[MAXN],_count[MAXN],last[MAXN],res[MAXN] ;
int main(void){
    int n ;
    cin>>n ;
    for(int i=0;i<n;i++){
        cin>>arr[i] ;
    }
    for(int start=0;start<n;start++){
        set<Data>myset ;
        set<Data>::iterator it ;
        memset(_count,0,sizeof(_count)) ;
        memset(last,-1,sizeof(last)) ;
    //    int cnt=0;
        cout<<start<<":\n" ;
        for(int en=start;en<n;en++){
            if(last[arr[en]]==-1) last[arr[en]]=en ;
            temp.idx=last[arr[en]] ;
            temp.val = _count[arr[en]] ;
            it = myset.find(temp) ;
            if(it!=myset.end()) {
                myset.erase(it) ;
            }
            _count[arr[en]]++ ;
            temp.val=_count[arr[en]] ;
            myset.insert(temp) ;
           // if(myset.empty()) continue ;

            it  = myset.begin() ;
            res[arr[it->idx]]++ ;
            for(it=myset.begin();it!=myset.end();it++) cout<<arr[it->idx]<<" "<<it->val<<endl ;
            cout<<endl ;
        }
        cout<<"----------------"<<endl;
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" " ;
     return 0 ;
}
