#include <iostream>

using namespace std;

class processor : public components {
private:
	short cores;
	short frequency;
	string socket;
	string manufacturer;
	bool video;

public:
	processor() {}

	void set_cpu_cores(short cores) {
		this->cores = cores;
	}
	void set_cpu_frequency(short frequency) {
		this->frequency = frequency;
	}
	void set_cpu_socket(string socket) {
		this->socket = socket;
	}
	void set_cpu_manufacturer(string manufacturer) {
		this->manufacturer = manufacturer;
	}
	void set_cpu_video(bool video) {
		this->video = video;
	}

	short get_cpu_cores() {
		return cores;
	}
	short get_cpu_frequency() {
		return frequency;
	}
	string get_cpu_socket() {
		return socket;
	}
	string get_cpu_manufacturer() {
		return manufacturer;
	}
	bool get_cpu_video() {
		return video;
	}
};