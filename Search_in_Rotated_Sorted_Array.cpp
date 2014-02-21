//Search in Rotated Sorted Array Total Accepted: 8346 Total Submissions: 29624 My Submissions
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//
//
//
// Basically, B-search but it's not very good implementation.
//








#include<iostream>
class Solution {
public:
    int search(int A[], int n, int target) 
    {
        return bisearch(A,0,n-1,target);
        
    }
    
    int b_search(int A[], int s, int e, int key)
    {
        int p=(s+e)/2;
         while((A[p] != key) && (s <= e))
         {
             if (A[p] > key)               // If the number is > key, ..
             {                                                       // decrease position by one.
                e = p - 1;    
             }                                                      
             else                                                
            {                                                        // Else, increase position by one.
                s = p + 1;     
            }
             p = (e + s) / 2;
         }
         if (s <= e)
            return p;
         else
            return -1;
        
    }
    int bisearch(int A[], int s, int e, int t)
    {
        if(s>=e)
	    if(A[s]==t)
		return s;
	    else
		return -1; 
	if(A[s]<A[e])
            return b_search(A,s,e,t);
        int mid=(s+e)/2;
        int key=A[mid];
        if(key==t)
            return mid;
        if(mid == s && mid == e)
            return -1;
        if(key>t)
        {
            if(key >= A[s] && t < A[s])
                return bisearch(A,mid+1,e,t);
            if(key >= A[s] && t >= A[s])    
                return b_search(A,s,mid-1,t);
            if(key < A[s])     
                return bisearch(A,s,mid-1,t);
        }
        else
        {
            if(key>A[s])
                    return bisearch(A,mid+1,e,t);
            if(key<=A[s] && t>=A[s])
                    return bisearch(A,s,mid-1,t);
            if(key<=A[s] && t<A[s])    
                    return b_search(A,mid+1,e,t);
        }
    }
    
    
};



int main()
{
int A[]={279,284,285,287,288,296,2,8,10,11,12,13,14,19,20,22,25,26,27,28,29,33,37,39,42,43,47,48,49,50,57,62,63,66,68,69,71,73,74,77,78,79,85,89,92,94,99,111,113,117,120,122,125,134,145,152,155,157,160,161,167,168,181,182,188,189,190,194,199,201,204,208,213,220,223,225,226,227,231,237,240,242,247,254,259,260,261,264,267,271,275};
int m=0;
Solution so;
for(int i=0;i<100;i++)
{
	
	std::cout<<i<<' '<<A[i]<<std::endl;
}
m=so.search(A,93,298);
std::cout<<m;
return 0;
}
