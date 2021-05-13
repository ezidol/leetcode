class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows == 1) return s;
      vector<string> rows((min(int(s.length()), numRows)));
      int curRow = 0;
      bool goDown = false;
      string ret;

      for (char c: s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1) goDown = !goDown;
        curRow += goDown ? 1 : -1;
      }

      for (string row: rows) ret += row;

      return ret;
    }
};