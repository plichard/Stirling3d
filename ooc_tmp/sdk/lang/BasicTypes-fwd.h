/* lang.BasicTypes header file, generated with ooc */
#ifndef ___lang_BasicTypes__fwd__
#define ___lang_BasicTypes__fwd__


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
typedef void lang__Void;
typedef void *lang__Pointer;
typedef char lang__Char;
typedef unsigned char lang__UChar;
typedef wchar_t lang__WChar;
typedef char *lang__String;
typedef long long lang__LLong;
typedef int lang__Int;
typedef unsigned int lang__UInt;
typedef short lang__Short;
typedef unsigned short lang__UShort;
typedef long lang__Long;
typedef unsigned long lang__ULong;
typedef unsigned long long lang__ULLong;
typedef int8_t lang__Int8;
typedef int16_t lang__Int16;
typedef int32_t lang__Int32;
typedef int64_t lang__Int64;
typedef uint8_t lang__UInt8;
typedef uint16_t lang__UInt16;
typedef uint32_t lang__UInt32;
typedef uint64_t lang__UInt64;
typedef uint8_t lang__Octet;
typedef size_t lang__SizeT;
typedef bool lang__Bool;
typedef float lang__Float;
typedef long double lang__LDouble;
typedef double lang__Double;
typedef struct _lang__Range lang__Range;
struct _lang__Class;
typedef struct _lang__Class lang__Class;
struct _lang__ClassClass;
typedef struct _lang__ClassClass lang__ClassClass;
struct _lang__Object;
typedef struct _lang__Object lang__Object;
struct _lang__ObjectClass;
typedef struct _lang__ObjectClass lang__ObjectClass;
struct _lang__Iterator;
typedef struct _lang__Iterator lang__Iterator;
struct _lang__IteratorClass;
typedef struct _lang__IteratorClass lang__IteratorClass;
struct _lang__Iterable;
typedef struct _lang__Iterable lang__Iterable;
struct _lang__IterableClass;
typedef struct _lang__IterableClass lang__IterableClass;
struct _lang__Interface;
typedef struct _lang__Interface lang__Interface;
struct _lang__InterfaceClass;
typedef struct _lang__InterfaceClass lang__InterfaceClass;
struct _lang__Exception;
typedef struct _lang__Exception lang__Exception;
struct _lang__ExceptionClass;
typedef struct _lang__ExceptionClass lang__ExceptionClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
lang__Class *Pointer_class();
lang__Class *Char_class();
bool Char_isAlphaNumeric(char this);
bool Char_isAlpha(char this);
bool Char_isDigit(char this);
bool Char_isWhitespace(char this);
char Char_toLower(char this);
int Char_toInt(char this);
void Char_print(char this);
void Char_println(char this);
lang__Class *UChar_class();
lang__Class *WChar_class();
lang__Class *String_class();
char *String_new(size_t length);
#ifndef String_length
#define String_length strlen
#endif

bool String_equals(char *this, char *other);
#ifndef String_toInt
#define String_toInt atoi
#endif

#ifndef String_toLong
#define String_toLong atol
#endif

#ifndef String_toLLong
#define String_toLLong atoll
#endif

#ifndef String_toDouble
#define String_toDouble atof
#endif

#ifndef String_toFloat
#define String_toFloat atof
#endif

bool String_isEmpty(char *this);
bool String_startsWith(char *this, char *s);
bool String_endsWith(char *this, char *s);
size_t String_indexOf(char *this, char c);
bool String_contains(char *this, char c);
char *String_trim_space(char *this);
char *String_trim(char *this, char c);
size_t String_first(char *this);
size_t String_lastIndex(char *this);
char String_last(char *this);
size_t String_lastIndexOf(char *this, char c);
char *String_substring_tillEnd(char *this, size_t start);
char *String_substring(char *this, size_t start, size_t end);
char *String_reverse(char *this);
void String_print(char *this);
void String_println(char *this);
char *String_times(char *this, int count);
char *String_clone(char *this);
char *String_append(char *this, char *other);
char *String_append_char(char *this, char other);
char *String_replace(char *this, char oldie, char kiddo);
char *String_prepend(char *this, char *other);
char *String_prepend_char(char *this, char other);
char *String_toLower(char *this);
char *String_toUpper(char *this);
char String_charAt(char *this, size_t index);
lang__Class *LLong_class();
char *LLong_toString(long long this);
char *LLong_toHexString(long long this);
bool LLong_isOdd(long long this);
bool LLong_isEven(long long this);
bool LLong_in(long long this, lang__Range range);
lang__Class *Int_class();
char *Int_toString(int this);
bool Int_isOdd(int this);
bool Int_isEven(int this);
bool Int_in(int this, lang__Range range);
lang__Class *UInt_class();
lang__Class *Short_class();
lang__Class *UShort_class();
lang__Class *Long_class();
lang__Class *ULong_class();
lang__Class *ULLong_class();
lang__Class *Int8_class();
lang__Class *Int16_class();
lang__Class *Int32_class();
lang__Class *Int64_class();
lang__Class *UInt8_class();
lang__Class *UInt16_class();
lang__Class *UInt32_class();
lang__Class *UInt64_class();
lang__Class *Octet_class();
lang__Class *SizeT_class();
lang__Class *Bool_class();
char *Bool_toString(bool this);
lang__Class *Float_class();
lang__Class *LDouble_class();
lang__Class *Double_class();
char *Double_toString(double this);
double Double_abs(double this);
lang__Class *Range_class();
lang__Range Range_new(int min, int max);
lang__Class *Class_class();

