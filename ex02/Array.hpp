#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template<typename T>
class Array {
	private:
		T* _arr;
		unsigned int _len;
	public:
		Array(void): _arr(new T[0]), _len(0) {}
		Array(unsigned int n): _arr(new T[n]), _len(n) {}
		Array(const Array& ref): _arr(new T[ref._len]), _len(ref._len) {
			for (int i = 0; i < _len; i++) this->_arr[i] = ref._arr[i];
		}
		Array& operator=(const Array& ref) {
			delete[] this->_arr;

			this->_len = ref._len;
			this->_arr = new T[this->_len];
			for (int i = 0; i < _len; i++) this->_arr[i] = ref._arr[i];
		}
		T& operator[](unsigned int i) {
			if (i >= _size) throw InvalidIndexException();
			return this->_arr[i];
		};
		~Array(void) {
			delete[] this->_arr;
		}
		unsigned int size(void) const {
			return this->_len;
		}

		class InvalidIndexException : public std::exception {
			public:
				const char *what() const throw() {
					return "exception: index is out of bounds";
				};
		}
};

#endif