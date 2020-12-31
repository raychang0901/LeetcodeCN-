# 動態規劃

## 题目链接

https://leetcode-cn.com/problems/UlBDOe/

力扣LCP 19. 秋叶收藏集

一開始只想到遞迴做法，就超時了..   
學習詳解的動態規劃，架構跟遞迴是相同的   
    
---------------------------------------

```cpp
class Solution {
public:
    int minimumOperations(string leaves) {
        //status 0-->first r, 1--> y, 2-->second r
        vector<vector<int>> dp(leaves.size(), vector<int>(3));
        dp[0][1] = dp[0][2] = dp[1][2] = 10e5;
        if(leaves[0]=='y'){
            dp[0][0] = 1;
        }
        else{
            dp[0][0] = 0;
        }
        for(int i = 1; i<leaves.size(); i++){
            bool isRed = (leaves[i] == 'r');
            bool isYellow = (leaves[i] == 'y');
            dp[i][0] = dp[i - 1][0] + isYellow; //必須是r 否則置換(+1)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + isRed; //必須是y 否則置換(+1)
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + isYellow; //必須是r 否則置換(+1)
        }
        return dp[leaves.size()-1][2];
        //return recur(leaves, 0, 0, 0, false);
    }
    //遞迴法  超時
    // //status 0-->first r, 1--> y, 2-->second r
    // int recur(const string leaves, int status, int idx, int count, bool done){
    //     if(idx > leaves.size()-1 && status == 2){
    //         if(done)    

    //             return count;
    //         else
    //             return 10e5;
    //     }
    //     else if(idx > leaves.size()-1){
    //         return 10e5;
    //     }
    //     if(status==0){ 
    //         if(leaves[idx]=='r'){
    //             return min(recur(leaves, 0, idx+1, count, false), recur(leaves, 1, idx+1, count, false));
    //         }
    //         else{
    //             return min(recur(leaves, 0, idx+1, count+1, false), recur(leaves, 1, idx+1, count+1, false));
                
    //         }
    //     }
    //     else if(status == 1){
    //         if(leaves[idx]=='y'){
    //             return min(recur(leaves, 1, idx+1, count, false), recur(leaves, 2, idx+1, count, false));
    //         }
    //         else{
    //             return min(recur(leaves, 1, idx+1, count+1, false), recur(leaves, 2, idx+1, count+1, false));
    //         }
    //     }
    //     // status = 2
    //     else{
    //         if(leaves[idx]=='r'){
    //             return recur(leaves, 2, idx+1, count, true);
    //         }
    //         else{
    //             return recur(leaves, 2, idx+1, count+1, true);
    //         }
    //     }
    //     return 10e5;
    // }
};
```
