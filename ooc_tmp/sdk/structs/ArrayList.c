/* structs.ArrayList source file, generated with ooc */
#include "ArrayList.h"

void ArrayList___defaults___impl(struct _structs__ArrayList *this){
	List___defaults___impl((structs__List *) this);
	#line 15 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->size = 0;
}

void ArrayList___destroy___impl(struct _structs__ArrayList *this){
}

void ArrayList_init_impl(struct _structs__ArrayList *this){
	#line 18 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayList_init_withCapacity(this, 10);
}

void ArrayList_init_withCapacity_impl(struct _structs__ArrayList *this, int capacity){
	#line 21 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->capacity = capacity;
	#line 22 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	void *genref = (void *) gc_malloc(((size_t) (capacity * ((lang__Iterable*) this)->T->size)));
	#line 22 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->data = genref;
}

void ArrayList_init_withData_impl(struct _structs__ArrayList *this, uint8_t *data, int size){
	#line 25 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->size = size;
	#line 26 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	void *genref = (void *) gc_malloc(((size_t) (size * ((lang__Iterable*) this)->T->size)));
	#line 26 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->data = genref;
	#line 27 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	memcpy(((void *) (this->data)), ((void *) (data)), ((size_t) (size * ((lang__Iterable*) this)->T->size)));
	#line 28 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->capacity = size;
}

void ArrayList_add_impl(struct _structs__ArrayList *this, uint8_t * element){
	#line 32 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayList_ensureCapacity(this, this->size + 1);
	#line 33 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	memcpy(((void *) (this->data + this->size * ((lang__Iterable*) this)->T->size)), ((void *) (element)), ((lang__Iterable*) this)->T->size);
	#line 34 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->size += 1;
}

void ArrayList_add_withIndex_impl(struct _structs__ArrayList *this, int index, uint8_t * element){
	#line 38 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayList_checkIndex(this, index);
	#line 39 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayList_ensureCapacity(this, this->size + 1);
	#line 40 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	uint8_t *dst, *src;
	#line 41 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	dst = ((uint8_t *) (this->data + (((lang__Iterable*) this)->T->size * (index + 1))));
	#line 42 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	src = ((uint8_t *) (this->data + (((lang__Iterable*) this)->T->size * index)));
	#line 43 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	int bsize = (this->size - index) * ((lang__Iterable*) this)->T->size;
	#line 44 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	memmove(((void *) (dst)), ((void *) (src)), ((size_t) (bsize)));
	#line 45 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	memcpy(((void *) (this->data + index * ((lang__Iterable*) this)->T->size)), ((void *) (element)), ((lang__Iterable*) this)->T->size);
	#line 46 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->size += 1;
}

void ArrayList_clear_impl(struct _structs__ArrayList *this){
	#line 50 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->size = 0;
}

void ArrayList_get_impl(struct _structs__ArrayList *this, void *__returnArg, int index){
	#line 54 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayList_checkIndex(this, index);
	#line 55 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	if (__returnArg){
		#line 55 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		memcpy(__returnArg, ((void *) (this->data + index * ((lang__Iterable*) this)->T->size)), ((lang__Iterable*) this)->T->size);
	}
	#line 55 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return;
}

int ArrayList_indexOf_impl(struct _structs__ArrayList *this, uint8_t * element){
	#line 59 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	int index = 0 - 1;
	#line 60 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	while (index < this->size){
		#line 61 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		index += 1;
		#line 62 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		uint8_t *candidate[((lang__Iterable*) this)->T->size];
		#line 63 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		memcpy(((void *) (candidate)), ((void *) (this->data + index * ((lang__Iterable*) this)->T->size)), ((lang__Iterable*) this)->T->size);
		#line 64 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		if ((*candidate) == (*element)){
			#line 64 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
			return index;
		}
	}
	#line 66 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return 0 - 1;
}

int ArrayList_lastIndexOf_impl(struct _structs__ArrayList *this, uint8_t * element){
	#line 70 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	int index = this->size;
	#line 71 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	while (index){
		#line 72 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		uint8_t *candidate[((lang__Iterable*) this)->T->size];
		#line 73 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		memcpy(((void *) (candidate)), ((void *) (this->data + index * ((lang__Iterable*) this)->T->size)), ((lang__Iterable*) this)->T->size);
		#line 74 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		if ((*candidate) == (*element)){
			#line 74 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
			return index;
		}
		#line 75 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		index -= 1;
	}
	#line 77 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return 0 - 1;
}

