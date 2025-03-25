#include <iostream>

using namespace std;

void incr()
{
    int j = 0;
    static int i;
    cout << "i = " << i++ << "\t" << "j = " << j++ << endl;
}

int main()
{
    incr();
    incr();
    incr();

    // ALl static variables are initialised to zero by default.

    return 0;
}