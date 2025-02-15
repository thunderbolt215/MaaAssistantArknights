#pragma once

#ifdef _MSC_VER
#define ASST_DO_PRAGMA(x) __pragma(x)
#elif defined(__GNUC__)
#define ASST_DO_PRAGMA(x) _Pragma(#x)
#else
#define ASST_DO_PRAGMA(x)
#endif

#ifdef _MSC_VER
#define ASST_SUPPRESS_CV_WARNINGS_START \
ASST_DO_PRAGMA(warning(push))           \
ASST_DO_PRAGMA(warning(disable: 5054))
#define ASST_SUPPRESS_CV_WARNINGS_END \
ASST_DO_PRAGMA(warning(pop))
#elif defined(__clang__)
#define ASST_SUPPRESS_CV_WARNINGS_START \
ASST_DO_PRAGMA(clang diagnostic push)   \
ASST_DO_PRAGMA(clang diagnostic ignored "-Wdeprecated-enum-enum-conversion") \
ASST_DO_PRAGMA(clang diagnostic ignored "-Wdeprecated-anon-enum-enum-conversion")
#define ASST_SUPPRESS_CV_WARNINGS_END \
ASST_DO_PRAGMA(clang diagnostic pop)
#elif defined(__GNUC__)
#define ASST_SUPPRESS_CV_WARNINGS_START \
ASST_DO_PRAGMA(GCC diagnostic push)     \
ASST_DO_PRAGMA(GCC diagnostic ignored "-Wdeprecated-enum-enum-conversion")
#define ASST_SUPPRESS_CV_WARNINGS_END \
ASST_DO_PRAGMA(GCC diagnostic pop)
#else
#define ASST_SUPPRESS_CV_WARNINGS_START
#define ASST_SUPPRESS_CV_WARNINGS_END
#endif

#ifdef __GNUC__
#define ASST_AUTO_DEDUCED_ZERO_INIT_START \
ASST_DO_PRAGMA(GCC diagnostic push)     \
ASST_DO_PRAGMA(GCC diagnostic ignored "-Wmissing-field-initializers")
#define ASST_AUTO_DEDUCED_ZERO_INIT_END \
ASST_DO_PRAGMA(GCC diagnostic pop)
#elif defined(__clang__)
#define ASST_AUTO_DEDUCED_ZERO_INIT_START \
ASST_DO_PRAGMA(clang diagnostic push)   \
ASST_DO_PRAGMA(clang diagnostic ignored "-Wmissing-field-initializers")
#define ASST_AUTO_DEDUCED_ZERO_INIT_END \
ASST_DO_PRAGMA(clang diagnostic pop)
#else
#define ASST_AUTO_DEDUCED_ZERO_INIT_START
#define ASST_AUTO_DEDUCED_ZERO_INIT_END
#endif
