#ifndef __Sequence__
#define __Sequence__
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Sequence {
 public:
  Sequence(std::string);
  ~Sequence();
  void lcs_length(Sequence&);
  void construir(std::vector<std::vector<int>>&, int, int, Sequence&);
  void lcs_all(Sequence&);

 private:
  std::string sequence_;
};

#endif