#include <ctime>
#include <iostream>
#include <vector>
#include "components.h"
#include "motherboard.h"
#include "processor.h"
#include "ram.h"
#include "cooling.h"
#include "powersupply.h"
#include "drives.h"
#include "case.h"
#include "videocard.h"
#include "pc.h"
#include "math.h"

using namespace std;

string mb_pci_interface[] = { "v3.0", "v4.0", "v5.0" };
string mb_formfactor[] = { "m-ATX", "ATX", "E-ATX" };
string mb_names[] = { "ASROCK", "MSI", "GIGABYTE", "ASUS" };
string mb_second_names[] = { " RTG 2024 Ultra", " CCS Max Fast", " PSL 2020 Prime", " CPS 8030", " 3900 Pro" };

string cpu_manufacturer[] = { "AMD", "Intel" };
string cpu_intel_names[] = { "Intel Core i3", "Intel Core i5", "Intel Core i7", "Intel Core i9" };
string cpu_intel_socket[] = { "LGA1700", "LGA1200", "LGA1151-v2", "LGA2066" };
string cpu_amd_names[] = {" Ryzen 3", "Ryzen 5", "Ryzen 7", "Ryzen 9" };
string cpu_amd_socket[] = { "AM3", "AM4", "AM5" };

string ram_names[] = { "AData RDG 43", "GSkill SFC3945", "Kingston RFRM3931", "Sumsung PBMRN3925" };
short ram_frequency[] = { 800, 1066, 1333, 1600, 1866, 2133, 2400, 1866, 2666, 2933, 3200, 4800, 5200, 5600, 6000 };

string ps_names[] = { "RTG2024 Pro Ultra Max", "CCSFast", "Prime PSL2020", "CPS 803", "PS 3983" };
string ps_manufacturer[] = { "Thermaltake", "Zalman", "Cooler Master", "Chieftec", "Deepcool"};

string vc_manufacturer[] = { "NVIDIA", "AMD" };
string vc_nvidia_names[] = { "GTX 660", "GTX 830", "GTX720", "GTX1080", "GTX1600", "RTX2060 super" , "RTX3060", "RTX4070 Ti" };
string vc_amd_names[] = { "RX 630", "RX 700", "RX 800", "RX 900 Pro", "RX 1200" };
short vc_vram_volume[] = { 2, 4, 6, 8, 12, 16, 24 };

string drive_ssd_names[] = { "SSDReal130", "SUP340", "A104", "FR850", "SL301"};
string drive_hdd_names[] = { "HW990", "RSFH3330", "IOFHW-3904", "CYMH-5600", "DYW227"};
string drive_connectors[] = { "M2", "Sata" };

string enclosure_names[] = { "BlackLine pro", "WhitePastel", "DreamingCoreBlue", "ScarletAndViolet", "FreedomView" };

string cooling_liquid_names[] = { "FCD285", "LEC1000", "AFAF250", "LiquidMaxC" };
string cooling_air_names[] = { "FanMC2034", "AirPro20", "YKC-1003", "FTS740" };

int rand_range(int, int);

processor _cpu_set(bool);
void _cpu_get(processor&);
motherboard _mb_set(processor&, bool);
void _mb_get(motherboard&);
powersupply _powersupply_set(bool);
void _powersupply_get(powersupply&);
ram _ram_set(motherboard&, bool);
void _ram_get(ram&);
vcard _vc_set(motherboard&);
void _vc_get(vcard&);
drives _drive_set(motherboard&, bool);
void _drive_get(drives&);
enclosure _case_set(motherboard&, bool);
void _case_get(enclosure&);
cooling _cool_set(motherboard&, bool);
void _cool_get(cooling&);

void build_pc(bool);

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    char check = 0;
    cout << "Добро пожаловать\n";
    while (check != 'q') {
        cout << "\nВведите :" << endl;
        cout << "1 - если хотите собрать офисный ПК" << endl;
        cout << "2 - если хотите собрать профессиональный ПК" << endl;
        cout << "q - для выхода из программы" << endl << endl;
        cin >> check;

        switch (check) {
        case '1': { build_pc(false); break; }
        case '2': { build_pc(true);  break; }
        case 'q': { cout << "Выход!\n"; break; }
        }
    }
}

