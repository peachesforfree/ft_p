#include "../includes/ft_p.h"

void	usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(-1);
}

int		create_server(int port)
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
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Bind error\n");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

int		main(int argc, char **argv)
{
	int					port;
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	int					r;
	char				buf[1024];
	
	if (argc != 2)
		usage(argv[0]);
	port = atoi(argv[1]);
	sock = create_server(port);

printf("Creating server\n");
	cs = accept(sock, (struct sockaddr*)&csin, &cslen);
printf("Accepted connection\n");
//send a message?
	while ((r = read(cs, buf, 1023)) > 0)
	{
		buf[r] = '\0';
		printf("Recieved %d bytes: [%s]\n", r, buf);
	}
	close (cs);
	close (sock);
	return (0);
}
