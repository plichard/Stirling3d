/* lang.stdio header file, generated with ooc */
#ifndef ___lang_stdio__fwd__
#define ___lang_stdio__fwd__


#include <stdio.h>
typedef FILE *lang__FStream;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <sdk/lang/BasicTypes.h>
lang__Class *FILE_class();
lang__Class *FStream_class();
char FStream_readChar(FILE *this);
char *FStream_readLine(FILE *this);
bool FStream_hasNext(FILE *this);
void FStream_write_chr(FILE *this, char chr);
void FStream_write(FILE *this, char *str);
size_t FStream_write_precise(FILE *this, char *str, size_t offset, size_t length);
void println_withStr(char *str);
void println();

#endif // ___lang_stdio__fwd__

