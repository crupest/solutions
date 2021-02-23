#include <string>

using std::string;

#include <vector>

class CombinationIterator {
public:
  string chars;
  int char_length;
  int combinationLength;
  bool has_next = true;
  std::vector<int> indices;

  CombinationIterator(string characters, int combinationLength)
      : chars(characters), char_length(characters.size()),
        combinationLength(combinationLength) {
    for (int i = 0; i < combinationLength; i++) {
      indices.push_back(i);
    }
  }

  string next() {
    string result;
    for (auto index : indices) {
      result.push_back(chars[index]);
    }

    int count = 1;
    while (indices[combinationLength - count] == char_length - count) {
      count++;
      if (count > combinationLength) {
        has_next = false;
        return result;
      }
    }

    indices[combinationLength - count] += 1;
    for (int i = combinationLength - count + 1; i < combinationLength; i++) {
      indices[i] = indices[i - 1] + 1;
    }

    return result;
  }

  bool hasNext() {
    return has_next;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */