#include <iostream>

using namespace std;

class motherboard;

class components {
private:
	int price;
	string name;
public:
	components() {}
	void set_price(int price) {
		this->price = price;
	}
	void set_name(string name) {
		this->name = name;
	}
	int get_price() {
		return price;
	}
	string get_name() {
		return name;
	}
};
