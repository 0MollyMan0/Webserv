/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 21:37:59 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/24 23:34:36 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cerrno>

#include <unistd.h>

int main(void)
{
	// Creation of socket	
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	// Verification of socket
	if (socket_fd == -1)
	{
		std::cerr << "socket: " << std::strerror(errno) << std::endl;
		return (1);
	}
	std::cout << "Socket successful" << std::endl;

	// Creation of the struct sockaddr_in, this struct is needed by the socket so they know where to connect
	struct sockaddr_in server_address = {};

	// Configuration of server_address
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8080);
	server_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	// Conversion of sockaddr_in to sockaddr * for bind()
	struct sockaddr *serv_addr = reinterpret_cast<struct sockaddr *>(&server_address);

	int res_bind = bind(socket_fd, serv_addr, sizeof(server_address));
	if (res_bind == -1)
	{
		std::cerr << "bind: " << std::strerror(errno) << std::endl;
		close(socket_fd);
		return (1);
	}
	std::cout << "Bind successful" << std::endl;

	int res_listen = listen(socket_fd, 10);
	if (res_listen == -1)
	{
		std::cerr << "listen: " << std::strerror(errno) << std::endl;
		close(socket_fd);
		return (1);
	}
	std::cout << "Listen successful" << std::endl;
	
	int	client_fd = accept(socket_fd, NULL, NULL);
	if (client_fd == -1)
	{
		std::cerr << "accept: " << std::strerror(errno) << std::endl;
		close(socket_fd);
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
