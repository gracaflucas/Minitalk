/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:23:12 by lufiguei          #+#    #+#             */
/*   Updated: 2024/07/12 13:23:13 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
