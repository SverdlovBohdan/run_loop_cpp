#pragma once

#include "time_provider.h"

namespace rl_cpp {
/**
 * @brief Uses steady time.
 *
 */
class SteadyTimeProvider : public TimeProvider {
 public:
  /** @see TimeProvider. */
  TimestampMs Now() const override;
};
}  // namespace rl_cpp