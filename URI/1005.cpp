#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14159
 
int main() {
    double x,y;
    cin >> x >> y;
	double m=(x*3.5+y*7.5)/11;
    cout << "MEDIA = " << fixed << setprecision(5) << m << endl;
    return 0;
}
