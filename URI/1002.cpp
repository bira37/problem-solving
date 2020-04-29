#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14159
 
int main() {
    double x;
    cin >> x;
    cout << "A=" << fixed << setprecision(4) << x*x*PI << endl;
    return 0;
}
