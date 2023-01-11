#pragma once

#include <memory>

#include "pending_task.h"

namespace rl {
struct TaskHandle {
  TaskHandle() : TaskHandle{nullptr} {}

  explicit TaskHandle(const std::shared_ptr<PendingTask>& pending_task)
      : task{pending_task} {}

  std::weak_ptr<PendingTask> task;
};
}  // namespace rl