void build_pc(bool type_pc) {
    int component_view_number = 3;
    vector<motherboard> vect_mb;
    vector <ram> vect_memory;
    vector <processor> vect_cpu;
    vector <cooling> vect_fan;
    vector <powersupply> vect_ps;
    vector <enclosure> vect_case;
    vector <drives> vect_drive;
    vector <vcard> vect_vcard;
    pc compucter;

    /*   for (int i = 0; i < component_view_number; i++) {
           vect_cpu.push_back(_cpu_set(type_pc));
       }
       for (int i = 0; i < component_view_number; i++) {
           _cpu_get(vect_cpu[i]);
       } */
    vect_cpu.push_back(_cpu_set(type_pc));
    _cpu_get(vect_cpu[0]);

    vect_mb.push_back(_mb_set(vect_cpu[0], type_pc));
    _mb_get(vect_mb[0]);

    vect_fan.push_back(_cool_set(vect_mb[0], type_pc));
    _cool_get(vect_fan[0]);

    vect_memory.push_back(_ram_set(vect_mb[0], type_pc));
    _ram_get(vect_memory[0]);

    vect_ps.push_back(_powersupply_set(type_pc));
    _powersupply_get(vect_ps[0]);

    vect_drive.push_back(_drive_set(vect_mb[0], type_pc));
    _drive_get(vect_drive[0]);

    vect_case.push_back(_case_set(vect_mb[0], type_pc));
    _case_get(vect_case[0]);

    if (type_pc) {
        vect_vcard.push_back(_vc_set(vect_mb[0]));
        _vc_get(vect_vcard[0]);
    }
}

motherboard _mb_set(processor& _cpu, bool type_pc) {
    motherboard _mb;
    _mb.set_name(mb_names[rand() % 3] + mb_second_names[rand() % 4]);
    _mb.set_mp_socket(_cpu.get_cpu_socket());
    _mb.set_mp_pci_interface(mb_pci_interface[rand() % 2]);
    if (type_pc) {
        _mb.set_mp_m2_slot(true);
        _mb.set_price((rand() % (20 - 7 + 1) + 7) * 1000);
        _mb.set_mp_formfactor(mb_formfactor[rand() % 1 + 1]);
        _mb.set_mp_ram_types(rand() % (5 - 4 + 1) + 4);
        _mb.set_mp_ram_slots(pow(2, rand() % 1 + 2));
        
    } else {
        _mb.set_mp_m2_slot(false);
        _mb.set_price((rand() % (9 - 3 + 1) + 3) * 1000);
        _mb.set_mp_formfactor(mb_formfactor[rand() % 2]);
        _mb.set_mp_ram_types(rand() % (4 - 3 + 1) + 3);
        _mb.set_mp_ram_slots(pow(2, rand() % 1 + 1));
    }

    return _mb;
}

void _mb_get(motherboard& _mb) {
    cout << "**МП**" << endl;
    cout << "Название: " << _mb.get_name() << endl;
    cout << "Цена: " << _mb.get_price() << " руб" << endl;
    cout << "Сокет: " << _mb.get_mp_socket() << endl;
    cout << "Формфактор: " << _mb.get_mp_formfactor() << endl;
    cout << "Типы RAM: DDR" << _mb.get_mp_ram_types() << endl;
    cout << "Количество слотов под RAM: " << _mb.get_mp_ram_slots() << endl;
    cout << "PCI интерфейс: " << _mb.get_mp_pci_interface() << endl;
    if (_mb.get_mp_m2_slot()) {
        cout << "M2 слот присутствует.\n" << endl;
    }
    else {
        cout << "M2 слот отсутствует.\n" << endl;
    }
}


processor _cpu_set(bool type_pc) {
    processor _proc;

    _proc.set_cpu_manufacturer(cpu_manufacturer[rand_range(0, 1)]);
    if (_proc.get_cpu_manufacturer() == "AMD") {
        if (type_pc) {
            _proc.set_name(cpu_amd_names[rand_range(2, 3)]);
            _proc.set_cpu_socket(cpu_amd_socket[rand_range(1, 2)]);
        } else {
            _proc.set_name(cpu_amd_names[rand_range(0, 1)]);
            _proc.set_cpu_socket(cpu_amd_socket[rand_range(0, 1)]);
        }  
    } 
    else {
        if (type_pc) {
            _proc.set_name(cpu_intel_names[rand_range(1, 3)]);
        }
        else {
            _proc.set_name(cpu_intel_names[rand_range(0, 1)]);
        }
        _proc.set_cpu_socket(cpu_intel_socket[rand_range(0, 3)]);
    }
    if (type_pc) {
        _proc.set_cpu_video(false);
        _proc.set_price((rand() % (60 - 24 + 1) + 24) * 500);
        _proc.set_cpu_cores(rand_range(2, 4) * 2);
        _proc.set_cpu_frequency(rand() % (5000 - 2200 + 1) + 2200);
    } 
    else {
        _proc.set_cpu_video(true);
        _proc.set_price((rand() % (16 - 5 + 1) + 5) * 500);
        _proc.set_cpu_cores(rand_range(1, 3) * 2);
        _proc.set_cpu_frequency(rand() % (3200 - 1200 + 1) + 1200);
    }

    return _proc;
} 

