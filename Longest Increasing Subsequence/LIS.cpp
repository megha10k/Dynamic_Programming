//RECURSION
int getAns(int arr[], int n,  int ind, int prev_index){
    // base condition
    if(ind == n) return 0;        ;
    
    int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
    int take = 0;
    
    if(prev_index == -1 || arr[ind] > arr[prev_index]){
        take = 1 + getAns(arr,n,ind+1,ind);
    }
    return max(notTake,take);
}

int longestIncreasingSubsequence(int arr[], int n){
    return getAns(arr,n,0,-1,dp);
}



//MEMOISATION
int getAns(int arr[], int n,  int ind, int prev_index, vector<vector<int>>& dp){
    
    // base condition
    if(ind == n) return 0;        
    if(dp[ind][prev_index+1]!=-1) return dp[ind][prev_index+1];
    
    int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
    int take = 0;
    
    if(prev_index == -1 || arr[ind] > arr[prev_index]){
        take = 1 + getAns(arr,n,ind+1,ind,dp);
    }
    return dp[ind][prev_index+1] = max(notTake,take);
}

int longestIncreasingSubsequence(int arr[], int n){
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return getAns(arr,n,0,-1,dp);
}




//TABULATION
int longestIncreasingSubsequence(int arr[], int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0)); 
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
            int notTake = 0 + dp[ind+1][prev_index +1];
            int take = 0;
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                 take = 1 + dp[ind+1][ind+1];
            }
            dp[ind][prev_index+1] = max(notTake,take);
         }
    }
    return dp[0][0];
}


//SPACE OPTIMISATION
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> next(n+1,0), cur(n+1,0);
    
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            int notTake = 0 + next[prev_index +1];
            int take = 0;
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                take = 1 + next[ind+1];
            }
            cur[prev_index+1] = max(notTake,take);
        }
        next = cur;
    }
    return cur[0];
}
