//Cyclic Substring Maximum Sum
#include <bits/stdc++.h>
using namespace std;

int maxCyclicSubstringSum(string s) {
    string t = s + s;  // simulate cyclic
    unordered_set<char> st;

    int left = 0, sum = 0, maxSum = 0;

    for (int right = 0; right < t.size(); right++) {
        // Remove duplicates
        while (st.count(t[right])) {
            st.erase(t[left]);
            sum -= (t[left] - 'a' + 1);
            left++;
        }

        // Add current character
        st.insert(t[right]);
        sum += (t[right] - 'a' + 1);

        // Limit window size to original string length
        if (right - left + 1 > s.size()) {
            st.erase(t[left]);
            sum -= (t[left] - 'a' + 1);
            left++;
        }

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main() {
    string s;
    cin >> s;
    cout << maxCyclicSubstringSum(s);
}
