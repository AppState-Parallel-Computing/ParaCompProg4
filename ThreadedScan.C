#include <vector>
#include <math.h>
#include <chrono>
#include "helpers.h"
#include "ThreadPool.h"
#include "ThreadedScan.h"

/*
 * ThreadedScan
 * Initializes the private data members of the ThreadedScan object.
 */ 
ThreadedScan::ThreadedScan(std::vector<int> nums, uint64_t numThreads, 
                           uint64_t subarraySize)
{
  this->numThreads = numThreads;
  this->subarraySize = subarraySize;
  //Use std::move to prevent another copy of nums being made.
  //Moves the nums resources to this->nums.
  this->nums = std::move(nums);
  this->pool = new ThreadPool(numThreads);
  this->activeThreads = 0;
}

/*
 * performScan
 * This function performs the parallel prefix scan that is
 * described in the textbook on pages 25 and 26 (Listing 2.2).
 * It uses the ThreadPool implementation to complete the
 * various tasks.
 *
 * You should write some helper lambda functions.
 */
float ThreadedScan::performScan()
{ 

  TIMERSTART(threaded)

  //Step 1:
  //Create the tasks to be performed and add them to the thread
  //pool using the enqueue function.
  //Ignore the future object returned by enqueue since it isn't needed


  //wait for the number of tasks to be completed becomes 0
  //You'll need to implement this function in the ThreadPool class.
  pool->waitForZeroTasks();

  //Step 2:
  //Main thread performs prefix scan of right most values in each subarray
  
  //Step 3:
  //Create the tasks to be performed so that each tasks adds the value computed by 
  //task i - 1 in the last step to each element of subarray i and
  //add each task to the thread pool.

  //wait for the number of tasks to be completed becomes 0
  pool->waitForZeroTasks();

  TIMERSTOP(threaded)

  delete pool;

  return GETTIME(threaded);
}

/*
 * get
 * Returns a reference to the private vector.
 */
std::vector<int> & ThreadedScan::get()
{
  return nums;
}

