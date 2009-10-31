/* structs.LinkedList source file, generated with ooc */
#include "LinkedList.h"
#include <sdk/os/Terminal.h>

void LinkedList___defaults___impl(struct _structs__LinkedList *this){
	List___defaults___impl((structs__List *) this);
	#line 12 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->size = 0;
}

void LinkedList___destroy___impl(struct _structs__LinkedList *this){
}

void LinkedList_init_impl(struct _structs__LinkedList *this){
	#line 17 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->first = NULL;
	#line 18 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->last = NULL;
}

void LinkedList_add_impl(struct _structs__LinkedList *this, uint8_t * data){
	#line 22 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__Node *node;
	#line 23 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	if (this->first){
		#line 24 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		node = Node_new_withParams(((lang__Iterable*) this)->T, this->last, NULL, data);
		#line 25 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		this->last->next = node;
	}
	#line 26 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	else {
		#line 27 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		node = Node_new_withParams(((lang__Iterable*) this)->T, NULL, NULL, data);
		#line 28 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		this->first = node;
	}
	#line 30 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->last = node;
	#line 31 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->size += 1;
}

void LinkedList_add_withIndex_impl(struct _structs__LinkedList *this, int index, uint8_t * data){
	#line 35 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	if (index > 0){
		#line 36 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		struct _structs__Node *prevNode;
		#line 36 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		prevNode = LinkedList_getNode(this, index - 1);
		#line 37 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		struct _structs__Node *nextNode = prevNode->next;
		#line 38 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		struct _structs__Node *node = Node_new_withParams(((lang__Iterable*) this)->T, prevNode, nextNode, data);
		#line 39 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		prevNode->next = node;
		#line 40 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		nextNode->prev = node;
	}
	#line 41 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	else if (index == 0){
		#line 42 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		void *node = Node_new_withParams(((lang__Iterable*) this)->T, NULL, this->first, data);
		#line 43 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if (this->first){
			#line 44 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			this->first->prev = node;
			#line 45 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			this->first = node;
		}
		#line 46 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		else {
			#line 47 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			this->first = node;
			#line 48 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			this->last = node;
		}
	}
	#line 50 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	else {
		#line 51 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		Exception_throw(Exception_new(LinkedList_class(), __OP_ADD_String_String__String("Check index: 0 <= ", __OP_ADD_Int_String__String(index, __OP_ADD_String_Int__String(" < ", this->size)))));
	}
}

void LinkedList_clear_impl(struct _structs__LinkedList *this){
	#line 56 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__Node *current = this->first;
	#line 57 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->first = NULL;
	#line 58 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	while (current){
		#line 59 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		struct _structs__Node *next = current->next;
		#line 60 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		current->next = NULL;
		#line 61 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		current->prev = NULL;
		#line 62 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		current = next;
	}
	#line 64 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->last = NULL;
}

void LinkedList_get_impl(struct _structs__LinkedList *this, void *__returnArg, int index){
	#line 68 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	if (__returnArg){
		#line 68 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		memcpy(__returnArg, ((void *) (LinkedList_getNode(this, index)->data)), ((lang__Iterable*) this)->T->size);
	}
	#line 68 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return;
}

struct _structs__Node *LinkedList_getNode_impl(struct _structs__LinkedList *this, int index){
	#line 72 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	if (index < 0 || index >= this->size){
		#line 73 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		Exception_throw(Exception_new(LinkedList_class(), __OP_ADD_String_String__String("Check index: 0 <= ", __OP_ADD_Int_String__String(index, __OP_ADD_String_Int__String(" < ", this->size)))));
	}
	#line 76 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	int i = 0;
	#line 77 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__Node *current = this->first;
	#line 78 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	while (current->next && i < index){
		#line 79 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		current = current->next;
		#line 80 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		i += 1;
	}
	#line 82 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return current;
}

int LinkedList_indexOf_impl(struct _structs__LinkedList *this, uint8_t * data){
	#line 86 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__Node *current = this->first;
	#line 87 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	int i = 0;
	#line 88 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	while (current){
		#line 89 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if ((*current->data) == (*data)){
			#line 90 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			return i;
		}
		#line 92 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		i += 1;
		#line 93 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		current = current->next;
	}
	#line 95 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return 0 - 1;
}

int LinkedList_lastIndexOf_impl(struct _structs__LinkedList *this, uint8_t * data){
	#line 99 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__Node *current = this->last;
	#line 100 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	int i = this->size - 1;
	#line 101 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	while (current){
		#line 102 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if ((*current->data) == (*data)){
			#line 103 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			return i;
		}
		#line 105 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		i -= 1;
		#line 106 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		current = current->prev;
	}
	#line 108 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return 0 - 1;
}

