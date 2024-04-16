class Solution {
public:
    int dayOfYear(string date) {
        vector<pair<int, int>> days = {{1, 31}, {2, 28},  {3, 31},  {4, 30},
                                       {5, 31}, {6, 30},  {7, 31},  {8, 31},
                                       {9, 30}, {10, 31}, {11, 30}, {12, 31}};
        int ans = 0;
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int leap = 0;

        // check if year is leap year or not
        if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) &&
            (month >= 3)) {
            leap = 1;
        }

        // now calculate the total days till that required month
        for (auto it : days) {
            int month_check = it.first;
            if (month_check != month) {
                ans += it.second;
            } else {
                break;
            }
        }

        // add the number of days in the current month
        ans += day;

        // add another day if leap year or not
        if (leap == 1) {
            ans++;
        }

        // return the answer
        return ans;
    }
};