/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 20:58:53 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/29 18:22:37 by anfouger         ###   ########.fr       */
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
	std::vector<Client>		_clients;
	// std::map<std::string, std::string> _address_port;
public:
	Server();
	// Server(std::map<std::string, std::string> address_port);
	~Server();

	// === SETUP PART === //
	bool	setup();

	// === RUN PART === //
	bool	run();
	bool	acceptNewClient();
};

#endif