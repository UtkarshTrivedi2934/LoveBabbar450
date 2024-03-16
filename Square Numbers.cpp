//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
        bool a[100000];
    long long primes[100000],in=0;
    
    void Sieve(int n)
    {
        memset(a,true,sizeof(a));
        a[1]=false;
        for(int i=2; i*i<=n; i++)
        {
            if(a[i])
            {
                for(int j=2*i; j<=n; j+=i)
                    a[j]=false;
            }
        }
        for(int i=2; i<=n; i++)
        {
            if(a[i])
                primes[in++]=i;
        }
    }
    
    long long calc(long long in, long long cur, long long k)
    {
		long long newCur = primes[in]*primes[in]*cur;
		long long res=0;
		if(newCur>k)//case when [k/newCur]=0, so we dont need to recurse any further
            return 0;
        //include this to answer
		res += k/(newCur);
		res += calc(in+1,cur,k);
		
		//exclude from answer the repeated ones
		res -= calc(in+1,newCur,k);
		return res;
    }
    
    long long sqNum(long long N) {
        
        Sieve(100000);
        
        long long ans = calc(0,1,N);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.sqNum(N) << endl;
    }
    return 0;
}
// } Driver Code Ends