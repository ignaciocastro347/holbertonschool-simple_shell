#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char *line = 0;
	size_t len = 0;
	char *token, *btoken;

	printf("$");
	while ((getline(&line, &len, stdin)) != 1)
	{
		/* remove last char of line (\n), if it fails return -1 */
		if (!strtok(line, "\n"))
			return (-1);

		/* make a backup variable to not mutate original buffer */
		btoken = strdup(line);

		printf("This is what you put: %s\n", line);

		/* take first token */
		token = strtok(btoken, " ");

		/* walk through other tokens */
		while (token)
		{
			printf("%s\n", token);
			/*take next token*/
			token = strtok(NULL, " ");
		}
		printf("$");
	}
	return (0);
}
