/* structs.List source file, generated with ooc */
#include "List.h"

void List___defaults___impl(struct _structs__List *this){
	Iterable___defaults___impl((lang__Iterable *) this);
}

void List___destroy___impl(struct _structs__List *this){
}

void List_addAll_impl(struct _structs__List *this, struct _lang__Iterable *list){
	#line 24 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	List_addAll_atStart(this, 0, list);
}

void List_addAll_atStart_impl(struct _structs__List *this, int start, struct _lang__Iterable *list){
	#line 34 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	if (start == 0){
		#line 35 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		
		{
			#line 35 "/media/shared/dev/ooc/sdk/structs/List.ooc"
			uint8_t *element[((lang__Iterable*) this)->T->size];
			#line 35 "/media/shared/dev/ooc/sdk/structs/List.ooc"
			
			{
				#line 35 "/media/shared/dev/ooc/sdk/structs/List.ooc"
				struct _lang__Iterator *iter1 = Iterable_iterator(list);
				#line 35 "/media/shared/dev/ooc/sdk/structs/List.ooc"
				while (Iterator_hasNext(iter1)){
					#line 35 "/media/shared/dev/ooc/sdk/structs/List.ooc"
					Iterator_next(iter1, element);
					#line 36 "/media/shared/dev/ooc/sdk/structs/List.ooc"
					List_add(this, element);
				}
			};
		};
		#line 38 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		return;
	}
	#line 41 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	int index = 0;
	#line 42 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	struct _lang__Iterator *iter = Iterable_iterator(list);
	#line 43 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	while (index < start){
		#line 44 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		Iterator_next(iter, NULL);
		#line 45 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		index += 1;
	}
	#line 47 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	while (Iterator_hasNext(iter)){
		#line 47 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		
		{
			#line 47 "/media/shared/dev/ooc/sdk/structs/List.ooc"
			struct _lang__Class *gcall;
			#line 47 "/media/shared/dev/ooc/sdk/structs/List.ooc"
			Iterator_next(iter, &gcall);
			#line 47 "/media/shared/dev/ooc/sdk/structs/List.ooc"
			List_add(this, (uint8_t*) &gcall);
		};
	}
}

bool List_removeLast_impl(struct _structs__List *this){
	#line 62 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	int size = List_size(this);
	#line 63 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	if (size > 0){
		#line 64 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		List_removeAt(this, NULL, size - 1);
		#line 65 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		return true;
	}
	#line 67 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	return false;
}

bool List_contains_impl(struct _structs__List *this, uint8_t * element){
	#line 74 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	return List_indexOf(this, element) != 0 - 1;
}

bool List_isEmpty_impl(struct _structs__List *this){
	#line 92 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	return (List_size(this) == 0);
}

void List_last_impl(struct _structs__List *this, void *__returnArg){
	#line 131 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	
	{
		#line 131 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		struct _lang__Class *retval;
		#line 131 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		List_get(this, &retval, List_lastIndex(this));
		#line 131 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		if (__returnArg){
			#line 131 "/media/shared/dev/ooc/sdk/structs/List.ooc"
			memcpy(__returnArg, ((void *) (&retval)), ((lang__Iterable*) this)->T->size);
		}
		#line 131 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		return;
	};
}

size_t List_lastIndex_impl(struct _structs__List *this){
	#line 135 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	return List_size(this) - 1;
}

void *List_toArray_impl(struct _structs__List *this){
	#line 142 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	uint8_t *arr = (void *) gc_malloc(((size_t) (List_size(this) * ((lang__Iterable*) this)->T->size)));
	#line 143 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	
	{
		#line 143 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		int i;
		#line 143 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		for (i = 0; i < List_size(this); i++){
			#line 144 "/media/shared/dev/ooc/sdk/structs/List.ooc"
			
			{
				#line 144 "/media/shared/dev/ooc/sdk/structs/List.ooc"
				struct _lang__Class *gcall;
				#line 144 "/media/shared/dev/ooc/sdk/structs/List.ooc"
				__OP_IDX_List_Int__T(&gcall, ((lang__Iterable*) this)->T, this, i);
				#line 144 "/media/shared/dev/ooc/sdk/structs/List.ooc"
				memcpy(((void *) (arr + i * ((lang__Iterable*) this)->T->size)), ((void *) (&gcall)), ((lang__Iterable*) this)->T->size);
			};
		}
	};
	#line 146 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	return arr;
}

lang__Class *List_class(){
	static bool __done__ = false;
	static structs__ListClass class = {{{{
					.instanceSize = sizeof(structs__List),
					.size = sizeof(void*),
					.name = "List",
				},
				.__load__ = (void (*)()) List___load__,
				.__defaults__ = (void (*)(struct _lang__Object *)) List___defaults___impl,
				.__destroy__ = (void (*)(struct _lang__Object *)) List___destroy___impl,
			},
		},
		.add = List_add,
		.add_withIndex = List_add_withIndex,
		.addAll = List_addAll_impl,
		.addAll_atStart = List_addAll_atStart_impl,
		.clear = List_clear,
		.removeLast = List_removeLast_impl,
		.contains = List_contains_impl,
		.get = List_get,
		.indexOf = List_indexOf,
		.isEmpty = List_isEmpty_impl,
		.lastIndexOf = List_lastIndexOf,
		.removeAt = List_removeAt,
		.remove = List_remove,
		.set = List_set,
		.size = List_size,
		.clone = List_clone,
		.last = List_last_impl,
		.lastIndex = List_lastIndex_impl,
		.toArray = List_toArray_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Iterable_class();
	}
	return classPtr;
}


