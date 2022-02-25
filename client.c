static void	send_signal(int pid, char *string)
{
	int	shift;
	int	i;

	i = 0;
	while (string[i++ + 1])
	{
		shift = 0;
		while (shift <= 7)
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

static char	get_error(int ac, char **av, int pid, char *string)
{
	if (ac != 3)
	{
		ft_printf("Error, need two arguments, the pid then the string to send");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= -1)
	{
		ft_printf("Error, the pid is invalid. it need to be an int");
		return (2);
	}
	i = 2;
	while (i++ < ac)
		string = ft_strjoin(string, av[i])
	if (string == NULL)
	{
		printf("Error, couln't get the string send as seconde arguments")
		return (3);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	pid;
	char	*string;

	if (check_args(int ac, char **av, char *string));
	pid = atoi(av[1]);
	send_bit(pid, string);
	return (0);
}