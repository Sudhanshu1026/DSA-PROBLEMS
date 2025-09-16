class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
           vector<long long> st;  // use long long for safe LCM calculation
        for (int num : nums) {
            st.push_back(num);
            while (st.size() > 1) {
                long long a = st.back();
                long long b = st[st.size() - 2];
                long long g = gcd(a, b);
                if (g == 1) break;  // coprime, stop merging
                st.pop_back();
                st.pop_back();
                long long l = lcm(a, b);
                st.push_back(l);
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }

private:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;  // safe from overflow (since final values ≤ 1e8)
    }
};