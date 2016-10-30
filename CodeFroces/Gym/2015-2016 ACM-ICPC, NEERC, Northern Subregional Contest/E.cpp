#include<bits/stdc++.h>
using namespace std ;
int main(void){
    freopen("easy.in","r",stdin) ;
    freopen("easy.out","w",stdout) ;
    string str,res="" ;
    cin>>str ;
    int i = 0 ;
    while(i<(int)str.length()){
        if(str[i]=='-'){
            res.push_back(str[i]) ;
            i++ ;
            if(i<(int)str.length()){
                bool f=1;
                res.push_back(str[i]) ;
                i++ ;
                while(i<(int)str.length() && str[i]!='+' && str[i]!='-'){
                    if(f) res.push_back('+') ;
                    res.push_back(str[i]) ;
                    if(str[i]!='0') f=0 ;
                    i+=1 ;
                }
            }
        }
        else{
            res.push_back(str[i]);
			i++ ;
        }
    }
    cout<<res<<endl ;
    return 0 ;
}
