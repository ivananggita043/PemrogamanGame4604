#include <iostream>
using namespace std;

// Deklarasi struct tokoh
struct tokoh {
    int MP = 70;
    int HP = 90;
    int damage = 2;
};

// Deklarasi struct inv
struct inv {
    int herbs = 3;
    int Mpotion = 2;
    int Hpotion = 2;
    int Sword[3] = {15, 17, 23};
    int jumlahSword = 3; // Menambah variabel untuk menyimpan jumlah pedang
};

// Fungsi untuk menampilkan stat tokoh
void tampilStat(tokoh *pemain) {
    cout << "===Stat Tokoh===" << endl;
    cout << "HP     : " << pemain->HP << endl;
    cout << "MP     : " << pemain->MP << endl;
    cout << "Damage : " << pemain->damage << endl;
}

// Fungsi untuk menampilkan inventori
void tampilInv(inv *inventori) {
    cout << "====Inventori====" << endl;
    cout << "1. Herbs         : " << inventori->herbs << endl;
    cout << "2. Mana Potion   : " << inventori->Mpotion << endl;
    cout << "3. Health Potion : " << inventori->Hpotion << endl;
    cout << "4. Sword         : " << inventori->jumlahSword << " ("; //Menampilkan jumlah pedang
    for (int i = 0; i < inventori->jumlahSword; ++i) {
        cout << inventori->Sword[i]; //Menampilkan damage pedang
        if (i != inventori->jumlahSword - 1) cout << ", ";
    }
    cout << ")" << endl;
    cout << "================" << endl;
}

// Fungsi untuk menggunakan Mana Potion
void useMpotion(tokoh *pemain, inv *inventori) {
    if (pemain->MP < 100 && inventori->Mpotion > 0) { //Kondisi jika MP kurang dari 100 dan Mana Potion lebih dari 1 di inventori
        pemain->MP += 50; //Maka MP akan bertambah 50
        if (pemain->MP > 100) pemain->MP = 100; // Maksimum Mana adalah 100
        inventori->Mpotion--; //Mana Potion di inventori akan berkurang
        cout << "Sukses mengunakan Mana Potion. MP +50." << endl;
    } else {
        cout << "Tidak bisa menggunakan Mana Potion. Karena MP sudah full atau Mana Potion sudah habis." << endl;
    }
}

// Fungsi untuk menggunakan Herbs
void useHerbs(tokoh *pemain, inv *inventori) {
    if (pemain->HP < 100 && inventori->herbs > 0) { //Kondisi jika HP kurang dari 100 dan Herbs lebih dari 1 di inventori
        pemain->HP += 10; //Maka HP akan bertambah 10
        if (pemain->HP > 100) pemain->HP = 100; // Maksimum Healt adalah 100
        inventori->herbs--;
        cout << "Sukses mengunakan Herbs. HP +10." << endl;
    } else {
        cout << "Tidak bisa menggunakan Herbs. Karena HP sudah full atau Herbs sudah habis." << endl;
    }
}

// Fungsi untuk menggunakan Health Potion
void useHpotion(tokoh *pemain, inv *inventori) {
    if (pemain->HP < 100 && inventori->Hpotion > 0) { //Kondisi jika HP kurang dari 100 dan Health Potion lebih dari 1 di inventori
        pemain->HP += 50; //Maka HP akan bertambah 50
        if (pemain->HP > 100) pemain->HP = 100; // Maksimum HP adalah 100
        inventori->Hpotion--;
        cout << "Sukses mengunakan Health Potion. HP +50." << endl;
    } else {
        cout << "Tidak bisa menggunakan Health Potion. Karena HP sudah full atau Health Potion sudah habis." << endl;
    }
}

// Fungsi untuk equip Sword
void equipSword(tokoh *pemain, inv *inventori, int choice) {
    if (choice >= 1 && choice <= inventori->jumlahSword) {
        pemain->damage += inventori->Sword[choice - 1];
        cout << "Sukses memakai pedang. Damage + " << inventori->Sword[choice - 1] << "." << endl;
    } else {
        cout << "Invalid." << endl;
    }
}

int main() {
    tokoh pemain;
    inv inventori;

    int pilih;
    do {
        tampilStat(&pemain);
        tampilInv(&inventori);
        cout << "Pilih aksi! : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                useHerbs(&pemain, &inventori);
                break;
            case 2:
                useMpotion(&pemain, &inventori);
                break;
            case 3:
                useHpotion(&pemain, &inventori);
                break;
            case 4:
                int equip;
                cout << "Pilih nomor pedang untuk dipakai: ";
                cin >> equip;
                equipSword(&pemain, &inventori, equip);
                break;
            default:
                cout << "Aksi tidak valid." << endl;
        }
    } while (pilih != 0);

    return 0;
}
