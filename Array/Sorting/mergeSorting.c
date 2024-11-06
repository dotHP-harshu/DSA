#include <stdio.h>


void merge(int arr[], int low, int mid, int high){
   int i , j, k ;

   // First we make two temporary array. Then we perform merging them and copy them in 'arr'
   int n1 = mid -low+1; // here we add 1 because of loop
   int n2 = high-mid;

   int left[n1], right[n2];
   // copying the elements to temporary arrays.
   for (int  i = 0; i < n1; i++)
   {
      left[i]= arr[low + i];
   }
   for (int  j = 0; j < n2; j++)
   {
      right[j]= arr[mid+1+j];
   }

   // initialize counters for merging 

   i=0;
   j=0;
   k=low;
   // comparing the elements of leftArray and rightArray and after sorting copying on arr.
   while (i< n1 && j<n2)
   {
      if (left[i]<right[j])
      {
         arr[k]= left[i];
         i++;
         k++;
      }else{
         arr[k] = right[j];
         j++;
         k++;
      }
   }
   
   // copy remaining elements as it is
   while (i<n1)
   {
      arr[k]=left[i];
      k++;
      i++;
   }
   while (j<n2)
   {
      arr[k] = right[j];
      k++;
      j++;
   }
}


void mergeSort(int arr[], int low , int high){
   if(low<high){
      int mid = low -(low -high)/2;
      mergeSort(arr, low , mid); // calling same function untill found only one element in left side
      mergeSort(arr, mid+1, high); //calling same function untill found only one element in right side
      merge(arr, low , mid , high);
   }
}

void printArray(int arr[], int size){
   for (int i = 0; i < size; i++)
   {
      printf("%d \t", arr[i]);
   }
   
}

int main (){
   int arr[]={12,5,8,6,10,9,1,20};
   int size = sizeof(arr)/sizeof(arr[0]);
   printf("unsorted \n");
   printArray(arr, size);
   
   mergeSort(arr, 0, size-1);
   printf("\nsorted\n");
   printArray(arr, size);
   return 0;
}