void merge(int arr[], int left, int middle, int right) {
   int i, j, k;
   int n1 = middle - left + 1;
   int n2 = right - middle;
   int L[n1], R[n2];
   for (i = 0; i < n1; i++) L[i] = arr[left+i];
   for (j = 0; j < n2; j++) R[j] = arr[middle + 1 + j];
   i = 0;
   j = 0;
   k = left;
   while (i < n1 && j < n2) {
       if (L[i] < R[j]) {
           arr[k] = L[i];
           i++;
       } else {
           arr[k] = R[j];
           j++;
       }
       k++;
   }
   while (i < n1) {
       arr[k] = L[i];
       i++;
       k++;
   }
   while (j < n2) {
       arr[k] = R[j];
       j++;
       k++;
   }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
            mergeSort(arr, left, middle);
            mergeSort(arr, middle + 1, right);
            merge(arr, left, middle, right);
    }
    
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int length = nums1Size + nums2Size;
    int array[length];
    int i, j;
    for (i = 0; i < nums1Size; i++) array[i] = nums1[i];
    for (j = nums1Size; j < length; j++) array[j] = nums2[j - i];
    mergeSort(array, 0, length - 1);
    if (length % 2 == 0) return (double) ((double) (array[(int) (length / 2)] + (double) array[(int) ((length / 2) - 1)]) / 2);
    else return (double) (array[length / 2]);
    
}
