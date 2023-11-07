#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  FILE *fptr;
  fptr=fopen("input.txt","r");
  int i,j=0,k,n,req[50],cp,min,mini,distance[50],a[50],mov=0,cp1;
  fscanf(fptr,"%d",&cp);
  fscanf(fptr,"%d",&n);
  for(i=0;i<n;i++)
  {
    fscanf(fptr,"%d",&req[i]);
  }
  cp1=cp;
  for(k=0;k<n;k++)
  {
    for(i=0;i<n;i++)
    {
      distance[i]=abs(cp1-req[i]);
    }
    min=distance[0];
    mini=0;
    for(i=1;i<n;i++)
    {
      if(distance[i]<min)
      {
        min=distance[i];
        mini=i;
      }
    }
    a[j]=req[mini];
    cp1=req[mini];
    j++;
    req[mini]=10000;
  }
  printf("Sequence is: ");
  printf("%d -> %d",cp,a[0]);
  mov=mov+abs(cp-a[0]);
  for(i=1;i<n;i++)
  {
    printf(" -> %d",a[i]);
    mov=mov+abs(a[i]-a[i-1]);
  }
  printf("\nTotal head movement = %d\n",mov);
  fclose(fptr);
  return 0;
}