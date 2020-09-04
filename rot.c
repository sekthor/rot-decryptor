#include <stdio.h>
#include <ctype.h>
#include <string.h>

void usage();

int main(int argc, char *argv[])
{
	int shift_value;
	char msg[BUFSIZ];


	// checking for sufficient arguments
	if (argc < 2) {
		usage();
		return 1;
	}

	for (int i = 0; i < argc; i++) {
		if (!strcmp(argv[i], "-h")) {
			usage();
			return 0;
		}
	}

	shift_value = -13;
	strcpy(msg, argv[1]);

	// converting msg to upper case
	char *current = msg;
	while (*current) {
		*current = toupper((unsigned char) *current);
		current++;
	}

	// shift char by shift_value spaces
	for (int i = 0; i < strlen(msg); i++) {

		// make sure only letters are shifted
		if (msg[i] < 65 || msg[i] > 90)
			continue;


		msg[i] += shift_value;

		// correct out of bounds of alphabet
		// (higher than 'Z' or lower than 'A')
		if (msg[i] > 90) {
			msg[i] -= 26;
		} else if (msg[i] < 65) {
			msg[i] += 26;
		}
	}

	// output to stdout
	printf("%s\n", msg);

	return 0;
}

void usage()
{
	printf("Usage: rot <option> STRING\n");
}