void ArrayList_removeAt_impl(struct _structs__ArrayList *this, void *__returnArg, int index){
	#line 81 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	uint8_t *element[((lang__Iterable*) this)->T->size];
	#line 81 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	memcpy(((void *) (element)), ((void *) (this->data + index * ((lang__Iterable*) this)->T->size)), ((lang__Iterable*) this)->T->size);
	#line 82 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	memmove(((void *) (this->data + (index * ((lang__Iterable*) this)->T->size))), ((void *) (this->data + ((index + 1) * ((lang__Iterable*) this)->T->size))), ((size_t) ((this->size - index) * ((lang__Iterable*) this)->T->size)));
	#line 83 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->size -= 1;
	#line 84 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	if (__returnArg){
		#line 84 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		memcpy(__returnArg, ((void *) (element)), ((lang__Iterable*) this)->T->size);
	}
	#line 84 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return;
}

bool ArrayList_remove_impl(struct _structs__ArrayList *this, uint8_t * element){
	#line 94 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	int index = ArrayList_indexOf(this, element);
	#line 95 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	if (index == 0 - 1){
		#line 95 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		return false;
	}
	#line 96 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	else {
		#line 97 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		ArrayList_removeAt(this, NULL, index);
	}
	#line 99 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return true;
}

void ArrayList_set_impl(struct _structs__ArrayList *this, int index, uint8_t * element){
	#line 107 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	memcpy(((void *) (this->data + index * ((lang__Iterable*) this)->T->size)), ((void *) (element)), ((lang__Iterable*) this)->T->size);
}

int ArrayList_size_impl(struct _structs__ArrayList *this){
	#line 113 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return this->size;
}

void ArrayList_ensureCapacity_impl(struct _structs__ArrayList *this, int newSize){
	#line 121 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	while (newSize > this->capacity){
		#line 122 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		ArrayList_grow(this);
	}
}

void ArrayList_grow_impl(struct _structs__ArrayList *this){
	#line 128 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->capacity = this->capacity * 1.1 + 10;
	#line 129 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	void *tmpData = (void *) gc_realloc(((void *) (this->data)), ((size_t) (this->capacity * ((lang__Iterable*) this)->T->size)));
	#line 130 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	if (tmpData){
		#line 131 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		this->data = tmpData;
	}
	#line 132 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	else {
		#line 133 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		printf("Failed to allocate %zu bytes of memory for array to grow! Exiting..\n", this->capacity * ((lang__Iterable*) this)->T->size);
		#line 135 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		int x = 0;
		#line 136 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		x = 1 / x;
	}
}

void ArrayList_checkIndex_impl(struct _structs__ArrayList *this, int index){
	#line 142 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	if (index < 0){
		#line 142 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		Exception_throw(Exception_new(ArrayList_class(), __OP_ADD_String_String__String("Index too small! ", __OP_ADD_Int_String__String(index, " < 0"))));
	}
	#line 143 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	if (index >= this->size){
		#line 143 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		Exception_throw(Exception_new(ArrayList_class(), __OP_ADD_String_String__String("Index too big! ", __OP_ADD_Int_String__String(index, __OP_ADD_String_Int__String(" >= ", ArrayList_size(this))))));
	}
}

struct _lang__Iterator *ArrayList_iterator_impl(struct _structs__ArrayList *this){
	#line 146 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return ((struct _lang__Iterator *) (ArrayListIterator_new(((lang__Iterable*) this)->T, this)));
}

struct _structs__ArrayList *ArrayList_clone_impl(struct _structs__ArrayList *this){
	#line 149 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	struct _structs__ArrayList *copy = ArrayList_new_withCapacity(((lang__Iterable*) this)->T, ArrayList_size(this));
	#line 150 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	List_addAll((struct _structs__List *) copy, ((struct _lang__Iterable *) (this)));
	#line 151 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return copy;
}

void *ArrayList_toArray_impl(struct _structs__ArrayList *this){
	#line 155 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return this->data;
}

