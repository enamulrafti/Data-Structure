#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int data[], int n);
void bubbleSort(int data[], int n);
void insertionSort(int data[], int n);


int i;
int main()
{
    //printf("hello");

    int data[100], n, i;



    printf("enter array size: ");
    scanf("%d",&n);
    srand(time(NULL));
    for(i = 0; i < n; i++)
    {
        //scanf("%d",&data[i]);
        data[i] = rand()%100+1;
    }
    printf("before sorting: ");
    for(i = 0; i < n; i++)
    {
        //scanf("%d",&data[i]);
        printf("%d ", data[i]);
    }

    //selectionSort(data, n);
    //bubbleSort(data, n);
    insertionSort(data, n);
    printf("\n\nafter sorting: ");
    for(i = 0; i < n; i++)
    {
        //scanf("%d",&data[i]);
        printf("%d ", data[i]);
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



