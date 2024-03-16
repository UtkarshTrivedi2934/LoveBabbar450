//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    int calcSum(vector<int> &s) {
        int sum = 0;
        for(int i = 0;i<s.size();i++) {
            sum+=s[i];
        }
        return sum;
    }

    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int s1 = calcSum(S1);
        int s2 = calcSum(S2);
        int s3 = calcSum(S3);
        
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<N1 and j<N2 and k<N3) {
            if(s1 == s2 and s2 == s3)
            return s1;
            
            int minSum = min(s1,min(s2,s3));
            
            if(s1 != minSum) {
                s1-=S1[i];
                i++;
            }
            if(s2 != minSum) {
                s2-=S2[j];
                j++;
            }
            if(s3 != minSum) {
                s3-=S3[k];
                k++;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends