#include <stdio.h>
#include <stdlib.h>
#include <event2/event.h>
#include <sys/signal.h>


#define evsignal_new(base, signum, cb, arg) \
			       event_new(base, signum, EV_SIGNAL|EV_PERSIST, cb, arg)

void signal_cb(int fd, short event, void* arg)
{
	struct event_base* base = (struct event_base*)arg;
	printf("get a event interrupt signal\n");
	event_base_loopexit(base, NULL);
}

int main()
{
	// init event base
	struct event_config *ev_config;
	ev_config = event_config_new();
	event_config_set_flag(ev_config, EVENT_BASE_FLAG_NOLOCK);
	struct event_base* base = event_base_new_with_config(ev_config);
	event_config_free(ev_config);

	struct event* signal_event = evsignal_new(base, SIGINT, signal_cb, base);
	event_add(signal_event, NULL);
	event_base_dispatch(base);
	
	event_free(signal_event);
	event_base_free(base);
	return 0;	
}
