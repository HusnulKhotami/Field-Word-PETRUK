#include <iostream>
#include <cstring>
using namespace std;

void toUpperCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// Fungsi untuk mencari kata secara horizontal
bool horizontal(const char* word, char matrix[][24], int wordLen) {
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j <= 24 - wordLen; j++) {
            bool found = true;
            for (int k = 0; k < wordLen; k++) {
                if (matrix[i][j + k] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }
    }
    return false;
}

// Fungsi untuk mencari kata secara vertikal
bool vertical(const char* word, char matrix[][24], int wordLen) {
    for (int i = 0; i <= 24 - wordLen; i++) {
        for (int j = 0; j < 24; j++) {
            bool found = true;
            for (int k = 0; k < wordLen; k++) {
                if (matrix[i + k][j] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }
    }
    return false;
}

// Fungsi untuk mencari kata secara diagonal
bool diagonal(const char* word, char matrix[][24], int wordLen) {
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 24; ++j) {
            bool found = true;
            // Cek diagonal kanan bawah
            if (i <= 24 - wordLen && j <= 24 - wordLen) {
                for (int k = 0; k < wordLen; k++) {
                    if (matrix[i + k][j + k] != word[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) return true;
            }
            // Cek diagonal kiri bawah
            found = true;
            if (i <= 24 - wordLen && j >= wordLen - 1) {
                for (int k = 0; k < wordLen; k++) {
                    if (matrix[i + k][j - k] != word[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) return true;
            }
        }
    }
    return false;
}

// Fungsi untuk mencari kata dalam matriks
bool searchWord(const char* word, char matrix[][24]) {
    int wordLen = strlen(word);
    return horizontal(word, matrix, wordLen) || vertical(word, matrix, wordLen) || diagonal(word, matrix, wordLen);
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Membersihkan buffer input

    char words[N][24]; // Array untuk menyimpan kata-kata

    // Membaca kata-kata yang ingin dicari
    for (int i = 0; i < N; ++i) {
        cin.getline(words[i], 24);
        toUpperCase(words[i]); // Konversi huruf ke huruf besar
    }

    // Matriks karakter
    char matrix[24][24] = {
        "AAFLKHPFSSUFICICLESGNNH",
        "SFVREOMRWLRTTSXOQQNAOAO",
        "QEIAIFXAEIRFVFYSXIMINJI",
        "WSTRLGOCAPBIAFIWIWTUACM",
        "FEYAEAISTPCRLUJKOAKCERS",
        "RVDAKPNDEEHDEMSNCKKFOAH",
        "MRNEDSLCRRIWNRSAAFITMMI",
        "YAAECIEAHYMOTAVHRSSTISB",
        "RJSEWELCCENNIETOHWSGLSE",
        "ATANYYMOIEESNESIOIRELTR",
        "UTENEWEBHMYBETNNRAIEBEN",
        "RCLKUTEAEQJLSGSHTGDSKOA",
        "BHOICATNRRSDDECEHOOLGIT",
        "ENSLUARIRSETALOCOHCTOHE",
        "FZFUDQJYMADOYIWYGLOVESU",
        "TEKALFWONSNAEBMIEJTZNTG",
        "ESWPOSJXEUTUYOZUWAKEZHM",
        "KZUHBPEZEERFLMSNOWBALLH",
        "NSNOWBOARDYTVWYCLEVOHSA",
        "ACOCRQLGZIYCHODRAZZILBI",
        "LBVKKWANZAAQINWOLPWONSL",
        "BFREEZINGRAINSLILGTMELT",
        "HQPYLWHFMNFFUFPSWXNUMMV"
    };

    // Mencari setiap kata dalam matriks dan mencetak hasil
    for (int i = 0; i < N; i++) {
        if (searchWord(words[i], matrix)) {
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }

    return 0;
}

