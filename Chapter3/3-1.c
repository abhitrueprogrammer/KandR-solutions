#include <stdio.h>
int bitsearch(int x,int v[], int n);
int main(void)
{
  int arr[] = {-10,-5,0,1,2,3,4,5,6,7,8,9,10};
  printf("%i\n",bitsearch(0,arr,13));
  return 0;
}
// int bitsearch(int x, int v[], int n)
// {
// int low, high, mid;
// low = 0;
// high = n - 1;
// while (low <= high) {
// mid = (low+high) / 2;
// if (x < v[mid])
// high = mid - 1;
// else if (x > v[mid])
// low = mid + 1;
// else
// /* found match */
// return mid;
// }
// return -1; /* no match */
// }
int bitsearch(int x,int v[], int n)
{
    int low = 0;
    int high = n- 1;
    while (low <= high)
    {
      int mid = (low+high)/2;
      if (v[mid] == x)
      {
        return mid;
      }
      else
      {
        if (x < v[mid])
          high = mid -1;
        else
          low = mid + 1;
      }

    }
    return -1;
}