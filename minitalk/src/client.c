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
        if (c[i] == 1)
            if (kill(pid, SIGUSR1) < 0)
            {
                ft_printf("Unexpected Error");
                exit[EXIT_FAILURE];
            }
        else
            if (kill(pid, SIGUSR2) < 0)
            {
                ft_printf("Unexpected Error");
                exit[EXIT_FAILURE];
            }
        usleep(200);
        i++;
    }
}

// Function to send a string to the server
void	send_string(pid_t pid, char *str)
{
    int i;
    int j;
    char  *byte;

    i = 0;
    byte = (char *)malloc(sizeof(char) * 8 + 1);
    while (str[i])
    {
        j = 0;
        while (j < 7)
        {
            byte[j] = (str[i] >> j) & 1;
            j++;
        }
        send_signal(pid, str[i]);
        i++;
    }
    send_signal(pid, '\0');
}

// Main function
int	main(int argc, char **argv)
{
    int	pid;

    if (argc != 3)
    {
        ft_printf("Error: Wrong number of arguments\n");
        return (1);
    }
    pid = ft_atoi(argv[1]);
    send_string(pid, argv[2]);
    return (0);
}
