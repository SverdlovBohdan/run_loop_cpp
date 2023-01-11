#include "priority_task_queue.h"

#include <gtest/gtest.h>

#include <memory>

#include "pending_task.h"

namespace rl {
class PriorityTaskQueueTest : public ::testing::Test {
 protected:
  PriorityTaskQueue queue_;
  std::shared_ptr<PendingTask> task_ = std::make_shared<PendingTask>();
};

TEST_F(PriorityTaskQueueTest, AddsTask) {
  const auto handler = queue_.AddTask(task_);
  ASSERT_EQ(handler.task.lock().get(), task_.get());
}

TEST_F(PriorityTaskQueueTest, CanTellIfEmpty) {
  ASSERT_TRUE(queue_.IsEmpty());
  const auto handler = queue_.AddTask(task_);
  ASSERT_FALSE(queue_.IsEmpty());
}

TEST_F(PriorityTaskQueueTest, PopsTask) {
  const auto handler = queue_.AddTask(task_);
  auto task = queue_.PopTask();
  ASSERT_EQ(task.get(), task_.get());
}

TEST_F(PriorityTaskQueueTest, GetsNextTaskCallTime) {
  queue_.AddTask(std::make_shared<PendingTask>([]() {}, TimestampMs{100}));
  queue_.AddTask(std::make_shared<PendingTask>([]() {}, TimestampMs{10}));
  queue_.AddTask(std::make_shared<PendingTask>([]() {}, TimestampMs{50}));

  ASSERT_EQ(TimestampMs{10}, queue_.GetNextTaskCallTime());
  queue_.PopTask();
  ASSERT_EQ(TimestampMs{50}, queue_.GetNextTaskCallTime());
  queue_.PopTask();
  ASSERT_EQ(TimestampMs{100}, queue_.GetNextTaskCallTime());
}
}  // namespace rl