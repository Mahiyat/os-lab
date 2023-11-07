#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    FILE *fptr;
    fptr=fopen("input.txt","r");
    int i,n,req[50],mov=0,cp;
    fscanf(fptr,"%d",&cp);
    fscanf(fptr,"%d",&n);
    for(i=0;i<n;i++)
    {
	fscanf(fptr,"%d",&req[i]);
    }
    mov=mov+abs(cp-req[0]);
    printf("%d -> %d",cp,req[0]);
    for(i=1;i<n;i++)
    {
	mov=mov+abs(req[i]-req[i-1]);
	printf(" -> %d",req[i]);
    }
    printf("\n");
    printf("Total head movement = %d\n",mov);
    fclose(fptr);
    return 0;
}
