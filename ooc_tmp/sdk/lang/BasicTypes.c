/* lang.BasicTypes source file, generated with ooc */
#include "BasicTypes.h"
lang__Class *Pointer_class() {
	#line 7 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 7 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 7 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 7 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Pointer);
		#line 7 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Pointer);
		#line 7 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Pointer";
	}
	#line 7 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *Char_class() {
	#line 23 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 23 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 23 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 23 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Char);
		#line 23 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Char);
		#line 23 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Char";
	}
	#line 23 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


bool Char_isAlphaNumeric(char this) {
	#line 26 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return isalnum(((int) (this)));
}


bool Char_isAlpha(char this) {
	#line 30 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return isalpha(((int) (this)));
}


bool Char_isDigit(char this) {
	#line 34 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return isdigit(((int) (this)));
}


bool Char_isWhitespace(char this) {
	#line 38 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return isspace(((int) (this)));
}


char Char_toLower(char this) {
	#line 42 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return tolower(((int) (this)));
}


int Char_toInt(char this) {
	#line 46 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if ((this >= 48) && (this <= 57)){
		#line 47 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		return (this - 48);
	}
	#line 49 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return 0 - 1;
}


void Char_print(char this) {
	#line 53 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	printf("%c", this);
}


void Char_println(char this) {
	#line 57 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	printf("%c\n", this);
}


lang__Class *UChar_class() {
	#line 13 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 13 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 13 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 13 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__UChar);
		#line 13 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__UChar);
		#line 13 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "UChar";
	}
	#line 13 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *WChar_class() {
	#line 14 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 14 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 14 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 14 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__WChar);
		#line 14 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__WChar);
		#line 14 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "WChar";
	}
	#line 14 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *String_class() {
	#line 64 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 64 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 64 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 64 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Pointer);
		#line 64 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Pointer);
		#line 64 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "String";
	}
	#line 64 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


char *String_new(size_t length) {
	#line 67 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return (void *) gc_malloc(length);
}


bool String_equals(char *this, char *other) {
	#line 73 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if ((this == NULL) || (other == NULL)){
		#line 74 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		return false;
	}
	#line 76 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if ((size_t) String_length(this) != (size_t) String_length(other)){
		#line 77 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		return false;
	}
	#line 79 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	
	{
		#line 79 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		size_t i;
		#line 79 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		for (i = 0; i < (size_t) String_length(other); i++){
			#line 80 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
			if (__OP_IDX_String_SizeT__Char(this, i) != __OP_IDX_String_SizeT__Char(other, i)){
				#line 81 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
				return false;
			}
		}
	};
	#line 84 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return true;
}


bool String_isEmpty(char *this) {
	#line 93 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return (this == NULL) || (__OP_IDX_String_SizeT__Char(this, 0) == 0);
}


bool String_startsWith(char *this, char *s) {
	#line 96 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if ((size_t) String_length(this) < (size_t) String_length(s)){
		#line 96 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		return false;
	}
	#line 97 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	
	{
		#line 97 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		size_t i;
		#line 97 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		for (i = 0; i < (size_t) String_length(s); i++){
			#line 98 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
			if (__OP_IDX_String_SizeT__Char(this, i) != __OP_IDX_String_SizeT__Char(s, i)){
				#line 98 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
				return false;
			}
		}
	};
	#line 100 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return true;
}


bool String_endsWith(char *this, char *s) {
	#line 104 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t l1 = (size_t) String_length(this);
	#line 105 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t l2 = (size_t) String_length(s);
	#line 106 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (l1 < l2){
		#line 106 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		return false;
	}
	#line 107 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t offset = (l1 - l2);
	#line 108 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	
	{
		#line 108 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		size_t i;
		#line 108 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		for (i = 0; i < l2; i++){
			#line 109 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
			if (__OP_IDX_String_SizeT__Char(this, i + offset) != __OP_IDX_String_SizeT__Char(s, i)){
				#line 110 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
				return false;
			}
		}
	};
	#line 113 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return true;
}


