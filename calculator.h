#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include "boolean.h"

#define Nil -999
#define ValidInput '0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9'|'+'|'-'|'*'|'/'|'^'|'('|')'|'.'|' '
#define Operator '+'|'-'|'*'|'/'|'^'

// PREDIKAT
boolean IsDigit(char X);
// Mengecek apakah karakter tersebut adalah titik
boolean IsOperator(char X);
// Mengecek apakah karakter tersebut adalah operator
boolean IsPlusMin (char X);
// Mengecek apakah karakter tersebut '+' atau '-'
boolean IsTimeDivide (char X);
// Mengecek apakah karakter tersebut '*' atau '/'
boolean IsPower (char X);
// Mengecek apakah karakter tersebut '^'
boolean IsBukaKurung (char X);
// Mengecek apakah karakter tersebut '('
boolean IsTutupKurung (char X);
// Mengecek apakah karakter tersebut '}'
boolean IsNegatif (char X);
// Mengecek apakah karakter tersebut '-'
boolean IsPoint (char X);
// Mengecek apakah karakter tersebut '.'
boolean IsEnd (char X);
// Mengecek apakah karakter tersebut '\0'
boolean IsStillValid (char *str, int *idx);
// Mengecek apakah karakter tersebut masih valid

// OPERATOR
void Count (char *str, int *idx, float *returnValue, boolean *valid);
// Menghitung banyaknya input
void CreateNumber (char *str, int *idx, float *returnValue, boolean *valid);
// Mengembalikan angka yang dimiliki dari serian angka

#endif
