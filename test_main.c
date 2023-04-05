#include <stdio.h>

int main()
{
	int i;
	int arr[] = {1,2,3,4,5};
	int len;
	int result;

	len = sizeof(arr) / sizeof(int);

	i = 0;
	result = 0;
	for (int j = 0; j < len; j++)
	{
		printf(" %d\n", arr[i++]);
	}
	return 0;
}