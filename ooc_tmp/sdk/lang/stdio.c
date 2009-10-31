/* lang.stdio source file, generated with ooc */
#include "stdio.h"
lang__Class *FILE_class() {
	#line 43 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	static lang__Class *_class = NULL;
	#line 43 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	if (_class == NULL){
		#line 43 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 43 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		_class->size = sizeof(FILE);
		#line 43 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		_class->instanceSize = sizeof(FILE);
		#line 43 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		_class->name = "FILE";
	}
	#line 43 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	return _class;
}


lang__Class *FStream_class() {
	#line 44 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	static lang__Class *_class = NULL;
	#line 44 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	if (_class == NULL){
		#line 44 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 44 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		_class->size = sizeof(lang__Pointer);
		#line 44 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		_class->instanceSize = sizeof(lang__Pointer);
		#line 44 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		_class->name = "FStream";
	}
	#line 44 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	return _class;
}


char FStream_readChar(FILE *this) {
	#line 48 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	char c;
	#line 49 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	fread(((void *) (&c)), ((size_t) (1)), ((size_t) (1)), this);
	#line 50 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	return c;
}


char *FStream_readLine(FILE *this) {
	#line 55 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	int chunk = 128;
	#line 56 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	int length = chunk;
	#line 57 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	int pos = 0;
	#line 58 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	char *str = ((char *) ((void *) gc_malloc(((size_t) (length)))));
	#line 60 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	fgets(str, ((size_t) (chunk)), this);
	#line 63 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	while (String_last(str) != '\n'){
		#line 65 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		pos += chunk - 1;
		#line 68 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		length += chunk;
		#line 69 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		void *tmp = (void *) gc_realloc(((void *) (str)), ((size_t) (length)));
		#line 70 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		if (!tmp){
			#line 70 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
			Exception_new(FStream_class(), "Ran out of memory while reading a (apparently never-ending) line!");
		}
		#line 71 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		str = tmp;
		#line 75 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
		fgets(((char *) (str)) + pos, ((size_t) (chunk)), this);
	}
	#line 78 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	return str;
}


bool FStream_hasNext(FILE *this) {
	#line 82 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	return feof(this) == 0;
}


void FStream_write_chr(FILE *this, char chr) {
	#line 86 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	fputc(chr, this);
}


void FStream_write(FILE *this, char *str) {
	#line 90 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	fputs(str, this);
}


size_t FStream_write_precise(FILE *this, char *str, size_t offset, size_t length) {
	#line 95 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	return fwrite(((void *) (str + offset)), ((size_t) (1)), length, this);
}


void println_withStr(char *str) {
	#line 5 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	printf("%s\n", str);
}

void println() {
	#line 8 "/media/shared/dev/ooc/sdk/lang/stdio.ooc"
	printf("\n");
}


void _lang_stdio_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_lang_BasicTypes_load();
	}
}

