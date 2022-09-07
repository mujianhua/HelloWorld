#include <chrono>
#include <iostream>
#include <list>
#include <mutex>
#include <thread>

std::list<int> test_list;

std::mutex mutex_;

void in_list() {
  for (int num = 0; num < 100; num++) {
    std::unique_lock<std::mutex> my_unique(mutex_, std::try_to_lock);
    if (my_unique.owns_lock()) {
      std::cout << "insert: " << num << '\n';
      test_list.push_back(num);
    } else {
      std::cout << "...\n ";
    }
  }
}

void out_list() {
  for (int i = 0; i < 100; i++) {
    std::unique_lock<std::mutex> my_unique(mutex_);
    std::chrono::seconds dura(1);
    std::this_thread::sleep_for(dura);
    if (!test_list.empty()) {
      std::cout << "pop: " << test_list.front() << '\n';
      test_list.pop_front();
    } else {
      std::cout << "empty\n";
    }
  }
}

int main() {
  std::thread in_thread(in_list);
  std::thread out_thread(out_list);

  in_thread.join();
  out_thread.join();
  return 0;
}
