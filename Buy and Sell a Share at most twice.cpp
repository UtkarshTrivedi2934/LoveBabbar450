//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// Tabulation

int solveTab(vector<int>&price) {
    int n = price.size();
    vector<vector<vector<int>>> output(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    
    for(int index = n-1;index>=0;index--) {
        for(int canBuy = 0;canBuy<2;canBuy++) {
            for(int limit = 1;limit < 3;limit++) {
                int profit = 0;
                if(canBuy) {
                    int buy = -price[index] + output[index+1][0][limit];
                    int skip = 0 + output[index+1][1][limit];
                    profit = max(buy,skip);   
                }
                else {
                    int sell = price[index] + output[index+1][1][limit-1];
                    int skip = 0 + output[index+1][0][limit];
                    profit = max(sell,skip);   
                }
                output[index][canBuy][limit] = profit;
            }
        }
    }
    return output[0][1][2];
}

// 3-D DP

int solve(vector<int>&price,int index,int limit,int canBuy,vector<vector<vector<int>>> &output) {
    if(index == price.size())
    return 0;
    if(limit == 2)
    return 0;
    
    if(output[index][canBuy][limit] != -1)
    return output[index][canBuy][limit];
    
    int profit = 0;
    if(canBuy) {
        int buy = -price[index] + solve(price,index+1,limit,0,output);
        int skip = 0 + solve(price,index+1,limit,1,output);
        profit = max(buy,skip);   
    }
    else {
        int sell = price[index] + solve(price,index+1,limit+1,1,output);
        int skip = 0 + solve(price,index+1,limit,0,output);
        profit = max(sell,skip);   
    }
    return output[index][canBuy][limit] = profit;
    
}


int maxProfit(vector<int>&price){
    int n = price.size();
    vector<vector<vector<int>>> output(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(price,0,0,1,output);
}


int solve(vector<int>&price,int index,int limit,int canBuy) {
    if(index == price.size())
    return 0;
    if(limit == 2)
    return 0;
    
    int profit = 0;
    if(canBuy) {
        int buy = -price[index] + solve(price,index+1,limit,0);
        int skip = 0 + solve(price,index+1,limit,1);
        profit = max(buy,skip);   
    }
    else {
        int sell = price[index] + solve(price,index+1,limit+1,1);
        int skip = 0 + solve(price,index+1,limit,0);
        profit = max(sell,skip);   
    }
    return profit;
    
}


int maxProfit(vector<int>&price){
    return solve(price,0,0,1);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends