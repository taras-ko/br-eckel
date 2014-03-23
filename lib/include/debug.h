#ifndef DEBUG_H
#define DEBUG_H

#define d(expr) \
    std::cout << __LINE__ << ' ' << #expr << ';' << std::endl;\
    expr

#endif // DEBUG_H
