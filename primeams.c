#include<stdio.h>
#include<math.h>
int prime( int n )
{	int i,j,c=0;


	for(i=2 ; i<=n/2 ; i++)
	{ if (n%i==0)
		{ return 0;}
	  else{c=c+1;}
	
	}
    if (c==n/2)
		{return 1;}
}
int ams( int n )
{   
	int on=n, r ,re = 0, ne=0;
	while ( on != 0)
	{
		on /= 10;
		++ne;
	}
	on=n;
	while (on != 0 )
	{
	   r=on%10;
	   re += pow(r,ne);
	   on /= 10;
	}
	if(re==n)
	{
		return 1;
	}
	else 
	{ return 0;}
}
int main()
{
	int n,count=0,p,k;
	int c = 1; 
	while (c == 1)
	{ count=count+1;
      printf("enter number up to --");
	  scanf("%d",&n);
      p=ams(n);
	  k=prime(n);
	  if (k==1)
	  {printf("the number is prime\n");}
      else {printf("the number is not a prime\n");}
	  if (p==1)
	  {printf("the number is amstrong");}
      else {printf("the number is not a amstrong\n");}
	printf("\nto exit press 0 else to  1 ");
	scanf("%d",&c);
	
	}
	printf("count is %d",count);
	return 0;
}