#include <iostream>

bool canSolve(vector<pair<string, string>>& vec) {
    unordered_set<
}

int main()
{
    int numCase;
    cin >> numCase;
    for(int i = 1; i <= numCase; i++) {
        int numInput;
        cin >> numInput;
        vector<pair<string, string>> vec(numInput);
        for(int j = 0; j < numInput; j++) {
            cin >> vec[j].first >> vec[j].second;
        }
        if(canSolve(vec))
            cout << "Case #%d: Yes" << endl;
        else
            cout << "Case #%d: No" << endl;
    }
    return 0;
}
