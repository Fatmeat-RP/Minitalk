#include <libft.h>
#include <stdio.h>
#include <signal.h>

static void	send_signal(int pid, char *string)
{
	int	shift;
	int	i;

	i = 0;
	while (string[i])
	{
		shift = 0;
		while (shift)
		{
			if ((string[i] >> shift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift--;
			usleep(200);
		}
		i++;
	}
}

static int	get_error(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		printf("Error, need two arguments, the pid then the string to send");
		return (-1);
	}
	pid = atoi(av[1]);
	if (pid < 1)
	{
		printf("Error, the pid is invalid. it need to be an int");
		return (-1);
	}
	return (pid);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*string;

	pid = 0;
	pid = get_error(ac, av);
	printf("%d", pid);
	if (pid == -1)
		return (-1);
	string = av[2];
	send_signal(pid, string);
	return (0);
}