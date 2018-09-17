/*
 * lat_mem_rd.h - measure memory load latency
 * based on lat_mem_rd.c
 *
 * Copyright (c) 1994 Larry McVoy.  
 * Copyright (c) 2003, 2004 Carl Staelin.
 *
 * Distributed under the FSF GPL with additional restriction that results 
 * may published only if:
 * (1) the benchmark is unmodified, and
 * (2) the version in the sccsid below is included in the report.
 * Support for this development by Sun Microsystems is gratefully acknowledged.
 */

#define	ONE	p=(char **)*p;
#define	FIVE	ONE ONE ONE ONE ONE
#define	TEN	FIVE FIVE
#define	FIFTY	TEN TEN TEN TEN TEN
#define	HUNDRED	FIFTY FIFTY

benchmp_f fpInit = stride_initialize;

static void
benchmark_loads(iter_t iterations, void *cookie)
{
  struct mem_state* state = (struct mem_state*)cookie;
  register char **p = (char**)state->p[0];
  register size_t i;
  register size_t count = state->len / (state->line * 100) + 1;
  
  while (iterations-- > 0) {
    for (i = 0; i < count; ++i) {
      HUNDRED;
    }
  }
  
  use_pointer((void *)p);
  state->p[0] = (char*)p;
}

static float 
compute_latency (size_t len, long stride, int warmup, int repetitions)
{
  float latency = 0.0;
  size_t count;
  struct mem_state state;
  
  state.width = 1;
  state.len = len;
  state.maxlen = len;
  state.line = stride;
  state.pagesize = getpagesize();
  count = 100 * (state.len / (state.line * 100) + 1);
  
  /*
   * Now walk them and time it.
   */
  benchmp (fpInit, benchmark_loads, mem_cleanup, 100000, 1, warmup, repetitions, &state);
  
  /* We want to get to nanoseconds / load. */
  save_minimum();
  latency = (1000. * (double)gettime()) / (double)(count * get_n());

  return latency;
}