size_t String_indexOf(char *this, char c) {
	#line 117 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t length = (size_t) String_length(this);
	#line 118 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	
	{
		#line 118 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		size_t i;
		#line 118 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		for (i = 0; i < length; i++){
			#line 119 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
			if (__OP_IDX_String_SizeT__Char(this, i) == c){
				#line 120 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
				return i;
			}
		}
	};
	#line 123 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return 0 - 1;
}


bool String_contains(char *this, char c) {
	#line 126 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return String_indexOf(this, c) != 0 - 1;
}


char *String_trim_space(char *this) {
	#line 128 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return String_trim(this, ' ');
}


char *String_trim(char *this, char c) {
	#line 131 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	int start = 0;
	#line 132 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	while (__OP_IDX_String_SizeT__Char(this, start) == c){
		#line 132 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		start += 1;
	}
	#line 133 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t end = (size_t) String_length(this);
	#line 134 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	while (__OP_IDX_String_SizeT__Char(this, end - 1) == c){
		#line 134 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		end -= 1;
	}
	#line 135 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (start != 0 || end != (size_t) String_length(this)){
		#line 135 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		return String_substring(this, start, end);
	}
	#line 136 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this;
}


size_t String_first(char *this) {
	#line 140 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return __OP_IDX_String_SizeT__Char(this, 0);
}


size_t String_lastIndex(char *this) {
	#line 144 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return (size_t) String_length(this) - 1;
}


char String_last(char *this) {
	#line 148 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return __OP_IDX_String_SizeT__Char(this, String_lastIndex(this));
}


size_t String_lastIndexOf(char *this, char c) {
	#line 153 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t i = (size_t) String_length(this);
	#line 154 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	while (i){
		#line 155 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		if (__OP_IDX_String_SizeT__Char(this, i) == c){
			#line 156 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
			return i;
		}
		#line 158 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		i -= 1;
	}
	#line 160 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return 0 - 1;
}


char *String_substring_tillEnd(char *this, size_t start) {
	#line 164 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t len = (size_t) String_length(this);
	#line 166 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (start > len){
		#line 167 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		printf("String.substring~tillEnd: out of bounds: length = %zd, start = %zd\n", len, start);
		#line 169 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		return NULL;
	}
	#line 172 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t diff = (len - start);
	#line 173 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *sub = ((char *) ((void *) gc_malloc(diff + 1)));
	#line 174 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	sub[diff] = '\0';
	#line 175 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	memcpy(((void *) (sub)), ((void *) (((char *) (this)) + start)), diff);
	#line 176 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return sub;
}


char *String_substring(char *this, size_t start, size_t end) {
	#line 180 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t len = (size_t) String_length(this);
	#line 182 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (start > len || start > end || end > len){
		#line 183 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		printf("String.substring: out of bounds: length = %zd, start = %zd, end = %zd\n", len, start, end);
		#line 185 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		return NULL;
	}
	#line 188 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t diff = (end - start);
	#line 189 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *sub = ((char *) ((void *) gc_malloc(diff + 1)));
	#line 190 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	sub[diff] = 0;
	#line 191 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	memcpy(((void *) (sub)), ((void *) (((char *) (this)) + start)), diff);
	#line 192 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return sub;
}


char *String_reverse(char *this) {
	#line 197 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t len = (size_t) String_length(this);
	#line 199 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (!len){
		#line 200 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		return NULL;
	}
	#line 203 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *result = ((char *) ((void *) gc_malloc(len + 1)));
	#line 204 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	
	{
		#line 204 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		size_t i;
		#line 204 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		for (i = 0; i < len; i++){
			#line 205 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
			result[i] = this[(len - 1) - i];
		}
	};
	#line 207 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	result[len] = 0;
	#line 209 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return result;
}


void String_print(char *this) {
	#line 213 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	printf("%s", this);
	#line 214 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	fflush(stdout);
}


void String_println(char *this) {
	#line 218 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	printf("%s\n", this);
}


char *String_times(char *this, int count) {
	#line 222 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t length = (size_t) String_length(this);
	#line 223 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *result = ((char *) ((void *) gc_malloc((length * count) + 1)));
	#line 224 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	
	{
		#line 224 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		int i;
		#line 224 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		for (i = 0; i < count; i++){
			#line 225 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
			memcpy(((void *) (result + (i * length))), ((void *) (this)), length);
		}
	};
	#line 227 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	result[length * count] = '\0';
	#line 228 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return result;
}


