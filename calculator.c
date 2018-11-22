#include "calculator.h"
#include <stdio.h>
#include <string.h>

// PREDIKAT
boolean IsDigit(char X)
// Mengecek apakah karakter tersebut adalah titik
{
  // KAMUS LOKAL
  int N;
  // ALGORITMA
  N = X - '0';
  return ((N >= 0) && (N <= 9));
}
boolean IsOperator(char X)
// Mengecek apakah karakter tersebut adalah operator
{
  // KAMUS LOKAL
  // ALGORITMA
  return (X == Operator);
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
<<<<<<< Updated upstream
boolean IsBukaKurung (char X)
// Mengecek apakah karakter tersebut '('
{
  // KAMUS LOKAL
  // ALGORITMA
  return (X == '(');
}
boolean IsTutupKurung (char X)
// Mengecek apakah karakter tersebut '}'
{
  // KAMUS LOKAL
  // ALGORITMA
  return (X == ')');
}
boolean IsNegatif (char X)
// Mengecek apakah karakter tersebut '-'
{
  // KAMUS LOKAL
  // ALGORITMA
  return (X == '-');
}
boolean IsPoint (char X)
// Mengecek apakah karakter tersebut '.'
{
  // KAMUS LOKAL
  // ALGORITMA
  return (X == '.');
}
boolean IsEnd (char X)
// Mengecek apakah karakter tersebut '\0'
{
  // KAMUS LOKAL
  // ALGORITMA
  return (X == '\0');
}
boolean IsStillValid (char *str, int *idx)
// Mengecek apakah karakter tersebut masih valid
{
  // KAMUS LOKAL
  // ALGORITMA
  if (*idx > strlen(str))
  {
    return false;
  }
  else
  {
    return (str[*idx] == ValidInput);
  }
}

// OPERATOR
void Count (char *str, int *idx, float *returnValue, boolean *valid)
// Menghitung hasil dari string input
{
  // KAMUS LOKAL
  float temp;

  // ALGORITMA
  CreateNumber (str, idx, returnValue, valid);
}

void CreateNumber (char *str, int *idx, float *returnValue, boolean *valid)
// Mengembalikan angka yang dimiliki dari serian angka
{
  // KAMUS LOKAL
  float temp, multiplier;

  // ALGRORITMA
  temp = 0;
  while (IsDigit(str[*idx]))
  {
    temp = 10 * temp + (str[*idx] - '0');
    (*idx)++;
  }
  if (IsPoint(str[*idx]))
  {
    (*idx)++;
    if (!IsDigit(str[*idx]))
    {
      *returnValue = Nil;
      *valid = false;
    }
    else
    {
      multiplier = 0.1;
      while (IsDigit(str[*idx]))
      {
        temp += multiplier * (str[*idx] - '0');
        multiplier /= 10;
        (*idx)++;
      }
      if (!IsOperator(str[*idx]) && !IsEnd(str[*idx]))
      {
        *returnValue = Nil;
        *valid = false;
      }
      else
      {
        *returnValue = temp;
      }
    }
  }
  else
  {
    if (!IsOperator(str[*idx]) && !IsEnd(str[*idx]))
    {
      *returnValue = Nil;
      *valid = false;
    }
    else
    {
      *returnValue = temp;
    }
  }
}

int main ()
{
  // KAMUS
  char str[50];
  boolean valid;
  int idx;
  float res;

  // ALGORITMA
  printf("Masukkan string operasi!\n");
  scanf ("%s", str);
  valid = true;
  idx = 0;
  Count(str, &idx, &res, &valid);
  if (valid)
      printf("%.2f",res);
  else
      printf("SINTAKS ERROR");

  return 0;
