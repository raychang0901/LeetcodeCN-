# 數組

## 题目链接

https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/

剑指 Offer 11. 旋转数组的最小数字

這種數組題很多類似的題目，通常從升序降序來解    
    
---------------------------------------

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        //先假設升序
        for(int i = 0; i<numbers.size()-1; i++){
            if(numbers[i+1]-numbers[i]<0)
            {
                return numbers[i+1];
            }
        }
        return numbers[0];
    }
};
```