void Class___load__();
void Class___defaults__(struct _lang__Class *this);
void Class___defaults___impl(struct _lang__Class *this);
void Class___destroy__(struct _lang__Class *this);
void Class___destroy___impl(struct _lang__Class *this);
struct _lang__Object *Class_alloc(struct _lang__Class *this);
bool Class_instanceof(struct _lang__Class *this, struct _lang__Class *T);

lang__Class *Object_class();

void Object___load__();
void Object___defaults__(struct _lang__Object *this);
void Object___defaults___impl(struct _lang__Object *this);
void Object___destroy__(struct _lang__Object *this);
void Object___destroy___impl(struct _lang__Object *this);

lang__Class *Iterator_class();

void Iterator___load__();
void Iterator___defaults__(struct _lang__Iterator *this);
void Iterator___defaults___impl(struct _lang__Iterator *this);
void Iterator___destroy__(struct _lang__Iterator *this);
void Iterator___destroy___impl(struct _lang__Iterator *this);
bool Iterator_hasNext(struct _lang__Iterator *this);
void Iterator_next(struct _lang__Iterator *this, void *__returnArg);

lang__Class *Iterable_class();

void Iterable___load__();
void Iterable___defaults__(struct _lang__Iterable *this);
void Iterable___defaults___impl(struct _lang__Iterable *this);
void Iterable___destroy__(struct _lang__Iterable *this);
void Iterable___destroy___impl(struct _lang__Iterable *this);
struct _lang__Iterator *Iterable_iterator(struct _lang__Iterable *this);

lang__Class *Interface_class();

void Interface___load__();
void Interface___defaults__(struct _lang__Interface *this);
void Interface___defaults___impl(struct _lang__Interface *this);
void Interface___destroy__(struct _lang__Interface *this);
void Interface___destroy___impl(struct _lang__Interface *this);
struct _lang__Interface *Interface_new(struct _lang__Object *realThis, struct _lang__Object *funcs);
void Interface_init(struct _lang__Interface *this, struct _lang__Object *realThis, struct _lang__Object *funcs);
void Interface_init_impl(struct _lang__Interface *this, struct _lang__Object *realThis, struct _lang__Object *funcs);

lang__Class *Exception_class();

void Exception___load__();
void Exception___defaults__(struct _lang__Exception *this);
void Exception___defaults___impl(struct _lang__Exception *this);
void Exception___destroy__(struct _lang__Exception *this);
void Exception___destroy___impl(struct _lang__Exception *this);
struct _lang__Exception *Exception_new(struct _lang__Class *origin, char *msg);
void Exception_init(struct _lang__Exception *this, struct _lang__Class *origin, char *msg);
void Exception_init_impl(struct _lang__Exception *this, struct _lang__Class *origin, char *msg);
struct _lang__Exception *Exception_new_noOrigin(char *msg);
void Exception_init_noOrigin(struct _lang__Exception *this, char *msg);
void Exception_init_noOrigin_impl(struct _lang__Exception *this, char *msg);
void Exception_crash(struct _lang__Exception *this);
void Exception_crash_impl(struct _lang__Exception *this);
char *Exception_getMessage(struct _lang__Exception *this);
char *Exception_getMessage_impl(struct _lang__Exception *this);
void Exception_print(struct _lang__Exception *this);
void Exception_print_impl(struct _lang__Exception *this);
void Exception_throw(struct _lang__Exception *this);
void Exception_throw_impl(struct _lang__Exception *this);

bool __OP_EQ_String_String__Bool(char *str1, char *str2);
char __OP_IDX_String_SizeT__Char(char *string, size_t index);
char *__OP_MUL_String_Int__String(char *str, int count);
char *__OP_ADD_String_String__String(char *left, char *right);
char *__OP_ADD_LLong_String__String(long long left, char *right);
char *__OP_ADD_String_LLong__String(char *left, long long right);
char *__OP_ADD_Int_String__String(int left, char *right);
char *__OP_ADD_String_Int__String(char *left, int right);
char *__OP_ADD_Bool_String__String(bool left, char *right);
char *__OP_ADD_String_Bool__String(char *left, bool right);
char *__OP_ADD_Double_String__String(double left, char *right);
char *__OP_ADD_String_Double__String(char *left, double right);
char *__OP_ADD_String_Char__String(char *left, char right);
char *__OP_ADD_Char_String__String(char left, char *right);

#endif // ___lang_BasicTypes__fwd__

