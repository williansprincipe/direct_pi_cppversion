// direct_pi.cpp
// calculates pi with direct sampling
// wpfernandes 20160721_08h32min
//

#include "direct_pi.h"
#include <iostream>
#include <random>
#include <cmath>

double direct_pi(int n)
{ int n_hits = 0;
  int& n_trials = n;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, 1);
  std::cout << "n_trials = " << n_trials << "\n";
  double x, y, r;
  for (int i_trials = 0; i_trials < n_trials; ++i_trials)
  { x = dis(gen);
    y = dis(gen);
    r = std::hypot(x,y);
    std::cout << "i_trials = " << i_trials 
              << ", generated random values = (" << x << ", " << y << ")"
              << ", radius = " << r << ".\n";
    if (r < 1.0)
    { ++n_hits;
    }
  }
  return 4.0 * static_cast<double>(n_hits) / static_cast<double>(n_trials);
}
// end of file direct_pi.cpp
