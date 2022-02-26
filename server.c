#include <libft.h>
#include <stdio.h>
#include <signal.h>

	static char	c = 0;
	static int	i = 0;

static void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
//		c += (1 << i++);
		write(1, "1", 1);
	else if (sig == SIGUSR2)
		write(1, "0", 1);
//		i++;
	if (i == 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	usleep(200);
}

int	main(void)
{
	printf("PID : %d\n", getpid());
	signal (SIGUSR1, sig_handler);
	signal (SIGUSR2, sig_handler);
	while (1)
	{
		pause();
	}
}	