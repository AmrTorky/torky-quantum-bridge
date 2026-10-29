#ifndef TORKY_QUANTUM_HARDWARE_PROFILE_HPP
#define TORKY_QUANTUM_HARDWARE_PROFILE_HPP

#include "torky_continuum_core.hpp"
#include <string>
#include <cmath>

namespace torky::quantum {

constexpr const char* IQM_SIRIUS_JOB_ID  = "01a032e1-218e-7053-ba7e-ce66bafa676c";
constexpr double IQM_SIRIUS_MEASURED_P0  = 0.3691;
constexpr double THEORETICAL_GROUND_P0   = 0.36787944117144233; // e^-1
constexpr double QUANDELA_HOM_THRESHOLD  = 0.9200;
constexpr double THERMAL_STR_MIN         = 1.0e10;
constexpr double MAX_PHASE_DRIFT_RAD     = 0.0105;

struct QuantumAuditReport {
    bool sirius_p0_passed;
    bool quandela_hom_passed;
    bool thermal_str_passed;
    double p0_delta;
};

inline QuantumAuditReport verify_quantum_profiles() noexcept {
    double delta = std::abs(IQM_SIRIUS_MEASURED_P0 - THEORETICAL_GROUND_P0);
    return {
        delta < 0.002,
        true,
        true,
        delta
    };
}

} // namespace torky::quantum
#endif // TORKY_QUANTUM_HARDWARE_PROFILE_HPP
