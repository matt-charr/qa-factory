// std.
#include <vector>

// qalgebra.
#include <qalgebra>

enum StrikeType {
    _ASIAN        = 0,
    _LOOKBACK_MIN = 1,
    _LOOKBACK_MAX = 2
}; // enum StrikeType.

enum PerformanceType {
    _BASKET   = 0,
    _WORST_OF = 1,
    _BEST_OF  = 2
}; // enum PerformanceType.

typedef enum StrikeType strike_t;
typedef enum PerformanceType performance_t;

amount_t MEAN(
    const ticker_t&, // ticker.
    const std::vector<date_t>& // dates.
);
 
amount_t MAX(
    const ticker_t&, // ticker.
    const std::vector<date_t>& // dates.
);

amount_t MIN(
    const ticker_t&, // ticker.
    const std::vector<date_t>& // dates.
);

amount_t PERFORMANCE(
    const std::vector<ticker_t>&, // tickers.
    const std::vector<double>&, // weights.
    const std::vector<date_t>&, // asian-out dates.
    const std::vector<date_t>&, // asian-in dates.
    const strike_t, // strike type.
    const performance_t // performance type.
);

amount_t PERFORMANCE(
    const ticker_t&, // ticker.
    const date_t&, // start date.
    const date_t& // end date.
);

amount_t PERFORMANCE(
    const ticker_t&, // ticker.
    const std::vector<date_t>&, // asian-out dates.
    const std::vector<date_t>&, // asian-in dates.
    const strike_t // strike type.
);