/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 20:58:53 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/29 15:54:00 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include <map>
# include <iostream>
# include <cstring>
# include <stdlib.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>

# include <netinet/in.h>
# include <arpa/inet.h>
# include <cerrno>
# include <poll.h>

# include <unistd.h>
# include <string.h>
# include <vector>

class Server
{
private:
	int	_socketFd;
	std::vector<struct pollfd> _pollFds;
	// std::map<std::string, std::string> _address_port;
public:
	Server();
	// Server(std::map<std::string, std::string> address_port);
	~Server();

	bool	setup();
	bool	run();
};

#endif