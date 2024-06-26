#include <iostream>

using namespace std;

class vcard : public components {
private:
	short vram;
	short frequency;
	string manufacturer;
	string pci_interface;

public:
	vcard() {}

	void set_vram(short vram) {
		this->vram = vram;
	}
	void set_video_frequency(short frequency) {
		this->frequency = frequency;
	}
	void set_video_manufacturer(string manufacturer) {
		this->manufacturer = manufacturer;
	}
	void set_video_pci_interface(string pci_interface) {
		this->pci_interface = pci_interface;
	}

	short get_vram() {
		return vram;
	}
	short get_video_frequency() {
		return frequency;
	}
	string get_video_manufacturer() {
		return manufacturer;
	}
	string get_video_pci_interface() {
		return pci_interface;
	}
};
