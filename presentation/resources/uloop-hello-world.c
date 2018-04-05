#include <libubox/uloop.h>

static struct uloop_timeout my_event_timer;

static void my_event_handler(struct uloop_timeout *timeout)
{
    // if we want to make a repeatable event, set the timer again by calling uloop_timeout_set()
}

static void set_event(void)
{
    // configure function which will be called when timer is expired
    my_event_timer.cb = my_event_handler;
    // schedule a timer which will timeout in one second from now
    uloop_timeout_set(&my_event_timer, 1000);
}

int main(void)
{
    // initialize uloop, must be called before uloop_run()
    uloop_init();
    // add a one-shot timer task
    set_event();
    // start main event loop, which is a blocking operation and will run continuously until we set the global variable uloop_cancelled to true
    uloop_run();
    // cleanup resources used by uloop
    uloop_done();

    return 0;
}
