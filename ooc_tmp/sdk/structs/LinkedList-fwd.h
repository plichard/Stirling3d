/* structs.LinkedList header file, generated with ooc */
#ifndef ___structs_LinkedList__fwd__
#define ___structs_LinkedList__fwd__


struct _structs__LinkedList;
typedef struct _structs__LinkedList structs__LinkedList;
struct _structs__LinkedListClass;
typedef struct _structs__LinkedListClass structs__LinkedListClass;
struct _structs__Node;
typedef struct _structs__Node structs__Node;
struct _structs__NodeClass;
typedef struct _structs__NodeClass structs__NodeClass;
struct _structs__LinkedListIterator;
typedef struct _structs__LinkedListIterator structs__LinkedListIterator;
struct _structs__LinkedListIteratorClass;
typedef struct _structs__LinkedListIteratorClass structs__LinkedListIteratorClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <sdk/structs/List.h>
#include <sdk/os/Terminal-fwd.h>
lang__Class *LinkedList_class();

void LinkedList___load__();
void LinkedList___defaults__(struct _structs__LinkedList *this);
void LinkedList___defaults___impl(struct _structs__LinkedList *this);
void LinkedList___destroy__(struct _structs__LinkedList *this);
void LinkedList___destroy___impl(struct _structs__LinkedList *this);
struct _structs__LinkedList *LinkedList_new(struct _lang__Class *T);
void LinkedList_init(struct _structs__LinkedList *this);
void LinkedList_init_impl(struct _structs__LinkedList *this);
void LinkedList_add(struct _structs__LinkedList *this, uint8_t * data);
void LinkedList_add_impl(struct _structs__LinkedList *this, uint8_t * data);
void LinkedList_add_withIndex(struct _structs__LinkedList *this, int index, uint8_t * data);
void LinkedList_add_withIndex_impl(struct _structs__LinkedList *this, int index, uint8_t * data);
void LinkedList_clear(struct _structs__LinkedList *this);
void LinkedList_clear_impl(struct _structs__LinkedList *this);
void LinkedList_get(struct _structs__LinkedList *this, void *__returnArg, int index);
void LinkedList_get_impl(struct _structs__LinkedList *this, void *__returnArg, int index);
struct _structs__Node *LinkedList_getNode(struct _structs__LinkedList *this, int index);
struct _structs__Node *LinkedList_getNode_impl(struct _structs__LinkedList *this, int index);
int LinkedList_indexOf(struct _structs__LinkedList *this, uint8_t * data);
int LinkedList_indexOf_impl(struct _structs__LinkedList *this, uint8_t * data);
int LinkedList_lastIndexOf(struct _structs__LinkedList *this, uint8_t * data);
int LinkedList_lastIndexOf_impl(struct _structs__LinkedList *this, uint8_t * data);
void LinkedList_removeAt(struct _structs__LinkedList *this, void *__returnArg, int index);
void LinkedList_removeAt_impl(struct _structs__LinkedList *this, void *__returnArg, int index);
bool LinkedList_remove(struct _structs__LinkedList *this, uint8_t * data);
bool LinkedList_remove_impl(struct _structs__LinkedList *this, uint8_t * data);
void LinkedList_removeNode(struct _structs__LinkedList *this, struct _structs__Node *toRemove);
void LinkedList_removeNode_impl(struct _structs__LinkedList *this, struct _structs__Node *toRemove);
void LinkedList_set(struct _structs__LinkedList *this, int index, uint8_t * data);
void LinkedList_set_impl(struct _structs__LinkedList *this, int index, uint8_t * data);
int LinkedList_size(struct _structs__LinkedList *this);
int LinkedList_size_impl(struct _structs__LinkedList *this);
struct _structs__LinkedListIterator *LinkedList_iterator(struct _structs__LinkedList *this);
struct _structs__LinkedListIterator *LinkedList_iterator_impl(struct _structs__LinkedList *this);
struct _structs__LinkedList *LinkedList_clone(struct _structs__LinkedList *this);
struct _structs__LinkedList *LinkedList_clone_impl(struct _structs__LinkedList *this);
void LinkedList_print(struct _structs__LinkedList *this);
void LinkedList_print_impl(struct _structs__LinkedList *this);

lang__Class *Node_class();

void Node___load__();
void Node___defaults__(struct _structs__Node *this);
void Node___defaults___impl(struct _structs__Node *this);
void Node___destroy__(struct _structs__Node *this);
void Node___destroy___impl(struct _structs__Node *this);
struct _structs__Node *Node_new(struct _lang__Class *T);
void Node_init(struct _structs__Node *this);
void Node_init_impl(struct _structs__Node *this);
struct _structs__Node *Node_new_withParams(struct _lang__Class *T, struct _structs__Node *prev, struct _structs__Node *next, uint8_t * data);
void Node_init_withParams(struct _structs__Node *this, struct _structs__Node *prev, struct _structs__Node *next, uint8_t * data);
void Node_init_withParams_impl(struct _structs__Node *this, struct _structs__Node *prev, struct _structs__Node *next, uint8_t * data);

lang__Class *LinkedListIterator_class();

void LinkedListIterator___load__();
void LinkedListIterator___defaults__(struct _structs__LinkedListIterator *this);
void LinkedListIterator___defaults___impl(struct _structs__LinkedListIterator *this);
void LinkedListIterator___destroy__(struct _structs__LinkedListIterator *this);
void LinkedListIterator___destroy___impl(struct _structs__LinkedListIterator *this);
struct _structs__LinkedListIterator *LinkedListIterator_new(struct _lang__Class *T, struct _structs__LinkedList *list);
void LinkedListIterator_init(struct _structs__LinkedListIterator *this, struct _structs__LinkedList *list);
void LinkedListIterator_init_impl(struct _structs__LinkedListIterator *this, struct _structs__LinkedList *list);
bool LinkedListIterator_hasNext(struct _structs__LinkedListIterator *this);
bool LinkedListIterator_hasNext_impl(struct _structs__LinkedListIterator *this);
void LinkedListIterator_next(struct _structs__LinkedListIterator *this, void *__returnArg);
void LinkedListIterator_next_impl(struct _structs__LinkedListIterator *this, void *__returnArg);
struct _structs__Node *LinkedListIterator_nextNode(struct _structs__LinkedListIterator *this);
struct _structs__Node *LinkedListIterator_nextNode_impl(struct _structs__LinkedListIterator *this);

void __OP_IDX_LinkedList_Int__T(void *__returnArg, lang__Class *T, structs__LinkedList *list, int index);

#endif // ___structs_LinkedList__fwd__

