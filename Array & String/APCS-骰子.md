# 數組

## 題目鏈結：
https://zerojudge.tw/ShowProblem?problemid=f580

## 思路
這題最難的地方就是骰子到底是怎麼翻的==

## 代碼

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class dize{
	public:
		int tp = 1;
		int rs = 2;
		int ls = 5;
		int fs = 3;
		int bs = 4;
		int bt = 6;
};
void f_rt(dize& d){
	int ffs, bbt,bbs,ttp;
	ffs = d.fs;
	bbt = d.bt;
	bbs = d.bs;
	ttp = d.tp;
	d.tp = ffs;
	d.fs = bbt;
	d.bt = bbs;
	d.bs = ttp;
}
void r_rt(dize& d){
	int rrs, lls,bbt,ttp;
	rrs = d.rs;
	lls = d.ls;
	bbt = d.bt;
	ttp = d.tp;
	d.tp = lls;
	d.ls = bbt;
	d.rs = ttp;
	d.bt = rrs;
}
int main(){
	
	int n,m;
	cin>>n>>m;
	vector<dize> d(20);
	while(m--){
		int a,b;
		cin>>a>>b;
		if(b==-1){
			f_rt(d[a]);
		}
		else if(b==-2){
			r_rt(d[a]);
		} 
		else{
			swap(d[a], d[b]);
		}
	}
	for(int i = 1; i<n+1; i++){
		cout<< d[i].tp<<" ";
	}
}
```
