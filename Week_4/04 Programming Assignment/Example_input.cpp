//Будем считывать из файлового потока по одной строке и сразу выводить их в стандартный поток вывода.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream input("input.txt");

  string line;
  while (getline(input, line)) {
    cout << line << endl;
  }

  return 0;
}