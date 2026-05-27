#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

// class utk menyimpan data mahasiswa
class dataMahasiswa {
    // di private ad data nama, nim, dan ipk mahasiswa
    private:
        string nama, nim;
        float ipk; 
    
    // public agar bisa diakses di luar class
    public:
        // input_data() utk input nama, nim, dan ipk
        void input_data() {
            cin.ignore(); 
            cout << "Nama: ";
            getline(cin, nama); // getline agar bisa mengambil nama yg lebih dari 1 kata
 
            cout << "NIM: ";
            cin >> nim;
 
            cout << "IPK: ";
            cin >> ipk;
        }
        
        // tampilkan_data() utk mengoutput nama, nim, dan IPK mahasiswa
        void tampilkan_data() {
            cout << "Nama : " << nama << "\n"; 
            cout << "NIM  : " << nim  << "\n";
            cout << "IPK  : " << fixed << setprecision(2) << ipk << "\n"; // pakai fixed dan setprecision agar hanya ouput 2 desimal
            cout << "------------------------\n";
        }
        
        // return_ipk() agar mengambil nilai IPK dari class
        float return_ipk() {
            return ipk;
        }
        
        // return_nama() agar mengambilnama dari class
        string return_nama() {
            return nama;
        }
};

vector<dataMahasiswa> mhs; // data mahasiswa disimpan dlm vektor bernama mhs dgn tipe data dari class dataMahasiswa

// pilihan menu tambah data
void tambah_data(){
    dataMahasiswa temp; // simpan data yg diinput ke data temp terlebih dahulu
    temp.input_data(); // input data
    mhs.push_back(temp); // simpan data dari temp ke mhs
    cout << "Data berhasil ditambahkan!\n";
    system("pause");
}

// pilihan menu tampilkan data
void tampilkan_data() {
    // jika data mahasiswa belum ada, maka akan menampilkan bahwa belum ada data mahasiswa
    if (mhs.empty()) {
        cout << "Belum ada data mahasiswa.\n";
        system("pause");
        return;
    }

    // jika data mahasiswa sudah ada, maka akan menampilkan data mahasiswa yg ada
    cout << "======== DATA MAHASISWA ========\n";
    for (auto &x : mhs) x.tampilkan_data(); // pakai auto utk mengakses tiap data yg, lalu mengakses void tampilkan_data() utk output data
    system("pause"); // kasih pause agar user bisa melihat data
}

// pilihan menu rata-rata IPK
void rata_ipk() {
    // jika data mahasiswa belum ada, maka akan menampilkan bahwa belum ada data mahasiswa
    if (mhs.empty()) {
        cout << "Belum ada data mahasiswa.\n";
        system("pause");
        return;
    }

    float rata = 0; 
    for (auto &x : mhs) rata += x.return_ipk(); // pakai auto utk mengakses tiap data yg, lalu menambahkan semua nilianya ke var. rata
    rata /= mhs.size(); // nilai rata dibagi dengan jumlah data yg ada, agar menjadi nilai IPK rata-rata

    cout << "Rata-rata IPK: " << fixed << setprecision(2) << rata << "\n"; // pakai fixed dan setprecision agar hanya ouput 2 desimal
    system("pause");
}

// pilihan menu IPK tertinggi
void ipk_tertinggi() {
    // jika data mahasiswa belum ada, maka akan menampilkan bahwa belum ada data mahasiswa
    if (mhs.empty()) {
        cout << "Belum ada data mahasiswa.\n";
        system("pause");
        return;
    }

    vector <string> vec; // utk menyimpan nama mahasiswa dengan nilai IPK tertinggi
    float highest = 0; // deklarasi nilai tertinggi dengan nilai terendah

    for (auto &x : mhs) {
        float temp = x.return_ipk(); // temp utk menyimpan nilai IPK mahasiswa yg sdg diakses
        // jika temp > lebih besar dari nilai tertinggi
        if (temp > highest) {
            highest = temp; // nilai tertinggi menjadi nilai temp
            vec.clear(); // vektor yg menyimpan nama dgn mahasiswa tertinggi dibersihkan
            vec.push_back(x.return_nama());  // simpan nama mahasiswa dgn nilai tertinggi saat ini
        }
        // jika temp = nilai tertinggi saat ini
        else if (temp == highest) {
            vec.push_back(x.return_nama()); // nama mahasiswa dimasukkan ke vektor yg berisi nama mahasiswa dgn nilai tertinggi
        }
    }

    cout << "IPK Tertinggi: " << fixed << setprecision(2) << highest << "\n"; // cout nilai IPK tertinggi, dgn 2 angka desimal
    // cout semua nama mahasiswa dengan IPK tertinggi, dengan urutan leksikografis
    cout << "Mahasiswa dengan IPK tertinggi:\n"; 
    sort(vec.begin(), vec.end());
    for (auto &x : vec) cout << "  - " << x << "\n";
    system("pause");
}

