#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the solve function below.
string solve(vector<vector<int>> grid) {
    int x_min=INT_MAX,y_min=INT_MAX;
    for(int i=0;i<5;i++){
        x_min = min(grid[i][0],x_min);
        y_min = min(grid[i][1],y_min);
    }

    for(int i=0;i<5;i++){
        grid[i][0] -= x_min;
        grid[i][1] -= y_min;
        if(grid[i][0] > 2){
            return "No";
        }
        if(grid[i][1] > 2){
            return "No";
        }
    }

    int arr[3][3];
    memset(arr, -1, sizeof arr);
    for(int i=0;i<5;i++){
        arr[grid[i][0]][grid[i][1]] = 1;
    }

    //for(int i=0;i<3;i++){
        //for(int j=0;j<3;j++){
            //cout << arr[i][j] << " ";
        //}
        //cout << endl;
    //}

    if(arr[0][0] == 1 and arr[0][1] == 1 and arr[0][2] == 1 and arr[1][1] == 1 and arr[2][1] == 1) {
        return "Yes";
    }
    if(arr[0][0] == 1 and arr[1][0] == 1 and arr[2][0] == 1 and arr[1][1] == 1 and arr[1][2] == 1) {
        return "Yes";
    }
    if(arr[2][0] == 1 and arr[2][1] == 1 and arr[2][2] == 1 and arr[1][1] == 1 and arr[0][1] == 1) {
        return "Yes";
    }
    if(arr[1][0] == 1 and arr[1][1] == 1 and arr[1][2] == 1 and arr[0][2] == 1 and arr[2][2] == 1) {
        return "Yes";
    }
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        vector<vector<int>> points(5);

        for (int i = 0; i < 5; i++) {
            points[i].resize(2);

            string points_row_temp_temp;
            getline(cin, points_row_temp_temp);

            vector<string> points_row_temp = split(rtrim(points_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int points_row_item = stoi(points_row_temp[j]);

                points[i][j] = points_row_item;
            }
        }

        string result = solve(points);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
