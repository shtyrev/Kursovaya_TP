#include <iostream>

using namespace std;

class enclosure : public components {
private:
	string formfactor;

public:
	enclosure() {}

	void set_case_formfactor(string formfactor) {
		this->formfactor = formfactor;
	}

	string get_case_formfactor() {
		return formfactor;
	}
};
