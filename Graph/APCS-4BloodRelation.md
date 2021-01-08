# 圖

## 題目敘述：

小宇有一個大家族。有一天，他發現記錄整個家族成員和成員間血緣關係的家族族譜。
小宇對於最遠的血緣關係(我們稱之為"血緣距離") 有多遠感到很好奇。右圖為家族的關係圖。
0是7的孩子，1、2和3是0的孩子，4和5是1的孩子，6是3的孩子。
我們可以輕易的發現最遠的親戚關係為4(或5)和6，他們的"血緣距離"是4 (4->1，1->0，0->3，3->6)。給予任一家族的關係圖，請找出最遠的"血緣距離"。
你可以假設只有一個人是整個家族成員的祖先，而且沒有兩個成員有同樣的小孩。    
## 輸出/輸入格式：
輸入格式    
第一行為一個正整數n 代表成員的個數，每人以0~n-1之間惟一的編號代表。    
接著的n-1行，每行有兩個以一個空白隔開的整數a與b (0 ≤ a,b ≤ n-1)，代表b是a的孩子。    
輸出格式    
## 思路：    
adjacency matrix 在圖上dfs尋找最長路徑    
每筆測資輸出一行最遠"血緣距離"的答案。
這題APCS考題沒有提供測試資料的組數，但是可以從節點關係反推，只要有節點還未被定義，就繼續輸入(節點個數是確定的)      


程式碼：
------------------------------------
```cpp
#include <iostream>
#include <vector>
using namespace std;
int max_res = -10e5;
void checkHash(const vector<vector<int> >& arr);
void dfs(const vector<vector<int> >& hash, int node, vector<bool> visited, int dist){
	if(dist>max_res){
		max_res = dist;
	}
	for(int i = 0; i<hash[node].size(); i++){
		if(i!=node){
			if(hash[node][i]&&!visited[i]){
				visited[i] = true;
				dfs(hash, i, visited, dist+1);
			}
		}
	}
	return;
}
void solve(){
	int N = -1;
	cin>>N;
	vector<vector<int> > hash(N, vector<int>(N));
	
	//由輸入反推測資數量 
	vector<bool> defined(N, false);
	int vis_quan = 0;
	int i, j = 0;
	// 實際做出adjacency matrix 
	while(vis_quan<N){
		cin>>i>>j;
		hash[i][j] = 1;
		hash[j][i] = 1;
		if(!defined[i]){
			vis_quan++;
			defined[i] = true;
		}
		if(!defined[j]){
			vis_quan++;
			defined[j] = true;
		}
	}
	checkHash(hash);
	
	//對每個節點 dfs
	for(int i= 0; i<hash.size(); i++){
		vector<bool> visited(N);
		visited[i] = true;
		dfs(hash, i, visited, 0);
	}
};
void checkHash(const vector<vector<int> >& arr){
	for(int i = 0; i<arr.size(); i++){
		for(int j = 0; j<arr[i].size(); j++){
			cout<< arr[i][j]<<" ";
		}
		cout<< endl;
	}
}
int main(){
	solve();
	cout<< max_res;
}
