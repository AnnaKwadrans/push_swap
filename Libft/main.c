/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:05:15 by akwadran          #+#    #+#             */
/*   Updated: 2024/10/14 21:13:50 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	ft_print_result(int n)
	{
		char c;

		if (n >= 10)
			ft_print_result(n / 10);
		c = n % 10 + '0';
		write (1, &c, 1);
	}

int	main(void)
{
/*
	// ft_type.c

	printf("isalpha: %d\n", isalpha('A'));
	printf("ft_isalpha: %d\n\n", ft_isalpha('A'));

	printf("isdigit: %d\n", isdigit('3'));
	printf("ft_isdigit: %d\n\n", ft_isdigit('3'));

	printf("isalnum: %d\n", isalnum('C'));
	printf("ft_isalnum: %d\n\n", ft_isalnum('C'));

	printf("isascii: %d\n", isascii(128));
	printf("ft_isascii: %d\n\n", ft_isascii(128));

	printf("isprint: %d\n", isprint(' '));
	printf("ft_isprint: %d\n\n", ft_isprint(' '));
*/
/*
	// ft_ctype2.c

	// toupper

	unsigned int i;
	char teststring[] = "holu HOLA holi 785*anna 500";
	i = 0;
	while (teststring[i])
	{
		teststring[i] = ft_toupper(teststring[i]);
		i++;
	}
	printf("%s", teststring);
	
	// tolower

	i = 0;
	while (teststring[i])
	{
		teststring[i] = ft_tolower(teststring[i]);
		i++;
	}
	printf("%s", teststring);

	//ft_string.c

	// strlen

    printf("strlen: %lu\n", strlen("hol0"));
	printf("ft_strlen: %zu\n\n", ft_strlen("hol0"));

	// memset
*/
/*
    char str[] = "hola mundo";
    memset(str, '8', 4);
    printf("memset: %s\n", str);

    int arr[10] = {0};
    memset(arr, 42, sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

	char strmem[] = "hola mundo";
    	ft_memset(strmem, '8', 4);
    	printf("ft_memset: %s\n", strmem);



	int arrmem[10] = {0};
	ft_memset(arrmem, 42, sizeof(int) * 10);
	for (int i = 0; i < 10; i++) {
		printf("ft: %d ", arrmem[i]);
	}
	printf("\n");
*/
/*
	// memcpy

	char str1[] = "";
	char str2[] = "";
	char str3[] = "";

	memcpy(str2, str1, ft_strlen(str1));
	ft_memcpy(str3, str1, ft_strlen(str1));

	printf("memcpy: %s\n", str2);
	printf("ft_memcpy: %s\n", str3);
*/
/*
	// memmove

	char str1[] = "hola mundo";
	//char str2[] = "xxxxxxxxxx";
	//char str3[] = "xxxxxxxxxx";

	memmove(str1 + 5, str1, sizeof(char) * 5);
	ft_memmove(str1 + 5, str1, sizeof(char) * 5);

	printf("memmove: %s\n", str1);
	printf("ft_memmove: %s\n", str1);
*/


/*
	// ft_string2.c

	// strlcpy

	char str2[] = "xxxxxxxxxx";
	char str3[] = "xxxxxxxxxx";
	unsigned int j = 0;
	i = strlcpy(str2, str, 7);
	j = ft_strlcpy(str3, str, 7);
	printf("strlcpy: %s %d\nft_strlcpy: %s %d\n\n", str2, i, str3, j);
*/

	// strlcat

	//char string0[14] = "add";
	//char string1[] = "original";
	//char string2 = "original";
	//unsigned int i;
	//unsigned int j;

	//i = strlcat(string1, string0, sizeof(string1));
	//j = ft_strlcat(string2, string0, sizeof(string2));

	//printf("ft_strlcat: %s %d\n\n", string2, j);

	
/*
	char	*dest;
	
	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[10] = 'a';
	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
	write(1, "\n", 1);
	write(1, dest, 15);
	free(dest);
*/

	// strncmp
/*
	char	*str1;
	char	*str2;

	str1 = ft_strdup("abcdef");
	str2 = ft_strdup("abcdef");
	printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str1, str2, 6), strncmp(str1, str2, 6));
	printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str1, str2, 8), strncmp(str1, str2, 8));
	free(str1);
	free(str2);
	
	str1 = ft_strdup("abcdef");
	str2 = ft_strdup("abcdeF");
	printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str1, str2, 6), strncmp(str1, str2, 6));
	printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str1, str2, 8), strncmp(str1, str2, 8));
	free(str1);
	free(str2);

	str1 = ft_strdup("abcdef");
	str2 = ft_strdup("abcdeF");
	printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
	printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
	free(str1);
	free(str2);

	printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4), strncmp("abcdefgh", "abcdwxyz", 4));
	printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp("test\200", "test\0", 6), strncmp("test\200", "test\0", 6));

*/
	
	


