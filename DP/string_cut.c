#include <stdio.h>
#include <string.h>

int main()
{
	long int i,j,len,m,t=0;
	//char a[n]; for finding minimum time to cut knowledge of actual string is immaterial
	scanf("%ld %ld",&len,&m);

	long int l[m];
	for(i=0;i<m;i++)
		scanf("%ld",&l[i]);

	long int low=0,high=m-1;

	//string indexing is 1
	int str_beg = 1, str_end = len;
	while(low<=high)
	{
		t += str_end-str_beg+1;

		if(l[low]-str_beg+1>str_end-l[high])
		{
			str_beg = l[low]+1;
			low++;
			//printf("%d %d\n",l[low-1],str_end);

		}
		else
		{
			str_end = l[high];
			high--;
			//printf("%d %d\n",str_beg,l[high+1]);

		}

		//printf("%d %d\n",str_beg,str_end);
	}
	printf("%ld\n",t);
	return 0;

}