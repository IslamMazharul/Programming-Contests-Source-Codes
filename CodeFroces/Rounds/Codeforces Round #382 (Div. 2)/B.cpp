#include <bits/stdc++.h>
using namespace std ;
long double arr[1000000+7] ;
int main(void){
  //  freopen("in.in","r",stdin) ;
    int n,n1,n2 ;
    cin>>n>>n1>>n2 ;
    for(int i=0;i<n;i++){
        cin>>arr[i] ;
    }
    sort(arr,arr+n) ;
    if(n1<n2) swap(n1,n2) ;
    long double res1=0,res2=0;
    for(int i=0;i<n;i++){
            if(i<n2){
                res2+=arr[n-i-1] ;
            }else if(i-n2<n1){
                res1+=arr[n-i-1] ;
            }
    }
    cout<<fixed<<setprecision(10)<<res1/n1+res2/n2+1e-20<<endl ;
  //  printf("%lf\n",res/(n1*n2)) ;
    return 0 ;
}
