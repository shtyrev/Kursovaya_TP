#include <iostream>

using namespace std;

class ram : public components {
private:
	short capacity;
	short frequency;
	short ram_types;

public:
	ram() {}

	void set_ram_capacity(short capacity) {
		this->capacity = capacity;
	}
	void set_ram_frequency(short frequency) {
		this->frequency = frequency;
	}
	void set_ram_ram_types(short ram_types) {
		this->ram_types = ram_types;
	}

	short get_ram_capacity() {
		return capacity;
	}
	short get_ram_frequency() {
		return frequency;
	}
	short get_ram_ram_types() {
		return ram_types;
	}
};