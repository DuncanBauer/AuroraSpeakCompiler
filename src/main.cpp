#include "Compiler.hpp"

int main(int argc, char** argv)
{
  std::cout << *argv << '\n';
  
  Compiler compiler;
  compiler.run();
  
  return 0;
}