void _cpu_get(processor& _proc) {
    cout << "**ПРОЦЕССОР**" << endl;
    cout << _proc.get_name() << " - " << _proc.get_price() << "руб\n";
    cout << "Производитель: " << _proc.get_cpu_manufacturer() << endl;
    cout << "Сокет: " << _proc.get_cpu_socket() << endl;
    cout << "Кол-во ядер: " << _proc.get_cpu_cores() << endl;
    cout << "Частота: " << _proc.get_cpu_frequency()<< "МГц" << endl;
    if (_proc.get_cpu_video()) {
        cout << "Видео ядро: Есть\n" << endl;
    } else {
        cout << "Видео ядро: Отсутствует\n" << endl;
    }
}


cooling _cool_set(motherboard& _mb, bool type_pc) {
    cooling _cl;

    _cl.set_cool_socket(_mb.get_mp_socket());
    if (type_pc) {
        bool type = rand() % 1;
        if (type) {
            // Жидкое охлаждение
            _cl.set_name(cooling_liquid_names[rand_range(0, 2)]);
            _cl.set_price(rand_range(20, 100) * 100);
            _cl.set_cool_number_of_fan(rand_range(2, 3));
            _cl.set_cool_power_dissipation(rand_range(3, 6) * 40);
        }
        else {
            // Воздушное
            _cl.set_name(cooling_air_names[rand_range(0, 2)]);
            _cl.set_price(rand_range(3, 40) * 100);
            _cl.set_cool_number_of_fan(rand_range(1, 2));
            _cl.set_cool_power_dissipation(rand_range(5, 9) * 10);
        }
    }
    else {
        // Воздушное
        _cl.set_name(cooling_air_names[rand_range(0, 2)]);
        _cl.set_price(rand_range(3, 40) * 100);
        _cl.set_cool_number_of_fan(rand_range(1, 2));
        _cl.set_cool_power_dissipation(rand_range(5, 9) * 10);
    }

    return _cl;
}

void _cool_get(cooling& _cl) {
    cout << "**ОХЛАД**" << endl;
    cout << "Название: " << _cl.get_name() << endl;
    cout << "Цена: " << _cl.get_price() << " руб" << endl;
    cout << "Сокет: " << _cl.get_cool_socket() << endl;
    cout << "Количество вентиляторов: " << _cl.get_cool_number_of_fan() << endl;
    cout << "Рассеиваемая мощность: " << _cl.get_cool_power_dissipation() << " Вт\n" << endl;
}


ram _ram_set(motherboard& _mb, bool type_pc) {
    ram _ram;

    _ram.set_name(ram_names[rand_range(0, 2)]);
    _ram.set_ram_ram_types(_mb.get_mp_ram_types());
    switch (_ram.get_ram_ram_types()) {
    case 3: { _ram.set_ram_frequency(ram_frequency[rand_range(0, 6)]); break; }
    case 4: { _ram.set_ram_frequency(ram_frequency[rand_range(3, 9)]); break; }
    case 5: { _ram.set_ram_frequency(ram_frequency[rand_range(10, 13)]); break; }
    }
    if (type_pc) {
        _ram.set_ram_capacity(pow(2, rand_range(3, 6)) * 1024);
        _ram.set_price(rand_range(60, 140) * 100);
    }
    else
    {
        _ram.set_ram_capacity(pow(2, rand_range(0, 3)) * 1024);
        _ram.set_price(rand_range(15, 60) * 100);
    }

    return _ram;
}

void _ram_get(ram& _ram) {
    cout << "**ПАМЯТЬ**" << endl;
    cout << "Название: " << _ram.get_name() << endl;
    cout << "Цена: " << _ram.get_price() << " руб" << endl;
    cout << "Объем памяти: " << _ram.get_ram_capacity() << " MB" << endl;
    cout << "Тип памяти: DDR" << _ram.get_ram_ram_types() << endl;
    cout << "Частота: " << _ram.get_ram_frequency() << " МГц\n" << endl;
}


powersupply _powersupply_set(bool type_pc){
    powersupply _ps;

    _ps.set_name(ps_manufacturer[(rand() % (5))] + " " + ps_names[rand() % 5]);
    if (type_pc) {
        _ps.set_price(rand_range(50, 120) * 100);
        _ps.set_ps_capacity(rand_range(10, 17) * 50);
    }
    else
    {
        _ps.set_price(rand_range(10, 40) * 100);
        _ps.set_ps_capacity(rand_range(6, 9) * 50);
    }
    return _ps;
}