lang__Class *ArrayList_class(){
	static bool __done__ = false;
	static structs__ArrayListClass class = {{{{{
						.instanceSize = sizeof(structs__ArrayList),
						.size = sizeof(void*),
						.name = "ArrayList",
					},
					.__load__ = (void (*)()) ArrayList___load__,
					.__defaults__ = (void (*)(struct _lang__Object *)) ArrayList___defaults___impl,
					.__destroy__ = (void (*)(struct _lang__Object *)) ArrayList___destroy___impl,
				},
				.iterator = (struct _lang__Iterator * (*)(struct _lang__Iterable *)) ArrayList_iterator_impl,
			},
			.add = (void (*)(struct _structs__List *, uint8_t *)) ArrayList_add_impl,
			.add_withIndex = (void (*)(struct _structs__List *, int, uint8_t *)) ArrayList_add_withIndex_impl,
			.addAll = (void (*)(struct _structs__List *, struct _lang__Iterable *)) List_addAll_impl,
			.addAll_atStart = (void (*)(struct _structs__List *, int, struct _lang__Iterable *)) List_addAll_atStart_impl,
			.clear = (void (*)(struct _structs__List *)) ArrayList_clear_impl,
			.removeLast = (bool (*)(struct _structs__List *)) List_removeLast_impl,
			.contains = (bool (*)(struct _structs__List *, uint8_t *)) List_contains_impl,
			.get = (void (*)(struct _structs__List *, void *, int)) ArrayList_get_impl,
			.indexOf = (int (*)(struct _structs__List *, uint8_t *)) ArrayList_indexOf_impl,
			.isEmpty = (bool (*)(struct _structs__List *)) List_isEmpty_impl,
			.lastIndexOf = (int (*)(struct _structs__List *, uint8_t *)) ArrayList_lastIndexOf_impl,
			.removeAt = (void (*)(struct _structs__List *, void *, int)) ArrayList_removeAt_impl,
			.remove = (bool (*)(struct _structs__List *, uint8_t *)) ArrayList_remove_impl,
			.set = (void (*)(struct _structs__List *, int, uint8_t *)) ArrayList_set_impl,
			.size = (int (*)(struct _structs__List *)) ArrayList_size_impl,
			.clone = (struct _structs__List * (*)(struct _structs__List *)) ArrayList_clone_impl,
			.last = (void (*)(struct _structs__List *, void *)) List_last_impl,
			.lastIndex = (size_t (*)(struct _structs__List *)) List_lastIndex_impl,
			.toArray = (void * (*)(struct _structs__List *)) ArrayList_toArray_impl,
		},
		.new = ArrayList_new,
		.init = ArrayList_init_impl,
		.new_withCapacity = ArrayList_new_withCapacity,
		.init_withCapacity = ArrayList_init_withCapacity_impl,
		.new_withData = ArrayList_new_withData,
		.init_withData = ArrayList_init_withData_impl,
		.ensureCapacity = ArrayList_ensureCapacity_impl,
		.grow = ArrayList_grow_impl,
		.checkIndex = ArrayList_checkIndex_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = List_class();
	}
	return classPtr;
}


