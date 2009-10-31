/* structs.ArrayList header file, generated with ooc */
#ifndef ___structs_ArrayList__fwd__
#define ___structs_ArrayList__fwd__


struct _structs__ArrayList;
typedef struct _structs__ArrayList structs__ArrayList;
struct _structs__ArrayListClass;
typedef struct _structs__ArrayListClass structs__ArrayListClass;
struct _structs__ArrayListIterator;
typedef struct _structs__ArrayListIterator structs__ArrayListIterator;
struct _structs__ArrayListIteratorClass;
typedef struct _structs__ArrayListIteratorClass structs__ArrayListIteratorClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <sdk/structs/List.h>
lang__Class *ArrayList_class();

void ArrayList___load__();
void ArrayList___defaults__(struct _structs__ArrayList *this);
void ArrayList___defaults___impl(struct _structs__ArrayList *this);
void ArrayList___destroy__(struct _structs__ArrayList *this);
void ArrayList___destroy___impl(struct _structs__ArrayList *this);
struct _structs__ArrayList *ArrayList_new(struct _lang__Class *T);
void ArrayList_init(struct _structs__ArrayList *this);
void ArrayList_init_impl(struct _structs__ArrayList *this);
struct _structs__ArrayList *ArrayList_new_withCapacity(struct _lang__Class *T, int capacity);
void ArrayList_init_withCapacity(struct _structs__ArrayList *this, int capacity);
void ArrayList_init_withCapacity_impl(struct _structs__ArrayList *this, int capacity);
struct _structs__ArrayList *ArrayList_new_withData(struct _lang__Class *T, uint8_t *data, int size);
void ArrayList_init_withData(struct _structs__ArrayList *this, uint8_t *data, int size);
void ArrayList_init_withData_impl(struct _structs__ArrayList *this, uint8_t *data, int size);
void ArrayList_add(struct _structs__ArrayList *this, uint8_t * element);
void ArrayList_add_impl(struct _structs__ArrayList *this, uint8_t * element);
void ArrayList_add_withIndex(struct _structs__ArrayList *this, int index, uint8_t * element);
void ArrayList_add_withIndex_impl(struct _structs__ArrayList *this, int index, uint8_t * element);
void ArrayList_clear(struct _structs__ArrayList *this);
void ArrayList_clear_impl(struct _structs__ArrayList *this);
void ArrayList_get(struct _structs__ArrayList *this, void *__returnArg, int index);
void ArrayList_get_impl(struct _structs__ArrayList *this, void *__returnArg, int index);
int ArrayList_indexOf(struct _structs__ArrayList *this, uint8_t * element);
int ArrayList_indexOf_impl(struct _structs__ArrayList *this, uint8_t * element);
int ArrayList_lastIndexOf(struct _structs__ArrayList *this, uint8_t * element);
int ArrayList_lastIndexOf_impl(struct _structs__ArrayList *this, uint8_t * element);
void ArrayList_removeAt(struct _structs__ArrayList *this, void *__returnArg, int index);
void ArrayList_removeAt_impl(struct _structs__ArrayList *this, void *__returnArg, int index);
bool ArrayList_remove(struct _structs__ArrayList *this, uint8_t * element);
bool ArrayList_remove_impl(struct _structs__ArrayList *this, uint8_t * element);
void ArrayList_set(struct _structs__ArrayList *this, int index, uint8_t * element);
void ArrayList_set_impl(struct _structs__ArrayList *this, int index, uint8_t * element);
int ArrayList_size(struct _structs__ArrayList *this);
int ArrayList_size_impl(struct _structs__ArrayList *this);
void ArrayList_ensureCapacity(struct _structs__ArrayList *this, int newSize);
void ArrayList_ensureCapacity_impl(struct _structs__ArrayList *this, int newSize);
void ArrayList_grow(struct _structs__ArrayList *this);
void ArrayList_grow_impl(struct _structs__ArrayList *this);
void ArrayList_checkIndex(struct _structs__ArrayList *this, int index);
void ArrayList_checkIndex_impl(struct _structs__ArrayList *this, int index);
struct _lang__Iterator *ArrayList_iterator(struct _structs__ArrayList *this);
struct _lang__Iterator *ArrayList_iterator_impl(struct _structs__ArrayList *this);
struct _structs__ArrayList *ArrayList_clone(struct _structs__ArrayList *this);
struct _structs__ArrayList *ArrayList_clone_impl(struct _structs__ArrayList *this);
void *ArrayList_toArray(struct _structs__ArrayList *this);
void *ArrayList_toArray_impl(struct _structs__ArrayList *this);

lang__Class *ArrayListIterator_class();

void ArrayListIterator___load__();
void ArrayListIterator___defaults__(struct _structs__ArrayListIterator *this);
void ArrayListIterator___defaults___impl(struct _structs__ArrayListIterator *this);
void ArrayListIterator___destroy__(struct _structs__ArrayListIterator *this);
void ArrayListIterator___destroy___impl(struct _structs__ArrayListIterator *this);
struct _structs__ArrayListIterator *ArrayListIterator_new(struct _lang__Class *T, struct _structs__ArrayList *list);
void ArrayListIterator_init(struct _structs__ArrayListIterator *this, struct _structs__ArrayList *list);
void ArrayListIterator_init_impl(struct _structs__ArrayListIterator *this, struct _structs__ArrayList *list);
bool ArrayListIterator_hasNext(struct _structs__ArrayListIterator *this);
bool ArrayListIterator_hasNext_impl(struct _structs__ArrayListIterator *this);
void ArrayListIterator_next(struct _structs__ArrayListIterator *this, void *__returnArg);
void ArrayListIterator_next_impl(struct _structs__ArrayListIterator *this, void *__returnArg);

void __OP_IDX_ArrayList_Int__T(void *__returnArg, lang__Class *T, structs__ArrayList *list, int i);
void __OP_IDX_ASS_ArrayList_Int_T(lang__Class *T, structs__ArrayList *list, int i, uint8_t * element);
void __OP_ADD_ASS_ArrayList_T(lang__Class *T, structs__ArrayList *list, uint8_t * element);
bool __OP_SUB_ASS_ArrayList_T__Bool(lang__Class *T, structs__ArrayList *list, uint8_t * element);
structs__ArrayList *__OP_AS_T__star_SizeT__ArrayList(lang__Class *T, uint8_t *data, size_t size);

#endif // ___structs_ArrayList__fwd__

