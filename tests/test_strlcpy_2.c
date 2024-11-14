#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int    ft_strlcat(char *dest, char *src, unsigned int size);

void run_test(const char *dst, char *src, size_t dstsize) {
    char str11[100], str12[100];
    size_t ret1, ret2;

    strcpy(str11, dst);
    strcpy(str12, dst);

    ret1 = strlcat(str11, src, dstsize);
    ret2 = ft_strlcat(str12, src, dstsize);

    printf("\nstrlcat:    %s + %s = %s (return: %zu)\n", dst, src, str11, ret1);
    printf("###################\n");
    printf("ft_strlcat: %s + %s = %s (return: %zu)\n", dst, src, str12, ret2);
}

int    main(void)
{

    run_test("Test", "Case", 20);

    // Insufficient buffer size
    run_test("Insufficient", "Buffer", 10);

    // Destination string exactly fits
    run_test("ExactFit", "Buffer", 14);

    // Source string is too long
    run_test("ShortDest", "ThisSourceStringIsTooLong", 20);

    // Buffer size is smaller than destination length
    run_test("DestLongerThanBuffer", "Source", 10);

    // Source string is empty
    run_test("NonEmptyDest", "", 20);

    // Destination string is empty
    run_test("", "NonEmptySource", 20);

    // Both strings are empty
    run_test("", "", 10);

    // Buffer size is zero
    run_test("NonEmptyDest", "NonEmptySource", 0);

    // Buffer size is one
    run_test("NonEmptyDest", "NonEmptySource", 1);

    return (0);
}

