/* From topcoder */
int read(int idx){
    /* this will return single value of the idx-th index */

    int sum = 0 ;
	while(idx>0){
		sum+=tree[idx] ;
		idx -= (idx &(-idx)) ;
	}

	return sum ;

}


void update(int idx,int val){

    while(idx<=n){
		tree[idx]+=val ;
		idx += (idx &(-idx)) ; ;
	}

}

int readSingle(int idx){

    int sum = tree[idx];
	if (idx > 0){
		int z = idx - (idx & -idx);
	    idx--;
        while (idx != z){
        	sum -= tree[idx];
		    idx -= (idx & -idx);
        }
	}

return sum;

}
