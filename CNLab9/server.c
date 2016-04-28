#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include "timestampserver.h"

#define MAXBUFLEN 100

void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void)
{
	int sockfd;
	struct addrinfo hints, *servinfo, *p;
	int rv;
	int numbytes;
	struct sockaddr_storage their_addr;
	char buf[MAXBUFLEN];
	socklen_t addr_len;
	char s[INET6_ADDRSTRLEN];

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; 
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;

	if ((rv = getaddrinfo("172.22.45.146", SERVERPORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("Socket error!");
			continue;
		}

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("bind error!");
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "Failed to bind socket\n");
		return 2;
	}

	freeaddrinfo(servinfo);

	printf("Waiting to recvfrom...\n");

	addr_len = sizeof their_addr;
	if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN-1 , 0,
		(struct sockaddr *)&their_addr, &addr_len)) == -1) {
		perror("recvfrom error");
		exit(1);
	}

	printf("Got packet from %s\n",
		inet_ntop(their_addr.ss_family,
			get_in_addr((struct sockaddr *)&their_addr),
			s, sizeof s));
	printf("Packet is %d bytes long\n", numbytes);
	buf[numbytes] = '\0';
	printf("Packet contains \"%s\"\n", buf);
	sprintf(data.username,"%s",buf);
	time_t mytime;
    mytime = time(NULL);
    sprintf(data.time,"%s",ctime(&mytime));
    printf("%s\n",buf );
   // sprintf(data.time,"%s",buf);
    if ((numbytes = sendto(sockfd, &data, sizeof(data), 0,
			 (struct sockaddr *)&their_addr, addr_len)) == -1) {
		perror("Sendto failed");
		exit(1);
	}

	printf("server: sent %d bytes to %s\n", numbytes,inet_ntop(their_addr.ss_family,
			get_in_addr((struct sockaddr *)&their_addr),
			s, sizeof s));

	close(sockfd);

	return 0;
}
