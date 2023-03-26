#include <iostream>
#include <stack>
#include <tuple>
#include <map>

using namespace std;



int main ()
{
    stack <pair<int, int>> st;
    map <int, int> results;
    int N;
    cin >> N;
    int input;
    st.push(make_pair(-1,-1));
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        while (input < st.top().second && st.top().second != -1)
        {
            results[st.top().first] = i;
            st.pop();
        }
        st.push(make_pair(i, input));
    }

    for (int i = 0; i < N; i++)
    {
        results.try_emplace(i, -1);
        cout << results[i]<< " ";
    }
    
    return 0;
}