char *String_clone(char *this) {
	#line 232 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t length = (size_t) String_length(this);
	#line 233 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	void *copy = (void *) gc_malloc(length + 1);
	#line 234 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	memcpy(copy, ((void *) (this)), length + 1);
	#line 235 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return copy;
}


char *String_append(char *this, char *other) {
	#line 239 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t length = (size_t) String_length(this);
	#line 240 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t rlength = (size_t) String_length(other);
	#line 241 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *copy = ((char *) ((void *) gc_malloc(length + rlength + 1)));
	#line 242 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	memcpy(((void *) (copy)), ((void *) (this)), length);
	#line 243 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	memcpy(((void *) (copy + length)), ((void *) (other)), rlength + 1);
	#line 244 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return copy;
}


char *String_append_char(char *this, char other) {
	#line 248 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t length = (size_t) String_length(this);
	#line 249 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *copy = ((char *) ((void *) gc_malloc(length + 2)));
	#line 250 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	memcpy(((void *) (copy)), ((void *) (this)), length);
	#line 251 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	copy[length] = other;
	#line 252 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return copy;
}


char *String_replace(char *this, char oldie, char kiddo) {
	#line 256 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t length = (size_t) String_length(this);
	#line 257 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	
	{
		#line 257 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		int i;
		#line 257 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		for (i = 0; i < length; i++){
			#line 258 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
			if (__OP_IDX_String_SizeT__Char(this, i) == oldie){
				#line 258 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
				this[i] = kiddo;
			}
		}
	};
	#line 260 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this;
}


char *String_prepend(char *this, char *other) {
	#line 264 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return String_append(other, this);
}


char *String_prepend_char(char *this, char other) {
	#line 268 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t length = (size_t) String_length(this);
	#line 269 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *copy = ((char *) ((void *) gc_malloc(length + 2)));
	#line 270 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	copy[0] = other;
	#line 271 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	memcpy(((void *) (copy + 1)), ((void *) (this)), length);
	#line 272 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return copy;
}


char *String_toLower(char *this) {
	#line 276 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *copy = String_clone(this);
	#line 277 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t length = (size_t) String_length(this);
	#line 278 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	
	{
		#line 278 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		int i;
		#line 278 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		for (i = 0; i < length; i++){
			#line 279 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
			copy[i] = tolower(((int) (copy[i])));
		}
	};
	#line 281 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return copy;
}


char *String_toUpper(char *this) {
	#line 285 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *copy = String_clone(this);
	#line 286 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	size_t length = (size_t) String_length(this);
	#line 287 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	
	{
		#line 287 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		int i;
		#line 287 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		for (i = 0; i < length; i++){
			#line 288 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
			copy[i] = toupper(((int) (copy[i])));
		}
	};
	#line 290 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return copy;
}


char String_charAt(char *this, size_t index) {
	#line 294 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return ((char *) (this))[index];
}


lang__Class *LLong_class() {
	#line 357 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 357 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 357 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 357 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__LLong);
		#line 357 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__LLong);
		#line 357 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "LLong";
	}
	#line 357 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


char *LLong_toString(long long this) {
	#line 360 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *str = (void *) gc_malloc(((size_t) (64)));
	#line 361 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	sprintf(str, "%lld", this);
	#line 362 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return str;
}


char *LLong_toHexString(long long this) {
	#line 366 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *str = (void *) gc_malloc(((size_t) (64)));
	#line 367 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	sprintf(str, "%llx", this);
	#line 368 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return str;
}


bool LLong_isOdd(long long this) {
	#line 371 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this % 2 == 1;
}


bool LLong_isEven(long long this) {
	#line 372 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this % 2 == 0;
}


bool LLong_in(long long this, lang__Range range) {
	#line 375 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this >= range.min && this < range.max;
}


lang__Class *Int_class() {
	#line 380 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 380 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 380 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 380 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Int);
		#line 380 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Int);
		#line 380 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Int";
	}
	#line 380 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


char *Int_toString(int this) {
	#line 383 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *str = (void *) gc_malloc(((size_t) (64)));
	#line 384 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	sprintf(str, "%d", this);
	#line 385 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return str;
}


