class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    int n = rectangles.size();

    if (n == 1) return true;

    map<pair<int, int>, int> cnt;

    for (auto& rect : rectangles) {
      cnt[{rect[0], rect[1]}]++;
      cnt[{rect[2], rect[3]}]++;
      cnt[{rect[0], rect[3]}]--;
      cnt[{rect[2], rect[1]}]--;
    }

    int numMarks = 0;

    for (auto it = cnt.begin(); it != cnt.end(); it++) {
      if (it->second != 0) {
        if (abs(it->second) != 1) return false;

        numMarks++;
      }
    }

    return numMarks == 4;
  }
};