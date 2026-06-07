#include "random_vector.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
// TODO: add any include you might require

RandomVector::RandomVector(int size, double max_val) { 
  // TODO: Write your code here
  srand(time(0));
  this->vect.resize(size);
  for(size_t i = 0; i < vect.size(); i++) {
    this->vect[i] = (static_cast<double>(rand())/RAND_MAX) * max_val;
  }
}

void RandomVector::print(){
  // TODO: Write your code here
  for(size_t i = 0; i<vect.size(); i++) {
    std::cout<<vect[i] <<" ";
  }
  std::cout<<std::endl;
}

double RandomVector::mean(){
  // TODO: Write your code here
  double sum = 0;
  for (size_t i = 0; i < vect.size(); i++) {
    sum += vect[i];
  }
  return sum / vect.size();
}

double RandomVector::max(){
  // TODO: Write your code here
  double result = vect[0]; //assume first result is max
  for(size_t i = 1; i<vect.size(); i++) {
    if (vect[i] > result) {
    result = vect[i];
    }
  }
  return result;
}

double RandomVector::min(){
  //TODO:  Write your code here
  double result = vect[0];
  for (size_t i = 0; i < vect.size(); i++) {
    if (vect[i] < result) {
        result = vect[i];
    }
  }
  return result;
}

void RandomVector::printHistogram(int bins){
  // TODO: Write your code here
  double mn = min(); // 10
  double mx = max(); // 20
  std::vector<int> counts(bins, 0);
  double range = mx - mn; //10
  double bin_width = range / bins; // 10 / 5 = 2
  for (size_t i = 0; i < vect.size(); i++) { 
    int binIndex = static_cast<int>((vect[i] - mn) / bin_width);
    
    if (binIndex >= bins) {
      binIndex = bins - 1;
    }

    counts[binIndex]++;
  }

  int maxCount = counts[0];
  for (int i = 1; i < bins; i++) {
      if (counts[i] > maxCount) maxCount = counts[i];
  }

  // Print row by row from top to bottom
  for (int row = maxCount; row >= 1; row--) { // print maxCOunt amount of rows
      for (int i = 0; i < bins; i++) { // column limit
          if (counts[i] >= row) { 
              std::cout << "***";  // this bin reaches this row
          } else {
              std::cout << "   ";  // empty space
          }
          std::cout << " ";  // space between bins
      }
      std::cout << std::endl;
  }

}
