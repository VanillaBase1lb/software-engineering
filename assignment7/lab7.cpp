
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

// PROXY BEGIN Data
class Data
{
  public:
    int x1[20] = {255, 475, 362, 341, 469, 255, 248, 195, 223, 310, 191, 449, 258, 233, 347, 284, 339, 135, 280, 303};
    int y1[20] = {600, 1440, 300, 780, 1440, 600, 780, 420, 780, 780, 360, 900, 660, 720, 780, 1020, 960, 300, 660, 420};
};
// PROXY END Data

// PROXY BEGIN Regression
class Regression
{
  public:
    // PROXY FN BEGIN
    double beta1_fun(int *x, int *y, double size)
    {
      double xbar = 0;
      int n = size;

      for (int i = 0; i < n; i++)
        xbar += (double)x[i];
      xbar = xbar / (double)n;

      double ybar = 0;
      for (int i = 0; i < n; i++)
        ybar += (double)y[i];
      ybar = ybar / (double)n;

      double beta1_num = 0, beta1_den = 0;
      for (int i = 0; i < n; i++)
      {
        beta1_num += (x[i] - xbar) * (y[i] - ybar);
        beta1_den += (x[i] - xbar) * (x[i] - xbar);
      }

      return beta1_num / beta1_den;
    }
    // PROXY FN END

    // PROXY FN BEGIN
    double beta0_fun(int *x, int *y, double beta1, double size)
    {
      double xbar = 0;
      int n = size;
      for (int i = 0; i < n; i++)
        xbar += (double)x[i];
      xbar = xbar / (double)n;

      double ybar = 0;
      for (int i = 0; i < n; i++)
        ybar += (double)y[i];
      ybar = ybar / (double)n;

      return (ybar - (beta1 * xbar));
    }
    // PROXY FN END
};
// PROXY END Regression



// PROXY BEGIN Main
// PROXY FN BEGIN
int main()
{

  Data d;
  int *x, *y;
  double size, LOCe;

  x = d.x1;
  y = d.y1;
  size = sizeof(d.x1) / sizeof(d.x1[0]);

  cout << "Enter raw estimated value:";
  cin >> LOCe;
  if (LOCe < 0)
    cout << "Invalid input : entered negative value\n";
  else
  {
    Regression r;
    double beta1 = r.beta1_fun(x, y, size);
    double beta0 = r.beta0_fun(x, y, beta1, size);
    cout << "Raw Estimate         " << LOCe << endl;
    cout << "beta0      " <<beta0 << endl;
    cout << "beta1      " <<beta1 << endl;
  }
}
// PROXY FN END
// PROXY END Main
