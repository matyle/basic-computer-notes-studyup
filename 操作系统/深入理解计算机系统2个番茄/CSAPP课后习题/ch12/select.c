/* $begin select */
#include "csapp.h"
void echo(int connfd);
void command(void);

int main(int argc, char **argv) 
{
    int listenfd, connfd, port;
    socklen_t clientlen = sizeof(struct sockaddr_in);
    struct sockaddr_in clientaddr;
    fd_set read_set, ready_set;

    if (argc != 2) {
    	fprintf(stderr, "usage: %s <port>\n", argv[0]);
    	exit(0);
    }
    port = atoi(argv[1]);
    listenfd = Open_listenfd(port);  //line:conc:select:openlistenfd

    FD_ZERO(&read_set);              /* Clear read set */ //line:conc:select:clearreadset
    FD_SET(STDIN_FILENO, &read_set); /* Add stdin to read set */ //line:conc:select:addstdin
    FD_SET(listenfd, &read_set);     /* Add listenfd to read set */ //line:conc:select:addlistenfd
    FD_SET(connfd, &read_set);       //设置connfd

    while (1) {
    	ready_set = read_set;
    	Select(listenfd+1, &ready_set, NULL, NULL, NULL); //line:conc:select:select
    	if (FD_ISSET(STDIN_FILENO, &ready_set)) //line:conc:select:stdinready
    	    command(); /* Read command line from stdin */
    	if (FD_ISSET(listenfd, &ready_set)) { //line:conc:select:listenfdready
    	    connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
    	    echo(connfd);           //Echo client input until \n
            Close(connfd);
	    }    
    }
}

void echo(int connfd) 
{
    size_t n; 
    char buf[MAXLINE]; 
    rio_t rio;

    Rio_readinitb(&rio, connfd);
    if ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {     //12.22 将while循环改成if
        printf("server received %d bytes\n", (int)n);
        Rio_writen(connfd, buf, n);
    }
}

void command(void)
{
    char buf[MAXLINE];
    if (!Fgets(buf, MAXLINE, stdin))
	   exit(0); /* EOF */
    printf("%s", buf); /* Process the input command */
}
/* $end select */

