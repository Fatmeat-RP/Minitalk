/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:06:46 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/28 14:06:46 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <signal.h>

static void	sig_handler(int sig)
{
	static char	c = 0;
	static int	i = 7;

	if (sig == SIGUSR1)
		c += (1 << (i--));
	if (sig == SIGUSR2)
		c += (0 << (i--));
	if (i == -1)
	{
		if (c == 0)
			c = '\n';
		write(1, &c, 1);
		c = 0;
		i = 7;
	}
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
