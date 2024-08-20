#include "main.h"
/**
 *chaild - creates a child of function
 *@comm: array of stings passed from main to execve
 *Return: void
 */
void syn(char **comm)
{
	int status;
	pid_t child_pid;

		child_pid = fork();
		if (child_pid  == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			execve(comm[0], comm, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
}
/**
 *print_user - prints name of the user and thanks
 *@argc: number of command-line arguments passed by the user
 *@argv: an array of strings passed by the user, first one being the program
 *Return: array of strings tokenized
 */
int print_user(int argc, char **argv)
{
	int i = 1;

	if (argc >= 2)
		printf("Welcome %s, thank you for using my shell! <3\n", argv[i]);
	else
		printf("Welcome, thank you for using my shell! <3\n");
	return (argc);
}
/**
 *tokenize - tokenizes input of the user from stdin
 *@line: input of the user from stdin
 *@delim: delimiter to tokenize input
 *Return: array of strings tokenized
 */
char **tokenize(char *line, const char *delim)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (tokens == NULL)
	{
		perror("malloc");
		free(tokens);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 *main - main function running infinite loop
 *@ac: number of command-line arguments passed by the user
 *@av: an array of strings passed by the user, first one being the program
 *Return: 0 or -1
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	const char delim[] = " ,\n,\t";
	char **comm;
	int j = 0;

	print_user(ac, av);
	while (1)
	{
		if (av[1])
			printf("%s$ ", av[1]);
		else
			printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == EOF)
		{
			if (av[1])
				printf("\nbye-bye %s UnU", av[1]);
			else
				printf("\nbye-bye UnU");
			putchar('\n');
			break;
		}
		if (read == -1)
			printf("error");
		comm = tokenize(line, delim);
		syn(comm);
		for (j = 0; comm[j] != NULL; j++)
			free(comm[j]);
	}
	free(comm);
	free(line);
	return (0);
}
