/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 20:58:53 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/29 18:34:48 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include <WebservInclude.h>
# include "Client.hpp"

class Server
{
private:
	int	_socketFd;
	std::vector<struct pollfd> _pollFds;
	std::map<int, Client>		_clients;
	// std::map<std::string, std::string> _address_port;

	// === SETUP PART === //

	// === RUN PART === //
	bool	acceptNewClient();

public:
	Server();
	// Server(std::map<std::string, std::string> address_port);
	~Server();

	bool	setup();
	bool	run();
};

#endif