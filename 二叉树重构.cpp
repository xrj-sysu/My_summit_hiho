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
          for (i = i + 1; i < s2.size(); ++i) {
              s2_right += s2[i];
          }
          for (i = 1; i <= len1; ++i) {
              s1_left += s1[i];
          }
          for (; i < s1.size(); ++i) {
              s1_right += s1[i];
          }
          return post_order(s1_left, s2_left) + post_order(s1_right, s2_right) + s1[0];
      }
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << post_order(s1, s2) << endl;
    return 0;
}
