//////////////////////////////////////////////////////////////////////////
//class Solution2 {
//public:
//    const int size = 256;
//    //��ģʽ���ַ�ʹ��hash��ʾ
//    void generateBC(char b[], int m, int bc[]) {
//        //b��ģʽ���� m��ģʽ���ĳ��ȣ� bc��ɢ�б�
//        //bc���±����ַ�����ASCII�룬����ֵ��ÿ���ַ���ģʽ���г��ֵ�λ�á�
//        for (int i = 0; i < size; i++) {
//            bc[i] = -1;
//        }
//        for (int i = 0; i < m; i++) {
//            int ascii = (int)b[i];
//            bc[ascii] = i;
//        }
//    }
//    /*
//    ��suffix�����prefix����
//    suffix������±�K��ʾ��׺�ִ��ĳ��ȣ�����ֵ��Ӧ�洢���ǣ���ģʽ���и��ú�׺{u}��ƥ����Ӵ�{u*}
//    ����ʼ�±�ֵ��
//    prefix�����ǲ����͡�����¼ģʽ���ĺ�׺�ִ��Ƿ���ƥ��ģʽ����ǰ׺�Ӵ���
//
//    */
//    void generateGS(char b[], int m, int suffix[], bool prefix[]) {
//        for (int i = 0; i < m; i++) {
//            suffix[i] = -1;
//            prefix[i] = false;
//        }
//        for (int i = 0; i < m - 1; ++i) {
//            int j = i;
//            int k = 0; //������׺�ִ�����
//            while (j >= 0 && b[j] == b[m - 1 - k]) {
//                //��b[0, m-1]�󹫹���׺�ִ�
//                --j;
//                ++k;
//                suffix[k] = j + 1; //j+1��ʾ������׺�ִ���b[0,i]�е���ʼ�±�
//            }
//            if (j == -1) prefix[k] = true;//���������׺�ִ�Ҳ��ģʽ����ǰ׺�ִ�
//
//        }
//    }
//
//    //j��ʾ���ַ���Ӧ��ģʽ���е��ַ��±꣬m��ģʽ���ĳ���
//    //�����ںú�׺������ģʽ������ƶ��ĸ��� 
//    int moveByGS(int j, int m, int suffix[], bool prefix[]) {
//        int k = m - 1 - j; //�ú�׺�ĳ���
//        if (suffix[k] != -1) return j - suffix[k] + 1;
//        for (int r = j + 2; r <= m - 1; ++r) {
//            if (prefix[m - r] == true) {
//                return r;
//            }
//        }
//        return m;
//    }
//
//    //BM�㷨
//    int boyerMoore(char a[], int n, char b[], int m) {
//        int suffix[m];
//        bool prefix[m];
//
//        int bc[size];//bc��¼ģʽ����ÿ���ַ������ֵ�λ��
//
//        generateBC(b, m, bc); //�����ַ���hash��
//        generateGS(b, m, suffix, prefix); //����ú�׺�ͺ�ǰ׺����
//
//        int i = 0; //��ʾ������ģʽ������ĵ�һ���ַ�
//        while (i <= n - m) {
//            int j;
//            for (j = m - 1; j >= 0; j--) { //ģʽ���Ӻ���ǰƥ��
//                if (a[i + j] != b[j]) break; //���ַ���Ӧ��ģʽ���±���j,��i+j λ���ǻ��ַ���λ��si        
//            }
//            if (j < 0) {
//                return i; //ƥ��ɹ�������������ģʽ����һ��ƥ����ַ���λ��
//            }
//            //����x��ͬ�ڽ�ģʽ�����󻬶�j-bc[(int)a[i+j]]λ
//            //bc[(int)a[i+j]]��ʾ�����л��ַ���ģʽ���г��ֵ�λ��xi
//            int x = i + (j - bc[(int)a[i + j]]);
//
//            int y = 0;
//            if (j < m - 1) {//����кú�׺�Ļ�,�����ڴ����������ƶ���λ��y
//                y = moveByGS(j, m, suffix, prefix);
//            }
//            i = i + max(x, y); //i����λ���Ժ��ƽ϶��λ��
//
//        }
//        return -1;
//    }
//};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void preBmGs(string needle, vector<int>& bmGs)
    {
        queue<int> que;
        for (int i = 0; i < needle.size() - 1; i++)
        {
            if (needle[i] != needle.back()) continue;
            que.push(i);
        }

        int same_len = 1;
        while (!que.empty())
        {
            int que_len = que.size();
            for (int i = 0; i < que_len; i++)
            {
                auto q = que.front();
                que.pop();

                int pos = bmGs.size() - same_len - 1;
                if (pos < 0) continue;
                bmGs[pos] = bmGs.size() - 1 - q;

                if (q - same_len < 0 || needle[q - same_len] == needle[needle.size() - 1 - same_len])
                {
                    que.push(q);
                }
            }
            same_len++;
        }

        cout << endl << "[bmGs]: " << endl;
        for (int i = 0; i < bmGs.size(); i++) cout << setw(3) << i << " "; cout << endl;
        for (int i = 0; i < bmGs.size(); i++) cout << setw(3) << bmGs[i] << " "; cout << endl;
    }

    int getBmBc(char c, map<char, int>& bmBc, int m)
    {
        if (bmBc.count(c) == 0)
        {
            return m;
        }
        return bmBc[c];
    }

    void preBmBc(string needle, unordered_map<char, int>& bmBc)
    {
        for (int i = 0; i < needle.size(); i++)
        {
            bmBc[needle[i]] = i;
        }

        cout << endl << "[bmBc]: " << endl;
        for (auto& p : bmBc) cout << p.first << "\t" << p.second << endl; cout << endl;
    }

    int boyerMoore(string haystack, string needle)
    {
        unordered_map<char, int> bmBc;
        vector<int> bmGs(needle.size(), 1);

        preBmGs(needle, bmGs);
        preBmBc(needle, bmBc);

        //int i = 0; // ��ʾ������ģʽ������ĵ�һ���ַ�
        //while (i <= haystack.size() - needle.size())
        //{
        //    int j;
        //    for (j = needle.size() - 1; j >= 0; j--)
        //    {
        //        if (haystack[i + j] != needle[j]) break;
        //    }
        //    if (j < 0) return i;

        //    // ���� x ��ͬ�ڽ�ģʽ�����󻬶� j - bc[(int)a[i+j]]λ
        //    // bc[(int)a[i+j]] ��ʾ�����л��ַ���ģʽ���г��ֵ�λ�� xi
        //    int x = i + (j - bmBc[haystack[i + j]);

        //    int y = 0;
        //    if (j < m - 1) 
        //    {
        //        y = moveByGS(j, m, suffix, prefix);
        //    }

        //    i += max(x, y);
        //}
        return -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string haystack, string needle)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

    for (int i = 0; i < haystack.size(); i++) cout << setw(3) << i << " "; cout << endl;
    for (int i = 0; i < haystack.size(); i++) cout << setw(3) << haystack[i] << " "; cout << endl;
    for (int i = 0; i < needle.size(); i++) cout << setw(3) << needle[i] << " "; cout << endl;
    Solution sln;
	return sln.boyerMoore(haystack, needle);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases& tc)
//{
//    int n = tc.get<int>();
//    stringstream ss;
//    ss << n;
//    while (n-- != 0)
//    {
//		ss << tc.get<string>();
//        ss << " ";
//	}
//
//    Solution sln;
//    sln.run(ss);
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
