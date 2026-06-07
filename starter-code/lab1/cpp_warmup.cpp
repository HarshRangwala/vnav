
/* This is a simple C++ program */
/** #include <iostream>
void reset(int &i) {
    i = 0;
    }

int main() {
    int j = 42;
    reset(j);
    std::cout << j << std::endl;
    return 0;
}

/** int main() {
    int i = 0, j;
    j = ++i;
    j = i++;
    std::cout << "i: " << i << ", j: " << j << std::endl; 

    int i = 42;
    std::string output = (i < 42) ? "a" : "b";
    std::cout << output << std::endl; 

    int i;
    int& ri = i;
    i = 5;
    ri = 10;
    std::cout << i << " " << ri << std::endl; 

    int i = 42;
    int* j = &i;
    *j = *j**j;
    std::cout << *j << std::endl;

    int i[4] = {42,24,42,24};
    *(i+2) = *(i+1)-i[3];
    std::cout << *(i+2) << std::endl; 




    return 0;
} **/
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
}
