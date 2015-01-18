
=========================================================================================
Problem 1
Note:-------------> if sum then we do i = 0; j = n-1
but for diff k we do i = 0; j = 1 and keep doing 
while(i < n-1 && j < n)

Count all distanct pairs whose diff is k 
r < n till we can move r
int countPairsWithDiffK(int arr[], int n, int k)
{
    int count = 0;
    sort(arr, arr+n);  // Sort array elements
 
    int l = 0;
    int r = 0;
    while(r < n)
    {
         if(arr[r] - arr[l] == k)
        {
              count++;
              l++;
              r++;
        }
         else if(arr[r] - arr[l] > k)
              l++;
         else // arr[r] - arr[l] < sum
              r++;
    }   
    return count;
}

===============================================================================================
Problem 2
you are given two int x and y 
you need to perform k operation on these no
in eahc operation you do 
wither 
x = x + y ,y = y  or x = x , y = x + y

you need to tell can you reach X,Y using these operation

bool dooperation(int x, int y,int X,int Y)
{
    if(x > X || y > Y)
    {
       return false;
    }
    
    if(x == X && y == Y)
    {
       return false;
    }
    
    return dooperation(x+y,y) || dooperation(x,x+y);
}

==============================================================================================
Problem 3

extern void fun(int);
void fun(int);

no error in this programme it compile well
=============================================================================================

Problem 4

declare a pointer to an array of int pointers

int *arr[5]; <==========array of ptrs
int *(*arr)[5]<========a pointer to an array of int ptrs correct
int **arr[5]<===========this is an error
=============================================================================================
Problem 5
You have an array of size n
initial all items are 0
you have m operation and each operation will add k to all items from a to b both include
found max value in array after m operation
