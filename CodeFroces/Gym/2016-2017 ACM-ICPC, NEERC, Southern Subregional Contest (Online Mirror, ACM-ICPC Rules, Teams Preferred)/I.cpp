#include <bits/stdc++.h>
using namespace std ;
#define LL long long
#define MAXN 3000+7
struct Data{
    LL a,b ,idx;
};
Data arr[MAXN] ;
int marked[MAXN] ;
int compare(Data p,Data q){
    if(p.a!=q.a) return p.a>q.a ;
    return p.b>q.b ;
}
int main(void){
    LL n,p,s ;
    cin>>n>>p>>s ;
    for(int i=0;i<n;i++) arr[i].idx=i+1 ;
    for(int i=0;i<n;i++) cin>>arr[i].a ;
    for(int i=0;i<n;i++) cin>>arr[i].b ;
    sort(arr,arr+n,compare) ;
    /*
    for(int i=0;i<n;i++){
        cout<<arr[i].a<<" "<<arr[i].b<<endl ;
    }
    */
    LL res=0 ;
    for(int i=0;i<p;i++){
        res+= arr[i].a ;
        marked[i]=1 ;
    }
  //  cout<<res<<endl ;
    for(int i=0;i<s;i++){
            int maxi = 0 ;
            int id ,ID;
            for(int j=0;j<n;j++){
                if(maxi<arr[j].a && marked[j]==0){ // not picked
                    maxi = arr[j].a ;
                    ID = j ;
                }
            }
            //cout<<ID<<endl ;
            maxi = 0 ;
            for(int j=0;j<n;j++){
                if(marked[j]==1){
                    if(maxi<res+arr[j].b-arr[j].a+arr[ID].a){ // take the i th player for tournament
                        maxi=res+arr[j].b-arr[j].a+arr[ID].a ;
                        id = j ;
                    }
                }
                else if(marked[j]==2){
                    // can not touch this
                }
                else{
                    if(maxi<res+arr[j].b){          // taking out the range
                            maxi = res+arr[j].b ;
                            id = j ;
                    }
                }
            }

            if(marked[id]){
                marked[ID]=1 ;
                marked[id]=2 ;
                res = maxi ;
            }
            else{
                marked[id]=2 ;
                res = maxi ;
            }
          //  cout<<res<<endl ;
    }
    cout<<res<<endl ;
    for(int i=0;i<n;i++){
        if(marked[i]==1) cout<<arr[i].idx<<" " ;
    }
    cout<<endl ;
    for(int i=0;i<n;i++){
        if(marked[i]==2) cout<<arr[i].idx<<" " ;
    }
    return 0 ;
}
