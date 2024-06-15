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
				ft_printf("Unexpected Error\n");
				exit(EXIT_FAILURE);
			}
			else if(kill(pid, SIGUSR2) < 0)
			{
				ft_printf("Unexpected Error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	usleep(200);
	i++;
}

void	send_string(pid_t pid, char *str)
{
	int		h;
	int		i;
	int		j;
	char	*byte;

	i = 0;
	byte = (char *)malloc(sizeof(int) * 8 + 1);
	while (str[i])
	{
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
	}
	send_string(pid, byte);
	free(byte);
	usleep(200);
}

// Main function
int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		//ft_printf("Error: Wrong number of arguments\n");
		//return (1);
	}
	pid = ft_atoi(argv[1]);
	send_string(pid, argv[2]);
	return (0);
}
