
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int breakNum(vector<int>& nums)
    {
        int ans = 0;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (!st.empty() && st.top() < nums[i])
            {
                int t = (nums[i] - 1) / st.top();
                ans += t;
                st.push(nums[i] / (t + 1));
                continue;
            }
            st.push(nums[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int breakNum(vector<int>& nums)
    {
        int ans = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i + 1] >= nums[i]) continue;
            int t = (nums[i] - 1) / nums[i + 1];
            ans += t;
            nums[i] /= (t + 1);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.breakNum(nums);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
