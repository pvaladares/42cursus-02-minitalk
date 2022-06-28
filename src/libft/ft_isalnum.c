/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:38:35 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:37:47 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ISALNUM(3)                 Library Functions Manual                ISALNUM(3)
//
// NAME
//      isalnum – alphanumeric character test
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <ctype.h>
//
//      int isalnum(int c);
//
// DESCRIPTION
//      The isalnum() function tests for any character for which isalpha(3) or
//      isdigit(3) is true.  The value of the argument must be representable as 
//		an unsigned char or the value of EOF.
//
//      In the ASCII character set, this includes the following characters
//      (preceded by their numeric values, in octal):
//
//      060 ``0'' 061 ``1'' 062 ``2'' 063 ``3'' 064 ``4''
//      065 ``5'' 066 ``6'' 067 ``7'' 070 ``8'' 071 ``9''
//      101 ``A'' 102 ``B'' 103 ``C'' 104 ``D'' 105 ``E''
//      106 ``F'' 107 ``G'' 110 ``H'' 111 ``I'' 112 ``J''
//      113 ``K'' 114 ``L'' 115 ``M'' 116 ``N'' 117 ``O''
//      120 ``P'' 121 ``Q'' 122 ``R'' 123 ``S'' 124 ``T''
//      125 ``U'' 126 ``V'' 127 ``W'' 130 ``X'' 131 ``Y''
//      132 ``Z'' 141 ``a'' 142 ``b'' 143 ``c'' 144 ``d''
//      145 ``e'' 146 ``f'' 147 ``g'' 150 ``h'' 151 ``i''
//      152 ``j'' 153 ``k'' 154 ``l'' 155 ``m'' 156 ``n''
//      157 ``o'' 160 ``p'' 161 ``q'' 162 ``r'' 163 ``s''
//      164 ``t'' 165 ``u'' 166 ``v'' 167 ``w'' 170 ``x''
//      171 ``y'' 172 ``z''
//
// RETURN VALUES
//      The isalnum() function returns zero if the character tests false and
//      returns non-zero if the character tests true.

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
