#include <bits/stdc++.h>
using namespace  std ;
#define Long  long long
int main(void){
    Long k=1,N,NUM=2 ;
    cin>>N ;
    while(N--){
            Long step = ((k+1)*k*(k+1))-(NUM/k) ;
          //  cout<<k<<endl ;
            //cout<<k*(k+1)*k*(k+1)-NUM<<endl ;
            if(step<0){
                //cout<<k<<endl ;
                //cout<<(k*(k+1)*k*(k+1))<<endl ;
                break ;
            }
            NUM = k*(k+1) ;
            k++ ;
            cout<<step<<endl ;
            /*
            if(step<0){
             //   cout<<"OK" ;
                break ;
            }
            */
    //    cout<<k<<endl ;
    }
    return 0 ;
}