// pilihan menu IPK terendah
void ipk_terendah() {
    // jika data mahasiswa belum ada, maka akan menampilkan bahwa belum ada data mahasiswa
    if (mhs.empty()) {
        cout << "Belum ada data mahasiswa.\n";
        system("pause");
        return;
    }

    vector<string> vec; // utk menyimpan nama mahasiswa dengan nilai IPK terendah
    float lowest = 4; // deklarasi nilai terendah dengan nilai tertinggi

    for (auto &x : mhs) {
        float temp = x.return_ipk(); // temp utk menyimpan nilai IPK mahasiswa yg sdg diakses
        if (temp < lowest) {
            lowest = temp; // nilai terendah menjadi nilai temp
            vec.clear(); // vektor yg menyimpan nama dgn mahasiswa terendah dibersihkan
            vec.push_back(x.return_nama()); // simpan nama mahasiswa dgn nilai terendah saat ini
        }
        // jika temp = nilai terendah saat ini
        else if (temp == lowest) {
            vec.push_back(x.return_nama()); // nama mahasiswa dimasukkan ke vektor yg berisi nama mahasiswa dgn nilai terendah
        }
    }

    cout << "IPK Terendah: " << fixed << setprecision(2) << lowest << "\n"; // cout nilai IPK terendah, dgn 2 angka desimal
    // cout semua nama mahasiswa dengan IPK terendah, dengan urutan leksikografis
    cout << "Mahasiswa dengan IPK terendah:\n";
    sort(vec.begin(), vec.end());
    for (auto &x : vec) cout << "  - " << x << "\n";
    system("pause");
}

int main() {
    // ulangi terus selama user belum menekan opsi 6
    while (true) {
        system("cls"); // clear screen setiap kali membuka menu agar terminal tidak penuh
        int input_menu;
        // cout semua pilihan menu
        cout << "======= MENU UTAMA =======\n";
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Tampilkan seluruh data mahasiswa\n";
        cout << "3. Hitung rata-rata IPK mahasiswa\n";
        cout << "4. Mahasiswa dengan IPK tertinggi\n";
        cout << "5. Mahasiswa dengan IPK terendah\n";
        cout << "6. Keluar\n";
        cout << "==========================\n";
        cout << "Pilih menu: ";
        cin >> input_menu;

        system("cls");  // clear screen setiap kali ingin menjalankan program di void
        if      (input_menu == 1) tambah_data(); // jika memilih menu tambah data mahasiswa
        else if (input_menu == 2) tampilkan_data(); // jika memilih menu tampilkan seluruh data mahasiswa
        else if (input_menu == 3) rata_ipk(); // jika memilih menu hitung rata-rata IPK mahasiswa
        else if (input_menu == 4) ipk_tertinggi(); // jika memilih menu mahasiswa dengan IPk tertinggi
        else if (input_menu == 5) ipk_terendah(); // jika memilih menu mahasiswa dengan IPk terendah
        else if (input_menu == 6) { // jika memilih menu keluar
            cout << "Terima kasih!\n";
            system("pause");
            break;
        }
        else { // jika input menu diluar range 1 <= input <= 6
            cout << "Menu tidak valid!\n";
            system("pause");
        }
    }

    return 0; // program berhenti
}