#pragma once

#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <vector>
#include <stdexcept>
#include <type_traits>

using namespace std;

bool is2power(int n) {
    return n > 0 && !(n&(n - 1));
}

string intTobinary(int n) {
    string bin = "";
    while(n) {
        bin += (n&1) ? '1' : '0';
        n >>= 1;
    }
    return bin;
}

int binaryToint(string& bin) {
    int num = 0;
    for(int i = bin.length() - 1; i > -1; i--) num += pow(2, bin.length() - i - 1)*(bin[i] == '0' ? 0 : 1);
    return num;
}

class HALF_ADDER {
public:
    uint8_t sum;
    uint8_t carry;
    void add(uint8_t A, uint8_t B);
};

void HALF_ADDER :: add(uint8_t A, uint8_t B) {
    this->sum = A^B;
    this->carry = A&B;
}

class FULL_ADDER {
public:
    uint8_t sum;
    uint8_t carry;
    void add(uint8_t A, uint8_t B, uint8_t cin);
};

void FULL_ADDER :: add(uint8_t A, uint8_t B, uint8_t cin) {
    this->sum = (A^B)^cin;
    this->carry = (A&B)|(B&cin)|(A&cin);
}


template <typename T>
class MULTIPLEXER {
public:
    MULTIPLEXER(int n);

public:
    int total_selection_lines;
    int total_data_lines;
    vector<T> data_line;
};

template <typename T>
MULTIPLEXER<T> :: MULTIPLEXER(int n) {
    if (is2power(n)) {
        this->total_selection_lines = (int)log2(n);
        this->total_data_lines = n;
        this->data_line.resize(this->total_data_lines, T());
    } else throw invalid_argument("n must be a power of 2");
}