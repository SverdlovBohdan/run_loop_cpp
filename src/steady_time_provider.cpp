#include "steady_time_provider.h"

namespace rl_cpp {
TimestampMs SteadyTimeProvider::Now() const {
  return std::chrono::duration_cast<TimestampMs>(
      std::chrono::steady_clock::now().time_since_epoch());
}
}  // namespace rl_cpp