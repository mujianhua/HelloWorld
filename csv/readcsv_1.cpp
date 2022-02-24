#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main() {
  string line, number;
  ifstream f("/home/mujianhua/cppLearning/csv/data.csv", ifstream::in);
  if (f.fail()) {
    cout << "Cannot open file" << endl;
    return -1;
  }
  std::vector<float> v1;
  while (std::getline(f, line)) {
    istringstream is(line);
    for (int i = 0; i < 3; ++i) {
      std::getline(is, number, ',');
      v1.push_back(atof(number.c_str()));
    }
  }
  for (int i = 0; i < 9; ++i) {
    cout << v1[i] << '\n';
  }
}
