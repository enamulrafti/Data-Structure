#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int data[], int n);
void bubbleSort(int data[], int n);
void insertionSort(int data[], int n);
int linearSearch(int data[], int n, int key);
int binarySearch(int data[], int n, int key);


int i;
int main()
{
    //printf("hello");

    int data[100], n, i, key;



    printf("enter array size: ");
    scanf("%d",&n);
    srand(time(NULL));
    for(i = 0; i < n; i++)
    {
        //scanf("%d",&data[i]);
        data[i] = rand()%100+1;
    }
    printf("values: ");
    for(i = 0; i < n; i++)
    {

        printf("%d ", data[i]);
    }

    printf("\nenter value to search: ");
    scanf("%d",&key);

    int pos = binarySearch(data, n, key);
    if(pos == 1)
    {
        printf("found\n");
    }
    else
    {
        printf("not found\n");
    }




}


void selectionSort(int data[], int n)
{
    int i, j, minIndex, temp;
    for(i = 0; i < n-1 ; i++)
    {
        minIndex = i;
        for(j = i+1; j < n; j++)
        {
            if(data[j] < data[minIndex])
            {
                minIndex = j;
            }

        }
        temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }

}


void bubbleSort(int data[], int n)
{
    int i, j, temp;

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(data[j] > data[j+1])
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

}

void insertionSort(int data[], int n)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = data[i];
        j = i-1;

        while(j >= 0 && data[j] > key)
        {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
}

int linearSearch(int data[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(data[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int data[], int n, int key)
{
    bubbleSort(data, n);
    int lo = 0, hi = n-1, mid;

    while(lo <= hi)
    {
        mid = (lo + hi)/2;
        if(data[mid] == key) return 1;
        else if(data[mid] > key) hi = mid - 1;
        else lo = mid + 1;
    }
    return 0;

}



