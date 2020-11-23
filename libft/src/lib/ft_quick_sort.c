/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:20:14 by fallard           #+#    #+#             */
/*   Updated: 2020/10/13 16:20:44 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_quick_sort(int *arr, int first, int last)
{
	int left;
	int right;
	int middle;
	int tmp;

	left = first;
	right = last;
	middle = arr[(left + right) / 2];
	while (left <= right)
	{
		while (arr[left] < middle)
			left++;
		while (arr[right] > middle)
			right--;
		if (left <= right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
		ft_quick_sort(arr, first, right);
		ft_quick_sort(arr, left, last);
	}
}
