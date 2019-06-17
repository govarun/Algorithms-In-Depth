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

bool checkPatternPresence (string sText, string sPattern, vector<int> v1) {
    int sizeText = sText.size();
    int sizePattern = sPattern.size();
    for (int a = 0; a < sizeText; ++a) {
        int i = 0;
        while ((i + 1) < sizePattern) {
            while (sPattern[i + 1] == sText[a] && (i + 1) < sizePattern && a < sizeText) {
                if ((i + 1) == sizePattern - 1) {
                  return true;  
                }
                ++i;
                ++a;
            }
            if (a >= sizeText || i > sizePattern) {
                    break;
            }
            if (sPattern[i + 1] != sText[a] && i == 0) {
                break;
            }
            if (sPattern[i + 1] != sText[a]) {
                i = v1[i];
            }  
        }    
    }
    return false;


}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string sText; cin >> sText;
    string sPattern; cin >> sPattern;
    int sizeText = sText.size();
    int sizePattern = sPattern.size();
    if (sizeText < sizePattern) {
        cout << "Not Possible: Pattern larger than text";
    }

    // sText = " " + sText;
    sPattern = " " + sPattern;

    vector<int> v1(sizePattern + 1);
    for (int i = 0; i <= sizePattern; ++i) {
        v1[i] = 0;
    }
    // cout << "Hello";
    createPrefixTable(sPattern, v1);
    // cout << "Hello";
    // for (int i = 1; i <= sizePattern; ++i) {
    //     cerr << (v1[i]) << endl;
    // }
    // cout << checkPatternPresence(sText, sPattern, v1);
    cout << checkPatternPresence(sText, sPattern, v1);

}
