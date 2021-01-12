# 動態規劃

## 題目鏈結：   

https://zerojudge.tw/ShowProblem?problemid=f314    

## 題目敘述：  

輸入為 m×n 大小的的陣列，每一格是一個介於 -100 與 100 之間的整數，表示經過這格可以累積的經驗值。
你可以從最上面一排任何一個位置開始，在最下面一排任何一個位置結束。
過程中每一步可以選擇往左、往右或往下走，但不能走回已經經過的位置。
請你算出最多可以獲得的經驗值總和(可能是負數)。

## 思路：

只能往左，往右，或往下-->dp[i][j] = max(dp[i-1][j],dp[i][j-1], dp[j+1]))    
實現時，先算一邊再算另外一邊，找最大值。

## 代碼：
--------------------------------
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int m,n,dp[55][10005],a[10005],l[10005], r[10005];;

int main() {
	 cin>>m>>n;
	 int res = -1e9;
	 for(int i = 1; i<=m; i++){
		//先算出一邊
	 	for(int j = 1;j<=n; j++){
	 		cin>>a[j];
	 		if(i==0){
	 			l[j] = a[j];
			 }
	 		else if(j==1){
				l[j] = dp[i-1][j]+a[j];
			}
			else{
				l[j] = max(dp[i-1][j], l[j-1])+a[j]; //從上or從左 
			}	
		}
		//再算另一邊
		for(int j = n; j>=1; j--){
			if(i==0){
	 			r[j] = a[j];
			}
			else if(j>=n){
				r[j] = dp[i-1][j] + a[j];
			}
			else {
				r[j] = max(dp[i-1][j], r[j+1])+a[j];	
			}
			dp[i][j] = max(l[j], r[j]);
			if(i==m){
				res=max(dp[i][j], res);
			}
		}
	 }
	 cout<< res;
}
```
