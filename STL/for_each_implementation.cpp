
template<class Iterator, class Function>
Function for_each(Iterator first, Iterator last, Function f) {
	while (first != last) {
		f(*first);	
		++first;
	}
	return f;
}
