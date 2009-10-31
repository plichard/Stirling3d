

ChainedList: class<T> {
	root: Node
	last: Node
	length: Int
	it : Node
	
	init: func {
		root = Node<T> new()
		last = root
		length = 0
		it = root
	}
	
	add: func(d: T) {
		last next = Node<T> new(last, null, d)
		last = last next
		length += 1
	}
	
	del: func(n: Int) -> Int{
		deled := getn(n)
		if(deled){
			n1 := deled prev
			n2 := deled next
			n1 next = n2
			n2 prev = n1
			return 0
		}
		return 1
	}
	
	insert: func(d: T, pos: Int){
		next := getn(pos)
		newNode :=  Node<T> new(next prev,next,d)
		next prev next = newNode
		next prev = newNode
	}
	
	getn: func(n: Int) -> Node{
		current := root
		i := 0
		printf("current: %p\n",current)
		current = current next
		while(current != null){
			if(i == n){
				return current
			}
			i += 1
			current = current next
		}
		return null
	}
	
	get: func(n: Int) -> T {
		ret := getn(n)
		if(ret){
			return ret
		}
		return null
	}
	
	next: func -> Node<T> {
		if(it != root){
			ret := it
			it = it next
			return ret
		}
		return null
	}
	
	print: func {
		current := root
		i := 0
		current = current next
		
		while(current != null){
			( i + ": " + current data) println()
			i += 1
			current = current next
		}
	}
	
	print: func ~range(b,e: Int){
		i := 0
		current := root
		current = current next
		i += 1
	}

}



Node: class<T>{
	prev: Node<T>
	next: Node<T>
	data: T
	
	init: func {
		prev = null
		next = null
	}
	
	init: func ~withParams(=prev, =next, = data)  {}
	
}

