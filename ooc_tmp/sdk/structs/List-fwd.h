/* structs.List header file, generated with ooc */
#ifndef ___structs_List__fwd__
#define ___structs_List__fwd__


struct _structs__List;
typedef struct _structs__List structs__List;
struct _structs__ListClass;
typedef struct _structs__ListClass structs__ListClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
lang__Class *List_class();

void List___load__();
void List___defaults__(struct _structs__List *this);
void List___defaults___impl(struct _structs__List *this);
void List___destroy__(struct _structs__List *this);
void List___destroy___impl(struct _structs__List *this);
void List_add(struct _structs__List *this, uint8_t * element);
void List_add_withIndex(struct _structs__List *this, int index, uint8_t * element);
void List_addAll(struct _structs__List *this, struct _lang__Iterable *list);
void List_addAll_impl(struct _structs__List *this, struct _lang__Iterable *list);
void List_addAll_atStart(struct _structs__List *this, int start, struct _lang__Iterable *list);
void List_addAll_atStart_impl(struct _structs__List *this, int start, struct _lang__Iterable *list);
void List_clear(struct _structs__List *this);
bool List_removeLast(struct _structs__List *this);
bool List_removeLast_impl(struct _structs__List *this);
bool List_contains(struct _structs__List *this, uint8_t * element);
bool List_contains_impl(struct _structs__List *this, uint8_t * element);
void List_get(struct _structs__List *this, void *__returnArg, int index);
int List_indexOf(struct _structs__List *this, uint8_t * element);
bool List_isEmpty(struct _structs__List *this);
bool List_isEmpty_impl(struct _structs__List *this);
int List_lastIndexOf(struct _structs__List *this, uint8_t * element);
void List_removeAt(struct _structs__List *this, void *__returnArg, int index);
bool List_remove(struct _structs__List *this, uint8_t * element);
void List_set(struct _structs__List *this, int index, uint8_t * element);
int List_size(struct _structs__List *this);
struct _lang__Iterator *List_iterator(struct _structs__List *this);
struct _structs__List *List_clone(struct _structs__List *this);
void List_last(struct _structs__List *this, void *__returnArg);
void List_last_impl(struct _structs__List *this, void *__returnArg);
size_t List_lastIndex(struct _structs__List *this);
size_t List_lastIndex_impl(struct _structs__List *this);
void *List_toArray(struct _structs__List *this);
void *List_toArray_impl(struct _structs__List *this);

void __OP_IDX_List_Int__T(void *__returnArg, lang__Class *T, structs__List *list, int i);
void __OP_IDX_ASS_List_Int_T(lang__Class *T, structs__List *list, int i, uint8_t * element);
void __OP_ADD_ASS_List_T(lang__Class *T, structs__List *list, uint8_t * element);
bool __OP_SUB_ASS_List_T__Bool(lang__Class *T, structs__List *list, uint8_t * element);

#endif // ___structs_List__fwd__

