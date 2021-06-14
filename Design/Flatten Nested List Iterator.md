# Stack & DFS

## 题目链接
https://leetcode-cn.com/problems/flatten-nested-list-iterator/

力扣341. Flatten Nested List Iterator

## 兩種解法
#### [法一] 
DFS初始化時就將List中每一個元素DFS到底，用一個list存    
#### [法二] 
初始化時，將每一個元素反向放入stack中，之後遍歷時再考慮是整數(Integer)或列表(List)，若是列表則再反向放入Stack中
## [法二]都是反向放入，為何不用Queue??
因為要運用Stack FIFO的特性，遍歷時遇到的List要先處理，先輸出，所以要用Stack儲存而非用Queue....    
但是考慮到要求輸出順序是由左到右，所以要由右到左(反向)放入元素    

[法一] 
---------------------------------------

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> arr;
    int curr = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = 0; i<nestedList.size(); ++i){
            if(nestedList[i].isInteger()){
                arr.push_back(nestedList[i].getInteger());
            }
            else{
                dfs(nestedList[i].getList());
            }
        }
    }
    
    int next() {
        return arr[curr++];
    }
    
    bool hasNext() {
        return curr<arr.size();
    }
    void dfs(vector<NestedInteger>& ele_list){
        for(int i = 0; i<ele_list.size(); ++i){
            if(ele_list[i].isInteger()){
                arr.push_back(ele_list[i].getInteger());
            }
            else{
                dfs(ele_list[i].getList());
            }
        }
        return;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```

[法二]
-----------------------------
```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger> sta;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i>=0; --i){
            sta.push(nestedList[i]);
        }
    }
    
    int next(){
        int tmp = sta.top().getInteger();
        sta.pop();
        return tmp;
        
    }
    
    bool hasNext() {
        while(!sta.empty()){
            if(sta.top().isInteger()){
                return true;
            }
            else{
                auto lst = sta.top().getList();
                sta.pop();
                for(int i = lst.size()-1; i>=0; --i){
                    sta.push(lst[i]);
                }
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```
