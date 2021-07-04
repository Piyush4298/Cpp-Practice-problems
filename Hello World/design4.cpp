/*
Output- 
      # 
    # #
  # # #
# # # #
*/
#include<iostream>
using namespace std;

int main()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(i+j < 3)
                cout << " " << " ";
        }

        for(int j = 0; j < 4; j++)
        {
            if(i+j >= 3 )
                cout << "#" << " ";
        }
        cout << "\n";
    }
    return 0;
}