void LinkedList_removeAt_impl(struct _structs__LinkedList *this, void *__returnArg, int index){
	#line 112 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	if (this->first && index >= 0 && index < this->size){
		#line 113 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		struct _structs__Node *toRemove = LinkedList_getNode(this, index);
		#line 114 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if (toRemove->next){
			#line 115 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			toRemove->next->prev = toRemove->prev;
		}
		#line 116 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		else {
			#line 117 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			this->last = toRemove->prev;
			#line 118 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			if (toRemove->prev){
				#line 119 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
				toRemove->prev->next = NULL;
			}
		}
		#line 123 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if (toRemove->prev){
			#line 124 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			toRemove->prev->next = toRemove->next;
		}
		#line 125 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		else {
			#line 126 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			this->first = toRemove->next;
			#line 127 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			if (toRemove->next){
				#line 128 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
				toRemove->next->prev = NULL;
			}
		}
		#line 131 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		this->size -= 1;
		#line 132 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if (__returnArg){
			#line 132 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			memcpy(__returnArg, ((void *) (toRemove->data)), ((lang__Iterable*) this)->T->size);
		}
		#line 132 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		return;
	}
	#line 133 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	else {
		#line 134 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		Exception_throw(Exception_new(LinkedList_class(), __OP_ADD_String_String__String("Check index: 0 <= ", __OP_ADD_Int_String__String(index, __OP_ADD_String_Int__String(" < ", this->size)))));
	}
}

bool LinkedList_remove_impl(struct _structs__LinkedList *this, uint8_t * data){
	#line 138 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return false;
}

void LinkedList_removeNode_impl(struct _structs__LinkedList *this, struct _structs__Node *toRemove){
	#line 141 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	if (toRemove->next){
		#line 142 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		toRemove->next->prev = toRemove->prev;
	}
	#line 143 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	else {
		#line 144 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		this->last = toRemove->prev;
		#line 145 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if (toRemove->prev){
			#line 146 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			toRemove->prev->next = NULL;
		}
	}
	#line 150 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	if (toRemove->prev){
		#line 151 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		toRemove->prev->next = toRemove->next;
	}
	#line 152 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	else {
		#line 153 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		this->first = toRemove->next;
		#line 154 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if (toRemove->next){
			#line 155 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			toRemove->next->prev = NULL;
		}
	}
	#line 158 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->size -= 1;
}

void LinkedList_set_impl(struct _structs__LinkedList *this, int index, uint8_t * data){
}

int LinkedList_size_impl(struct _structs__LinkedList *this){
	#line 163 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return this->size;
}

struct _structs__LinkedListIterator *LinkedList_iterator_impl(struct _structs__LinkedList *this){
	#line 166 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return LinkedListIterator_new(Pointer_class(), this);
}

struct _structs__LinkedList *LinkedList_clone_impl(struct _structs__LinkedList *this){
	#line 169 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return 0;
}

void LinkedList_print_impl(struct _structs__LinkedList *this){
	#line 173 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	println();
	#line 174 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	printf("prev: ");
	#line 175 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__Node *current = this->first;
	#line 176 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	while (current){
		#line 177 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if (current->prev){
			#line 178 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			Terminal_setFgColor(((os__ColorClass*) Color_class())->red + ((int) (current->prev)) % 7);
			#line 179 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			printf("|%p|", current->prev);
			#line 180 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			Terminal_reset();
		}
		#line 182 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		else {
			#line 183 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			printf("|         |");
		}
		#line 184 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		current = current->next;
	}
	#line 186 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	println();
	#line 188 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	printf("this: ");
	#line 189 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	current = this->first;
	#line 190 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	while (current){
		#line 191 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		Terminal_setFgColor(((os__ColorClass*) Color_class())->red + ((int) (current)) % 7);
		#line 192 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		printf("|%p|", current);
		#line 193 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		Terminal_reset();
		#line 194 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		current = current->next;
	}
	#line 196 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	println();
	#line 198 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	printf("next: ");
	#line 199 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	current = this->first;
	#line 200 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	while (current){
		#line 201 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if (current->next){
			#line 202 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			Terminal_setFgColor(((os__ColorClass*) Color_class())->red + ((int) (current->next)) % 7);
			#line 203 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			printf("|%p|", current->next);
			#line 204 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			Terminal_reset();
		}
		#line 206 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		else {
			#line 207 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			printf("|         |");
		}
		#line 208 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		current = current->next;
	}
	#line 210 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	println();
}