bool Int_isOdd(int this) {
	#line 388 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this % 2 == 1;
}


bool Int_isEven(int this) {
	#line 389 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this % 2 == 0;
}


bool Int_in(int this, lang__Range range) {
	#line 392 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this >= range.min && this < range.max;
}


lang__Class *UInt_class() {
	#line 398 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 398 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 398 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 398 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__UInt);
		#line 398 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__UInt);
		#line 398 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "UInt";
	}
	#line 398 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *Short_class() {
	#line 399 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 399 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 399 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 399 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Short);
		#line 399 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Short);
		#line 399 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Short";
	}
	#line 399 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *UShort_class() {
	#line 400 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 400 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 400 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 400 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__UShort);
		#line 400 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__UShort);
		#line 400 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "UShort";
	}
	#line 400 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *Long_class() {
	#line 401 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 401 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 401 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 401 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Long);
		#line 401 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Long);
		#line 401 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Long";
	}
	#line 401 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *ULong_class() {
	#line 402 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 402 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 402 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 402 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__ULong);
		#line 402 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__ULong);
		#line 402 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "ULong";
	}
	#line 402 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *ULLong_class() {
	#line 403 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 403 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 403 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 403 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__ULLong);
		#line 403 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__ULLong);
		#line 403 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "ULLong";
	}
	#line 403 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *Int8_class() {
	#line 408 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 408 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 408 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 408 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Int8);
		#line 408 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Int8);
		#line 408 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Int8";
	}
	#line 408 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *Int16_class() {
	#line 409 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 409 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 409 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 409 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Int16);
		#line 409 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Int16);
		#line 409 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Int16";
	}
	#line 409 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *Int32_class() {
	#line 410 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 410 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 410 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 410 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Int32);
		#line 410 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Int32);
		#line 410 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Int32";
	}
	#line 410 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *Int64_class() {
	#line 411 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 411 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 411 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 411 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Int64);
		#line 411 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Int64);
		#line 411 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Int64";
	}
	#line 411 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *UInt8_class() {
	#line 413 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 413 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 413 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 413 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__UInt8);
		#line 413 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__UInt8);
		#line 413 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "UInt8";
	}
	#line 413 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *UInt16_class() {
	#line 414 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 414 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 414 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 414 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__UInt16);
		#line 414 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__UInt16);
		#line 414 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "UInt16";
	}
	#line 414 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *UInt32_class() {
	#line 415 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 415 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 415 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 415 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__UInt32);
		#line 415 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__UInt32);
		#line 415 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "UInt32";
	}
	#line 415 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *UInt64_class() {
	#line 416 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 416 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 416 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 416 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__UInt64);
		#line 416 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__UInt64);
		#line 416 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "UInt64";
	}
	#line 416 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *Octet_class() {
	#line 418 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 418 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 418 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 418 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Octet);
		#line 418 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Octet);
		#line 418 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Octet";
	}
	#line 418 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *SizeT_class() {
	#line 420 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 420 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 420 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 420 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__SizeT);
		#line 420 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__SizeT);
		#line 420 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "SizeT";
	}
	#line 420 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *Bool_class() {
	#line 422 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 422 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 422 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 422 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Bool);
		#line 422 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Bool);
		#line 422 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Bool";
	}
	#line 422 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


char *Bool_toString(bool this) {
	#line 424 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this ? "true" : "false";
}


lang__Class *Float_class() {
	#line 431 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 431 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 431 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 431 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Float);
		#line 431 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Float);
		#line 431 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Float";
	}
	#line 431 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *LDouble_class() {
	#line 432 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 432 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 432 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 432 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__LDouble);
		#line 432 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__LDouble);
		#line 432 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "LDouble";
	}
	#line 432 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Class *Double_class() {
	#line 434 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 434 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 434 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 434 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Double);
		#line 434 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Double);
		#line 434 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Double";
	}
	#line 434 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


char *Double_toString(double this) {
	#line 437 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *str = (void *) gc_malloc(((size_t) (64)));
	#line 438 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	sprintf(str, "%.2f", this);
	#line 439 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return str;
}


