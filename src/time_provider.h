#pragma once

#include "time_types.h"

namespace rl_cpp {
/**
 * @brief Provides now timestamp
 *
 */
class TimeProvider {
 public:
  virtual ~TimeProvider() = default;

  /**
   * @brief Provides now timestamp.
   *
   * @return Now timestamp.
   */
  virtual TimestampMs Now() const = 0;
};
}  // namespace rl_cpp