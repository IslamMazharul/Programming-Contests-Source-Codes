//
// Solution for Poly-polygonal Numbers problem
// Author: Mohammad Saifur Rahman, BUET
//
#include<stdio.h>
#include<stdlib.h>
#include<ctime>

#define NMAX 50
#define IMAX 92700

unsigned int num[NMAX][IMAX];
unsigned int index[NMAX];
unsigned int count[NMAX];
unsigned int k[NMAX];

int cmp(const void* pa, const void* pb)
{
    unsigned int a = *((int*)pa);
    unsigned int b = *((int*)pb);

    return (a <= b) ? -1 : 1;
}

int main()
{
    int n,i,j,l,nRes;
    unsigned int s;
    bool fFirstRun = true;

   // clock_t start = clock();

   // freopen("sample.in", "r", stdin);

    while(true)
    {
        scanf("%u", &n);
        if (0 == n)
        {
            break;
        }

        if (fFirstRun)
        {
            fFirstRun = false;
        }
        else
        {
            printf("\n");
        }

        for(i=0;i<n;i++)
        {
            scanf("%u", &k[i]);
        }
        qsort(k, n, sizeof(k[0]), cmp);
        scanf("%u", &s);

        for(j=0;j<n;j++)
        {
            index[j] = 0;
            count[j] = 0;
            for(i=0;i<IMAX;i++)
            {
                if (i==0)
                {
                    l = 1;
                }
                else
                {
                    unsigned int del = 1+i*(k[j]-2);
                    if ((~0) - del < l)
                    {
                        break;
                    }

                    l += del;
                }

                if (l >= s)
                {
                    num[j][count[j]++] = l;
                }
            }
        }

        for(nRes=0;nRes<5;)
        {
            unsigned int minVal = (~0);
            int minK = 0;
            bool fRes = false;

            for(j=0;j<n;j++)
            {
                if(index[j] < count[j] && num[j][index[j]] < minVal)
                {
                    minVal = num[j][index[j]];
                    minK = j;
                    fRes = false;
                }
                else if(index[j] < count[j] && num[j][index[j]] == minVal)
                {
                    fRes = true;
                }
            }

            if (fRes)
            {
                printf("%u:%u", minVal, k[minK]);
                for(j=minK+1;j<n;j++)
                {
                    if (index[j] < count[j] && num[j][index[j]] == minVal)
                    {
                        printf(" %u", k[j]);
                        index[j]++;
                    }
                }
                printf("\n");
                nRes++;
            }
            
            index[minK]++;
        }
    }

    clock_t end = clock();
    fprintf(stderr, "Elapsed time: %lf second(s)\n", (end-start)*1.0/CLOCKS_PER_SEC);

    return 0;
}