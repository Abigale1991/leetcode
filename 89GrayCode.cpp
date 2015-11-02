#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int convers(vector<int> num)
{
    int res;
    int n = num.size();
    for(int i = n-1; i >= 0; i--) res += num[i]*pow(2,n-i-1);
    return res;
}   

void grayCode(int n) {
    const int N = pow(2,n);
    vector<vector<int> > res(N,vector<int>(n));
    int temp[2];
    int M,group;
    for(int i = 0; i < n; i++)
    {
        M = N/pow(2,i);//每一列的每一组有多少个元素，如上例子，第一列只有一组，里面有16个元素；第二列有两组，每组有8个元素
        group = N/M;//每一列分为多少组,如上例子，第一列只有一组，第二列有两组
        temp[0] = 0;
        temp[1] = 1;
        for(int j = 0; j < group; j++)
        {
            int idx = 0;
            while(idx < M/2) 
            {
                res[j*M+idx][i]=temp[0];
                cout << "res[" << j*M+idx <<"][" << i << "]=" << res[j*M+idx][i] << endl;
                idx++;                
            }
            while(idx < M)
            {
                res[j*M+idx][i]=temp[1];
                cout << "res[" << j*M+idx <<"][" << i << "]=" << res[j*M+idx][i] << endl;
                idx++;                
            }
            int x = temp[0];
            temp[0] = temp[1];
            temp[1] = x;
        }
    }
    vector<int> cores;
    for(int i = 0; i < N; i++)
    {
        cores.push_back(convers(res[i]));
    }
    for(int i = 0; i < N; i++) cout << cores[i] << " ";
    cout << endl;
}

int main() 
{
    int n = 3;
    grayCode(n);
    return 0;
}

    



