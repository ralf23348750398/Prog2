class IntArray {
public:
	IntArray(unsigned int size) {
		data = new int[size];
		this->size = size;
	}
	~IntArray() {
		delete[] data;
	}

	//Copy-Constructor
	IntArray(const IntArray& source) {
		this->size = source.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = source.data[i];
		}
	}

	//Move-Constructor - could also be defined as a simple method (e.g. 'move') which then can be called directly
	IntArray(IntArray&& source) noexcept {
		size = source.size;
		data = source.data;
		source.data = nullptr;
		source.size = 0;
	}

	//overloading '=' operator to execute move - otherwise it would need to be called manually (e.g. using std::move)
	IntArray& operator=(IntArray&& source) noexcept {
		size = source.size;
		data = source.data;
		source.data = nullptr;
		source.size = 0;
	}


	// ... , getter, setter ...
private:
	int* data;
	unsigned int size;
};