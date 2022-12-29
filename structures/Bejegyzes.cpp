#include "Bejegyzes.h"

/**
 * kiiro operator
 * @param os
 * @param b
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Bejegyzes& b) {
    b.print(os);
    return os;
}
