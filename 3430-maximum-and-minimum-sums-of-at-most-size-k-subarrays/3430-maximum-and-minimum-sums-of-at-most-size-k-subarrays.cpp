class Solution {
public:

    using ll = long long;

    // Number of pairs (x,y):
    // 1 <= x <= L
    // 1 <= y <= R
    // x + y <= k+1
    ll countValid(ll L, ll R, ll k) {

        ll m = min(L, k);

        // For first 'a' values of x, maximum y is R
        ll a = min(m, max(0LL, k + 1 - R));

        ll count = a * R;

        // Remaining values: y <= k+1-x
        ll remaining = m - a;

        count += remaining * (k + 1)
                 - ((a + 1 + m) * remaining) / 2;

        return count;
    }


    ll solveMin(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> prev(n), next(n);

        stack<int> st;

        // Previous strictly smaller
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            prev[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next smaller or equal
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            next[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        ll ans = 0;

        for (int i = 0; i < n; i++) {

            ll L = i - prev[i];
            ll R = next[i] - i;

            ll ways = countValid(L, R, k);

            ans += ways * nums[i];
        }

        return ans;
    }


    ll solveMax(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> prev(n), next(n);

        stack<int> st;

        // Previous strictly greater
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            prev[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next greater or equal
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            next[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        ll ans = 0;

        for (int i = 0; i < n; i++) {

            ll L = i - prev[i];
            ll R = next[i] - i;

            ll ways = countValid(L, R, k);

            ans += ways * nums[i];
        }

        return ans;
    }


    long long minMaxSubarraySum(vector<int>& nums, int k) {

        return solveMin(nums, k) + solveMax(nums, k);
    }
};