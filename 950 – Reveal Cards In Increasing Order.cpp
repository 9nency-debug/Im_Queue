#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());

        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        vector<int> ans(n);

        for(int card : deck) {
            int index = q.front();
            q.pop();

            ans[index] = card;

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        
        return ans;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> deck(n);
    for (int i = 0; i < n; i++) {
        cin >> deck[i];
    }

    Solution sol;
    vector<int> result = sol.deckRevealedIncreasing(deck);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}