#include <iostream>

using namespace std;

class pc {
private:
	int pc_price;
	motherboard mb;
	processor cpu;
	cooling cool;
	ram memory;
	powersupply ps;
	drives drive;
	enclosure _case;
	vcard vc;
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
	void set_ps(powersupply& ps) {
		this->ps = ps;
	}
	void set_drive(drives& drive) {
		this->drive = drive;
	}
	void set_case(enclosure& _case) {
		this->_case = _case;
	}
	void set_vcard(vcard& vc) {
		this->vc = vc;
	}
	void set_pc_price(int price) {
		this->pc_price = price;
	}
	

	motherboard& get_mb() {
		return mb;
	}
	processor& get_cpu() {
		return cpu;
	}
	cooling& get_cool() {
		return cool;
	}
	ram& get_memory() {
		return memory;
	}
	powersupply& get_ps() {
		return ps;
	}
	drives& get_drive() {
		return drive;
	}
	enclosure& get_case() {
		return _case;
	}
	vcard& get_vcard() {
		return vc;
	}
	int get_pc_price() {
		return pc_price;
	}

	
};
