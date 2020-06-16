
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        //A[i] + A[j] + -(j+i)
        //dp[i][j] = max(dp[i][j-1],A[i]+A[j]+i-j)


        //二維作法  超時
        /*int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n)); //2維dp初始化
        
        int max_val = INT_MIN;
        for(int i = 0; i<A.size(); i++){
            for(int j = i+1; j<A.size(); j++){
                dp[i][j] = max(dp[i][j-1], A[i]+A[j]+i-j);  //變數可整理成一維
                if(dp[i][j]>max_val){
                    max_val = dp[i][j];
                }
            }
        }
        return max_val;*/
        int n = A.size();
        int max_i = INT_MIN; //整理變數i
        int max_val = INT_MIN;
        for(int i = 0; i<A.size()-1; i++){
            max_i = max(max_i, A[i]+i);
            max_val = max(max_val,max_i+A[i+1]-(i+1));
        }
        return max_val;
    }
};

