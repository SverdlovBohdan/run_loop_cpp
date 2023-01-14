#include "task_pump_std.h"

#include <gmock/gmock.h>

namespace rl_cpp {
using ::testing::_;

class TestTaskPumpStd : public TaskPumpStd {
 public:
  MOCK_METHOD(void, Wait, (std::unique_lock<std::mutex> & lock), (override));
  MOCK_METHOD(void, WaitUntilTime,
              (std::unique_lock<std::mutex> & lock, TimestampMs time),
              (override));
  MOCK_METHOD(void, NotifyAll, (), (override));
};

class TaskPumpStdTest : public ::testing::Test {
 protected:
  TestTaskPumpStd pump_;
};

TEST_F(TaskPumpStdTest, WaitsUntil) {
  EXPECT_CALL(pump_, WaitUntilTime(_, TimestampMs{0}));
  pump_.WaitUntil(TimestampMs{0});
}

TEST_F(TaskPumpStdTest, WaitsUntilForever) {
  EXPECT_CALL(pump_, Wait(_));
  pump_.WaitUntil(TimestampMs::max());
}

TEST_F(TaskPumpStdTest, NotifiesClient) {
  EXPECT_CALL(pump_, NotifyAll());
  pump_.Notify();
}
}  // namespace rl_cpp