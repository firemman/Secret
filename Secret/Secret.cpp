#include <iostream>
#include <string>
#include <bitset>
#include <fstream>

using namespace std;

class A {
private:
    string secret = "Hello";
    friend void mySecret(A& secret);
};

void mySecret(A& secret) {
    ofstream out;
    out.open("out.txt");
    if (out.is_open()) {
        for (int i = 0; i < secret.secret.size(); i++) {
            out << bitset<8>(secret.secret[i]);
        }
    }
}

void unShifr() {
    string line;

    ifstream in("out.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
        }
    }
    in.close();

    for (int i = 0; i < line.size(); i += 8) {
        cout << (char)stoi(line.substr(i, 8), 0, 2);
    }
}

int main() {
    A one;
    cout << "Secret: ";
    mySecret(one);
    unShifr();
    cout << "\n";
}