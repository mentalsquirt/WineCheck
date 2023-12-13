#include <stdio.h>
#include "pe_reader.h"
#include "compatibility_checker.h"

int main() {
    char filepath[100];
    printf("Enter the path to the .exe file: ");
    scanf("%s", filepath);

    PEFile pe_file;
    if (read_pe_file(filepath, &pe_file) != 0) {
        printf("Failed to read the .exe file.\n");
        return 1;
    }

    CompatibilityReport report;
    check_compatibility(&pe_file, &report);

    print_report(&report);

    return 0;
}
