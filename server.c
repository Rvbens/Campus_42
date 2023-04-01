#define _GNU_SOURCE
#include <signal.h>
#include <unistd.h>

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	while (len--)
		*ptr++ = (unsigned char) c;
	return (b);
}

void	ft_itoa(int n)
{
	char	d;

	if (n < 0)
	{
		write(1, &"-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_itoa(n / 10);
	d =  n % 10 + '0';
	write(1, &d, 1);
}

void	sigusr_handler(int signal)
{
	if (signal == SIGUSR1)
		write(1, "\nSeñal recibida\n", 17);
	if (signal == SIGUSR2)
		write(1, "\nSeñal recibida\n", 17);
}

void set_sigactions(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &sigusr_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	main(void)
{
	ft_itoa(getpid());
	set_sigactions();
	while(1)
		continue ;
	return (0);
}