/* ooclib header file, generated with ooc */
#ifndef ___ooclib__
#define ___ooclib__

#include <mango/mangoobject.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>
#include <gc/gc.h>
#include <string.h>

typedef char Char;
typedef Char *String;
typedef int Int;
typedef void *Pointer;
typedef unsigned int UInt;
typedef float Float;
typedef double Double;
typedef long double LDouble;
typedef short Short;
typedef long Long;
typedef unsigned long ULong;
typedef long long LLong;
typedef void Void;
typedef bool Bool;
typedef Pointer Func;
typedef size_t SizeT;
typedef uint8_t Octet;

Int Char_toInt(Char this);
Int String_length(String this);
void println(String str);
void println_empty();
Pointer gc_calloc(SizeT nmemb, SizeT size);
void _ooclib_load();

#endif // ___ooclib__

