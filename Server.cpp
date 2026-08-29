/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:06:27 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/28 22:46:39 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Server.hpp>


Server::Server()
{
}

// Server::Server(std::map<std::string, std::string>  address_port)
// {
// 	this->_address_port = address_port;
// }

Server::~Server()
{
}

bool	Server::setup()
{
	struct addrinfo hints = {};
	struct addrinfo *res = NULL;

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	int status = getaddrinfo("127.0.0.1", "8080", &hints, &res);
	if (status != 0)
	{
		std::cerr << "getaddrinfo: " << gai_strerror(status) << std::endl;
		return (false);
	}

	this->_socketFd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (this->_socketFd == -1)
	{
		std::cerr << "socket: " << std::strerror(errno) << std::endl;
		freeaddrinfo(res);
		return (false);
	}
	std::cout << "Socket successful" << std::endl;

	int res_bind = bind(this->_socketFd, res->ai_addr, res->ai_addrlen);
	if (res_bind == -1)
	{
		std::cerr << "bind: " << std::strerror(errno) << std::endl;
		close(this->_socketFd);
		freeaddrinfo(res);
		return (false);
	}
	std::cout << "Bind successful" << std::endl;

	int res_listen = listen(this->_socketFd, 10);
	if (res_listen == -1)
	{
		std::cerr << "listen: " << std::strerror(errno) << std::endl;
		freeaddrinfo(res);
		close(this->_socketFd);
		return (false);
	}
	std::cout << "Listen successful" << std::endl;

	freeaddrinfo(res);
	return (true);
}


bool	Server::run()
{	
	int	client_fd = accept(this->_socketFd, NULL, NULL);
	if (client_fd == -1)
	{
		std::cerr << "accept: " << std::strerror(errno) << std::endl;
		close(this->_socketFd);
		return (false);
	}
	std::cout << "Client connected!" << std::endl;
	
	std::cout << "Server socket: " << this->_socketFd << std::endl;
	std::cout << "Client socket: " << client_fd << std::endl;

	return (true);
}
