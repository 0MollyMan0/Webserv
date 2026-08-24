/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 21:37:59 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/25 00:39:59 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <cerrno>

#include <unistd.h>

int main(void)
{
	struct addrinfo hints = {};
	struct addrinfo *res = NULL;

	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM; 
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, "8080", &hints, &res);

	// Creation of socket	
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	// Verification of socket
	if (socket_fd == -1)
	{
		std::cerr << "socket: " << std::strerror(errno) << std::endl;
		freeaddrinfo(res);
		return (1);
	}
	std::cout << "Socket successful" << std::endl;

	int res_bind = bind(socket_fd, res->ai_addr, res->ai_addrlen);
	if (res_bind == -1)
	{
		std::cerr << "bind: " << std::strerror(errno) << std::endl;
		close(socket_fd);
		freeaddrinfo(res);
		return (1);
	}
	std::cout << "Bind successful" << std::endl;

	int res_listen = listen(socket_fd, 10);
	if (res_listen == -1)
	{
		std::cerr << "listen: " << std::strerror(errno) << std::endl;
		close(socket_fd);
		freeaddrinfo(res);
		return (1);
	}
	std::cout << "Listen successful" << std::endl;
	
	int	client_fd = accept(socket_fd, NULL, NULL);
	if (client_fd == -1)
	{
		std::cerr << "accept: " << std::strerror(errno) << std::endl;
		close(socket_fd);
		freeaddrinfo(res);
		return (1);
	}
	std::cout << "Client connected!" << std::endl;
	
	std::cout << "Server socket: " << socket_fd << std::endl;
	std::cout << "Client socket: " << client_fd << std::endl;
	while (true)
		;
	close(socket_fd);
	return 0;
}
