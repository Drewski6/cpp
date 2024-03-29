# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 11:33:40 by dpentlan          #+#    #+#              #
#    Updated: 2024/02/01 12:59:28 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SUBDIRS = CPP_Module_00/project/ex00 \
					CPP_Module_00/project/ex01 \
					CPP_Module_00/project/ex02 \
					CPP_Module_01/project/ex00 \
					CPP_Module_01/project/ex00 \
					CPP_Module_01/project/ex01 \
					CPP_Module_01/project/ex02 \
					CPP_Module_01/project/ex03 \
					CPP_Module_01/project/ex04 \
					CPP_Module_01/project/ex05 \
					CPP_Module_01/project/ex06 \
					CPP_Module_02/project/ex00 \
					CPP_Module_02/project/ex01 \
					CPP_Module_02/project/ex02 \
					CPP_Module_02/project/ex03 \
					CPP_Module_03/project/ex00 \
					CPP_Module_03/project/ex01 \
					CPP_Module_03/project/ex02 \
					CPP_Module_03/project/ex03 \
					CPP_Module_04/project/ex00 \
					CPP_Module_04/project/ex01 \
					CPP_Module_04/project/ex02 \
					CPP_Module_04/project/ex03 \
					CPP_Module_05/project/ex00 \
					CPP_Module_05/project/ex01 \
					CPP_Module_05/project/ex02 \
					CPP_Module_05/project/ex03 \
					CPP_Module_06/project/ex00 \
					CPP_Module_06/project/ex01 \
					CPP_Module_06/project/ex02 \
					CPP_Module_07/project/ex00 \
					CPP_Module_07/project/ex01 \
					CPP_Module_07/project/ex02 \
					CPP_Module_08/project/ex00 \
					CPP_Module_08/project/ex01 \
					CPP_Module_08/project/ex02 \
					CPP_Module_09/project/ex00 \
					CPP_Module_09/project/ex01 \
					CPP_Module_09/project/ex02 \

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
		for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir clean; \
    done

fclean:
		for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir fclean; \
    done

.PHONY: $(SUBDIRS)

