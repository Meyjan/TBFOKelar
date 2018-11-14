#include "calculator.h"

boolean IsDigit(char X)
// Mengecek apakah karakter tersebut adalah titik
{
  // KAMUS LOKAL
  int N;

  // ALGORITMA
  N = X - '0';
  return ((N >= 0) && (N <= 9));
}

boolean IsPlusMin (char X)
// Mengecek apakah karakter tersebut '+' atau '-'
{
  // KAMUS LOKAL

  // ALGORITMA
  return (X == '+' || X == '-');
}

boolean IsTimeDivide (char X)
// Mengecek apakah karakter tersebut '*' atau '/'
{
  // KAMUS LOKAL

  // ALGORITMA
  return (X == '*' || X == '/');
}

boolean IsPower (char X)
// Mengecek apakah karakter tersebut '^'
{
  // KAMUS LOKAL

  // ALGORITMA
  return (X == '^');
}
