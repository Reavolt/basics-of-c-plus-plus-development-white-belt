// Поскольку функция MoveStrings должна изменить оба переданных вектора, их нужно принять по ссылке.

void MoveStrings(vector<string>& source, vector<string>& destination) {
  for (auto w : source) {
    destination.push_back(w);
  }
  source.clear();
}