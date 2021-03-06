/*
 Copyright (c) 2016 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include <gimxpoll/include/gpoll.h>
#include <gimxtimer/include/gtimer.h>
#include <gimxprio/include/gprio.h>

#include <gimxcommon/test/common.h>
#include <gimxcommon/test/handlers.c>
#include <gimxcommon/test/timer.c>

static unsigned int samples = 0;

static int slices[] = { 10, 25, 50, 100, 200 };

struct timer_test {
    unsigned int usec;
    struct gtimer * timer;
    unsigned long long int next;
    unsigned int sum;
    unsigned int count;
    unsigned int slices[sizeof(slices) / sizeof(*slices) + 1];
};

#define ADD_TEST(PERIOD) { PERIOD, NULL, 0, 0, 0, {} },

static struct timer_test timers[] = {
    ADD_TEST(1000)
    ADD_TEST(2000)
    ADD_TEST(3000)
    ADD_TEST(4000)
    ADD_TEST(5000)
    ADD_TEST(6000)
    ADD_TEST(7000)
    ADD_TEST(8000)
    ADD_TEST(9000)
    ADD_TEST(10000)
};

static void usage() {
  fprintf(stderr, "Usage: ./gtimer_test [-n samples]\n");
  exit(EXIT_FAILURE);
}

/*
 * Reads command-line arguments.
 */
static int read_args(int argc, char* argv[]) {

  int opt;
  while ((opt = getopt(argc, argv, "n:")) != -1) {
    switch (opt) {
    case 'n':
      samples = atoi(optarg);
      break;
    default: /* '?' */
      usage();
      break;
    }
  }
  return 0;
}

static int timer_close_callback(void * user __attribute__((unused))) {
  set_done();
  return 1;
}

static inline void process(struct timer_test * timer, long long int diff) {

  int percent = diff * 100 / timer->usec;

  unsigned int i;
  for (i = 0; i < sizeof(slices) / sizeof(*slices); ++i) {
      if (percent <= slices[i]) {
          break;
      }
  }
  timer->slices[i]++;

  timer->sum += diff;
  ++timer->count;

  if (timer == (timers + sizeof(timers) / sizeof(*timers) - 1) && timer->count == samples) {
    set_done();
  }
}

static int timer_read_callback(void * user) {

  struct timer_test * timer = (struct timer_test *) user;

  long long int diff = get_time() - timer->next;

  // Tolerate early firing:
  // - the delay between the timer firing and the process scheduling may vary
  // - on Windows the timer period is rounded to the highest multiple of the timer resolution not higher than the timer period.

  diff = abs(diff);

  process(user, abs(diff));

#ifdef WIN32
  timer->next = get_time() + timer->usec;
#else
  do {
    timer->next += timer->usec;
  } while (timer->next <= get_time());
#endif

  return 1; // Returning a non-zero value makes gpoll return, allowing to check the 'done' variable.
}

int main(int argc, char* argv[]) {

  setup_handlers();

  read_args(argc, argv);

  gprio();

  unsigned int i;
  for (i = 0; i < sizeof(timers) / sizeof(*timers); ++i) {

    GTIMER_CALLBACKS timer_callbacks = {
            .fp_read = timer_read_callback,
            .fp_close = timer_close_callback,
            .fp_register = REGISTER_FUNCTION,
            .fp_remove = REMOVE_FUNCTION,
    };
    timers[i].timer = gtimer_start(timers + i, timers[i].usec, &timer_callbacks);
    if (timers[i].timer < 0) {
      set_done();
      break;
    }

    timers[i].next = get_time() + timers[i].usec;
  }

  while(!is_done()) {
    gpoll();
  }

  for (i = 0; i < sizeof(timers) / sizeof(*timers); ++i) {
    gtimer_close(timers[i].timer);
  }

  fprintf(stderr, "Exiting\n");

  printf("timer\tperiod\tcount\tdiff");

  unsigned int j;
  for (j = 0; j < sizeof(slices) / sizeof(*slices); ++j) {
    if (j == 0) {
      printf("\t0-%d", slices[j]);
    } else {
      printf("\t%d-%d", slices[j - 1], slices[j]);
    }
  }
  printf("\t>%d\n", slices[j - 1]);

  for (i = 0; i < sizeof(timers) / sizeof(*timers); ++i) {
    printf("%d\t%uus\t%u\t%u%%", i, timers[i].usec, timers[i].count, timers[i].sum / timers[i].count * 100 / timers[i].usec);
    for (j = 0; j < sizeof(timers[i].slices) / sizeof(*timers[i].slices); ++j) {
      printf("\t%d", timers[i].slices[j]);
    }
    printf("\n");
  }

  return 0;
}
