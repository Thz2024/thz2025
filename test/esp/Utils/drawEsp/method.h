#include <UIKit/UIKit.h>
#import <vector>
#import <string>
#import "../MethodObfuscation.h"
#import "../../Security/oxorany/oxorany_include.h"

#define IM_PI 3.14159265358979323846f
#define RAD2DEG(x) ((float)(x) * (float)(180.f / IM_PI))
#define DEG2RAD(x) ((float)(x) * (float)(IM_PI / 180.f))
#define kWidth [UIScreen mainScreen].bounds.size.width
#define kHeight [UIScreen mainScreen].bounds.size.height

using namespace std;


std::string string_format(const std::string &fmt, ...) {
    std::vector<char> str(100,'\0');
    va_list ap;
    while (1) {
        va_start(ap, fmt);
        auto n = vsnprintf(str.data(), str.size(), fmt.c_str(), ap);
        va_end(ap);
        if ((n > -1) && (size_t(n) < str.size())) {
            return str.data();
        }
        if (n > -1)
            str.resize( n + 1 );
        else
            str.resize( str.size() * 2);
    }
    return str.data();
}






