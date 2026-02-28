#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;

        for (int s : students) {
            q.push(s);
        }

        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            st.push(sandwiches[i]);
        }

        int count = 0;
        while (!q.empty() && count < q.size()) {
            if (q.front() == st.top()) {
                q.pop();
                st.pop();
                count = 0; 
            } else {
                q.push(q.front());
                q.pop();
                count++;
            }
        }

        return q.size();
    }
};
int main () {
    int n;
    cin >> n;

    vector <int> students(n), sandwiches(n);

    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> sandwiches[i];
    }

    Solution obj;
    cout << obj.countStudents(students, sandwiches) << endl;

    return 0;
}