#include<stdio.h>
#include<conio.h>

void BuildMaxHeap(int [] , int);
void MaxHeapify(int [] , int , int);
void HeapSort(int [] , int);
void bubbleSort(int [] , int);
void insertionSort(int [] , int);
void selectionSort(int [] , int);
void mergeSort(int [],int ,int);
void merge(int [], int,int,int);
void quickSort(int[] , int,int);
int partiton(int[],int,int);
void merge(int[] ,int ,int ,int );
void mergeSort(int[] , int ,int );
void radixSort(int [] , int);
void main() {
    int arr[30] ,n ,i,option;
    printf("Enter the number of elements of the unsorted array.\n");
    scanf("%d" , &n);
    printf("\nEnter the elements of the array:\n");
    for(i=1 ; i<=n ; i++){
        printf("\nEnter the element:");
        scanf("%d" , &arr[i]);
    }
    printf("\nEnter the sorting option which you want to use for sorting the array: ");
    printf("\n1) BUBBLE SORT \n2) INSERTION SORT \n3) SELECTION SORT \n4) QUICK SORT \n5) HEAP SORT \n6) MERGE SORT \n7) SHELL SORT  \n8) RADIX SORT");
    scanf("%d" ,&option);

    switch(option) {
    case 1:
        bubbleSort(arr , n);
        break;
    case 2:
         insertionSort(arr, n);
        break;
    case 3 :
         selectionSort(arr, n);
        break;
    case 4 :
        quickSort(arr , 1 , n);
        break;
    case 5 :
        HeapSort(arr , n);
        break;
    case 6 :
         mergeSort(arr , 1, n);
        break;
    case 7 :
         //shellSort(a[] , n);
        break;
    case 8 :
        radixSort(arr , n);
        break;
    default :
        printf("\nEnter a valid option!!!");
        break;
    }
    printf("\nThe sorted array is :");
    for(i=1; i<=n; i++){
        printf("\n%d", arr[i]);
    }
}
//*********************************************************HEAP SORT *******************************************
void HeapSort(int arr[] ,int num)
{
    int i,temp ;
    BuildMaxHeap(arr, num);
    for(i= num ; i>=2 ; i--){
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        MaxHeapify(arr ,1,i-1);
    }
}

void BuildMaxHeap(int arr[],int n){
    int i;
    for(i = n/2 ; i>=1 ; i--){
        MaxHeapify(arr , i , n);
    }
}
void MaxHeapify(int arr[] , int i , int n ) {
    int temp , largest , l ,r;
    l= 2*i ;
    r = 2*i +1;
    if((l<n) && (arr[l]>arr[i])){
        largest = l;
    }
    else {
        largest = i;
    }
    if( (r<n) && (arr[r]>arr[largest]) ){
        largest = r;
    }
    if(largest!=i){
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] =  temp;
        MaxHeapify(arr ,largest , n);
    }
}
//*******************************************************BUBBLE SORT************************

void bubbleSort(int arr[] , int n)
{
    int i , j, temp;
    for(i=1 ; i<n ; i++){
        for(j=0 ; j<n-i ; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1] ;
                arr[j+1] = temp;
            }
        }
    }
}
// ********************************************************INSERTION SORT**********************

void insertionSort( int arr[] , int n)
{
    int key , i, j;
    for(i=1; i<=n;i++){
        key = arr[i];
        j = i-1;
        while(j>0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
//*******************************************************SELECTION SORT**************************************

void selectionSort(int arr[] , int n){

    int i,j,smallest,temp;
    for(i= 0 ;i<n-1 ; i++){
        smallest = i;
        for(j=i+1 ; j<n ; j++){
            if(arr[j]<arr[smallest]){
                smallest = j;
            }
        }
        if(smallest!=i){
            temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
        }
    }
}

//************************************************QUICK SORT***************************************************
void quickSort(int arr[],int l , int m)
{
    int k;
    if(l<m){
        k = partition(arr,l,m);
        quickSort(arr , l , k-1);
        quickSort(arr , k+1 , m);
    }
}


int partition(int arr[],int start,int end)
{
    int i,j,temp,temp2;
    int pivot = arr[end];
    i = start-1;
    j=start;
    while( j!=end){
        if(arr[j]<=arr[pivot])
        {
            i++;
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
        }

        temp2 = arr[i+1];
        arr[i+1]=arr[pivot];
        arr[pivot]=temp;
    }
    return(i+1);
}

//*************************************************SHELL SORT**************************************************

//**********************************************************RADIX SORT***************************************


void radixSort(int arr[] , int n){
    int buckets[10][10];
    int count[10],bucketno,passes,div,large,i,j,k;
        large = arr[1];

    for(i=2;i<=n;i++){
        if(arr[i]>large){
            large = arr[i];
        }
    }
    passes = 0;
    while(large>0){
        passes++;
        large  = large/10;
    }
    div= 1;
    for(i=1;i<=passes;i++){
        for(j=0;j<=9;j++){
            count[j+1] = 0;
        }

        for(j=1;j<=n;j++){
            bucketno = (arr[i]/div)%10;
            buckets[bucketno+1][count[bucketno+1]] = arr[j];
            count[bucketno+1]++;

        }
        j=0;
        for(bucketno = 1 ;bucketno<=10; bucketno++){
            for(k=1;k<=count[bucketno];k++)
            {

                arr[j++]= buckets[bucketno][k];
                div = div*10;
            }
        }

    }

}

//*************************************************MERGE SORT***************************************************

void mergeSort(int arr[] , int l , int m)
{
    int k = (l+m)/2;
    if(l<m){
        mergeSort(arr ,l,k);
        mergeSort(arr, k+1 , m);
        merge(arr,l,k,m);
    }
}

void merge(int arr[] , int start ,int mid, int end)
{
    int L[20],R[20];
    int n1 ; int n2;
    n1 = mid-start;
    n2= end-mid+1;
    int i , j , k;
    for(i=1; i<=n1 ; i++){
        L[i] = arr[i];
    }
    for(j=1;j<=n2;j++){
        R[j] = arr[mid + j -1];
    }
    i=j=1;
    k=1;
    while(i<=n1 && j<=n2){
        if(L[i]<R[j]){
            arr[k] = L[i];
            k++;
        }
        else if(L[i]>R[j]){
            arr[k] = R[j];
            k++;
        }
        k++;
    }
    while(i<=n1){
        arr[k] = L[i];
    }
    while(j<=n2) {
        arr[k] = R[j];
    }

}
//****************************************************THE END********************************************
