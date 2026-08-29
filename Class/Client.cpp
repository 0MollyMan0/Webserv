/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 15:50:03 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/29 18:17:35 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client(int fd)
{
	this->_fd = fd;
}

Client::~Client()
{
}

int	Client::getFd() const
{
	return (this->_fd);
}
