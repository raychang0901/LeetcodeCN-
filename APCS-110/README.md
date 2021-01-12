# 2021/1/9 APCS題目解題紀錄

## 題目鏈結

第一題
https://zerojudge.tw/ShowProblem?problemid=f605
第二題
https://zerojudge.tw/ShowProblem?problemid=f606
第三題
https://zerojudge.tw/ShowProblem?problemid=f607
第四題
https://zerojudge.tw/ShowProblem?problemid=f608

## 第一題： 

跟著敘述計算即可。    

## 第二題：

直接建二維陣列計算。多個伺服器要傳送到同一個城市要一起累加。    

## 第三題：

sol(1)[暴力法]：切下後往兩邊遍歷...    
sol(2)[插入排序]：先建立初始數組[0,L(長度)]之後插入arr[n]時切割費用 arr[n+1]-arr[n-1]    


## 第四題：

對x排序後，找最大上升數量(可不連續)    
sol(1)[直觀dp] dp[n] = max(dp[i]+1, dp[n])| j>i>=0    
sol(2)[二分搜尋法] 遍歷高度(y)時維護一個升序數組arr，若y[i]大於arr所有的數，將y[i]放入arr尾端(維護升序)，否則在arr數組中找到比y[i]大但距離最近的數字取代(使升序組變小)。
