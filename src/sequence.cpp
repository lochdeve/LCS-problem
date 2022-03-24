#include "../include/sequence.h"

Sequence::Sequence(std::string sequence) { sequence_ = sequence; }

Sequence::~Sequence() {}

void Sequence::lcs_length(Sequence& other_sequence) {
  int m = sequence_.size();
  int n = other_sequence.sequence_.size();
  std::vector<std::vector<int>> matriz(m + 1);
  for (size_t i = 0; i <= matriz.size(); i++) {
    matriz[i].resize(n + 1);
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (sequence_[i - 1] == other_sequence.sequence_[j - 1]) {
        matriz[i][j] = matriz[i - 1][j - 1] + 1;
      } else {
        matriz[i][j] = std::max(matriz[i - 1][j], matriz[i][j - 1]);
      }
    }
  }
  construir(matriz, m, n, other_sequence);
}

void Sequence::construir(std::vector<std::vector<int>>& matriz, int m, int n,
                         Sequence& other_sequence) {
  std::string subsequence = "";

  int i = m;
  int j = n;
  std::vector<std::pair<std::pair<int, int>, std::string>> pair;
  std::vector<std::string> subsequences;
  pair.push_back(std::pair<std::pair<int, int>, std::string>(
      std::pair<int, int>(m, n), subsequence));
  while (pair.size() != 0) {
    i = pair[0].first.first;
    j = pair[0].first.second;
    subsequence = pair[0].second;
    while (i > 0 && j > 0) {
      if (matriz[i - 1][j] == matriz[i][j]) {
        if (matriz[i][j - 1] == matriz[i][j]) {
          pair.push_back(std::pair<std::pair<int, int>, std::string>(
              std::pair<int, int>(i, j - 1), subsequence));
        }
        i--;
      } else if (matriz[i][j - 1] == matriz[i][j]) {
        j--;
      } else {
        subsequence = sequence_[i - 1] + subsequence;
        i--;
        j--;
      }
    }
    std::vector<std::string>::iterator it;
    it = std::find(subsequences.begin(), subsequences.end(), subsequence);
    bool exist = false;
    for (size_t i = 0; i < subsequences.size() && !exist; i++) {
      if (subsequences[i] == subsequence) {
        exist = true;
      }
    }

    if (!exist) {
      subsequences.push_back(subsequence);
    }

    pair.erase(pair.begin());
  }

  std::cout << "La secuencia 1: " << sequence_ << std::endl;
  std::cout << "La secuencia 2: " << other_sequence.sequence_ << std::endl;
  for (size_t i = 0; i < subsequences.size(); i++) {
    std::cout << "Subsecuencia " << i + 1 << ": " << subsequences[i]
              << " con una longitud de " << subsequences[i].size() << std::endl;
  }
}

/* void Sequence::construir(std::vector<std::vector<int>> matriz, int m, int n,
                         Sequence& other_sequence) {
  int index = matriz[m][n];
  char lcsAlgo[index + 1];
  int longitud = index;
  lcsAlgo[index] = '\0';

  int i = m;
  int j = n;
  while (i > 0 && j > 0) {
    if (sequence_[i - 1] == other_sequence.sequence_[j - 1]) {
      lcsAlgo[index - 1] = sequence_[i - 1];
      i--;
      j--;
      index--;
    } else if (matriz[i - 1][j] > matriz[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  std::cout << "La secuencia 1: " << sequence_ << std::endl;
  std::cout << "La secuencia 2: " << other_sequence.sequence_ << std::endl;
  std::cout << "La subsecuencia mas larga es " << lcsAlgo
            << " con una longitud de " << longitud << std::endl;
} */
