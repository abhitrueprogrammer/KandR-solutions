/* qsort: sort v[left]...v[right] into increasing order */
#include <string.h>
void q_sort(char *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, pivot;
    void swap(char *v[], int i, int j);

    if( left >= right)
    {
        return;
    }        

    swap(v, left, (left+right)/2);
    pivot = left;
    for(i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++pivot, i);
    swap(v, left, pivot);
    q_sort(v, left, pivot-1, comp);
    q_sort(v, pivot+1, right, comp);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}