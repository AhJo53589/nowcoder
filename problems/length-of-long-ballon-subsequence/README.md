# `（中等）` [202004031600.length-of-long-ballon-subsequence 最长气泡子序列](https://leetcode-cn.com/circle/discuss/JEGP8D/view/qve17n/)

### 题目描述
长度为 k 的正整数数组 b ，其中 k >= 3 。  
如果能找到一个先递增再递减的子序列，称为气泡序列。  
即子序列组成的新数组 c ，长度为 len，以第 j 个元素分割，从 c[0] 到 c[j] 是递增的，从 c[j] 到 c[len - 1] 是递减的。  
求最大的气泡序列长度。

---
### 思路
```
1. 正反两次单调栈，将对应位置的栈中元素的数量保存起来
2. 遍历每个位置，相加结果 -1 即为子序列长度
3. 注意如果只有递增或递减不符合题目要求
```



### 答题
``` C++
void f(vector<int>& nums, stack<int>& st, vector<int>& cnt, int i)
{
    if (!st.empty() && st.top() >= nums[i])
    {
        st.pop();
    }
    st.push(nums[i]);
    cnt[i] += st.size();
}

int lengthOfLongBallonSubsequence(vector<int>& nums)
{
    stack<int> st_inc;
    stack<int> st_dec;
    vector<int> inc(nums.size(), 0);
    vector<int> dec(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
    {
        f(nums, st_inc, inc, i);
        f(nums, st_dec, dec, nums.size() - i - 1);
    }

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = (inc[i] != 1 && dec[i] != 1) ? max(ans, inc[i] + dec[i] - 1) : ans;
    }
    return ans;
}
```




