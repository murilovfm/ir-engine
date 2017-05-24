#include "eliasCoding.hpp"

using namespace std;

void eliasCoding::encode(int num, bool* bitCode){
  if (num == 0){
    bitCode[0] = 0;
    return;
  }
  else if (num == 1){
    bitCode[0] = 1;
    return;
  }
  int n = floor(log2(num));
  int n1 = n+1;
  int n2 = num - pow(2,n);
  // cout << "n2: " << n2 << "\n";
  for (int i=0; i<n; i++){
    bitCode[i] = 1;
  }
  bitCode[n] = 0;
  int ci = n-1;
  for (int i=(n+1); i<=(2*n); i++){
    bitCode[i] = ((n2 & (1 << ci)) != 0);
    ci--;
  }
}

void eliasCoding::decode(int* num, bool* bitCode){
  int n = 0;
  while (bitCode[n] != 0){
    n++;
  }
  int n2 = 0;
  int ci = n-1;
  for (int i=(n+1); i<=(2*n); i++){
    n2 |= ((1 << ci) & bitCode[i]);
    ci--;
  }
  *num = pow(2,n)+n2;
}

// int main(){
//   ifstream f1,f2;
//   f1.open("compressed");
//   f2.open("uncompressed");
//   int num = 5;
//   int n = log2(num);
//   bool bitCode[2*n + 1];
//   code(num, bitCode);
//   for (int i=0; i<(2*n+1); i++) cout  << bitCode[i];
//   int asd;
//   decode(&asd, bitCode);
//   f1.close();
//   f2.close();
//   // cout << "\n" << asd;
//   return 0;
// }
