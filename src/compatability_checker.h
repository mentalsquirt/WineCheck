typedef struct {
    int isCompatible;
    char issues[512];
    char recommendations[512];
} CompatibilityReport;

void check_compatibility(const PEFile* pe_file, CompatibilityReport* report);
void print_report(const CompatibilityReport* report);