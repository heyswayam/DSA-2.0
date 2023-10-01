#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int findMinDifference(vector<string> &timePoints)
{
    int ans;
    vector<int> time;
    for (int i = 0; i < timePoints.size(); i++)
    {
        int hr = stoi(timePoints[i].substr(0, 2));
        int min = stoi(timePoints[i].substr(3, 2));
        if (hr == 0 && min == 0)
            time.push_back(24 * 60);
        else
            time.push_back(hr * 60 + min);
    }
    sort(time.begin(), time.end());

    return (time[1] - time[0]);
}
int main()
{
    vector<string> time{"00:00","00:00","23:59","00:00"};
    cout<<findMinDifference(time);

    return 0;
}