#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX_DATA_SET 100

// read elements function
// read all values separeted by space and calculate mean
std::vector<float> readElements(std::ifstream &fin, int dataset_count)
{
    std::vector<float> dataset(0);
    float num = 0;
    for (int i = 0; i < dataset_count; i++)
    {
        if (fin.eof())
        {
            std::cout << "EOF reached. Please ensure your input matches to the actual size of data set in the file" << std::endl;
            exit(1);
        }

        fin >> num;
        // std::cout << num;
        dataset.push_back(num);
    }

    return dataset;
}

// sorting function
std::vector<float> sortDataset(std::vector<float> dataset)
{
    std::sort(dataset.begin(), dataset.end());
    return dataset;
}

// average function
float datasetAvg(std::vector<float> dataset_sorted)
{
    float dataset_avg = 0;
    for (int i = 0; i < dataset_sorted.size(); i++)
    {
        dataset_avg += dataset_sorted[i];
    }
    dataset_avg = dataset_avg / dataset_sorted.size();

    return dataset_avg;
}

// median function
float datasetMedian(std::vector<float> dataset_sorted)
{
    int dataset_size = dataset_sorted.size();
    if (dataset_size % 2 == 0)
    {
        return (dataset_sorted[dataset_size / 2 - 1] + dataset_sorted[dataset_size / 2]) / 2;
    }

    return dataset_sorted[(dataset_size - 1) / 2];
}

// standard deviation function
float datasetSD(std::vector<float> dataset_sorted, float dataset_avg)
{
    int dataset_size = dataset_sorted.size();
    float sd;
    for (int i = 0; i < dataset_size; i++)
    {
        sd += pow(fabs(dataset_avg - dataset_sorted[i]), 2);
    }
    sd = sd / (dataset_size - 1);
    sd = pow(sd, 0.5);

    return sd;
}

// print alll vaules function
void printStatistics(float dataset_avg, float dataset_sd, float dataset_median)
{
    std::cout << "The average in the dataset is: " << dataset_avg << std::endl;
    std::cout << "The standard deviation in the dataset is: " << dataset_sd << std::endl;
    std::cout << "The median in the dataset is: " << dataset_median << std::endl;
}

int main(int argc, char *argv[])
{
    // take stdin input for number of elements in the data set
    int dataset_count = 0;
    std::cout << "Enter the size of data set in 'input.txt(upto 100)'" << std::endl;
    std::cin >> dataset_count;

    // input sanitation
    if (dataset_count > MAX_DATA_SET)
    {
        std::cout << "The size of the data set cannot be greater than 100" << std::endl;
        return 1;
    }
    if (dataset_count <= 1)
    {
        std::cout << "The size of the data set cannot be less than or equal to 1" << std::endl;
        return 1;
    }

    std::ifstream fin;
    fin.open("input.txt");

    if (!fin)
    {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    // allocate memory to store all the numbers
    std::vector<float> dataset = readElements(fin, dataset_count);

    // sort all elements
    std::vector<float> dataset_sorted = sortDataset(dataset);
    // for (int i = 0; i < dataset_sorted.size(); i++)
    // {
    //     std::cout << dataset_sorted[i] << std::endl;
    // }

    // calculate average
    float dataset_avg = datasetAvg(dataset_sorted);

    // calculate median
    float dataset_median = datasetMedian(dataset_sorted);

    // calculate standard deviation
    float dataset_sd = datasetSD(dataset_sorted, dataset_avg);

    // print all values
    printStatistics(dataset_avg, dataset_sd, dataset_median);

    fin.close();
    return 0;
}