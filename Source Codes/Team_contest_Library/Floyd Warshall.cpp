memset(dis,-1,sizeof(dis) ;
FOR(k,0,n-1){
	FOR(i,0,n-1){
		if(dis[i][k]!=-1)
		{
		    FOR(j,0,n-1){
		      if(dis[j][k]!=-1) dis[i][k] = max(dis[i][j],dis[i][k],dis[k][j]) ;
		    }
	    }
	}
}
