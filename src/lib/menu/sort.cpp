#include <system/adeline_types.h>
#include <menu/selector.h>

#include <string.h>

int MySortCompFunc(void const *ptra, void const *ptrb) {
    const char *const *left = (const char *const *)ptra;
    const char *const *right = (const char *const *)ptrb;
    return strcmp(*left, *right);
}