void List___defaults__(struct _structs__List *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void List___destroy__(struct _structs__List *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void List_add(struct _structs__List *this, uint8_t * element){
	((structs__ListClass *)((lang__Object *)this)->class)->add((struct _structs__List *) this, element);
}


void List_add_withIndex(struct _structs__List *this, int index, uint8_t * element){
	((structs__ListClass *)((lang__Object *)this)->class)->add_withIndex((struct _structs__List *) this, index, element);
}


void List_addAll(struct _structs__List *this, struct _lang__Iterable *list){
	((structs__ListClass *)((lang__Object *)this)->class)->addAll((struct _structs__List *) this, list);
}


void List_addAll_atStart(struct _structs__List *this, int start, struct _lang__Iterable *list){
	((structs__ListClass *)((lang__Object *)this)->class)->addAll_atStart((struct _structs__List *) this, start, list);
}


void List_clear(struct _structs__List *this){
	((structs__ListClass *)((lang__Object *)this)->class)->clear((struct _structs__List *) this);
}


bool List_removeLast(struct _structs__List *this){
	return (bool)((structs__ListClass *)((lang__Object *)this)->class)->removeLast((struct _structs__List *) this);
}


bool List_contains(struct _structs__List *this, uint8_t * element){
	return (bool)((structs__ListClass *)((lang__Object *)this)->class)->contains((struct _structs__List *) this, element);
}


void List_get(struct _structs__List *this, void *__returnArg, int index){
	((structs__ListClass *)((lang__Object *)this)->class)->get((struct _structs__List *) this, __returnArg, index);
}


int List_indexOf(struct _structs__List *this, uint8_t * element){
	return (int)((structs__ListClass *)((lang__Object *)this)->class)->indexOf((struct _structs__List *) this, element);
}


bool List_isEmpty(struct _structs__List *this){
	return (bool)((structs__ListClass *)((lang__Object *)this)->class)->isEmpty((struct _structs__List *) this);
}


int List_lastIndexOf(struct _structs__List *this, uint8_t * element){
	return (int)((structs__ListClass *)((lang__Object *)this)->class)->lastIndexOf((struct _structs__List *) this, element);
}


void List_removeAt(struct _structs__List *this, void *__returnArg, int index){
	((structs__ListClass *)((lang__Object *)this)->class)->removeAt((struct _structs__List *) this, __returnArg, index);
}


bool List_remove(struct _structs__List *this, uint8_t * element){
	return (bool)((structs__ListClass *)((lang__Object *)this)->class)->remove((struct _structs__List *) this, element);
}


void List_set(struct _structs__List *this, int index, uint8_t * element){
	((structs__ListClass *)((lang__Object *)this)->class)->set((struct _structs__List *) this, index, element);
}


int List_size(struct _structs__List *this){
	return (int)((structs__ListClass *)((lang__Object *)this)->class)->size((struct _structs__List *) this);
}


struct _lang__Iterator *List_iterator(struct _structs__List *this){
	return (struct _lang__Iterator *)((lang__IterableClass *)((lang__Object *)this)->class)->iterator((struct _lang__Iterable *) this);
}


struct _structs__List *List_clone(struct _structs__List *this){
	return (struct _structs__List *)((structs__ListClass *)((lang__Object *)this)->class)->clone((struct _structs__List *) this);
}


void List_last(struct _structs__List *this, void *__returnArg){
	((structs__ListClass *)((lang__Object *)this)->class)->last((struct _structs__List *) this, __returnArg);
}


size_t List_lastIndex(struct _structs__List *this){
	return (size_t)((structs__ListClass *)((lang__Object *)this)->class)->lastIndex((struct _structs__List *) this);
}


void *List_toArray(struct _structs__List *this){
	return (void *)((structs__ListClass *)((lang__Object *)this)->class)->toArray((struct _structs__List *) this);
}


void List___load__(){
}


void __OP_IDX_List_Int__T(void *__returnArg, lang__Class *T, structs__List *list, int i) {
	#line 152 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	
	{
		#line 152 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		uint8_t *gcall[T->size];
		#line 152 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		List_get(list, gcall, i);
		#line 152 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		if (__returnArg){
			#line 152 "/media/shared/dev/ooc/sdk/structs/List.ooc"
			memcpy(__returnArg, ((void *) (gcall)), T->size);
		}
		#line 152 "/media/shared/dev/ooc/sdk/structs/List.ooc"
		return;
	};
}

void __OP_IDX_ASS_List_Int_T(lang__Class *T, structs__List *list, int i, uint8_t * element) {
	#line 153 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	List_set(list, i, element);
}

void __OP_ADD_ASS_List_T(lang__Class *T, structs__List *list, uint8_t * element) {
	#line 154 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	List_add(list, element);
}

bool __OP_SUB_ASS_List_T__Bool(lang__Class *T, structs__List *list, uint8_t * element) {
	#line 155 "/media/shared/dev/ooc/sdk/structs/List.ooc"
	return List_remove(list, element);
}


void _structs_List_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		List___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
	}
}

