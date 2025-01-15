#include <iostream>
#include <string>
using namespace std;

bool isOneEditDistance(const string& s1, const string& s2) {
    int len1 = s1.size(), len2 = s2.size();
    if (abs(len1 - len2) > 1) return false;

    int i = 0, j = 0, edits = 0;
    while (i < len1 && j < len2) {
        if (s1[i] != s2[j]) {
            if (++edits > 1) return false;
            if (len1 > len2) i++;         // Deletion
            else if (len1 < len2) j++;    // Insertion
            else { i++; j++; }            // Substitution
        } else {
            i++; j++;
        }
    }

    return edits == 1 || (edits == 0 && abs(len1 - len2) == 1);
}

int main() {
    string s1, s2;
    // cout << "Enter the first string: ";
    // cin >> s1;
    // cout << "Enter the second string: ";
    // cin >> s2;
    s1 = "cat";
    s2 = "cats";

    cout << (isOneEditDistance(s1, s2) ? "True" : "False") << endl;
}
