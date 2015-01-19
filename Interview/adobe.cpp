======================================================================================
problem 1

bool isPalindrome(int n)
{
    if(n < 0) return 0;
    
    int num = n;
    int factor = 1;
 
    while(num>= 10)
    {
       factor = factor*10;
       num = num/10;
    }
    
    while(n>0)
    {
       if(n/factor == n%10)
       {
          n=n%factor;
          n=n/10;
          factor=factor/100;
       }
       else return false;
    }
 
    return true;
}
============================================================================
 
#include<iostream>
#include<stack>
using namespace std;
 
bool isOpening(char ch)
{
    if(ch == '(' || ch == '{' || ch == '[')
    {
        return true;
    }
    return false;
}
 
bool isClosing(char ch)
{
    if(ch == ')' || ch == '}' || ch == ']')
    {
        return true;
    }
    return false;
}
 
bool isMatched(char ch1, char ch2)
{
    if((ch1 == ')' && ch2 == '(') || (ch1 == '}' && ch2 == '{') || (ch1 == ']' && ch2 == '['))
    {
        return true;
    }
    return false;
}
int paranmatch(string str)
{
    if(str.empty() == true) return 1;
 
    stack<char> st;
 
    int s = str.size();
 
    int i = 0;
 
    while(i < s)
    {
       if(isOpening(str[i]))
       {
          st.push(str[i]);
       }
       else if(isClosing(str[i]))
       {
          if(st.empty() == true)
          {
             return 0;
          }
 
          char ch = st.top();
          st.pop();
 
          if(isMatched(str[i],ch))
          {
 
          }
          else
          {
             return 0;
          }
      }
      i++;
   }
   if(st.empty() == true)
   {
     return 1;
   }
 
   return 0;
}
 ===================================================================
 
  
node* reverse(node* head)
{
if(head == NULL || head->next == NULL)
{
return head;
}
 
node* prev = NULL;
 
node* curr = head;
node* cNext = NULL;
 
while(curr != NULL)
{
cNext = curr->next;
curr->next = prev;
prev = curr;
curr = cNext;
}
return prev;
}
 
==============================================================================

 
int getLastIndex(int arr[],int low, int high)
{
if(low > high) return -1;
 
if(low == high)
{
if(arr[low] == 1) return low;
return -1;
}
 
if(low+1 == high)
{
if(arr[high] == 1) return high;
if(arr[low] == 1) return low;
return -1;
}
 
int mid = (low+high)/2;
 
if(arr[mid] == 1)
{
return getLastIndex(arr,mid,high);
}
else
{
if(low == mid) return -1;
return getLastIndex(arr,low,mid-1);
}
}
int maxRow(int arr[], int N)
{
 
int row = 0;
 
int low = 0;
int high = 0;
 
int lastrow = 0;
int lastindex = -1;
 
 
for(int row = 0; row < N; row++)
{
low = row*N;
high = low + N-1;
 
if(lastindex != -1)
{
if(arr[low+lastindex] == 1)
{
 
lastindex = getLastIndex(arr,low+lastindex,high);
lastindex = lastindex%N;
lastrow = row;
}
}
else
{
lastindex = getLastIndex(arr,low,high);
lastindex = lastindex%N;
lastrow = row;
}
}
return lastrow+1;
}
