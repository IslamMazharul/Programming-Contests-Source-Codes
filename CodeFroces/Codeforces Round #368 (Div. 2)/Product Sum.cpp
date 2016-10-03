#include <bits/stdc++.h>
using namespace std ;
#define Long long long
#define MOD 1000000007
Long DP[11] ,Power_45[34],Power_10[34];
Long Log(Long val){
	//if(val==0) return 0 ;
	Long llog=0 ;
	while(val>0){
		val/=10 ;
		llog++ ;
	}
	return llog ;
}
Long getProduct(Long num){
	Long mul=1 ;
	Long powerr=Log(num)-1;
	Long ret=0;
	string number="" ;
	while(num>0){
        number.push_back(num%10+'0') ;
        num/=10 ;
	}1
	reverse(number.begin(),number.end()) ;
	//cout<<number<<endl ;
	for(int i=0;i<number.length();i++){
		Long digit=number[i]-'0' ;
		//cout<<mul<<" "<<DP[digit+1]<<" "<<Power_45[powerr]<<endl ;
		ret += (mul*DP[digit+1]*Power_45[powerr]) ;
	//	cout<<ret<<endl ;
		powerr-- ;
		mul*=digit ;
		mul%=MOD ;
		num/=10 ;
	}
    ret+=mul ;
	return ret%MOD ;
}

int main(void){
    DP[9]=9 ;
    for(int i=8;i>=0;i--){
        DP[i]+=DP[i+1]+i ;
    }

    Power_45[0]=Power_10[0]=1 ;
    for(int i=1;i<20;i++){
        Power_45[i]=Power_45[i-1]*45 ;
        Power_45[i]%=MOD ;
        Power_10[i]=Power_10[i-1]*10 ;
        Power_10[i]%=MOD ;
    }
    //cout<<getProduct(35)<<endl ;
    ///*
    Long TC ,A,B,res;

    cin>>TC ;
    while(TC--){

        cin>>A>>B ;
        res=0 ;
        if(Log(A)==Log(B)){
            Long temp1 = getProduct(A) ;
            Long temp2 = getProduct(B+1) ;
          //  cout<<temp1<<" "<<temp2<<endl ;
            //cout<<(temp2-temp1+2*MOD)%MOD<<endl ;
            res += (temp1-temp2+MOD)%MOD ;
        }
        else{
            for(int k=Log(A)+1;k<Log(B);k++){
                res+=Power_45[k] ;
                res%=MOD ;
            }
    //        cout<<res<<endl ;
            res+=getProduct(A) ;
            res%=MOD ;
      //      cout<<res<<endl ;
            //cout<<Power_10[Log(B)]<<endl ;
            Long temp1 = getProduct(Power_10[Log(B)-1]) ;
            Long temp2 = getProduct(B+1) ;
            //cout<<temp1<<" "<<temp2<<endl ;
            //cout<<(temp2-temp1+2*MOD)%MOD<<endl ;
            res += (temp1-temp2+MOD)%MOD ;
        }
        cout<<res<<endl ;
    }
    return 0 ;
}
