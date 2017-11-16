#include <iostream>
#include <chrono>

using namespace std;

// here you should implement your own magic checker.
// returns true if the square is magic, false otherwise
//
//                8 1 6    this is
// "816357492" =  3 5 7    a magic
//                4 9 2    square
//
bool check_if_magic(const std::string& square)
{
  if (((square[0] & 1) != 0) || ((square[1] & 1) == 0) || ((square[2] & 1) == 1)
    || ((square[3] & 1) == 0) || ((square[4] & 1) == 0) || ((square[5] & 1) == 0)
    || ((square[6] & 1) != 0) || ((square[7] & 1) == 0) || ((square[8] & 1) == 1))
    return false;
  if(square == "816357492")
    return true;
  if(square == "492357816")
    return true;
  if(square == "618753294")
    return true;
  if(square == "294753618")
    return true;
  if(square == "834159672")
    return true;
  if(square == "672159834")
    return true;
  if(square == "438951276")
    return true;
  if(square == "276951438")
    return true;

  return false;
}

// this generates all possible combinations of 1-9 cyphers
// that may or may not form a magic square
static string buffer = "000000000";
void generate_or_check(int index_or_check = 8){
  if(index_or_check == -1){
    if(check_if_magic(buffer))
      cout << buffer << "\n";
    return;
  }

  for(auto i = 1u; i < 10; ++i){
    buffer[index_or_check] = '0' + i;
    generate_or_check(index_or_check-1);
  }
}

// this runs the generator and measures time
int main()
  {
  auto start = std::chrono::system_clock::now();
  generate_or_check();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> difference = end - start;
  std::cout << difference.count() << "\n";
  }

