/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:43:45 by ana-maro          #+#    #+#             */
/*   Updated: 2024/06/09 20:15:29 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

// Function to send a signal to the server
void	send_signal(pid_t pid, char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '1')
		{
			if (kill(pid, SIGUSR1) < 0)
			{
				ft_printf("Unexpected Error 1\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (c[i] == '0')
		{
			if(kill(pid, SIGUSR2) < 0)
			{
				ft_printf("Unexpected Error 0\n");
				exit(EXIT_FAILURE);
			}
		}
		usleep(200);
		i++;
	}
}

void	send_string(pid_t pid, char *str)
{
	int		h;
	int		i;
	int		j;
	char	*byte;

	i = 0;
	while (str[i])
	{
		byte = (char *)malloc(sizeof(int) * 7 + 1);
		h = 0;
		j = 6;
		while (h < 7)
		{
			byte[j] = (str[i] % 2) + '0';
			str[i] /= 2;
			h++;
			j--;
		}
		byte[7] = '\0';
		send_signal(pid, byte);
		free(byte);
		usleep(500);
		i++;
	}
}

// Main function
int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	send_string(pid, message);
	send_string(pid, "\0");

	return (0);
}
