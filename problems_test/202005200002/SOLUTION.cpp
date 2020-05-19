
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int main() {
        int L = 0;
        int S = 0;
        int T = 0;
        int M = 0;
        cin >> L;
        cin >> S >> T >> M;

        vector<int> stones(M, 0);
        for (int i = 0; i < M; i++) {
            cin >> stones[i];
        }
        unordered_set<int> us;
        for (int i = 0; i < M; i++) {
            us.insert(stones[i]);
        }

        int ans = INT_MAX;
        vector<int> dp(10, INT_MAX);

        for (int i = 0; i < L; i++) {
            int t = i % 10;
            if (i != 0 && dp[t] == INT_MAX) continue;
            for (int j = S; j <= T; j++) {

                int k = (i + j) % 10;
                int newVal = 0;
                if (i == 0) {
                    newVal = (us.count(i + j) != 0) ? 1 : 0;
                }
                else {
                    newVal = (us.count(i + j) != 0) ? dp[t] + 1 : dp[t];
                }

                dp[k] = min(dp[k], newVal);
                if (i + j >= L) {
                    ans = min(ans, dp[k]);
                }

            }
        }

        cout << ans;

        return 0;
    }
};

//////////////////////////////////////////////////////////////////////////
//string _solution_run(string s1)
//{
//    //int caseNo = -1;
//    //static int caseCnt = 0;
//    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
//
//    Solution sln;
//    return sln.run(s1);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
    FILE* ssin;
    freopen_s(&ssin, "C:\\AhJo53589\\nowcoder\\problems_test\\202005200002\\1.in", "r", stdin);

    FILE* ssout;
    freopen_s(&ssout, "C:\\AhJo53589\\nowcoder\\problems_test\\202005200002\\1.out", "w", stdout);

    Solution sln;
    sln.main();

    freopen_s(&ssout, "CON", "w", stdout);

    //FILE* ssout;
    //freopen_s(&ssout, "C:\\AhJo53589\\nowcoder\\problems_test\\0\\1.out", "r", stdin);
    //char c;
    //while ((c = getchar()) != EOF && c != '\n') putchar(c);
    //cout << endl;

    return {};
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
