# `（中等）` [202003161400.find-mid-num-in-unsorted-array 无序数组寻找中间数](https://leetcode-cn.com/circle/discuss/q5wVRM/view/982rpT/)

### 题目描述
原描述：
给出一个元素无序的数组，求出一个数，使得其左边的数都小于它，右边的数都大于等于它。
要求时间复杂度n

整理及丰富细节：
一个无序的数组，找出所有符合以下特点的数，返回它们的索引。
这个数的左边的数都小于它，右边的数都大于等于它。
要求时间复杂度 O(n) 。



---
### 思路
```
```



### 答题
``` C++
vector<int> getMidNum(vector<int>& nums)
{
    vector<int> ans;
    int maxn = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!ans.empty() && !(nums[ans.back()] < nums[i]))
        {
            ans.pop_back();
        }

        if (nums[i] > maxn)
        {
            ans.push_back(i);
        }

        maxn = max(maxn, nums[i]);
    }
    return ans;
}
```




