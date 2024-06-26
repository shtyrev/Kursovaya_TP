#include <iostream>

using namespace std;

class drives : public components {
private:
	short speed;
	short capacity;
	string drive_type;
	string connector;

public:
	drives() {}

	void set_drive_capacity(short capacity) {
		this->capacity = capacity;
	}
	void set_drive_speed(short speed) {
		this->speed = speed;
	}
	void set_drive_type(string drive_type) {
		this->drive_type = drive_type;
	}
	void set_drive_connector(string connector) {
		this->connector = connector;
	}

	short get_drive_capacity() {
		return capacity;
	}
	short get_drive_speed() {
		return speed;
	}
	string get_drive_type() {
		return drive_type;
	}
	string get_drive_connector() {
		return connector;
	}
};
