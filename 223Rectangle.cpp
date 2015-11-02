#include <iostream>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int Ver = (min(D,H) > max(B,F))?(min(D,H) - max(B,F)):0;
    int Hor = (min(C,G) > max(A,E))?(min(C,G) - max(A,E)):0;
    int subS = 0, sum;
    if((Ver > 0) && (Hor > 0)) subS = Ver * Hor;
    sum = (D - B) * (C - A) + (H - F) * (G - E);
    sum = sum - subS;
    return sum;
}

int main()
{
	cout << computeArea(-1500000001,0,-1500000000,1,1500000000,0,1500000001,1) << endl;
	return 0;
}