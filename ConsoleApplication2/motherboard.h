#include <iostream>

using namespace std;

class motherboard : public components{
private:
	short ram_slots;
	string socket;
	string formfactor;
	short ram_types;
	string pci_interface;
	bool m2_slot;

public:
	motherboard() {}

	void set_mp_ram_slots(short ram_slots) {
		this->ram_slots = ram_slots;
	}
	void set_mp_socket(string socket) {
		this->socket = socket;
	}
	void set_mp_formfactor(string formfactor) {
		this->formfactor = formfactor;
	}
	void set_mp_ram_types(short ram_types) {
		this->ram_types = ram_types;
	}
	void set_mp_pci_interface(string pci_interface) {
		this->pci_interface = pci_interface;
	}
	void set_mp_m2_slot(bool m2_slot) {
		this->m2_slot = m2_slot;
	}

	short get_mp_ram_slots() {
		return ram_slots;
	}
	string get_mp_socket() {
		return socket;
	}
	string get_mp_formfactor() {
		return formfactor;
	}
	short get_mp_ram_types() {
		return ram_types;
	}
	string get_mp_pci_interface() {
		return pci_interface;
	}
	bool get_mp_m2_slot() {
		return m2_slot;
	}
};
