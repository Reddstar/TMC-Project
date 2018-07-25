#include <sys/types.h>
#ifndef _WIN32
#include <sys/select.h>
#include <sys/socket.h>
#else
#include <winsock2.h>
#endif
#include <string.h>
#include <microhttpd.h>
#include <stdio.h>
#include <stdlib.h>
#include "project_c/_main.h"

#define PORT 8082

static int answer_to_connection (void *cls, struct MHD_Connection *connection,
                      const char *url, const char *method,
                      const char *version, const char *upload_data,
                      size_t *upload_data_size, void **con_cls)
{
	struct MHD_response *response;
	char res = malloc( 1000 );
	
	strcat(res, "This is a response");

	response = MHD_create_response_from_buffer (strlen(res), (void *) res, MHD_RESPMEM_PERSISTENT);
	
	int ret = MHD_queue_response (connection, MHD_HTTP_OK, response);
	MHD_destroy_response (response);

	return ret;
}

int main() {
	struct MHD_Daemon *daemon;

	daemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL, &answer_to_connection, NULL, MHD_OPTION_END);

	if (daemon == NULL) {
		return 1;
	}
	
	(void) getchar();

	MHD_stop_daemon (daemon);
	return 0;
}