double Double_abs(double this) {
	#line 443 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this < 0 ? 0 - this : this;
}


lang__Class *Range_class() {
	#line 451 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	static lang__Class *_class = NULL;
	#line 451 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (_class == NULL){
		#line 451 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 451 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->size = sizeof(lang__Range);
		#line 451 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->instanceSize = sizeof(lang__Range);
		#line 451 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		_class->name = "Range";
	}
	#line 451 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return _class;
}


lang__Range Range_new(int min, int max) {
	#line 456 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	lang__Range this;
	#line 457 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	this.min = min;
	#line 458 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	this.max = max;
	#line 459 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this;
}



void Class___defaults___impl(struct _lang__Class *this){
	Object___defaults___impl((lang__Object *) this);
}

void Class___destroy___impl(struct _lang__Class *this){
}

struct _lang__Object *Class_alloc(struct _lang__Class *this){
	#line 486 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	struct _lang__Object *object = ((struct _lang__Object *) ((void *) gc_malloc(this->instanceSize)));
	#line 487 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (object){
		#line 488 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		object->class = this;
		#line 489 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		Object___defaults__(object);
	}
	#line 491 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return object;
}

bool Class_instanceof(struct _lang__Class *this, struct _lang__Class *T){
	#line 495 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (this == T){
		#line 495 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		return true;
	}
	#line 496 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return (this->super ? Class_instanceof(this->super, T) : false);
}

