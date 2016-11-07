#include <bits/stdc++.h>
using namespace std ;
int main(void){
    freopen("in.txt","r",stdin) ;
    int testcases ;
    cin>>testcases ;
    string  str ;
    string res="" ;
    getline(cin,str) ;
    while(testcases--){
        getline(cin,str) ;
        for(int i=0;i<str.size()-3;i++){
            if(str[i]==':' && str[i+1]=='-' && str[i+2]=='('){
                    res+="dukkher bepar";
                    i+=2 ;
            }
            else{
                res+=str[i] ;
            }
        }
    }
    cout<<res<<endl ;
    return 0 ;
}
