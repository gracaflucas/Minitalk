/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:23:04 by lufiguei          #+#    #+#             */
/*   Updated: 2024/07/12 13:23:06 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include "printf/ft_printf.h"

typedef struct s_list
{
	char			c;
	struct s_list	*next;
}			t_list;

#endif
