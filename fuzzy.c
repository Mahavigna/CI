#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

// int greenhouse_main(void);
int strength_main(void);

typedef int (*ProgramFunction)(void);

typedef struct {
    const char *name;
    ProgramFunction function;
} Program;

static Program programs[] = {
    // {"Greenhouse Watering Time", greenhouse_main},
    {"Paint Strength", strength_main}
};

#define PROGRAM_COUNT \
    ((int)(sizeof(programs) / sizeof(programs[0])))

int run_program(void)
{
    printf("\nSelect a program to run:\n");

    for (int i = 0; i < PROGRAM_COUNT; i++) {
        printf(
            "%d. %s\n",
            i + 1,
            programs[i].name
        );
    }

    printf("Enter your choice: ");

    int choice;

    if (scanf("%d", &choice) != 1) {
        fprintf(
            stderr,
            "Invalid input. Please enter a number.\n"
        );

        return 1;
    }

    if (choice < 1 || choice > PROGRAM_COUNT) {
        fprintf(
            stderr,
            "Invalid choice. Select 1 to %d.\n",
            PROGRAM_COUNT
        );

        return 1;
    }

    printf(
        "\nRunning: %s\n",
        programs[choice - 1].name
    );

    return programs[choice - 1].function();
}

int main(void)
{
    while (true) {
        int result = run_program();

        if (result != 0) {
            return result;
        }

        printf(
            "\nDo you want to run another program? (y/n): "
        );

        char choice;

        if (scanf(" %c", &choice) != 1) {
            return 1;
        }

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}