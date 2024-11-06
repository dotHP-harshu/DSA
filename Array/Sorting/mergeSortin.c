#include <stdio.h>

void printArray (int arr[], int size){
   for (int i = 0; i < size; i++)
   {
      printf("%d ", arr[i]);
   }
   
}

void merge(int arr[], int low , int mid, int high){
   int i ,j ,k;

   int n1 = mid-low+1;
   int n2 = high - mid;

   int left[n1], right[n2];

   for (int i = 0; i < n1; i++)
   {
      left[i]= arr[low+i];
   }
   for (int j = 0; j < n1; j++)
   {
      right[j]= arr[mid+1+j];
   }

   i = 0;
   j = 0;
   k = low;


   while (i<n1&& j<n2)
   {
      if (left[i]< right[j])
      {
         arr[k]=left[i];
         i++;
      }else{
         arr[k]= right[j];
         j++;
      }
      k++;
   }

   while (i<n1)   
   {
      arr[k] = left[i];
      i++;
      k++;
   }

   while (j<n2)
   {
      arr[k] = right[j];
      j++;
      k++;
   }
}
void mergeSort (int arr[], int low , int high){
   if (low<high)
   {
      int mid = low-(low-high)/2;
      mergeSort(arr, low, mid);
      mergeSort(arr, mid+1, high);
      merge(arr, low,mid, high);
   }
}

int main(){
   int arr[] = {6,5,8,7,3,9,1};
   int h = sizeof(arr)/sizeof(arr[0]);

   mergeSort(arr, 0,h-1);
   printArray(arr,h-1);

   return 0;
};