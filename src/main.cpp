#include <iostream>

#include "own/string.h"
#include "own/identstr.h"

int main() {
    own::IdentStr *str = new own::IdentStr("abc");
    //own::IdentStr *istr = new own::IdentStr("Ya");
    //own::IdentStr t("aue");
    //own::IdentStr estr = ~t;
    str->show();
    std::cout << (*str)[0] << std::endl;
    (~*str).show();
    //estr.show();
    return 0;
}
