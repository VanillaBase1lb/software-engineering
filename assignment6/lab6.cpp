#include <iostream>
#include <string>
#include <cmath>
#include <array>
using namespace std;
#if !defined(ARRAY_SIZE)
    #define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

// PROXY BEGIN Data
class Data
{
public:
    double data_cal[10]
 = {1.269,2.049,1.897,1.322,1.832,1.329,1.672,2.152,0.985,1.420};

 double data_data[13]={1.278,1.501,1.176,1.387,1.287,1.418,1.594,1.387,1.021,1.427,1.194,1.339,1.250};
double data_io[10]={1.397,1.180,0.963,1.101,0.880,1.539,0.716,1.574,1.755,1.176};


    int x1[20] = {124,360,229,321,279,352,297,263,357,311,341,153,390,260,215,468,528,232,304,459};
    int y1[20] = {98,284,292,286,350,464,381,369,365,284,277,212,319,218,238,312,676,266,225,395};

};
// PROXY END Data

// PROXY BEGIN Regression
class Calculation
{
public:

    //PROXY FN BEGIN
    double mean_fun(double *data_array,int size)
    {
        //calculating mean
      
        
       
        double sum = 0;
        for (int i = 0; i < size; i++)
          sum += data_array[i];

        return sum / size;
    }
    //PROXY FN ENDS

 //PROXY FN BEGIN
    double stdeviation_fun(double *data_array,double mean,int size)
    {
        // calculating st deviation//(x1-median)
        
        double sumof_diff = 0;
        for (int i = 0; i < size; i++)
         sumof_diff += (mean - data_array[i]) * (mean - data_array[i]);
        
        sumof_diff = sumof_diff / (size - 1);
        double st_dev = sqrt( sumof_diff);
        return st_dev;
    }
    //PROXY FN ENDS

    //PROXY FN BEGIN
    void midpoint_fn(double mean,double st_dev)
    {
       mean=pow(10,mean);
    st_dev=pow(10,st_dev);
        cout<<"VS midpint : "<<mean-2*st_dev<<" "<<"   Range : 0 to"<<mean-1.5*st_dev<<endl;
        cout<<"S midpint : "<<mean-st_dev<<" "<<"   Range : "<<mean-1.5*st_dev<<" to "<<mean-0.5*st_dev<<endl;
        cout<<"M midpint : "<<mean<<"   Range : "<<mean-0.5*st_dev<<" to "<<mean+0.5*st_dev<<endl;
        cout<<"L midpint : "<<mean+st_dev<<"   Range : "<<mean+0.5*st_dev<<" to "<<mean+1.5*st_dev<<endl;
        cout<<"VL midpint : "<<mean+2*st_dev<<"   Range : "<<mean+1.5*st_dev<<" to  inf"<<endl;
    }
    //PROXY FN ENDS

    // PROXY FN BEGIN
    double beta1_fun(int *x, int *y)
    {
        // xbar
        double xbar = 0;
        int n = sizeof(x);
        ;
        // cout<<"n="<<n<<endl;
        for (int i = 0; i < n; i++)
            xbar += (double)x[i];
        xbar = xbar / (double)n;
        // cout<< "xbar "<<xbar <<endl;
        // ybar
        double ybar = 0;
        for (int i = 0; i < n; i++)
            ybar += (double)y[i];
        ybar = ybar / (double)n;
        double beta1_num = 0, beta1_den = 0;
        // sum(x-xbar*y-ybar)
        for (int i = 0; i < n; i++)
        {
            beta1_num += (x[i] - xbar) * (y[i] - ybar);
            beta1_den += (x[i] - xbar) * (x[i] - xbar);
        }
        // cout<<beta1_num<<endl;
        // cout<<beta1_den<<endl;
        return beta1_num / beta1_den;
    }
    // PROXY FN END

    // PROXY FN BEGIN
    double beta0_fun(int *x, int *y, double beta1)
    {
        // xbar
        double xbar = 0;
        int n = sizeof(x);
        for (int i = 0; i < n; i++)
            xbar += (double)x[i];
        xbar = xbar / (double)n;
        // ybar
        double ybar = 0;
        for (int i = 0; i < n; i++)
            ybar += (double)y[i];
        ybar = ybar / (double)n;
        double beta1_num = 0, beta1_den = 0;

        return (ybar - (beta1 * xbar));
    }
    // PROXY FN END
};
// PROXY END Regression

// PROXY BEGIN Display
class Display
{
public:
    // PROXY FN BEGIN
    void print_menu()
    {
        cout << "Select option for test sample taken\n";
        cout << " Enter 1 for Test1\n Enter 2 for Test2\n Enter 3 for Test3\n\n";
    }
    // PROXY FN END
};
// PROXY END Display

// PROXY BEGIN Main
// PROXY FN BEGIN
int main()
{

    // get data
    Data d;
    double *array,size;
    int num;
     Display dis;
    dis.print_menu();
    cout << "Enter : ";
    cin >> num;
    switch (num)
    {
    case 1:
        array=d.data_cal;
        size=sizeof(d.data_cal)/sizeof(d.data_cal[0]);

        break;
    case 2:
        array=d.data_data;
        size=sizeof(d.data_data)/sizeof(d.data_data[0]);

        break;
    case 3:
        array=d.data_io;
        size=sizeof(d.data_io)/sizeof(d.data_io[0]);

        break;

    default:
        cout << "Invalid choice\n";
    }
   
    //calculate mean and st-d
    Calculation cal;
    double mean=cal.mean_fun(array,size);
    double st_dev=cal.stdeviation_fun(array,mean,size);
    cout<<"Mean : "<<mean<<endl;
    cout<<"Standard deviation :"<<st_dev<<endl;
    cal.midpoint_fn(mean,st_dev);


    
    
}
// PROXY FN END
// PROXY END Main

