# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 15:54:14 by mwagner           #+#    #+#              #
#    Updated: 2021/12/07 16:02:49 by mwagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rule_a:
	@echo "RULE A"

rule_b: rule_a	# since rule B has rule A as a dependency "make" first executes rule a, then rule B
	echo "RULE B"