void ArrayList___defaults__(struct _structs__ArrayList *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void ArrayList___destroy__(struct _structs__ArrayList *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void ArrayList_init(struct _structs__ArrayList *this){
	((structs__ArrayListClass *)((lang__Object *)this)->class)->init((struct _structs__ArrayList *) this);
}


void ArrayList_init_withCapacity(struct _structs__ArrayList *this, int capacity){
	((structs__ArrayListClass *)((lang__Object *)this)->class)->init_withCapacity((struct _structs__ArrayList *) this, capacity);
}


void ArrayList_init_withData(struct _structs__ArrayList *this, uint8_t *data, int size){
	((structs__ArrayListClass *)((lang__Object *)this)->class)->init_withData((struct _structs__ArrayList *) this, data, size);
}


void ArrayList_add(struct _structs__ArrayList *this, uint8_t * element){
	((structs__ListClass *)((lang__Object *)this)->class)->add((struct _structs__List *) this, element);
}


void ArrayList_add_withIndex(struct _structs__ArrayList *this, int index, uint8_t * element){
	((structs__ListClass *)((lang__Object *)this)->class)->add_withIndex((struct _structs__List *) this, index, element);
}


void ArrayList_clear(struct _structs__ArrayList *this){
	((structs__ListClass *)((lang__Object *)this)->class)->clear((struct _structs__List *) this);
}


void ArrayList_get(struct _structs__ArrayList *this, void *__returnArg, int index){
	((structs__ListClass *)((lang__Object *)this)->class)->get((struct _structs__List *) this, __returnArg, index);
}


int ArrayList_indexOf(struct _structs__ArrayList *this, uint8_t * element){
	return (int)((structs__ListClass *)((lang__Object *)this)->class)->indexOf((struct _structs__List *) this, element);
}


int ArrayList_lastIndexOf(struct _structs__ArrayList *this, uint8_t * element){
	return (int)((structs__ListClass *)((lang__Object *)this)->class)->lastIndexOf((struct _structs__List *) this, element);
}


void ArrayList_removeAt(struct _structs__ArrayList *this, void *__returnArg, int index){
	((structs__ListClass *)((lang__Object *)this)->class)->removeAt((struct _structs__List *) this, __returnArg, index);
}


bool ArrayList_remove(struct _structs__ArrayList *this, uint8_t * element){
	return (bool)((structs__ListClass *)((lang__Object *)this)->class)->remove((struct _structs__List *) this, element);
}


void ArrayList_set(struct _structs__ArrayList *this, int index, uint8_t * element){
	((structs__ListClass *)((lang__Object *)this)->class)->set((struct _structs__List *) this, index, element);
}


int ArrayList_size(struct _structs__ArrayList *this){
	return (int)((structs__ListClass *)((lang__Object *)this)->class)->size((struct _structs__List *) this);
}


void ArrayList_ensureCapacity(struct _structs__ArrayList *this, int newSize){
	((structs__ArrayListClass *)((lang__Object *)this)->class)->ensureCapacity((struct _structs__ArrayList *) this, newSize);
}


void ArrayList_grow(struct _structs__ArrayList *this){
	((structs__ArrayListClass *)((lang__Object *)this)->class)->grow((struct _structs__ArrayList *) this);
}


void ArrayList_checkIndex(struct _structs__ArrayList *this, int index){
	((structs__ArrayListClass *)((lang__Object *)this)->class)->checkIndex((struct _structs__ArrayList *) this, index);
}


struct _lang__Iterator *ArrayList_iterator(struct _structs__ArrayList *this){
	return (struct _lang__Iterator *)((lang__IterableClass *)((lang__Object *)this)->class)->iterator((struct _lang__Iterable *) this);
}


struct _structs__ArrayList *ArrayList_clone(struct _structs__ArrayList *this){
	return (struct _structs__ArrayList *)((structs__ListClass *)((lang__Object *)this)->class)->clone((struct _structs__List *) this);
}


void *ArrayList_toArray(struct _structs__ArrayList *this){
	return (void *)((structs__ListClass *)((lang__Object *)this)->class)->toArray((struct _structs__List *) this);
}


void ArrayList___load__(){
}


struct _structs__ArrayList *ArrayList_new(struct _lang__Class *T){
	#line 17 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	struct _structs__ArrayList *this = ((struct _structs__ArrayList *) (Class_alloc(ArrayList_class())));
	#line 17 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	((lang__Iterable*) this)->T = T;
	#line 17 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayList_init(this);
	#line 17 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return this;
}


struct _structs__ArrayList *ArrayList_new_withCapacity(struct _lang__Class *T, int capacity){
	#line 21 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	struct _structs__ArrayList *this = ((struct _structs__ArrayList *) (Class_alloc(ArrayList_class())));
	#line 21 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	((lang__Iterable*) this)->T = T;
	#line 21 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayList_init_withCapacity(this, capacity);
	#line 21 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return this;
}


struct _structs__ArrayList *ArrayList_new_withData(struct _lang__Class *T, uint8_t *data, int size){
	#line 25 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	struct _structs__ArrayList *this = ((struct _structs__ArrayList *) (Class_alloc(ArrayList_class())));
	#line 25 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	((lang__Iterable*) this)->T = T;
	#line 25 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayList_init_withData(this, data, size);
	#line 25 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return this;
}



void ArrayListIterator___defaults___impl(struct _structs__ArrayListIterator *this){
	Iterator___defaults___impl((lang__Iterator *) this);
	#line 162 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->index = 0;
}

void ArrayListIterator___destroy___impl(struct _structs__ArrayListIterator *this){
}

void ArrayListIterator_init_impl(struct _structs__ArrayListIterator *this, struct _structs__ArrayList *list){
	#line 164 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->list = list;
}

bool ArrayListIterator_hasNext_impl(struct _structs__ArrayListIterator *this){
	#line 167 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return this->index < ArrayList_size(this->list);
}

void ArrayListIterator_next_impl(struct _structs__ArrayListIterator *this, void *__returnArg){
	#line 171 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	uint8_t *element[((lang__Iterator*) this)->T->size];
	#line 171 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayList_get(this->list, element, this->index);
	#line 172 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	this->index += 1;
	#line 173 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	if (__returnArg){
		#line 173 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		memcpy(__returnArg, ((void *) (element)), ((lang__Iterator*) this)->T->size);
	}
	#line 173 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return;
}

lang__Class *ArrayListIterator_class(){
	static bool __done__ = false;
	static structs__ArrayListIteratorClass class = {{{{
					.instanceSize = sizeof(structs__ArrayListIterator),
					.size = sizeof(void*),
					.name = "ArrayListIterator",
				},
				.__load__ = (void (*)()) ArrayListIterator___load__,
				.__defaults__ = (void (*)(struct _lang__Object *)) ArrayListIterator___defaults___impl,
				.__destroy__ = (void (*)(struct _lang__Object *)) ArrayListIterator___destroy___impl,
			},
			.hasNext = (bool (*)(struct _lang__Iterator *)) ArrayListIterator_hasNext_impl,
			.next = (void (*)(struct _lang__Iterator *, void *)) ArrayListIterator_next_impl,
		},
		.new = ArrayListIterator_new,
		.init = ArrayListIterator_init_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Iterator_class();
	}
	return classPtr;
}


void ArrayListIterator___defaults__(struct _structs__ArrayListIterator *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void ArrayListIterator___destroy__(struct _structs__ArrayListIterator *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void ArrayListIterator_init(struct _structs__ArrayListIterator *this, struct _structs__ArrayList *list){
	((structs__ArrayListIteratorClass *)((lang__Object *)this)->class)->init((struct _structs__ArrayListIterator *) this, list);
}


bool ArrayListIterator_hasNext(struct _structs__ArrayListIterator *this){
	return (bool)((lang__IteratorClass *)((lang__Object *)this)->class)->hasNext((struct _lang__Iterator *) this);
}


void ArrayListIterator_next(struct _structs__ArrayListIterator *this, void *__returnArg){
	((lang__IteratorClass *)((lang__Object *)this)->class)->next((struct _lang__Iterator *) this, __returnArg);
}


void ArrayListIterator___load__(){
}


struct _structs__ArrayListIterator *ArrayListIterator_new(struct _lang__Class *T, struct _structs__ArrayList *list){
	#line 164 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	struct _structs__ArrayListIterator *this = ((struct _structs__ArrayListIterator *) (Class_alloc(ArrayListIterator_class())));
	#line 164 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	((lang__Iterator*) this)->T = T;
	#line 164 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayListIterator_init(this, list);
	#line 164 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return this;
}


void __OP_IDX_ArrayList_Int__T(void *__returnArg, lang__Class *T, structs__ArrayList *list, int i) {
	#line 179 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	
	{
		#line 179 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		uint8_t *gcall[T->size];
		#line 179 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		ArrayList_get(list, gcall, i);
		#line 179 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		if (__returnArg){
			#line 179 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
			memcpy(__returnArg, ((void *) (gcall)), T->size);
		}
		#line 179 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
		return;
	};
}

void __OP_IDX_ASS_ArrayList_Int_T(lang__Class *T, structs__ArrayList *list, int i, uint8_t * element) {
	#line 180 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayList_set(list, i, element);
}

void __OP_ADD_ASS_ArrayList_T(lang__Class *T, structs__ArrayList *list, uint8_t * element) {
	#line 181 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	ArrayList_add(list, element);
}

bool __OP_SUB_ASS_ArrayList_T__Bool(lang__Class *T, structs__ArrayList *list, uint8_t * element) {
	#line 182 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return ArrayList_remove(list, element);
}

structs__ArrayList *__OP_AS_T__star_SizeT__ArrayList(lang__Class *T, uint8_t *data, size_t size) {
	#line 183 "/media/shared/dev/ooc/sdk/structs/ArrayList.ooc"
	return ArrayList_new_withData(T, data, size);
}


void _structs_ArrayList_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		ArrayList___load__();
		ArrayListIterator___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_structs_List_load();
	}
}

