#include <stdio.h>
int bitsearch(int x,int v[], int n);
int main(void)
{
  int arr[] = {-10,-5,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
  printf("%i\n",bitsearch(17,arr,53));
  return 0;
}
int bitsearch(int x, int v[], int n)
{
int low, high, mid;
low = 0;
high = n - 1;
while (low <= high) {
mid = (low+high) / 2;
if (x < v[mid])
high = mid - 1;
else if (x > v[mid])
low = mid + 1;
else
/* found match */
return mid;
}
return -1; /* no match */
}