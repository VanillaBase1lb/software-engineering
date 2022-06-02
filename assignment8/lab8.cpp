#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

//PROXY BEGIN Data
class Data
{
public:
   double LOCe[20]={255,475,362,341,469,255,248,195,223,310,191,449,258,233,347,284,339,135,280,303};
   double LOCa[20]={258,562,121,321,534,256,323,197,302,343,151,430,256,294,359,394,376,117,232,148};
   double Da[20]={600,1440,300,780,1440,600,780,420,780,780,360,900,660,720,780,1020,960,300,660,420};

};
//PROXY END Data

//PROXY BEGIN T_distribution_prob
class T_distribution_prob
{
public:
//PROXY FN BEGIN
    double gamma_function(double num)
    {
        if (num == 1)
            return 1;
        else if (num == 0.5)
            return sqrt(3.1415926);
        else
            return (num - 1) * gamma_function(num - 1);
    }
//PROXY FN END

    // t curve function value
//PROXY FN BEGIN
    double t_function(int df, float tvalue)
    {
        double df1 = double(df);
        double denominator = pow((1 + (tvalue * tvalue) / df1), (df1 + 1) / 2);
        return ((gamma_function((df1 + 1) / 2)) / ((gamma_function(df1 / 2)) * sqrt(df1 * 3.1415926) * denominator));
    }
//PROXY FN END

//PROXY FN BEGIN
    double area_by_simpsonrule(double tvalue, int tails, int df, int steps)
    {
        int N = steps;
        double prob;
        double x = 0;
        double delta_x = tvalue / double(N);
        double area = 0;
        for (int i = 0; i <= N; i++)
        {
            if (i == 0 || i == N)
                area = area + t_function(df, x);
            else if (i % 2 == 0 && i != 0 && i != N)
                area = area + (2 * t_function(df, x));
            else if (i % 2 != 0 && i != 0 && i != N)
                area = area + (4 * t_function(df, x));
            // next x value
            x = x + delta_x;
        }
        area = area * (delta_x / 3);
        // net area probability
        if (tails == 2)
            prob = 2 * (area + 0.5) - 1;
        else
            prob = area + 0.5;

        return prob;
    }
//PROXY FN END
};
//PROXY END T_distribution_prob

//PROXY BEGIN Correlation
class Correlation{
    public:
  T_distribution_prob tdp;
//PROXY FN BRGIN
double calculate_r(double *x, double *y,double size)
{
    // xbar
        double sum_x = 0,sum_y=0,sum_xy,sum_xx=0,sum_yy=0;
        int n = size;
        ;
        // cout<<"n="<<n<<endl;
        for (int i = 0; i < n; i++)
           {
               sum_x += x[i];
               sum_y+= y[i];
               sum_xy+= y[i]*x[i];
               sum_xx+=x[i]*x[i];
               sum_yy+=y[i]*y[i];

           }
        
        return (((double)n*sum_xy)-(sum_x*sum_y))/sqrt(((double)n*sum_xx-sum_x*sum_x)*((double)n*sum_yy-sum_y*sum_y));
}
//PROXY FN END

//PROXY FN BRGIN
double calculate_sig(double r,double size)
{
   double t_val=(fabs(r)*sqrt(size-2))/(sqrt(1-(r*r)));
   return 1-tdp.area_by_simpsonrule(t_val,2,18,4);

   
}
//PROXY FN END

    
};
//PROXY END Correlation

//PROXY BEGIN Main
//PROXY FN BEGIN
int main()
{

    // get data
    Data d;
    // using class T_distribution_prob
    T_distribution_prob tdp;
    Correlation corr;
double size = sizeof(d.LOCe) / sizeof(d.LOCe[0]);
   //test 1
   cout<<"LOCe x LOCa => r : "<<corr.calculate_r(d.LOCe,d.LOCa,size)<<"   sig : "
   <<corr.calculate_sig(corr.calculate_r(d.LOCe,d.LOCa,size),size)<<endl;

   //test 2
   cout<<"LOCe x Da => r : "<<corr.calculate_r(d.LOCe,d.Da,size)<<"   sig : "
   <<corr.calculate_sig(corr.calculate_r(d.LOCe,d.Da,size),size)<<endl;


   //test 3
   cout<<"LOCa x Da => r : "<<corr.calculate_r(d.LOCa,d.Da,size)<<"   sig : "
   <<corr.calculate_sig(corr.calculate_r(d.LOCa,d.Da,size),size)<<endl;
   
}
//PROXY FN END
//PROXY END Main
