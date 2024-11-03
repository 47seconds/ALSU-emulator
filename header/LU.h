#pragma once
#include "BaseClass.h"
#include <stdexcept>

class LU {
public:
    LU();
    ~LU();

private:
    MULTIPLEXER<uint8_t> *mux;

public:
    void setup_args(uint8_t A, uint8_t B);
    uint8_t calc (uint8_t s0, uint8_t s1);
};

LU :: LU () {
    mux = new MULTIPLEXER<uint8_t>(4);
}

LU::~LU() {
    delete mux;
}

void LU :: setup_args(uint8_t A, uint8_t B) {
    if (mux->total_data_lines >= 4) {
        mux->data_line[0] = static_cast<uint8_t>(A&B);
        mux->data_line[1] = static_cast<uint8_t>(A|B);
        mux->data_line[2] = static_cast<uint8_t>(A^B);
        mux->data_line[3] = static_cast<uint8_t>(!A);
    } else throw runtime_error("Insufficient data lines in the multiplexer for logical operations");
}

uint8_t LU :: calc (uint8_t s0, uint8_t s1) {
    uint8_t ind = (s1 ? 2 : 0) + (s0 ? 1 : 0);
    if (ind >= 4) throw runtime_error("Invalid Logical operation called");
    return static_cast<uint8_t>(mux->data_line[ind]);
}