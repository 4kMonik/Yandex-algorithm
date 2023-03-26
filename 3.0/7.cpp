#include <iostream>

using namespace std;

int main()
{
    int hhA, mmA, ssA;
    cin >> hhA;
    cin.get();
    cin >> mmA;
    cin.get();
    cin >> ssA;
    
    int hhB, mmB, ssB;
    cin >> hhB;
    cin.get();
    cin >> mmB;
    cin.get();
    cin >> ssB;
    
    int hhC, mmC, ssC;
    cin >> hhC;
    if (hhC < hhA)
       hhC += 24; 
    cin.get();
    cin >> mmC;
    cin.get();
    cin >> ssC;
    
    auto delta = int(( (hhC*3600 + mmC*60 + ssC) - (hhA*3600 + mmA*60 + ssA) + 0.5)/2. + 0.5);
    auto D = hhB*3600 + mmB*60 + ssB + delta;
    auto hhD = (D/3600)%24;
    auto mmD = (D%3600)/60;
    auto ssD = D%60;
    if (hhD < 10)
        cout << '0';
    cout << hhD << ":";
    if (mmD < 10)   
        cout << '0';
    cout << mmD << ":";
    if (ssD < 10)
        cout << '0';
    cout << ssD;
    
    return 0;
}