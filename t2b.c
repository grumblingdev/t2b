#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define T2B_HELP "usage: t2b STRING.. -[Hh]\n\
	-H -- hex conversion (BINARY BY DEFAULT)\n\
	-h -- print this message (DEFAULT BEHAVIOR)\n"

int main(int argc, char **argv) {
	if (argc < 2) {
		fputs(T2B_HELP, stderr);
		return EXIT_FAILURE;
	}

	int opt;
	bool hex_flag = false;

	while ((opt = getopt(argc, argv, "hH")) != -1) {
		switch (opt) {
			case 'H':
				hex_flag = true;
				break;             	
			case 'h':
				fputs(T2B_HELP, stderr);
				return EXIT_SUCCESS;	
			default:
				fputs(T2B_HELP, stderr);
				return EXIT_FAILURE;	
		}                                                     	
	}

	while (optind < argc) {
		const char *s = argv[optind];
		printf("\"%s\": ", s);
		for (int i = 0; i < strlen(s); i++) {
			if (hex_flag) {
				printf("%X ", s[i]);
			} else {
				printf("%b ", s[i]);
			}
		}
		putchar('\n');
		optind++;
	}

	return EXIT_SUCCESS;
}
