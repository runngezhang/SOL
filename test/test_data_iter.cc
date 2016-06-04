/*********************************************************************************
*     File Name           :     test_data_iter.cc
*     Created By          :     yuewu
*     Creation Date       :     [2016-02-12 18:11]
*     Last Modified       :     [2016-02-12 23:49]
*     Description         :
**********************************************************************************/

#include <string>
#include <cstdlib>
#include <iostream>

#include "lsol/pario/data_iter.h"

using namespace lsol;
using namespace lsol::pario;
using namespace std;

int main(int argc, char** argv) {
  string path = "data/a1a";
  string dtype = "svm";
  if (argc == 3) {
    path = argv[1];
    dtype = argv[2];
  }

  DataIter iter;
  iter.AddReader(path, dtype);

  MiniBatch* mb = nullptr;
  while (true) {
    mb = iter.Next(mb);
    if (mb == nullptr) break;

    fprintf(stdout, "mini-batch size: %d\n", mb->size());
    for (int i = 0; i < mb->size(); ++i) {
      DataPoint& dp = (*mb)[i];
      fprintf(stdout, "%d", dp.label());
      for (size_t d = 0; d < dp.size(); ++d) {
        fprintf(stdout, " %d:%f", dp.indexes(d), dp.features(d));
      }
      fprintf(stdout, "\n");
    }
  }
  return 0;
}
