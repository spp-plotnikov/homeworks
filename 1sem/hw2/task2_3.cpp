#include <iostream>

using namespace std;

void partition(int parts[], int, int, int);

int main()
{
    cout << "This application produces a partition of a natural number N" << endl;
    cout << "Please enter N" << endl;

    int numberN = 0;
    cin >> numberN;

    int parts[1000] = {};  //It is assumed that the N does not exceed 1000
    partition(parts, 0, numberN, numberN);

    return 0;
}


void partition(int parts[], int position, int sum, int previousPart)
{
    for (int i = 1; i <= previousPart && i <= sum; i++)
    {
        parts[position] = i;
        partition(parts, position + 1, sum - i, i);
    }
    if (sum == 0)
    {
        for (int i = 0; i < position; i++)
        {
            cout << parts[i] << " ";
        }
        cout << endl;
        return;
    }
}
