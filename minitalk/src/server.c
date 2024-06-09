/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:30:21 by ana-maro          #+#    #+#             */
/*   Updated: 2024/06/09 19:49:33 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void signal_handler(int sig)
{
	static int	character;
	static int	num_bits;

	character = 0;
	num_bits = 0;
  if (sig == SIGUSR1)
		character = (character << 1) | 1;
  else if (sig == SIGUSR2)
    character = (character << 1) | 0;
  num_bits++;
  if (num_bits == 7)
  {
		printf("%c", character);
    fflush(stdout);
    num_bits = 0;
    character = 0;
  }
}

void setup_signal_handlers(void)
{
	if (signal(SIGUSR1, signal_handler) == SIG_ERR)
  perror("Error: SIGUSR1");
	if (signal(SIGUSR2, signal_handler) == SIG_ERR)
  perror("Error: SIGUSR2");
}

int main(void)
{
    printf("\033[0;32mSUCCESS!, Server is ready :D! The PID:%d\033[0m\n", getpid());
    setup_signal_handlers();
    printf("\033[0;32mRecibiendo señal del cliente\033[0m\n");
    while (1)
    {
      pause();
      printf("\033[0;32mServidor en espera\033[0m\n");
    }
    return 0;
}