#include <concepts>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <limits>
#include <stdexcept>


// It's an overkill

typedef struct BitNode {
	struct BitNode *  next;
	std::size_t       minIndex;
	std::size_t       maxIndex;
	uint8_t *         field;
} BitNode;


template<typename T> requires std::integral<T>
class BitVector {

public:
	BitVector(std::initializer_list<T>);
	BitVector(size_t);
	~BitVector();

	T operator[](std::size_t i) {
		BitNode * node;
		
		__sentinel->minIndex = i;
		__sentinel->minIndex = i;

		for (node = __bitfield;
			 (i < node->minIndex) || (i > node->maxIndex);
			 node = node->next);

		for ()
		
		if (node == __sentinel)
			throw std::out_of_range;
			
		return 
	}
	
	constexpr T * begin() noexcept;
	constexpr T * end() noexcept;
	void insert(T);
	
private:
	BitNode *    __bitfield;
	BitNode *    __sentinel;
	std::size_t  __size;

	T  __min;
	T  __max;
};

	
template<typename T> requires std::integral<T>
BitVector<T>::
BitVector(std::initializer_list<T> l)
{
	__bitfield = new BitNode;
	__min = std::numeric_limits<T>::max();
	__max = std::numeric_limits<T>::min();

	for (auto & i : l) {
		__min = i < __min ? i : __min;
		__max = i > __max ? i : __max;
	}
	
	__bitfield->field    = new uint8_t[((__max - __min) >> 3) + 1];
	__bitfield->minIndex = 0;
	__bitfield->maxIndex = l.size() - 1;
	__bitfield->next     = __sentinel;

	for (auto & i : l)
		__bitfield->field[(i - __min) >> 3] |= 1 << (i % 8);
}

	
template<typename T> requires std::integral<T>
BitVector<T>::
BitVector(std::size_t s)
{
	
}


template<typename T> requires std::integral<T>
BitVector<T>::
~BitVector(void)
{
	BitNode *  node;
	BitNode *  toDelete;

	for (node = __bitfield;
		 node != nullptr;
		 node = node->next, delete toDelete)
	{
		delete [] node->field;
		toDelete = node;
	}
}


/*
 *  Everything is in alphabetical order
 */

template<typename T> requires std::integral<T>
constexpr T * BitVector<T>::
begin(void) noexcept {
	return &this[0];
}


template<typename T> requires std::integral<T>
constexpr T * BitVector<T>::
end(void) noexcept {
	return &this[__size - 1];
}


template<typename T> requires std::integral<T>
void BitVector<T>::
insert(T x)
{
	
}
