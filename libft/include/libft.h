/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:58:04 by lefendie          #+#    #+#             */
/*   Updated: 2021/09/22 18:37:22 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define RD_BUFFER_SIZE 20
# define FAILURE 0
# define SUCCESS 1
# define CHAR_BIT 8
# define SCHAR_MIN -128
# define SCHAR_MAX 127
# define UCHAR_MAX 255
# define CHAR_MIN -128
# define CHAR_MAX 127
# define SHRT_MIN -32768
# define SHRT_MAX 32767
# define USHRT_MAX 65535
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define UINT_MAX 4294967295
# define LONG_MIN -9223372036854775808
# define LONG_MAX 9223372036854775807
# define ULONG_MAX 18446744073709551615

# include "libft_struct.h"
# include "converter.h"
# include "error.h"
# include "is_func.h"
# include "list.h"
# include "memory.h"
# include "other.h"
# include "print.h"
# include "string.h"
# include "tab.h"

#endif
