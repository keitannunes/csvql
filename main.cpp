#include <iostream>
#include "Scanner.h"

int main() {
    Scanner s = Scanner("+<>\n>\n>>=-\n>--hell\n.");
    for (auto& e : s.scanTokens()) {
        std::cout << e << std::endl;
    }

}
