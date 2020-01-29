#include <map>


/*
 * 50. Pow(x, n)
 * Medium
 *
 * speed: 4ms, faster than 100%
 * memory: 8.6MB, less than 99.73%
 *
 * https://leetcode.com/problems/powx-n/
 */
double myPowImpl(
  std::map<int, double>& dp,
  const double& x,
  const unsigned int& n
                ) {
  if      (n == 0) return 1;
  else if (n == 1) return x;

  if (dp.count(n)) return dp[n];
  else {
    double result = myPowImpl(dp, x, n/2);
    dp[n/2] = result;
    result *= result;
    if (n % 2 == 1) {
      result *= x;
    }
    return result;
  }
}

double myPow(double x, int n) {
  if (x == 0) return 0;

  double base;
  unsigned long long exp;

  if (n < 0) {
    base = 1/x;
    exp = ((long long) n) * -1;
  } else {
    base = x;
    exp = n;
  }

  auto dp = std::map<int, double>();
  return myPowImpl(dp, base, (unsigned int) exp);
}
