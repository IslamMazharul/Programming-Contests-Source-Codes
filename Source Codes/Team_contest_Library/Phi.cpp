//normal method

vector<int>primes ;  // we will preload the primes

int PHI(int n){

    int ret  = n ;
    int primeSize = primes.size() ;
    for(int i=0;i<primeSize;i++){
        if(n%primes[i]==0) ret -= ret/primes[i] ;
    }

    return ret ;
}

int PHI(int n){

    int ret = n ;
    for(int i=;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i ;
            }
            ret -=ret/i ;
        }
    }
    return ret ;
}

//This is called when phi is called again and again

#define MAXN 1000005
int phi[MAXN] ;

void CalculatePhi(){

    for(int i=1;i<MAXN;i++) phi[i] = i ;

    for(int p=2;p<MAXN;p++){
        if(Phi[p]==p){
            for(int k=p;k<MAXN;k+=p)   phi[k] -=phi[k]/p ;
        }
    }
}
