#pragma once

#include <system/adeline_types.h>
#include <system/limits.h>

// -----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
extern char PathConfigFile[ADELINE_MAX_PATH];

// -----------------------------------------------------------------------------
extern U32 RegisterInitClear(PTR_VOID_FUNC init, PTR_VOID_FUNC clear);

// =============================================================================
#ifdef __cplusplus
}
#endif
