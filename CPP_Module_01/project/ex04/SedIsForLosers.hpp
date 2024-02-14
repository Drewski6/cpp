/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:56:55 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/14 16:21:10 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <string>

bool findAndReplace(char *fileNameCh, std::string &searchStr,
                    std::string &replaceStr);
