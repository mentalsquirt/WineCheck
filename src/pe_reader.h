#include <pe.h>

typedef struct {
    int machine;
    int sizeOfOptionalHeader;
    int characteristics;
    int isDOS;
    int isMultithreaded;
} PEFile;

int read_pe_file(const char* filepath, PEFile* pe_file);