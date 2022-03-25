/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:06:53 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/28 14:06:53 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <signal.h>

static void	send_signal(int pid, char *string, int msglen)
{
	int	shift;
	int	i;

	i = 0;
	while (i <= msglen)
	{
		shift = 7;
		while (shift >= 0)
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
		write(1, "Error, need two arguments, "
			"the pid then the string to send\n", 59);
		return (-1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 1)
	{
		write(1, "Error, the pid is invalid. "
			"it need to be an int\n", 48);
		return (-1);
	}
	return (pid);
}

int	main(int ac, char **av)
{
	int	pid;
	int	msglen;

	pid = 0;
	pid = get_error(ac, av);
	if (pid == -1)
		return (-1);
	msglen = ft_strlen(av[2]);
	send_signal(pid, av[2], msglen);
	return (0);
}
