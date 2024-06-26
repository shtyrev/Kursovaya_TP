#include <iostream>

using namespace std;

class powersupply : public components {
private:
	short capacity;

public:
	powersupply() {}

	void set_ps_capacity(short capacity) {
		this->capacity = capacity;
	}

	short get_ps_capacity() {
		return capacity;
	}
};
