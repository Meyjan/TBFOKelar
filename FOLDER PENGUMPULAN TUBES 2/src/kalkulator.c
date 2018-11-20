#include <stdio.h>
#include <math.h>
#include "boolean.h"

// Asumsi hasil tidak mencapai Fail dan MathError
#define Fail -9999999

char *now;
char *start;
boolean syntaxerror;
boolean matherror;

// List perintah
boolean IsDigit(char c);
float charTofloat(char c);
boolean FailedInput();
boolean CanBeInteger(float x);

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

boolean FailedInput()
// Memberikan nilai true jika x adalah Fail
{
  return (syntaxerror || matherror);
}

boolean CanBeInteger(float x)
// Memberikan nilai true jika x dapat diconvert menjadi integer
{
  return (ceil(x) == x);
}

float checksign()
// Mengecek apakah digit tersebut memiliki nilai negatif, tanda kurung
// atau hanya bilangan biasa saja
{
  float checker;

  if (*now == '-')
  {
    if (now == start)
    {
      now++;
      checker = digit();
    }
    else
    {
      now--;
      if (*now == '(')
      {
        now++;now++;
        checker = digit();
      }
      else
      {
        checker = Fail;
        syntaxerror = true;
      }
    }
    if (!FailedInput())
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
        syntaxerror = true;
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
    syntaxerror = true;
    return (Fail);
  }
}

float plusminus ()
// Menghasilkan hasil penjumlahan dan pengurangan
{
  float x = timesdiv();
  if (FailedInput())
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
      if (FailedInput())
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
  if (FailedInput())
  {
    return (Fail);
  }
  while (*now == '*' || *now == '/')
  {
    char opr = *now;
    now++;
    float y = power();
    if (FailedInput())
    {
      return (Fail);
    }
    if (opr == '*')
    {
      x *= y;
    }
    else
    {
      if (y == 0)
      {
        matherror = true;
        return (Fail);
      }
      else
      {
        x /= y;
      }
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
    syntaxerror = true;
    return (Fail);
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
  if (*now == '^' && !FailedInput())
  {
    now++;
    x = executePower(x);
  }
  if (FailedInput())
  {
    return (Fail);
  }
  else
  {
    return (x);
  }
}

float executePower (float x)
// Membantu perpangkatan dengan pemanggilan rekursif
{
  float y = checksign();
  if (FailedInput())          // Basis
  {
    return (y);
  }
  else if (*now != '^')   // Basis
  {
    float a=pow(x,y);
    if (isnan(a)){
      matherror = true;
      return (Fail);
    }
    else{
      return (a);
    }
  }
  else                    // Rekurens
  {
    now++;
    float z = executePower(y);
    if (!FailedInput())
    {
      float b=pow(x,z);
      if (isnan(b)){
        matherror = true;
        return (Fail);
      }
      else{
        return (b);
      }
    }
    else
    {
      return (Fail);
    }
  }
}

void utama ()
{
  int choice;
  char input[50];

  printf("Pilihan Menu\n1. Calculator\n2. Quit\n");
  scanf("%d", &choice);

  while(choice != 2)
  {
    if (choice == 1)
    {
      printf("Masukkan operasi yang ingin dilakukan!\n");
      scanf ("%s", input);
      now = input;
      start = input;
      syntaxerror = false;
      matherror = false;
      float count = plusminus();

      if (syntaxerror || *now != '\0')
      {
        printf("Syntax error\n");
      }
      else if (matherror)
      {
        printf("Math error\n");
      }
      else
      {
        printf("Result = %.2f\n", count);
      }
    }
    else
    {
      printf("Input tidak dikenal\n");
    }
    printf("Pilihan Menu\n1. Calculator\n2. Quit\n");
    scanf("%d", &choice);
  }
}
