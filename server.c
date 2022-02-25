
static void	sig_handler(int sig)
{
	static char	c;
	static int	i;

	c += ((sig & 1) << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
	}
}

int	main(void)
{
	ft_printf("PID : %d\n", sighandler());
	signal (SIGUSR2, sig_handler);
	signal (SIGUSR1, sig_handler);
	while (1)
		pause();
}	