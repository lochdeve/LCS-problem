
#include <iostream>

#include "../include/sequence.h"

int main() {
  Sequence primera("hello how are you i'm good");
  Sequence segunda("how are yo");
  primera.lcs_length(segunda);
  return 0;
}