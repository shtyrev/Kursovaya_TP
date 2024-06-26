#include <iostream>

using namespace std;

class cooling : public components {
private:

	string socket;
	short power_dissipation;
	short number_of_fan;

public:
	cooling() {}

	void set_cool_power_dissipation(short power_dissipation) {
		this->power_dissipation = power_dissipation;
	}
	void set_cool_number_of_fan(short number_of_fan) {
		this->number_of_fan = number_of_fan;
	}
	void set_cool_socket(string socket) {
		this->socket = socket;
	}

	short get_cool_power_dissipation() {
		return power_dissipation;
	}
	short get_cool_number_of_fan() {
		return number_of_fan;
	}
	string get_cool_socket() {
		return socket;
	}
};