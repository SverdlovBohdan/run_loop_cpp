#pragma once

#include "time_provider.h"

namespace rl {
/**
 * @brief Uses steady time.
 *
 */
class SteadyTimeProvider : public TimeProvider {
 public:
  /** @see TimeProvider. */
  TimestampMs Now() const override;
};
}  // namespace rl