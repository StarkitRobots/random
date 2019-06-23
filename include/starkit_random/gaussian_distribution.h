#pragma once

namespace starkit_random
{
class GaussianDistribution
{
public:
  GaussianDistribution(double mean, double var);

  /// Return the loglikelihood of given value according to distribution
  double getLogLikelihood(double value) const;

private:
  double mean;
  double var;
};

}  // namespace starkit_random
