#include<iostream>
#include<vector>
using namespace std;

// int rowWithMaxOnes(vector<vector<int>> &v, int n, int m)
// {
//     int res_idx = -1;
//     int maxCount = 0;
//     for(int i = 0; i < n; i++)
//     {
//         int count = 0;
//         for(int j = 0; j < m; j++)
//         {
//             if(v[i][j] == 1)
//                 count++;
//         }
//         if(i == 0){
//             maxCount = count;
//             res_idx = i;
//         }
//         else{
//             if(count > maxCount)
//             {
//                 maxCount = count;
//                 res_idx = i;
//             }
//         }
//     }
//     return res_idx;
// }

int rowWithMaxOnes(vector<vector<int>> &v, int n, int m)
{
    int j = m-1, res_idx = -1;
    for(int i = 0; i < n; i++)
    {
        while(j >= 0)
        {
            if(v[i][j] == 1)
            {
                j--;
                res_idx = i;
            }
            else
                break;
        }
    }
    return res_idx;
}

int main()
{
    vector<vector<int>> v = {{0, 1, 1, 1},
                             {0, 0, 1, 1},
                             {1, 1, 1, 1},
                             {0, 0, 0, 0}};
    int n = v.size();
    int m = v[0].size();

    cout << rowWithMaxOnes(v, n, m);
    return 0;
}