lang__Class *Class_class(){
	static bool __done__ = false;
	static lang__ClassClass class = {{
			.instanceSize = sizeof(lang__Class),
			.size = sizeof(void*),
			.name = "Class",
		},
		.__load__ = Class___load__,
		.__defaults__ = Class___defaults___impl,
		.__destroy__ = Class___destroy___impl,
		.alloc = Class_alloc,
		.instanceof = Class_instanceof,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Class___defaults__(struct _lang__Class *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Class___destroy__(struct _lang__Class *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Class___load__(){
}



void Object___defaults___impl(struct _lang__Object *this){
}

void Object___destroy___impl(struct _lang__Object *this){
}

lang__Class *Object_class(){
	static lang__ObjectClass class = {{
			.instanceSize = sizeof(lang__Object),
			.size = sizeof(void*),
			.name = "Object",
		},
		.__load__ = Object___load__,
		.__defaults__ = Object___defaults___impl,
		.__destroy__ = Object___destroy___impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	return classPtr;
}


void Object___defaults__(struct _lang__Object *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Object___destroy__(struct _lang__Object *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Object___load__(){
}



void Iterator___defaults___impl(struct _lang__Iterator *this){
	Object___defaults___impl((lang__Object *) this);
}

void Iterator___destroy___impl(struct _lang__Iterator *this){
}

lang__Class *Iterator_class(){
	static bool __done__ = false;
	static lang__IteratorClass class = {{{
				.instanceSize = sizeof(lang__Iterator),
				.size = sizeof(void*),
				.name = "Iterator",
			},
			.__load__ = (void (*)()) Iterator___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Iterator___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Iterator___destroy___impl,
		},
		.hasNext = Iterator_hasNext,
		.next = Iterator_next,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Iterator___defaults__(struct _lang__Iterator *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Iterator___destroy__(struct _lang__Iterator *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


bool Iterator_hasNext(struct _lang__Iterator *this){
	return (bool)((lang__IteratorClass *)((lang__Object *)this)->class)->hasNext((struct _lang__Iterator *) this);
}


void Iterator_next(struct _lang__Iterator *this, void *__returnArg){
	((lang__IteratorClass *)((lang__Object *)this)->class)->next((struct _lang__Iterator *) this, __returnArg);
}


void Iterator___load__(){
}



void Iterable___defaults___impl(struct _lang__Iterable *this){
	Object___defaults___impl((lang__Object *) this);
}

void Iterable___destroy___impl(struct _lang__Iterable *this){
}

lang__Class *Iterable_class(){
	static bool __done__ = false;
	static lang__IterableClass class = {{{
				.instanceSize = sizeof(lang__Iterable),
				.size = sizeof(void*),
				.name = "Iterable",
			},
			.__load__ = (void (*)()) Iterable___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Iterable___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Iterable___destroy___impl,
		},
		.iterator = Iterable_iterator,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Iterable___defaults__(struct _lang__Iterable *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Iterable___destroy__(struct _lang__Iterable *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


struct _lang__Iterator *Iterable_iterator(struct _lang__Iterable *this){
	return (struct _lang__Iterator *)((lang__IterableClass *)((lang__Object *)this)->class)->iterator((struct _lang__Iterable *) this);
}


void Iterable___load__(){
}



void Interface___defaults___impl(struct _lang__Interface *this){
	Object___defaults___impl((lang__Object *) this);
}

void Interface___destroy___impl(struct _lang__Interface *this){
}

void Interface_init_impl(struct _lang__Interface *this, struct _lang__Object *realThis, struct _lang__Object *funcs){
	#line 538 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	this->funcs = funcs;
	#line 538 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	this->realThis = realThis;
}

lang__Class *Interface_class(){
	static bool __done__ = false;
	static lang__InterfaceClass class = {{{
				.instanceSize = sizeof(lang__Interface),
				.size = sizeof(void*),
				.name = "Interface",
			},
			.__load__ = (void (*)()) Interface___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Interface___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Interface___destroy___impl,
		},
		.new = Interface_new,
		.init = Interface_init_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Interface___defaults__(struct _lang__Interface *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Interface___destroy__(struct _lang__Interface *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Interface_init(struct _lang__Interface *this, struct _lang__Object *realThis, struct _lang__Object *funcs){
	((lang__InterfaceClass *)((lang__Object *)this)->class)->init((struct _lang__Interface *) this, realThis, funcs);
}


void Interface___load__(){
}


struct _lang__Interface *Interface_new(struct _lang__Object *realThis, struct _lang__Object *funcs){
	#line 538 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	struct _lang__Interface *this = ((struct _lang__Interface *) (Class_alloc(Interface_class())));
	#line 538 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	Interface_init(this, realThis, funcs);
	#line 538 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this;
}



void Exception___defaults___impl(struct _lang__Exception *this){
	Object___defaults___impl((lang__Object *) this);
}

void Exception___destroy___impl(struct _lang__Exception *this){
}

void Exception_init_impl(struct _lang__Exception *this, struct _lang__Class *origin, char *msg){
	#line 550 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	this->msg = msg;
	#line 550 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	this->origin = origin;
}

void Exception_init_noOrigin_impl(struct _lang__Exception *this, char *msg){
	#line 551 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	this->msg = msg;
}

void Exception_crash_impl(struct _lang__Exception *this){
	#line 554 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	fflush(stdout);
	#line 555 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	int x = 0;
	#line 556 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	x = 1 / x;
}

char *Exception_getMessage_impl(struct _lang__Exception *this){
	#line 560 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	int max = 1024;
	#line 561 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	char *buffer = ((char *) ((void *) gc_malloc(((size_t) (max)))));
	#line 562 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	if (this->origin){
		#line 562 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		snprintf(buffer, max, "[%s in %s]: %s\n", ((lang__Object*) this)->class->name, this->origin->name, this->msg);
	}
	#line 563 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	else {
		#line 563 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
		snprintf(buffer, max, "[%s]: %s\n", ((lang__Object*) this)->class->name, this->msg);
	}
	#line 564 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return buffer;
}

void Exception_print_impl(struct _lang__Exception *this){
	#line 568 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	fprintf(stderr, "%s", Exception_getMessage(this));
}

void Exception_throw_impl(struct _lang__Exception *this){
	#line 572 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	Exception_print(this);
	#line 573 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	Exception_crash(this);
}

lang__Class *Exception_class(){
	static bool __done__ = false;
	static lang__ExceptionClass class = {{{
				.instanceSize = sizeof(lang__Exception),
				.size = sizeof(void*),
				.name = "Exception",
			},
			.__load__ = (void (*)()) Exception___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Exception___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Exception___destroy___impl,
		},
		.new = Exception_new,
		.init = Exception_init_impl,
		.new_noOrigin = Exception_new_noOrigin,
		.init_noOrigin = Exception_init_noOrigin_impl,
		.crash = Exception_crash_impl,
		.getMessage = Exception_getMessage_impl,
		.print = Exception_print_impl,
		.throw = Exception_throw_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Exception___defaults__(struct _lang__Exception *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Exception___destroy__(struct _lang__Exception *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Exception_init(struct _lang__Exception *this, struct _lang__Class *origin, char *msg){
	((lang__ExceptionClass *)((lang__Object *)this)->class)->init((struct _lang__Exception *) this, origin, msg);
}


void Exception_init_noOrigin(struct _lang__Exception *this, char *msg){
	((lang__ExceptionClass *)((lang__Object *)this)->class)->init_noOrigin((struct _lang__Exception *) this, msg);
}


void Exception_crash(struct _lang__Exception *this){
	((lang__ExceptionClass *)((lang__Object *)this)->class)->crash((struct _lang__Exception *) this);
}


char *Exception_getMessage(struct _lang__Exception *this){
	return (char *)((lang__ExceptionClass *)((lang__Object *)this)->class)->getMessage((struct _lang__Exception *) this);
}


void Exception_print(struct _lang__Exception *this){
	((lang__ExceptionClass *)((lang__Object *)this)->class)->print((struct _lang__Exception *) this);
}


void Exception_throw(struct _lang__Exception *this){
	((lang__ExceptionClass *)((lang__Object *)this)->class)->throw((struct _lang__Exception *) this);
}


void Exception___load__(){
}


struct _lang__Exception *Exception_new(struct _lang__Class *origin, char *msg){
	#line 550 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	struct _lang__Exception *this = ((struct _lang__Exception *) (Class_alloc(Exception_class())));
	#line 550 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	Exception_init(this, origin, msg);
	#line 550 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this;
}


struct _lang__Exception *Exception_new_noOrigin(char *msg){
	#line 551 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	struct _lang__Exception *this = ((struct _lang__Exception *) (Class_alloc(Exception_class())));
	#line 551 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	Exception_init_noOrigin(this, msg);
	#line 551 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return this;
}


bool __OP_EQ_String_String__Bool(char *str1, char *str2) {
	#line 299 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return String_equals(str1, str2);
}

char __OP_IDX_String_SizeT__Char(char *string, size_t index) {
	#line 303 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return String_charAt(string, index);
}

char *__OP_MUL_String_Int__String(char *str, int count) {
	#line 307 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return String_times(str, count);
}

char *__OP_ADD_String_String__String(char *left, char *right) {
	#line 311 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return String_append(left, right);
}

char *__OP_ADD_LLong_String__String(long long left, char *right) {
	#line 315 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return __OP_ADD_String_String__String(LLong_toString(left), right);
}

char *__OP_ADD_String_LLong__String(char *left, long long right) {
	#line 319 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return __OP_ADD_String_String__String(left, LLong_toString(right));
}

char *__OP_ADD_Int_String__String(int left, char *right) {
	#line 323 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return __OP_ADD_String_String__String(Int_toString(left), right);
}

char *__OP_ADD_String_Int__String(char *left, int right) {
	#line 327 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return __OP_ADD_String_String__String(left, Int_toString(right));
}

char *__OP_ADD_Bool_String__String(bool left, char *right) {
	#line 331 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return __OP_ADD_String_String__String(Bool_toString(left), right);
}

char *__OP_ADD_String_Bool__String(char *left, bool right) {
	#line 335 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return __OP_ADD_String_String__String(left, Bool_toString(right));
}

char *__OP_ADD_Double_String__String(double left, char *right) {
	#line 339 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return __OP_ADD_String_String__String(Double_toString(left), right);
}

char *__OP_ADD_String_Double__String(char *left, double right) {
	#line 343 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return __OP_ADD_String_String__String(left, Double_toString(right));
}

char *__OP_ADD_String_Char__String(char *left, char right) {
	#line 347 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return String_append_char(left, right);
}

char *__OP_ADD_Char_String__String(char left, char *right) {
	#line 351 "/media/shared/dev/ooc/sdk/lang/BasicTypes.ooc"
	return String_prepend_char(right, left);
}


void _lang_BasicTypes_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		Class___load__();
		Object___load__();
		Iterator___load__();
		Iterable___load__();
		Interface___load__();
		Exception___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
	}
}

