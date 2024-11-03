#include <iostream>
#include "header/BaseClass.h"
#include "header/LogicUnit.h"
using namespace std;

// NOTE: FOR cout PURPOSES, TYPECAST TO int

int main() {

    // Testing our Logical Unit
    LogicUnit *logical_unit = new LogicUnit();
    logical_unit->setup_args(1, 0);
    cout << "A: " << 1 << ", B: " << 0 << endl;
    cout << "AND: " << static_cast<int>(logical_unit->calc(0, 0)) << endl;
    cout << "OR: " <<static_cast<int>(logical_unit->calc(0, 1)) << endl;
    cout << "XOR: " <<static_cast<int>(logical_unit->calc(1, 0)) << endl;
    cout << "NOT (A): " <<static_cast<int>(logical_unit->calc(1, 1)) << endl;
    delete logical_unit;

    return 0;
}

// OPTIONAL: g++ main.cpp -o main -Wall (Warning Flag: to show warnings in program / compilation)