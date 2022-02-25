#include <libft.h>
#include <stdio.h>
#include <signal.h>

static void	send_signal(int pid, char *string)
{
	int	shift;
	int	i;

	i = 0;
	while (string[i++ + 1])
	{
		shift = 0;
		while (shift < 7)
		{
			if ((string[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(200);
		}
	}
}

static char	get_error(int ac, char **av, int pid)
{
	if (ac != 3)
	{
		printf("Error, need two arguments, the pid then the string to send");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (!pid)
	{
		printf("Error, the pid is invalid. it need to be an int");
		return (2);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	pid;
	char	*string;

	pid = 0;
	if (get_error(ac, av, pid))
		return (-1);
	string = av[2];
	send_signal(pid, string);
	return (0);
}