void _powersupply_get(powersupply& _ps) {
    cout << "**БП**" << endl;
    cout << "Название: " << _ps.get_name() << endl;
    cout << "Цена: " << _ps.get_price() << " руб" << endl;
    cout << "Мощность: " << _ps.get_ps_capacity() << " Вт\n" << endl;
}


drives _drive_set(motherboard& _mb, bool type_pc) {
    drives _dr;
    
    if (type_pc){
        _dr.set_name(drive_ssd_names[rand() % 4]);
        _dr.set_drive_type("SSD");
        _dr.set_drive_capacity(rand_range(1, 4) * 1000);
        if (_mb.get_mp_m2_slot()) {
            _dr.set_drive_connector(drive_connectors[rand() % 1]);
        }
        else {
            _dr.set_drive_connector("SATA");
        }
        _dr.set_drive_speed((rand_range(50, 750)) * 10);
        _dr.set_price(rand_range(20, 120) * 100);
    }
    else {
        _dr.set_name(drive_hdd_names[rand() % 4]);
        _dr.set_drive_capacity(rand_range(1, 2) * 5 * 100);
        _dr.set_drive_type("HDD");
        _dr.set_drive_connector("SATA");
        if (rand() % 1) {
            _dr.set_drive_speed(5400);
        }
        else
        {
            _dr.set_drive_speed(7200);
        }
        
        _dr.set_price(rand_range(10, 40) * 100);
    }

    return _dr;

}

void _drive_get(drives& _dr) {
    cout << "**ДИСКИ**" << endl;
    cout << "Название: " << _dr.get_name() << endl;
    cout << "Цена: " << _dr.get_price() << " руб" << endl;
    cout << "Тип диска: " << _dr.get_drive_type() << endl;
    cout << "Тип коннектора: " << _dr.get_drive_connector() << endl;
    if (_dr.get_drive_type() == "SSD") {
        cout << "Скорость: " << _dr.get_drive_speed() << " Мб/с" << endl;
    }
    else {
        cout << "Скорость: " << _dr.get_drive_speed() << " Об/мин" << endl;
    }
    cout << "Объем: " << _dr.get_drive_capacity() << " Мб" << endl << endl;
}


enclosure _case_set(motherboard& _mb, bool type_pc) {
    enclosure _case;
    
    _case.set_name(enclosure_names[rand() % 4]);
    _case.set_case_formfactor(_mb.get_mp_formfactor());

    if (type_pc) {
        _case.set_price(rand_range(40, 120) * 100 - 1);
    }
    else
    {
        _case.set_price(rand_range(10, 30) * 100 - 1);
    }

    return _case;
}

void _case_get(enclosure& _case) {
    cout << "**КОРПУС**" << endl;
    cout << "Название: " << _case.get_name() << endl;
    cout << "Цена: " << _case.get_price() << " руб" << endl;
    cout << "Формфактор: " << _case.get_case_formfactor() << endl << endl;
}


vcard _vc_set(motherboard& _mb) {
    vcard _vc;

    short manuf_rand_seed = rand_range(0, 1);
    switch (manuf_rand_seed) {
    case 0: { _vc.set_name(vc_nvidia_names[rand() % 7]); _vc.set_video_manufacturer(vc_manufacturer[manuf_rand_seed]); break; }
    case 1: { _vc.set_name(vc_amd_names[rand() % 4]); _vc.set_video_manufacturer(vc_manufacturer[manuf_rand_seed]); break; }
    }
    _vc.set_price(rand_range(20, 100) * 1000);
    _vc.set_video_frequency(rand_range(7000, 14000));
    _vc.set_vram(vc_vram_volume[rand_range(0, 6)] * 1024);
    _vc.set_video_pci_interface(_mb.get_mp_pci_interface());
        
    return _vc;
}

void _vc_get(vcard& _vc) {
    cout << "**ВИДЕОКАРТА**" << endl;
    cout << "Название: " << _vc.get_name() << endl;
    cout << "Цена: " << _vc.get_price() << " руб" << endl;
    cout << "Производитель: " << _vc.get_video_manufacturer() << endl;
    cout << "Частота: " << _vc.get_video_frequency() << " МГц" << endl;
    cout << "Видеопамять: " << _vc.get_vram() << " ГБ" << endl;
    cout << "PCI интерфейс: " << _vc.get_video_pci_interface() << endl << endl;
}

int rand_range(int start, int end) {
    int val = rand() % (end - start + 1) + start;
    return val;
}