lang__Class *LinkedList_class(){
	static bool __done__ = false;
	static structs__LinkedListClass class = {{{{{
						.instanceSize = sizeof(structs__LinkedList),
						.size = sizeof(void*),
						.name = "LinkedList",
					},
					.__load__ = (void (*)()) LinkedList___load__,
					.__defaults__ = (void (*)(struct _lang__Object *)) LinkedList___defaults___impl,
					.__destroy__ = (void (*)(struct _lang__Object *)) LinkedList___destroy___impl,
				},
				.iterator = (struct _lang__Iterator * (*)(struct _lang__Iterable *)) LinkedList_iterator_impl,
			},
			.add = (void (*)(struct _structs__List *, uint8_t *)) LinkedList_add_impl,
			.add_withIndex = (void (*)(struct _structs__List *, int, uint8_t *)) LinkedList_add_withIndex_impl,
			.addAll = (void (*)(struct _structs__List *, struct _lang__Iterable *)) List_addAll_impl,
			.addAll_atStart = (void (*)(struct _structs__List *, int, struct _lang__Iterable *)) List_addAll_atStart_impl,
			.clear = (void (*)(struct _structs__List *)) LinkedList_clear_impl,
			.removeLast = (bool (*)(struct _structs__List *)) List_removeLast_impl,
			.contains = (bool (*)(struct _structs__List *, uint8_t *)) List_contains_impl,
			.get = (void (*)(struct _structs__List *, void *, int)) LinkedList_get_impl,
			.indexOf = (int (*)(struct _structs__List *, uint8_t *)) LinkedList_indexOf_impl,
			.isEmpty = (bool (*)(struct _structs__List *)) List_isEmpty_impl,
			.lastIndexOf = (int (*)(struct _structs__List *, uint8_t *)) LinkedList_lastIndexOf_impl,
			.removeAt = (void (*)(struct _structs__List *, void *, int)) LinkedList_removeAt_impl,
			.remove = (bool (*)(struct _structs__List *, uint8_t *)) LinkedList_remove_impl,
			.set = (void (*)(struct _structs__List *, int, uint8_t *)) LinkedList_set_impl,
			.size = (int (*)(struct _structs__List *)) LinkedList_size_impl,
			.clone = (struct _structs__List * (*)(struct _structs__List *)) LinkedList_clone_impl,
			.last = (void (*)(struct _structs__List *, void *)) List_last_impl,
			.lastIndex = (size_t (*)(struct _structs__List *)) List_lastIndex_impl,
			.toArray = (void * (*)(struct _structs__List *)) List_toArray_impl,
		},
		.new = LinkedList_new,
		.init = LinkedList_init_impl,
		.getNode = LinkedList_getNode_impl,
		.removeNode = LinkedList_removeNode_impl,
		.print = LinkedList_print_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = List_class();
	}
	return classPtr;
}


