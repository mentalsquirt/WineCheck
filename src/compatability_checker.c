#include "compatibility_checker.h"

void check_compatibility(const PEFile* pe_file, CompatibilityReport* report) {
    // Check if the executable is a DOS app
    if (pe_file->isDOS) {
        report->isCompatible = 0;
        strcpy(report->issues, "The executable is a DOS app, which may fail when started from Wine.\n");
        strcpy(report->recommendations, "Try running the executable in DOSBox.\n");
    }
    // Check if the executable is multithreaded
    else if (pe_file->isMultithreaded) {
        report->isCompatible = 0;
        strcpy(report->issues, "The executable is a multithreaded GUI app, which may deadlock in the winex11 driver surface section.\n");
        strcpy(report->recommendations, "Try running the executable with a different driver or in a single-threaded mode.\n");
    }
    else {
        report->isCompatible = 1;
        strcpy(report->issues, "No known compatibility issues.\n");
        strcpy(report->recommendations, "No recommendations.\n");
    }
}

void print_report(const CompatibilityReport* report) {
    if (report->isCompatible) {
        printf("The .exe file is compatible with Wine.\n");
    } else {
        printf("The .exe file is not compatible with Wine. Here are the issues:\n%s", report->issues);
    }
    printf("Recommendations:\n%s", report->recommendations);  // Print the recommendations
}
