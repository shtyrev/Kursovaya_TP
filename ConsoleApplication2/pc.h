#include <iostream>

using namespace std;

class pc {
private:
	int pc_price;
	motherboard mb;
	processor cpu;
	cooling cool;
	ram memory;
public:
	pc() {}

	pc(int pr) {
		this->pc_price = pr;
	}

	void set_mb(motherboard& mb) {
		this->mb = mb;
	}
	void set_cpu(processor& cpu) {
		this->cpu = cpu;
	}
	void set_cooling(cooling cool) {
		this->cool = cool;
	}
	void set_memory(ram& memory) {
		this->memory = memory;
	}
	void set_pc_price(int price) {
		this->pc_price = price;
	}
	

	motherboard get_mb() {
		return mb;
	}
	processor get_cpu() {
		return cpu;
	}
	cooling get_cool() {
		return cool;
	}
	ram get_memory() {
		return memory;
	}
	int get_pc_price() {
		return pc_price;
	}

	
};
