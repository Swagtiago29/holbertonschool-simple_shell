#include "main.h"
/**
 *syn - creates a child of function
 *@comm: array of stings passed from main to execve
 *Return: void
 */
void syn(char **comm, char **environ)
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
			if (execve(comm[0], comm, environ) == -1)
			{
				free(comm[0]);
				perror("execve");
			}
			exit(EXIT_FAILURE);
		}
		else
			waitpid(child_pid, &status, 0);
}
/**
 *tokenize - tokenizes input of the user from stdin
 *@line: input of the user from stdin
 *@delim: delimiter to tokenize input
 *Return: array of strings tokenized
 */
char **tokenize(char *line, char *delim)
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
		if (tokens[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, delim);
		tokens[i] = NULL;
	}
	return (tokens);
}
/**
 *main - main function running infinite loop
 *@ac: number of command-line arguments passed by the user
 *@av: an array of strings passed by the user, first one being the program
 *Return: 0 or -1
 */
int main(int ac, char **av, char **environ)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char delim[] = " ,\n\t";
	char **comm;
	int j = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
	       	{
            		printf("$ %i%s ",ac ,av[0]);
            		fflush(stdout);
        	}
		read = getline(&line, &len, stdin);
		if (read == -1)
	       	{
            		if (isatty(STDIN_FILENO)) 
                		putchar('\n');
            		break;
        	}
		if (strcmp(line, "exit\n") == 0)
		{	
			free(line);
			exit(EXIT_SUCCESS);
		}
		comm = tokenize(line, delim);
		syn(comm, environ);
		for (j = 0; comm[j] != NULL; j++)
			free(comm[j]);
		free(comm);
	}	
	free(line);
	return (0);
}
