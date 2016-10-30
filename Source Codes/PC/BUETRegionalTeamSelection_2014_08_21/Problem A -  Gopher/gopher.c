#include <stdio.h>
#include <math.h>
#include <assert.h>

double x[300], y[300];
int m,n,s,v;

char c[300][300];
int match[300], back[300];
int q[300], qn;

main(){
   int i,j,k;
   if (4 != scanf("%d%d%d%d",&n,&m,&s,&v)) return 0;
   
   for (i=0;i<300;i++) {
       for(j=0;j<300;j++) {
           c[i][j]=0 ;
       }
   }
   
   for (i=0;i<200;i++)  match[i]=back[i]=0;
   for (i=1;i<=n+m;i++) scanf("%lf%lf",x+i,y+i);
   for (i=1;i<=n;i++) {
       for (j=n+1;j<=n+m;j++) {
            if (hypot(x[i]-x[j],y[i]-y[j]) <= v*s+.00000001)
                c[i][j]=c[j][i] = 1 ;
            }
        }
   }

   for (i=1;i<=m+n;i++) if (find(i)) i=0;
   for (k=0,i=1;i<=n;i++) if (match[i]) k++;
   printf("%d\n",n-k);
/*
   for (i=1;i<=n;i++){
      printf("%0.1lf %0.1lf",x[i],y[i]);
      if (match[i]) {
          printf(" %0.1lf %0.1lf",x[match[i]],y[match[i]]);
          printf(" dist %0.1lf", hypot(x[match[i]]-x[i],y[match[i]]-y[i]));
      }
      printf("\n");
   }
*/

   main();
   return 0;
}

find(int i){
    
   int r,j,k;
   if (match[i]) return 0;
   for (j=1;j<=n+m;j++) back[j] = 0;
   q[0] = i;
   qn = 1;
   for (k=0;k<qn;k++){
      for (j=1;j<=n+m;j++){
         if (!c[q[k]][j]) continue;
         if (match[j]){
            if (!back[j]){
               back[j] = q[k]; back[match[j]] = j;
               q[qn++] = match[j];
            }
         }else{
            match[q[k]] = j; match[j] = q[k];
            for (r=back[q[k]];r;r=back[back[r]]){
               match[r] = back[r]; match[back[r]] = r;
            }
            return 1;
         }
      }
   }
   return 0;
}

