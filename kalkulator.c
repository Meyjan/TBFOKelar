#include <stdio.h>
#include <math.h>
#include <string.h>
#include "boolean.h"

#define Fail -99999
#define MathError -99998
char *now;

// List perintah
boolean IsDigit(char c);
float charTofloat(char c);
boolean FailedInput(float x);
float checksign();
float digit();
float plusminus();
float timesdiv();
float brackets();
float power();
float executePower(float x);

// Implementasi perintah-perintah

boolean IsDigit(char c)
// Mengembalikan nilai true jika char tersebut adalah digit
{
  return (c >= '0' && c <= '9');
}

float charTofloat(char c)
// Mengganti karkater ke float
{
  return (c - '0');
}

boolean FailedInput(float x)
// Memberikan nilai true jika x adalah Fail
{
  return (x == Fail);
}

float checksign()
// Mengecek apakah digit tersebut memiliki nilai negatif, tanda kurung
// atau hanya bilangan biasa saja
{
  float checker;

  if (*now == '-')
  {
    now++;
    checker = digit();
    if (checker != Fail)
    {
      return ((-1) * checker);
    }
    else
    {
      return (Fail);
    }
  }
  else if (*now == '(')
  {
    now++;
    return (brackets());
  }
  else
  {
    return (digit());
  }
}

float digit ()
// Menghasilkan digit angka pada bilangan
{
  float temp = 0;
  if (IsDigit(*now))
  {
    while (IsDigit(*now))
    {
      temp = (temp*10) + charTofloat(*now);
      now++;
    }
    if (*now == '.')
    {
      now++;
      float multiplier = 0.1;
      if (!IsDigit(*now))
      {
        return (Fail);
      }
      else
      {
        while (IsDigit(*now))
        {
          temp = temp + charTofloat(*now)*multiplier;
          multiplier /= 10;
          now++;
        }
      }
    }
    return (temp);
  }
  else
  {
    printf("Invalid input. Input not digits\n");
    return (Fail);
  }
}

float plusminus ()
// Menghasilkan hasil penjumlahan dan pengurangan
{
  float x = timesdiv();
  if (FailedInput(x))
  {
    return (Fail);
  }
  else
  {
    while (*now == '+' || *now == '-')
    {
      char opr = *now;
      now++;
      float y = timesdiv();
      if (FailedInput(y))
      {
        return (Fail);
      }
      if (opr == '+')
      {
        x += y;
      }
      else
      {
        x -= y;
      }
    }
    return x;
  }
}

float timesdiv ()
// Menghasilkan hasil perkalian dan pembagian
{
  float x = power();
  if (FailedInput(x))
  {
    return (Fail);
  }
  while (*now == '*' || *now == '/')
  {
    char opr = *now;
    now++;
    float y = power();
    if (FailedInput(y))
    {
      return (Fail);
    }
    if (opr == '*')
    {
      x *= y;
    }
    else
    {
      x /= y;
    }
  }
  return x;
}

float brackets ()
// Menghasilkan hasil dari tanda kurung jika berhasil
{
  float res = plusminus();
  if (*now != ')')
  {
    return Fail;
  }
  else
  {
    now++;
    return res;
  }
}

float power ()
// Mengembalikan hasil perpangkatan dari sebuah bilangan
{
  float x = checksign();
  if (*now == '^' && x != Fail)
  {
    now++;
    x = executePower(x);
  }
  return (x);
}

float executePower (float x)
// Membantu perpangkatan dengan pemanggilan rekursif
{
  float y = checksign();
  if (y == Fail)          // Basis
  {
    return (Fail);
  }
  else if (*now != '^')   // Basis
  {
    return (pow(x,y));
  }
  else                    // Rekurens
  {
    now++;
    float z = executePower(y);
    if (z != Fail)
    {
      return (pow(x,z));
    }
    else
    {
      return (Fail);
    }
  }
}

int main ()
{
  char input[50];
  printf("Masukkan operasi yang ingin dilakukan!\n");
  scanf ("%s", input);
  now = input;

  float count = plusminus();
  if (count == Fail || *now != '\0')
  {
    printf("Failed input\n");
  }
  else
  {
    printf("Result = %.2f", count);
  }
  return 0;
}
