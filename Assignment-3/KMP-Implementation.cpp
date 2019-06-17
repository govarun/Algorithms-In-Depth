#include <bits/stdc++.h>
using namespace std;

//Author: Varun Goyal (@govarun)

void createPrefixTable(string s, vector<int> &v1) {
    int sizePattern = s.size();
    v1[0] = 0;
    v1[1] = 0;
    for (int j = 2; j <= sizePattern; ++j) {
        int i = 1;
        while (i < j) {
            while (s[j] == s[i] && i < sizePattern && j <= sizePattern) { // j < i
                v1[j] = i;
                ++i; 
                ++j;
            }
            if (i >= sizePattern || j > sizePattern) {
                break;
            }
            if (s[j] != s[i] && i == 1) {
                v1[j] = 0;
                break;
            }
            else {
                i = 1;
            }

        }
    }
}


int main(){
    string sText; cin >> sText;
    string sPattern; cin >> sPattern;
    int sizeText = sText.size();
    int sizePattern = sPattern.size();
    if (sizeText < sizePattern) {
        cout << "Not Possible: Pattern larger than text";
    }

    sPattern = " " + sPattern;

    vector<int> v1(sizePattern + 1);

    createPrefixTable(sPattern, v1);
    // fa (i, 1, sizePattern) {

    //     d1(v1[i]);
    // }
}