/*
	// strchr

	char test[] = "i co sie gapisz";
	char *result;

	result = strchr(test, 'e');
	printf("strchr: %s; adres returned: %p\n", result, &result);
	
	result = ft_strchr(test, 'e');
	printf("ft_strchr: %s; adres returned: %p\n", result, &result);

	// strrchr

	char test_rr[] = "e i co sie gapisz";
	char *result_rr1;
	char *result_rr2;

	result_rr1 = strrchr(test_rr, 'e');
	printf("strrchr: %s; adres returned: %p\n", result_rr1, &result_rr1);
	
	result_rr2 = ft_strrchr(test_rr, 'e');
	printf("ft_strrchr: %s; adres returned: %p\n", result_rr2, &result_rr2);
	
	// strncmp
	
	char strin1[] = "";
	char strin2[] = "";
	int i, j;

	i = strncmp(strin1, strin2, 4);
	j = ft_strncmp(strin1, strin2, 4);

	printf("strncmp: %d, ft_strncmp: %d", i, j);
*/
/*
	// memchr

	char str[] = "hola mundo";
	char *str2 = ft_memchr(str, 'u', 11);
	printf("%s\n", str2);

	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
    printf("%s\n", (char *)ft_memchr(tab, -1, 7));
*/
	
	// ft_string3.c

	
	
	
	// strnstr
/*
	char	big[] = "";
	char	little[] = "czy";
	
	printf("%s\n", ft_strnstr(big, little, 0));

	char	str[] = "lelololelo";

	printf("%s\n", ft_strnstr(str, str, 10));

	printf("strnstr: %s ; ft_strnstr: %s\n", strnstr("abc", "abcdef", 3), ft_strnstr("abc", "abcdef", 3));
	
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	printf("libft tester\n");
	 printf("%s\n", ft_strnstr(haystack, needle, -1));
	 printf("%s\n", strnstr(haystack, needle, -1));
	 printf("%s\n", ft_strnstr(haystack, "abcd", 9));
	 printf("%s\n", strnstr(haystack, "abcd", 9));

*/	

	

	
	
	// strdup
/*	
	char *ptr;
	ptr = ft_strdup(teststring);
	printf("%s\n", ptr);
	free(ptr);
*/

	// stdlib
/*
	// atoi

	char	numstr[] = "    \n\t\v\r    -+12345678tfgsla";
	int		i = 0;

	i = ft_atoi(numstr);
	printf("%d\n", i);
	i = ft_atoi("\e475");
	printf("%d\n", i);
*/

	// calloc

/*	
	int	*array;
	int	i;

	array = ft_calloc(6, sizeof(int));
	if (array == NULL)
		printf("Memory err\n");
	i = 0;
	while (i < 6)
	{
		printf("%d ", array[i]);
		i++;
	}
	free(array);

	*/


	// substr
	/*
	char	*substr;
	char	str[] = "szukamy tutaj substringa czy go znajdziemy?";
	
	substr = ft_substr(str, 14, 10);
	 printf("%s\n", substr);
	free(substr);
	
	substr = ft_substr(str, 14, 0);
	printf("%s\n", substr);
	free(substr);

	char	str1[] = "";
	substr = ft_substr(str1, 14, 10);
	printf("%s\n", substr);
	free(substr);

	substr = ft_substr(str1, 0, 0);
	printf("%s\n", substr);
	free(substr);

	char	str2[] = "szukamy tutaj substring";
	substr = ft_substr(str2, 15, 10);
	printf("%s\n", substr);
	free(substr);

	substr = ft_substr(str2, 30, 10);
	printf("%s\n", substr);
	free(substr);
*/

	// strjoin
/*
	char	*str1 = NULL;
	char	str2[] = "";
	char	*ptr;
	
	ptr = ft_strjoin(str1, str2);
	printf("%s\n", ptr);
	free(ptr);
*/

	// strtrim

	
	char	*trimmed;
	
	trimmed = ft_strtrim("  \n\n  \t\n \n\n\n abdcef  \n\n\t\t  \n \n\n\n ", " \n\t");
	printf("%s\n", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("     ", " ");
	printf("%s\n", trimmed);
	free(trimmed);

	trimmed = ft_strtrim(NULL, " \n");
	printf("%s\n", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("abcdba", "acb");
	printf("%s\n", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("", "");
	printf("%s\n", trimmed);
	free(trimmed);

	// itoa
/*
	char	*num;
	num = ft_itoa(-321);
	printf("%s\n", num);
	free(num);
*/

	// split

/*
	
	char	**array;
	//int		i;

	array = ft_split("Suspendisse", ' ');
	i = 0;
	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
	free(array);
*/

	return (0);
}
