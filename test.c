/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:13:18 by dgarizad          #+#    #+#             */
/*   Updated: 2022/10/21 23:43:47 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);	
}


void rush(int fils,int cols)
{
	int c;
	int f;
	
	c= 0;
	f= 0;

	while (f < fils )
	{
		while(c< cols)
		{
			if(f==0)
			{
				if(c==0 || c == cols-1 )
				{
					ft_putchar('o');			
				}
				else
				{
					ft_putchar('-');
				}
			}
			else if (f==fils-1)
			{
				if(c==0 || c == cols-1 )
				{
					ft_putchar('o');
				}
				else
				{
	 				ft_putchar('-');
				}
			}
			else
			{		
				ft_putchar('-');
			}
			c++;
		}
		
		ft_putchar(10);
		f++;
		c=0;


	}
}

int main()
{
	rush(5, 5);
	return(0);
}
