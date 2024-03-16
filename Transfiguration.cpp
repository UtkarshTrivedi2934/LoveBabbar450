//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
int transfigure (string A, string B)

    {

    	// Your code goes here

    	int check[256]={0};

        if(A.length()!=B.length())

        {

            return -1;

        }

        

        for(int i=0;i<A.length();i++)

        {

            check[A[i]]++;

            check[B[i]]--;

        }

        

        for(int i=0;i<256;i++)

        {

            if(check[i]!=0)

            return -1;

        }

        

        int len1=A.length();

        int len2=B.length();

        int res=0;

        

        while(len1>=0)

        {

            if(A[len1]!=B[len2])

            {

                res++;

            }

            else

            {

                len2--;

            }

            len1--;

        }

        return res;

    }
};

//{ Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}
// } Driver Code Ends