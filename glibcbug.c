// From bug report on strncat max-size issue
#include <stdint.h>
#include <stdalign.h>
#include <string.h>
#include <stdio.h>

int main()
{
    alignas(64) char s[144];
    memset(s, 1, sizeof s);

    /* the first string... */
    char *s1 = s;             /* ...is at the start of the buffer */
    s1[0] = 0;                /* ...and is empty */

    /* the second string...  */
    char *s2 = s + 95;            /* ...starts as pos 95,  */
    memset(s2, 2, s + sizeof s - s2); /* ...filled with 2s for contrast */
    s2[33] = 0;                   /* ...and has the length 33 */

    printf("before:\n");
    for (int i = 0; i < 50; i++)
        printf("%x", (unsigned char)s[i]);
    printf("...\n");

    strncat(s1, s2, SIZE_MAX-10);

    printf("after:\n");
    for (int i = 0; i < 50; i++)
        printf("%x", (unsigned char)s[i]);
    printf("...\n");
    printf("%-33s^\n", "the string should end here");
}
