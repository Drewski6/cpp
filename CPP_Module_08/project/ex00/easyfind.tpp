/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:50:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/28 16:58:11 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> typename T::iterator easyfind(T &container, int value) {
  return std::find(container.begin(), container.end(), value);
};
