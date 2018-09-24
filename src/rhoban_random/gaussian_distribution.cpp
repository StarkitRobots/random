#include "rhoban_random/gaussian_distribution.h"

#include <cmath>

namespace rhoban_random {

GaussianDistribution::GaussianDistribution(double mean_, double var_) : mean(mean_), var(var_) {
  
}

double GaussianDistribution::getLogLikelihood(double val) const {
  double diff = val - mean;
  double diff2 = diff * diff;
  return -0.5 * (std::log(2*M_PI) + std::log(var) + diff2 / var);
}

}
