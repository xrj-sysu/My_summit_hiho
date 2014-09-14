#include<iostream>
#include<string>
using namespace std;
/* the core is   pre :  v  L-----  R------
                  in :  L-----  v  R------
                post :  -----L  ------R  v
*/
// 递归
string post_order(string s1, string s2) {
    if (s1.size() == 0) {
        return s1;
    } else {
          int len1 = 0, len2 = 0, i;
          string s1_left, s1_right, s2_left, s2_right;
          for (i = 0; s2[i] != s1[0]; ++i) {
                len1++;
                s2_left += s2[i];
          }
          len2 = s2.size() - len1 - 1;
          s2_right = s2.substr(i+1, len2);
          s1_left = s1.substr(1, len1);
          s1_right = s2.substr(len1+1, len2);
          return post_order(s1_left, s2_left) + post_order(s1_right, s2_right) + s1[0];
      }
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << post_order(s1, s2) << endl;
    return 0;
}
