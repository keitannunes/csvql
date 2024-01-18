#include <iostream>
#include "Scanner.h"

int main() {
    Scanner s = Scanner("23.2.+23");
    using namespace std;
    for (auto& e : s.scanTokens()) {
        cout << e;
        //cout << get<int>(e._literal.value());
    }

}
