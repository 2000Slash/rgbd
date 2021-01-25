#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

// looks for a suitable keyboard
EXTERNC int init_keyboard();
