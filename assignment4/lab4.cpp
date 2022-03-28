#include <iostream>
#include <vector>

class LinearRegression
{
public:
    float b0 = 0, b1 = 0, xy = 0, xSum = 0, sum_y = 0, x2 = 0, sum_y_square = 0;
    std::vector<float> x;
    std::vector<float> y;

    void calculateB0()
    {
        float N = x.size();
        b0 = (sum_y * x2 - xSum * xy) / (N * x2 - xSum * xSum);
    }

    void calculateB1()
    {
        float N = x.size();
        b1 = (N * xy - xSum * sum_y) / (N * x2 - xSum * xSum);
    }

    float returnB0()
    {
        if (b0 == 0)
            calculateB0();
        return b0;
    }

    float returnB1()
    {
        if (b1 == 0)
            calculateB1();
        return b1;
    }

    void calculateLinear()
    {
        if (b1 == 0 && b0 == 0)
        {
            calculateB1();
            calculateB0();
        }
    }

    void readInput(int inputCount)
    {
        for (int i = 0; i < inputCount; i++)
        {
            float xr;
            float yr;
            std::cin >> xr >> yr;
            xy += xr * yr;
            xSum += xr;
            sum_y += yr;
            x2 += xr * xr;
            sum_y_square += yr * yr;
            x.push_back(xr);
            y.push_back(yr);
        }
    }
};

int main(int argc, char *argv[])
{
    int inputCount;

    freopen("lab4_input.txt", "r", stdin);
    LinearRegression linear_regression;

    std::cin >> inputCount;

    linear_regression.readInput(inputCount);
    linear_regression.calculateLinear();

    std::cout << "B0 = " << linear_regression.returnB0() << std::endl;
    std::cout << "B1 = " << linear_regression.returnB1() << std::endl;

    return 0;
}