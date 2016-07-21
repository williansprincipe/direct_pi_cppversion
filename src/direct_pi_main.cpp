// direct_pi_main.cpp
// just the main to call the direct_pi function
// wpfernandes 20160721_08h45min
//

#include <iostream>
#include <string>
#include <stdexcept>
#include "direct_pi.h"

int main(int argc, char* argv[])
{ 
  if (argc != 2)
  { std::cout << "direct_pi (written in cpp) -- version 2016-07-21 08h52min\n";
    std::cout << "Estimative for pi by Direct Sampling Monte Carlo method.\n";
    std::cout << "Usage:\n";
    std::cout << "  direct_pi <n_trials>\n\n";
    return -1;
  }
  int n_trials;
  std::string string_n_trials = argv[1];
  try
  { if (string_n_trials.find_first_not_of("0123456789") != std::string::npos)
      { std::string msg = "Only digits (0, 1, 2, 3, 4, 5, 6, 7, 8 or 9) are allowed.";
        throw std::invalid_argument(msg);
      }
    n_trials = std::stoi(string_n_trials);
  }
  catch(const std::invalid_argument& e)
  { std::cout << "Invalid argument \"" << string_n_trials << "\".\n";
    std::string msg = e.what();
    if (msg == "stoi") // this branch of the if should never occur.
    { std::cout << "Argument could not be converted from string to integer.\n";
    }
    else
    { std::cout << msg << "\n";
    }
    return -2;
  }
  catch(const std::out_of_range& e)
  { std::cout << "Sorry man, this is to much to process. Try a small number.\n";
    return -2;
  }
  double pi=direct_pi(n_trials);
  std::cout << "Pi estimative with " << n_trials << " trials: " << pi << ".\n\n";
  return 0;
}
