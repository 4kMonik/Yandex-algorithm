#include <iostream>
#include <map> 
#include <utility> 
#include <iterator>

using namespace std;

int main()
{
    int M;
    cin >> M;
    int N;
    cin >> N;
    
    int count;
    int a_i;
    int b_i;
    map <int, int> sectors;
    sectors.insert({0,-1});
    for (int i = 0; i < N; i++)
    {
        cin >> a_i >> b_i;
        
        auto p = sectors.upper_bound(a_i);
        while (p->first <= b_i && p->second >= a_i )
        {
            p = sectors.erase(p);
            count--;
        }
        
        if (prev(p,1)->second >= a_i && prev(p,1)->second != -1)
        {
            sectors.erase(prev(p,1));
            count--;
        }
        sectors.insert(make_pair(a_i, b_i));
        count++;
    }
    
    cout << count;
    return 0;
}