void LinkedList___defaults__(struct _structs__LinkedList *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void LinkedList___destroy__(struct _structs__LinkedList *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void LinkedList_init(struct _structs__LinkedList *this){
	((structs__LinkedListClass *)((lang__Object *)this)->class)->init((struct _structs__LinkedList *) this);
}


void LinkedList_add(struct _structs__LinkedList *this, uint8_t * data){
	((structs__ListClass *)((lang__Object *)this)->class)->add((struct _structs__List *) this, data);
}


void LinkedList_add_withIndex(struct _structs__LinkedList *this, int index, uint8_t * data){
	((structs__ListClass *)((lang__Object *)this)->class)->add_withIndex((struct _structs__List *) this, index, data);
}


void LinkedList_clear(struct _structs__LinkedList *this){
	((structs__ListClass *)((lang__Object *)this)->class)->clear((struct _structs__List *) this);
}


void LinkedList_get(struct _structs__LinkedList *this, void *__returnArg, int index){
	((structs__ListClass *)((lang__Object *)this)->class)->get((struct _structs__List *) this, __returnArg, index);
}


struct _structs__Node *LinkedList_getNode(struct _structs__LinkedList *this, int index){
	return (struct _structs__Node *)((structs__LinkedListClass *)((lang__Object *)this)->class)->getNode((struct _structs__LinkedList *) this, index);
}


int LinkedList_indexOf(struct _structs__LinkedList *this, uint8_t * data){
	return (int)((structs__ListClass *)((lang__Object *)this)->class)->indexOf((struct _structs__List *) this, data);
}


int LinkedList_lastIndexOf(struct _structs__LinkedList *this, uint8_t * data){
	return (int)((structs__ListClass *)((lang__Object *)this)->class)->lastIndexOf((struct _structs__List *) this, data);
}


void LinkedList_removeAt(struct _structs__LinkedList *this, void *__returnArg, int index){
	((structs__ListClass *)((lang__Object *)this)->class)->removeAt((struct _structs__List *) this, __returnArg, index);
}


bool LinkedList_remove(struct _structs__LinkedList *this, uint8_t * data){
	return (bool)((structs__ListClass *)((lang__Object *)this)->class)->remove((struct _structs__List *) this, data);
}


void LinkedList_removeNode(struct _structs__LinkedList *this, struct _structs__Node *toRemove){
	((structs__LinkedListClass *)((lang__Object *)this)->class)->removeNode((struct _structs__LinkedList *) this, toRemove);
}


void LinkedList_set(struct _structs__LinkedList *this, int index, uint8_t * data){
	((structs__ListClass *)((lang__Object *)this)->class)->set((struct _structs__List *) this, index, data);
}


int LinkedList_size(struct _structs__LinkedList *this){
	return (int)((structs__ListClass *)((lang__Object *)this)->class)->size((struct _structs__List *) this);
}


struct _structs__LinkedListIterator *LinkedList_iterator(struct _structs__LinkedList *this){
	return (struct _structs__LinkedListIterator *)((lang__IterableClass *)((lang__Object *)this)->class)->iterator((struct _lang__Iterable *) this);
}


struct _structs__LinkedList *LinkedList_clone(struct _structs__LinkedList *this){
	return (struct _structs__LinkedList *)((structs__ListClass *)((lang__Object *)this)->class)->clone((struct _structs__List *) this);
}


void LinkedList_print(struct _structs__LinkedList *this){
	((structs__LinkedListClass *)((lang__Object *)this)->class)->print((struct _structs__LinkedList *) this);
}


void LinkedList___load__(){
}


struct _structs__LinkedList *LinkedList_new(struct _lang__Class *T){
	#line 16 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__LinkedList *this = ((struct _structs__LinkedList *) (Class_alloc(LinkedList_class())));
	#line 16 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	((lang__Iterable*) this)->T = T;
	#line 16 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	LinkedList_init(this);
	#line 16 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return this;
}



void Node___defaults___impl(struct _structs__Node *this){
	Object___defaults___impl((lang__Object *) this);
}

void Node___destroy___impl(struct _structs__Node *this){
}

void Node_init_impl(struct _structs__Node *this){
}

void Node_init_withParams_impl(struct _structs__Node *this, struct _structs__Node *prev, struct _structs__Node *next, uint8_t * data){
	#line 225 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	
	{
		#line 225 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if (!this->data){
			#line 225 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			this->data = (void *) gc_malloc(this->T->size);
		}
		#line 225 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		memcpy(((void *) (this->data)), ((void *) (data)), this->T->size);
	};
	#line 225 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->next = next;
	#line 225 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->prev = prev;
}

lang__Class *Node_class(){
	static bool __done__ = false;
	static structs__NodeClass class = {{{
				.instanceSize = sizeof(structs__Node),
				.size = sizeof(void*),
				.name = "Node",
			},
			.__load__ = (void (*)()) Node___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Node___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Node___destroy___impl,
		},
		.new = Node_new,
		.init = Node_init_impl,
		.new_withParams = Node_new_withParams,
		.init_withParams = Node_init_withParams_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Node___defaults__(struct _structs__Node *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Node___destroy__(struct _structs__Node *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Node_init(struct _structs__Node *this){
	((structs__NodeClass *)((lang__Object *)this)->class)->init((struct _structs__Node *) this);
}


void Node_init_withParams(struct _structs__Node *this, struct _structs__Node *prev, struct _structs__Node *next, uint8_t * data){
	((structs__NodeClass *)((lang__Object *)this)->class)->init_withParams((struct _structs__Node *) this, prev, next, data);
}


void Node___load__(){
}


struct _structs__Node *Node_new(struct _lang__Class *T){
	#line 222 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__Node *this = ((struct _structs__Node *) (Class_alloc(Node_class())));
	#line 222 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->T = T;
	#line 222 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	Node_init(this);
	#line 222 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return this;
}


struct _structs__Node *Node_new_withParams(struct _lang__Class *T, struct _structs__Node *prev, struct _structs__Node *next, uint8_t * data){
	#line 225 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__Node *this = ((struct _structs__Node *) (Class_alloc(Node_class())));
	#line 225 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->T = T;
	#line 225 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	Node_init_withParams(this, prev, next, data);
	#line 225 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return this;
}



void LinkedListIterator___defaults___impl(struct _structs__LinkedListIterator *this){
	Iterator___defaults___impl((lang__Iterator *) this);
}

void LinkedListIterator___destroy___impl(struct _structs__LinkedListIterator *this){
}

void LinkedListIterator_init_impl(struct _structs__LinkedListIterator *this, struct _structs__LinkedList *list){
	#line 234 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->list = list;
	#line 235 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->current = list->first;
}

bool LinkedListIterator_hasNext_impl(struct _structs__LinkedListIterator *this){
	#line 239 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	if (this->current){
		#line 240 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		return true;
	}
	#line 242 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return false;
}

void LinkedListIterator_next_impl(struct _structs__LinkedListIterator *this, void *__returnArg){
	#line 246 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__Node *prev = this->current;
	#line 247 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->current = this->current->next;
	#line 248 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	if (__returnArg){
		#line 248 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		memcpy(__returnArg, ((void *) (prev->data)), ((lang__Iterator*) this)->T->size);
	}
	#line 248 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return;
}

struct _structs__Node *LinkedListIterator_nextNode_impl(struct _structs__LinkedListIterator *this){
	#line 252 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__Node *prev = this->current;
	#line 253 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	this->current = this->current->next;
	#line 254 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return prev;
}

lang__Class *LinkedListIterator_class(){
	static bool __done__ = false;
	static structs__LinkedListIteratorClass class = {{{{
					.instanceSize = sizeof(structs__LinkedListIterator),
					.size = sizeof(void*),
					.name = "LinkedListIterator",
				},
				.__load__ = (void (*)()) LinkedListIterator___load__,
				.__defaults__ = (void (*)(struct _lang__Object *)) LinkedListIterator___defaults___impl,
				.__destroy__ = (void (*)(struct _lang__Object *)) LinkedListIterator___destroy___impl,
			},
			.hasNext = (bool (*)(struct _lang__Iterator *)) LinkedListIterator_hasNext_impl,
			.next = (void (*)(struct _lang__Iterator *, void *)) LinkedListIterator_next_impl,
		},
		.new = LinkedListIterator_new,
		.init = LinkedListIterator_init_impl,
		.nextNode = LinkedListIterator_nextNode_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Iterator_class();
	}
	return classPtr;
}


void LinkedListIterator___defaults__(struct _structs__LinkedListIterator *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void LinkedListIterator___destroy__(struct _structs__LinkedListIterator *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void LinkedListIterator_init(struct _structs__LinkedListIterator *this, struct _structs__LinkedList *list){
	((structs__LinkedListIteratorClass *)((lang__Object *)this)->class)->init((struct _structs__LinkedListIterator *) this, list);
}


bool LinkedListIterator_hasNext(struct _structs__LinkedListIterator *this){
	return (bool)((lang__IteratorClass *)((lang__Object *)this)->class)->hasNext((struct _lang__Iterator *) this);
}


void LinkedListIterator_next(struct _structs__LinkedListIterator *this, void *__returnArg){
	((lang__IteratorClass *)((lang__Object *)this)->class)->next((struct _lang__Iterator *) this, __returnArg);
}


struct _structs__Node *LinkedListIterator_nextNode(struct _structs__LinkedListIterator *this){
	return (struct _structs__Node *)((structs__LinkedListIteratorClass *)((lang__Object *)this)->class)->nextNode((struct _structs__LinkedListIterator *) this);
}


void LinkedListIterator___load__(){
}


struct _structs__LinkedListIterator *LinkedListIterator_new(struct _lang__Class *T, struct _structs__LinkedList *list){
	#line 234 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	struct _structs__LinkedListIterator *this = ((struct _structs__LinkedListIterator *) (Class_alloc(LinkedListIterator_class())));
	#line 234 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	((lang__Iterator*) this)->T = T;
	#line 234 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	LinkedListIterator_init(this, list);
	#line 234 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	return this;
}


void __OP_IDX_LinkedList_Int__T(void *__returnArg, lang__Class *T, structs__LinkedList *list, int index) {
	#line 260 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
	
	{
		#line 260 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		uint8_t *gcall[T->size];
		#line 260 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		LinkedList_get(list, gcall, index);
		#line 260 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		if (__returnArg){
			#line 260 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
			memcpy(__returnArg, ((void *) (gcall)), T->size);
		}
		#line 260 "/media/shared/dev/ooc/sdk/structs/LinkedList.ooc"
		return;
	};
}


void _structs_LinkedList_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		LinkedList___load__();
		Node___load__();
		LinkedListIterator___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_structs_List_load();
		_os_Terminal_load();
	}
}

