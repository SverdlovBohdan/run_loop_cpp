#include "run_loop.h"

#include <gtest/gtest.h>

#include <atomic>
#include <future>

#include "priority_task_queue.h"
#include "steady_time_provider.h"
#include "task_pump_std.h"

namespace rl {
class RunLoopTest : public ::testing::Test {
 protected:
  std::shared_ptr<TaskQueue> queue_ = std::make_shared<PriorityTaskQueue>();
  std::shared_ptr<TimeProvider> time_provider_ =
      std::make_shared<SteadyTimeProvider>();
  std::shared_ptr<TaskPump> pump_ = std::make_shared<TaskPumpStd>();

  RunLoop run_loop_{pump_, queue_, time_provider_};
};

TEST_F(RunLoopTest, RunsRunLoop) {
  bool is_executed = false;
  run_loop_.PostTask([this, &is_executed]() {
    run_loop_.Stop();
    is_executed = true;
  });
  run_loop_.Run();

  ASSERT_TRUE(is_executed);
}

TEST_F(RunLoopTest, PostsRepeatingTask) {
  std::atomic<std::size_t> times{0};
  run_loop_.PostRepeatingTask(
      [this, &times]() {
        times = times + 1;
        if (times == 3) {
          run_loop_.Stop();
        }
      },
      10, IntervalMs{1000});
  run_loop_.Run();

  ASSERT_EQ(3, times.load());
}

TEST_F(RunLoopTest, PostsDelayedTask) {
  std::atomic<std::size_t> times{0};
  auto task = [this, &times]() { times = times + 1; };
  run_loop_.PostDelayedTask([this]() { run_loop_.Stop(); }, IntervalMs{1000});

  run_loop_.PostTask(task);
  run_loop_.PostTask(task);

  run_loop_.Run();
  ASSERT_EQ(2, times.load());
}

TEST_F(RunLoopTest, CancelsTask) {
  bool is_executed = false;
  run_loop_.PostDelayedTask([this]() { run_loop_.Stop(); }, IntervalMs{2000});
  auto handle = run_loop_.PostDelayedTask(
      [&is_executed]() { is_executed = true; }, IntervalMs{1000});
  run_loop_.PostDelayedTask(
      [this, &handle]() { run_loop_.CancelTask(std::move(handle)); },
      IntervalMs{500});

  run_loop_.Run();
  ASSERT_FALSE(is_executed);
}
}  // namespace rl