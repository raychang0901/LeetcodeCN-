# 哈希表

## 題目鏈結：
https://zerojudge.tw/ShowProblem?problemid=f579
## 思路
利用hash存取物品的購買次數    
## 代碼

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int a,b;
	int n;
	int cnt = 0;
	
	cin>>a>>b;
	cin>>n;
	int vec_size = max(a,b);
	vector<int> hash(101, false);
	vector<int> tmp = hash;
	while(n--){
		while(true){
			int buy = 0;
			cin>>buy;
			if(buy==0)
				break;
			if(buy<0&&hash[buy*(-1)]){
				hash[buy*(-1)]-=1;
			}
			else if(buy>0){
				hash[buy]+=1;
			}
		}
		if(hash[a]&&hash[b])
			cnt++;
		hash = tmp;
	}
	cout<< cnt;
	
} 
```
