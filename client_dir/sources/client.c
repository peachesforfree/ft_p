#include "../includes/ft_p.h"

/*
 *get started from line 68 and then continue 
 * on to 49 break into multiple functions and put into its own file for 
 * command line management, then worry about sending message to server.
*/

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
	(void)addr;

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

/*
char *lsh_read_line(char *buffer)
{
	int bufsize;
	int position;
	int c;

	if (!buffer) //fatal error
		exit(1);
	position = 0;
	while (1)
	{
		c = getchar();	//make this read one byte from the command line

		// If we hit EOF, replace it with a null character and return.
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
			buffer[position] = c;
			position++;

		// If we have exceeded the buffer, reallocate.
		if (position >= bufsize)
		{
			char *old_buffer;
			bufsize += BUFFER_SIZE;
			old_buffer = buffer;
			buffer = (char*)malloc(bufsize);
			ft_memcpy(buffer, old_buffer, bufsize - BUFFER_SIZE);	//need to do some pointer magic here
			free(old_buffer);
			if (!buffer)	//didnt allocated mem for buffer
				exit(EXIT_FAILURE);
		}
	}
}*/

int main(int argc, char **argv)
{
	int					port;
	int					sock;
	char				buffer[1024];
	
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	int					r;

	if (argc != 3)
		usage(argv[0]);
	port = atoi(argv[2]);
	sock = create_client(argv[1], port);
	
	if ((cs = accept(sock, (struct sockaddr*)&csin, &cslen)) >= 0)
		printf("connection accepted\n");
	else
		printf("connection not accepted\n");
	while ((r = read(cs, buffer, 1023)) > 0)
	{
		buffer[r] = '\0';
		printf("Recieved %d bytes: [%s]\n", r, buffer);
	}
	close(cs);
/*	while (1)
	{
		//ssize_t send(int sockfd, const void *buf, size_t len, int flags);
		//send(sock, &buffer, len, );
		if ((buffer = read_line(&buffer)) != NULL)
			write(sock, &buffer, buff_len(buffer));
	}
*/	close (sock);
	return (0);
}
