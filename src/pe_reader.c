#include "pe_reader.h"

int read_pe_file(const char* filepath, PEFile* pe_file) {
    pe_ctx_t* ctx = pe_load(filepath, PE_LAZY_LOAD);
    if (ctx == NULL) {
        return 1;
    }

    const pe_hdr_t* hdr = pe_hdr(ctx);
    if (hdr == NULL) {
        pe_unload(ctx);
        return 1;
    }

    pe_file->machine = hdr->FileHeader.Machine;
    pe_file->characteristics = hdr->FileHeader.Characteristics;

    // check if the executable is a DOS app
    pe_file->isDOS = (hdr->DOSHeader.e_magic == IMAGE_DOS_SIGNATURE);

    // check if the executable is multithreaded
    pe_file->isMultithreaded = (hdr->FileHeader.Characteristics & IMAGE_FILE_DLL);

    pe_unload(ctx);
    return 0;
}
