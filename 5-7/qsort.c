/*qsort: sort v[left]...v[right] into increasing order*/
#include <string.h>
void swap(char *arrayOfStrings[], int i, int j); /*interchange *px and *py */

void quickSort(char *arrayOfStrings[], int startIdx, int endIdx) {
    int i, partitionIdx;

    if (startIdx >= endIdx) {
        /* do nothing if the array contains fewer than two elements */
        return;
    }

    /* Choosing the middle element as the pivot and swapping with the first element */
    swap(arrayOfStrings, startIdx, (startIdx + endIdx) / 2);
    partitionIdx = startIdx;

    /* Partitioning the array */
    for (i = startIdx + 1; i <= endIdx; i++) {
        if (strcmp(arrayOfStrings[i], arrayOfStrings[startIdx]) < 0) { //if i < startIdx
            swap(arrayOfStrings, ++partitionIdx, i); //swap partitionIdx with the start index
                                                    //increament partitionIdx
        }
    }

    /* Swapping the pivot back to its correct position */
    swap(arrayOfStrings, startIdx, partitionIdx);

    /* Recursively sorting the left and right sub-arrays */
    quickSort(arrayOfStrings, startIdx, partitionIdx - 1);
    quickSort(arrayOfStrings, partitionIdx + 1, endIdx);
}
/*swap: interchange v[i] & v[j]*/
void swap(char *v[], int i, int j) /*interchange *px and *py */
{
    char *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


// void qsort(char *v[], int left, int right)
// {
//     int i, last;
//     void swap(char *v[], int i, int j);
//     if (left >= right)
//         /* do nothing if array contains */
//         return;
//     swap(v, left, (left + right) / 2);
//     last = left;
//     for (i = left + 1; i <= right; i++)
//         if (strcmp(v[i], v[left]) < 0)
//             swap(v, ++last, i);
//     swap(v, left, last);
//     qsort(v, left, last - 1);
//     qsort(v, last + 1, right);
// }
