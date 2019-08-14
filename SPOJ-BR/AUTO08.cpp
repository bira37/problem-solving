#include <stdio.h>
int main()
{
	char c;
	int contador=0;
	int n,i;
	scanf("%d\n",&n);
	i=1;
	while(i<=n)
	{
		scanf("%c",&c);
		switch(c)
		{
		case 'A':{ contador+=1;
			   break;
			 }
		case 'C':{ contador+=2;
			  break;
			 }
		case 'P':{ contador+=2;
			  break;
			 }
		}
	i++;
	}
	printf("%d\n",contador);
	return(0);
}

