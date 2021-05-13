class Solution {
  public:
    int reverse(int x) {
      stringstream a;
      a << x;
      string aStr = a.str();
      if (x > 0) std::reverse(aStr.begin(), aStr.end());
      else std::reverse(aStr.begin()+1, aStr.end());
      long long ret = stol(aStr);
      if (ret > pow(2, 31)-1 || ret < -1 * pow(2,31)) return 0;
      return ret;
    }
};