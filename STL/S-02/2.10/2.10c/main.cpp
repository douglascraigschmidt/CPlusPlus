#include <string>
#include <iostream>
#include <thread>

#include "semaphore.h"

/**
 * Forward declaration.
 */
static void
play_pingpong (size_t max_iterations,
               const std::string &string_to_print,
               semaphore &my_semaphore,
               semaphore &other_semaphore);

/**
 * Number of threads to create.
 */
static const int num_threads = 2;

/**
 * Number of iterations for each thread to play ping/pong.
 */
static const size_t max_iterations = 4;

/**
 * This example shows the use of C++ variadic templates in the context
 * of passing a method and its parameters to the std::thread class.
 */
int 
main (int argc, char *argv[]) {
  std::thread threads[num_threads];
  std::cout << "Ready...Set...Go!" << std::endl;

  // Create the ping and pong semaphores that control alternation
  // between threads.
  semaphore ping_semaphore(1); // Starts unlocked
  semaphore pong_semaphore(0); // Starts locked

  // Create the ping thread, using a variadic template.
  threads[0] = std::thread(play_pingpong,
                           max_iterations,
                           "Ping!",
                           std::ref (ping_semaphore),
                           std::ref (pong_semaphore));

  // Create the pong thread, using a variadic template.
  threads[1] = std::thread(play_pingpong,
                           max_iterations,
                           "Pong!",
                           std::ref (pong_semaphore),
                           std::ref (ping_semaphore));

  // Barrier synchronization to join the ping and pong threads with
  // the main thread.
  for (auto &t : threads)
    t.join ();

  std::cout << "Done!" << std::endl;
  return 0;
}

/**
 * Run the ping/pong algorithm.
 */
static void
play_pingpong (size_t max_iterations,
               const std::string &string_to_print,
               semaphore &my_semaphore,
               semaphore &other_semaphore) {
  for (int loops_done = 1; loops_done <= max_iterations; ++loops_done) {
      my_semaphore.acquire();
      // Print the message.
      std::cout << string_to_print << "(" << loops_done << ")" << std::endl;
      other_semaphore.release();
  }
}

