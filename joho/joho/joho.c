#include <stdio.h>
#include <stdlib.h>
main() {
	for (int i = 0; i < 6; i++) {
		printf("%d\n", (1 + rand() % 45));
	}
}