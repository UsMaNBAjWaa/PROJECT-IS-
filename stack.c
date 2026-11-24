
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str)
{
    char buffer[12];

    /* FAST CFD student lab: observe how unchecked copies affect memory. */
    strcpy(buffer, str);

    printf("Input copied into the local buffer.\n");
    return 1;
}

int main(void)
{
    char str[517] = {0};
    FILE *badfile = fopen("badfile", "rb");

    if (badfile == NULL) {
        perror("Could not open badfile");
        return 1;
    }

    size_t bytes_read = fread(str, 1, sizeof(str) - 1, badfile);
    fclose(badfile);
    str[bytes_read] = '\0';

    bof(str);
    printf("Returned from bof().\n");

    return 0;
}
