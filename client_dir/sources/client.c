#include "ft_p.h"

void	usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(-1);
}

int		create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Connect error\n");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

int main(int argc, char **argv)
{
	int					port;
	int					sock;
	
	if (argc != 3)
		usage(argv[0]);
	port = atoi(argv[2]);
	sock = create_client(argv[1], port);
	while (1)
	{
		write(sock, "bonjour\n", 8);
	}
	close (sock);
	return (0);
}
