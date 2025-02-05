/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:18:47 by dlippelt          #+#    #+#             */
/*   Updated: 2025/02/05 12:07:39 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

#ifndef BONUS
# define BONUS 0
#endif

static void	test_basic(void)
{
	int	n1;
	int	n2;

	printf("\n=== Basic Tests ===\n");

	n1 = printf("1: Regular string without conversions\n");
	n2 = ft_printf("2: Regular string without conversions\n");
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	n1 = printf("1: Multiple %% signs: %% %% %% %%\n");
	n2 = ft_printf("2: Multiple %% signs: %% %% %% %%\n");
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);
}

static void	test_characters(void)
{
	int	n1;
	int	n2;

	printf("\n=== Character Tests ===\n");

	n1 = printf("1: Basic char: %c\n", 'A');
	n2 = ft_printf("2: Basic char: %c\n", 'A');
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	n1 = printf("1: Null char: %c|\n", '\0');
	n2 = ft_printf("2: Null char: %c|\n", '\0');
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	if (BONUS == 1)
	{
		n1 = printf("1: Width char: %5c|\n", 'B');
		n2 = ft_printf("2: Width char: %5c|\n", 'B');
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Left-aligned char: %-5c|\n", 'C');
		n2 = ft_printf("2: Left-aligned char: %-5c|\n", 'C');
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);
	}
}

static void	test_strings(void)
{
	int		n1;
	int		n2;
	char	*null_str;

	null_str = NULL;

	printf("\n=== String Tests ===\n");

	n1 = printf("1: Basic string: %s\n", "Hello");
	n2 = ft_printf("2: Basic string: %s\n", "Hello");
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	n1 = printf("1: Null string: %s|\n", null_str);
	n2 = ft_printf("2: Null string: %s|\n", null_str);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	if (BONUS == 1)
	{
		n1 = printf("1: Width string: %10s|\n", "Hello");
		n2 = ft_printf("2: Width string: %10s|\n", "Hello");
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Left-aligned string: %-10s|\n", "Hello");
		n2 = ft_printf("2: Left-aligned string: %-10s|\n", "Hello");
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Precision string: %.3s|\n", "Hello");
		n2 = ft_printf("2: Precision string: %.3s|\n", "Hello");
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Width and precision string: %10.3s|\n", "Hello");
		n2 = ft_printf("2: Width and precision string: %10.3s|\n", "Hello");
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Has width and precision 0 string: %10.s|\n", "Hello");
		n2 = ft_printf("2: Has width and precision 0 string: %10.s|\n", "Hello");
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Null string with no width precision smaller than ft_strlen(\"(null)\"): %.03s\n", null_str);
		n2 = ft_printf("2: Null string with no width precision smaller than ft_strlen(\"(null)\"): %.03s\n", null_str);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Null string with no width precision larger than or equal to ft_strlen(\"(null)\"): %.09s\n", null_str);
		n2 = ft_printf("2: Null string with no width precision larger than or equal to ft_strlen(\"(null)\"): %.09s\n", null_str);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Null string with width smaller than and precision smaller than ft_strlen(\"(null)\"): %3.s\n", null_str);
		n2 = ft_printf("2: Null string with width smaller than and precision smaller than ft_strlen(\"(null)\"): %3.s\n", null_str);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Null string with width larger than or equal to and precision smaller than ft_strlen(\"(null)\"): %10.s\n", null_str);
		n2 = ft_printf("2: Null string with width larger than or equal to and precision smaller than ft_strlen(\"(null)\"): %10.s\n", null_str);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Null string with width smaller than and precision larger than or equal to ft_strlen(\"(null)\"): %3.09s\n", null_str);
		n2 = ft_printf("2: Null string with width smaller than and precision larger than or equal to ft_strlen(\"(null)\"): %3.09s\n", null_str);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Null string with width larger than or equal to and precision larger than or equal to ft_strlen(\"(null)\"): %20.6s\n", null_str);
		n2 = ft_printf("2: Null string with width larger than or equal to and precision larger than or equal to ft_strlen(\"(null)\"): %20.6s\n", null_str);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);
	}
}

static void	test_integers(void)
{
	int	n1;
	int	n2;

	printf("\n=== Integer Tests ===\n");

	n1 = printf("1: Basic integer: %d\n", 42);
	n2 = ft_printf("2: Basic integer: %d\n", 42);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	n1 = printf("1: Negative integer: %d\n", -42);
	n2 = ft_printf("2: Negative integer: %d\n", -42);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	n1 = printf("1: Int min: %d\n", INT_MIN);
	n2 = ft_printf("2: Int min: %d\n", INT_MIN);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	n1 = printf("1: Int max: %d\n", INT_MAX);
	n2 = ft_printf("2: Int max: %d\n", INT_MAX);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	if (BONUS == 1)
	{
		n1 = printf("1: Zero-padded: %05d\n", 42);
		n2 = ft_printf("2: Zero-padded: %05d\n", 42);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative zero-padded: %05d\n", -42);
		n2 = ft_printf("2: Negative zero-padded: %05d\n", -42);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Left-aligned: %-5d|\n", 42);
		n2 = ft_printf("2: Left-aligned: %-5d|\n", 42);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Space flag: % d\n", 42);
		n2 = ft_printf("2: Space flag: % d\n", 42);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Plus flag: %+d\n", 42);
		n2 = ft_printf("2: Plus flag: %+d\n", 42);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative with precision (right aligned): %.6d\n", -4200000);
		n2 = ft_printf("2: Negative with precision (right aligned): %.6d\n", -4200000);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative with precision (left aligned): %-.6d\n", -42);
		n2 = ft_printf("2: Negative with precision (left aligned): %-.6d\n", -42);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative with width and precision (right aligned): %3.7i\n", -2375);
		n2 = ft_printf("2: Negative with width and precision (right aligned): %3.7i\n", -2375);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative with width and precision (left aligned): %-3.7i\n", -2375);
		n2 = ft_printf("2: Negative with width and precision (left aligned): %-3.7i\n", -2375);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative zero padded and precision (right aligned): %03.7i\n", -2375);
		n2 = ft_printf("2: Negative zero padded and precision (right aligned): %03.7i\n", -2375);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero and precision 0 (right aligned): %.0i\n", 0);
		n2 = ft_printf("2: Zero and precision 0 (right aligned): %.0i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero and precision 0 (left aligned): %-.0i\n", 0);
		n2 = ft_printf("2: Zero and precision 0 (left aligned): %-.0i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero and precision 0 with width (right aligned): %5.0i\n", 0);
		n2 = ft_printf("2: Zero and precision 0 with width (right aligned): %5.0i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero and precision 0 with width (left aligned): %-5.0i\n", 0);
		n2 = ft_printf("2: Zero and precision 0 with width (left aligned): %-5.0i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero and precision > 0 (right aligned): %.3i\n", 0);
		n2 = ft_printf("2: Zero and precision > 0 (right aligned): %.3i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero and precision > 0 (left aligned): %-.3i\n", 0);
		n2 = ft_printf("2: Zero and precision > 0 (left aligned): %-.3i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative and precision = ndig (right aligned): %.4i\n", -2372);
		n2 = ft_printf("2: Negative and precision = ndig (right aligned): %.4i\n", -2372);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative and precision = ndig (left aligned): %-.4i\n", -2372);
		n2 = ft_printf("2: Negative and precision = ndig (left aligned): %-.4i\n", -2372);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative and precision < ndig (right aligned): %.3i\n",-23646);
		n2 = ft_printf("2: Negative and precision < ndig (right aligned): %.3i\n",-23646);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative and precision < ndig (left aligned): %-.3i\n",-23646);
		n2 = ft_printf("2: Negative and precision < ndig (left aligned): %-.3i\n",-23646);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative with width and precision > ndig (right aligned): %10.5i\n", -216);
		n2 = ft_printf("2: Negative with width and precision > ndig (right aligned): %10.5i\n", -216);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Negative with width and precision > ndig (left aligned): %-10.5i\n", -216);
		n2 = ft_printf("2: Negative with width and precision > ndig (left aligned): %-10.5i\n", -216);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero with width > precision (right aligned): %8.5i\n", 0);
		n2 = ft_printf("2: Zero with width > precision (right aligned): %8.5i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero with width > precision (left aligned): %-8.5i\n", 0);
		n2 = ft_printf("2: Zero with width > precision (left aligned): %-8.5i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero with width <= precision (right aligned): %5.5i\n", 0);
		n2 = ft_printf("2: Zero with width <= precision (right aligned): %5.5i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero with width <= precision (left aligned): %-5.5i\n", 0);
		n2 = ft_printf("2: Zero with width <= precision (left aligned): %-5.5i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero with space: % i\n", 0);
		n2 = ft_printf("2: Zero with space: % i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero with plus: %+i\n", 0);
		n2 = ft_printf("2: Zero with plus: %+i\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);
	}
}

static void	test_unsigned(void)
{
	int	n1;
	int	n2;

	printf("\n=== Unsigned Tests ===\n");

	n1 = printf("1: Basic unsigned: %u\n", 42);
	n2 = ft_printf("2: Basic unsigned: %u\n", 42);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	n1 = printf("1: Large unsigned: %u\n", UINT_MAX);
	n2 = ft_printf("2: Large unsigned: %u\n", UINT_MAX);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	if (BONUS == 1)
	{
		n1 = printf("1: Zero-padded: %05u\n", 42);
		n2 = ft_printf("2: Zero-padded: %05u\n", 42);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero unsigned with width (right aligned): %5u\n", 0);
		n2 = ft_printf("2: Zero unsigned with width (right aligned): %5u\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero unsigned with width (left aligned): %-5u\n", 0);
		n2 = ft_printf("2: Zero unsigned with width (left aligned): %-5u\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero unsigned with precision (right aligned): %.0u\n", 0);
		n2 = ft_printf("2: Zero unsigned with precision (right aligned): %.0u\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero unsigned with precision (left aligned): %-.0u\n", 0);
		n2 = ft_printf("2: Zero unsigned with precision (left aligned): %-.0u\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero unsigned with width > precision (right aligned): %5.0u\n", 0);
		n2 = ft_printf("2: Zero unsigned with width > precision (right aligned): %5.0u\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero unsigned with width > precision (left aligned): %-5.0u\n", 0);
		n2 = ft_printf("2: Zero unsigned with width > precision (left aligned): %-5.0u\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);
	}
}

static void	test_hex(void)
{
	int	n1;
	int	n2;

	printf("\n=== Hexadecimal Tests ===\n");

	n1 = printf("1: Basic hex lower: %x\n", 42);
	n2 = ft_printf("2: Basic hex lower: %x\n", 42);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	n1 = printf("1: Basic hex upper: %X\n", 42);
	n2 = ft_printf("2: Basic hex upper: %X\n", 42);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	n1 = printf("1: Hex zero: %x\n", 0);
	n2 = ft_printf("2: Hex zero: %x\n", 0);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	n1 = printf("1: Hex max: %x\n", UINT_MAX);
	n2 = ft_printf("2: Hex max: %x\n", UINT_MAX);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	if (BONUS == 1)
	{
		n1 = printf("1: Hex with #: %#x\n", 42);
		n2 = ft_printf("2: Hex with #: %#x\n", 42);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero hex with precision (right aligned): %.0x\n", 0);
		n2 = ft_printf("2: Zero hex with precision (right aligned): %.0x\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero hex with precision (left aligned): %-.0x\n", 0);
		n2 = ft_printf("2: Zero hex with precision (left aligned): %-.0x\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero hex with precision (right aligned): %5.0x\n", 0);
		n2 = ft_printf("2: Zero hex with precision (right aligned): %5.0x\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Zero hex with width > precision (left aligned): %-5.0x\n", 0);
		n2 = ft_printf("2: Zero hex with width > precision (left aligned): %-5.0x\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Hex with 0 flag and width (right aligned): %#05x\n", 42);
		n2 = ft_printf("2: Hex with 0 flag and width (right aligned): %#05x\n", 42);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);
	}
}

static void	test_pointers(void)
{
	int		n1;
	int		n2;
	int		num;
	void	*ptr;
	void	*null_ptr;

	num = 42;
	ptr = &num;
	null_ptr = NULL;

	printf("\n=== Pointer Tests ===\n");

	n1 = printf("1: Basic pointer: %p\n", ptr);
	n2 = ft_printf("2: Basic pointer: %p\n", ptr);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Null pointer: %p\n", null_ptr);
	n2 = ft_printf("2: Null pointer: %p\n", null_ptr);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	if (BONUS == 1)
	{
		n1 = printf("1: Width pointer: %20p|\n", ptr);
		n2 = ft_printf("2: Width pointer: %20p|\n", ptr);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Left-aligned pointer: %-20p|\n", ptr);
		n2 = ft_printf("2: Left-aligned pointer: %-20p|\n", ptr);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);
	}
}

static void	test_mixed(void)
{
	int	n1;
	int	n2;

	printf("\n=== Mixed Tests ===\n");

	n1 = printf("1: Mixed test 1: %c %s %p %d %i %u %x %X %%\n",
				'A', "Hello", (void *)42, 42, -42, 42, 42, 42);
	n2 = ft_printf("2: Mixed test 1: %c %s %p %d %i %u %x %X %%\n",
				'A', "Hello", (void *)42, 42, -42, 42, 42, 42);
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	if (BONUS == 1)
	{
		n1 = printf("1: Mixed test 2: %5c|%-10s|%+d|%05i|%#x\n",
				'B', "World", 42, -42, 42);
		n2 = ft_printf("2: Mixed test 2: %5c|%-10s|%+d|%05i|%#x\n",
					'B', "World", 42, -42, 42);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Mixed test 3: 42% 10.8d42\n", 0);
		n2 = ft_printf("2: Mixed test 3: 42% 10.8d42\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Mixed test 4: 42%- 8.8d42\n", 0);
		n2 = ft_printf("2: Mixed test 4: 42%- 8.8d42\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Mixed test 5: !%+31.11d!\n", 0);
		n2 = ft_printf("2: Mixed test 5: !%+31.11d!\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Mixed test 6: ^.^/% 24.2d^.^/\n", 0);
		n2 = ft_printf("2: Mixed test 6: ^.^/% 24.2d^.^/\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Mixed test 7: !%-+31.11d!\n", 0);
		n2 = ft_printf("2: Mixed test 7: !%-+31.11d!\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Mixed test 8: ^.^/% -24.2d^.^/\n", 0);
		n2 = ft_printf("2: Mixed test 8: ^.^/% -24.2d^.^/\n", 0);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Mixed test 8: !% 11.11d!\n", -2046937716);
		n2 = ft_printf("2: Mixed test 8: !% 11.11d!\n", -2046937716);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Mixed test 9: !%- 42.42d!\n", -2046937716);
		n2 = ft_printf("2: Mixed test 9: !%- 42.42d!\n", -2046937716);
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);
	}
}

static void	test_percentage(void)
{
	int n1, n2;

	printf("\n=== Percentage Tests ===\n");

	n1 = printf("1: Basic percentage: %%\n");
	n2 = ft_printf("2: Basic percentage: %%\n");
	printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

	if (BONUS == 1)
	{
		n1 = printf("1: Width percentage: %5%\n");
		n2 = ft_printf("2: Width percentage: %5%\n");
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);

		n1 = printf("1: Left-aligned percentage: %-5%\n");
		n2 = ft_printf("2: Left-aligned percentage: %-5%\n");
		printf("Return values: printf=%d, ft_printf=%d\n\n", n1, n2);
	}
}

int main(void)
{
	setbuf(stdout, NULL);

	test_basic();
	test_characters();
	test_strings();
	test_integers();
	test_unsigned();
	test_hex();
	test_pointers();
	test_mixed();
	test_percentage();
	return (0);
}
