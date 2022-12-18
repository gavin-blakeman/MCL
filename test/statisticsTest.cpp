#include <MCL>

#include <fstream>
#include <iostream>
#include <sstream>
#include <valarray>
#include <vector>

  // Boost library headers

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

int main(int argc, char** args)
{
  std::ifstream ifs;  
  std::valarray<long> data;
  std::vector<long> inputData;
  std::string const ifn("data.csv");
  double mean, variance, stdev;
  double meanC, varianceC, stdevC;
  std::string dataLine;
  long index;

  MCL::maxThreads = 8;

  ifs.open(ifn);

  if (ifs)
  {
    std::getline(ifs, dataLine);
    boost::trim(dataLine);
    mean = boost::lexical_cast<double>(dataLine);

    std::getline(ifs, dataLine);
    boost::trim(dataLine);
    variance = boost::lexical_cast<double>(dataLine);

    std::getline(ifs, dataLine);
    boost::trim(dataLine);
    stdev = boost::lexical_cast<double>(dataLine);

    while ( !ifs.eof() )
    {
      std::getline(ifs, dataLine);   // First line of file is headers
      
      if (dataLine.size() > 0)
      {
        boost::trim(dataLine);
        index = boost::lexical_cast<long>(dataLine);
        inputData.push_back(index);
      };
    };

      // Copy the data to the valarray.

    data.resize(inputData.size());
    for (index = 0; index < inputData.size(); index++)
      data[index] = inputData[index];

    meanC = *MCL::mean(data);
    varianceC = *MCL::variance(data);
    stdevC = *MCL::stdev(data);

    std::cout.precision(20);
    std::cout << "Mean: " << mean << " Calculated mean: " << meanC << std::endl;
    std::cout << "Variance: " << variance << " Calculated variance: " << varianceC << std::endl;
    std::cout << "StDev: " << stdev << " Calculated StDev: " << stdevC << std::endl;

    ifs.close();
  }
  else
    std::cout << "Cannot open data file." << std::endl;

};