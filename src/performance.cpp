// std.
#include <vector>
#include <stdexcept>

// qalgebra.
#include <qalgebra>

// include.
#include <performance.hpp>

amount_t MEAN(
    const ticker_t& p_ticker,
    const std::vector<date_t>& p_dates
) {
    amount_t mean(CST(0.));
    const size_t c_nb_dates(p_dates.size());
    for(size_t date_index(0); date_index < c_nb_dates; date_index++) {
        mean = mean + SPOT(p_ticker, p_dates[date_index]);
    }
    mean = mean / c_nb_dates;
    return mean;
}
 
amount_t MAX(
    const ticker_t& p_ticker,
    const std::vector<date_t>& p_dates
) {
    amount_t max = CST(0.);
    const size_t c_nb_dates(p_dates.size());
    for (size_t date_index(0); date_index < c_nb_dates; date_index++) {
        max = date_index == 0 ? SPOT(p_ticker, p_dates[date_index]) : MAX(max, SPOT(p_ticker, p_dates[date_index]));
    }
    return max;
}

amount_t MIN(
    const ticker_t& p_ticker,
    const std::vector<date_t>& p_dates
) {
    amount_t min(CST(0.));
    const size_t c_nb_dates(p_dates.size());
    for (size_t date_index(0); date_index < c_nb_dates; date_index++) {
        min = date_index == 0 ? SPOT(p_ticker, p_dates[date_index]) : MIN(min, SPOT(p_ticker, p_dates[date_index]));
    }
    return min;
}

amount_t PERFORMANCE(
    const std::vector<ticker_t>& p_tickers,
    const std::vector<double>& p_weights,
    const std::vector<date_t>& p_asian_out_dates,
    const std::vector<date_t>& p_asian_in_dates,
    const strike_t p_strike_type,
    const performance_t p_performance_type
) {
    amount_t performance(CST(0.));
    const size_t c_nb_tickers(p_tickers.size());
    for (size_t ticker_index = 0; ticker_index < c_nb_tickers; ticker_index++) {
        switch (p_performance_type) {
        case PerformanceType::_BASKET:
            performance = performance + p_weights[ticker_index] * PERFORMANCE(p_tickers[ticker_index], p_asian_out_dates, p_asian_in_dates, p_strike_type);
            break;
        case PerformanceType::_WORST_OF:
            performance = ticker_index == 0 ? PERFORMANCE(p_tickers[ticker_index], p_asian_out_dates, p_asian_in_dates, p_strike_type) : MIN(performance, PERFORMANCE(p_tickers[ticker_index], p_asian_out_dates, p_asian_in_dates, p_strike_type));
            break;
        case PerformanceType::_BEST_OF:
            performance = ticker_index == 0 ? PERFORMANCE(p_tickers[ticker_index], p_asian_out_dates, p_asian_in_dates, p_strike_type) : MAX(performance, PERFORMANCE(p_tickers[ticker_index], p_asian_out_dates, p_asian_in_dates, p_strike_type));
            break;
        default:
            throw std::runtime_error("Unknown performance type");
        }
    }
    return performance;
}

amount_t PERFORMANCE(
    const ticker_t& p_ticker,
    const date_t& p_start_date, 
    const date_t& p_end_date
) {
    return (
        SPOT(p_ticker, p_end_date) / SPOT(p_ticker, p_start_date)
    );
}

amount_t PERFORMANCE(
    const ticker_t& p_ticker,
    const std::vector<date_t>& p_asian_out_dates,
    const std::vector<date_t>& p_asian_in_dates,
    const strike_t p_strike_type
) {
    switch (p_strike_type) {
    case StrikeType::_ASIAN:
        return MEAN(p_ticker, p_asian_out_dates) / MEAN(p_ticker, p_asian_in_dates);
    case StrikeType::_LOOKBACK_MIN:
        return MEAN(p_ticker, p_asian_out_dates) / MIN(p_ticker, p_asian_in_dates);
    case StrikeType::_LOOKBACK_MAX:
        return MEAN(p_ticker, p_asian_out_dates) / MAX(p_ticker, p_asian_in_dates);
    default:
        throw std::runtime_error("Unknown strike type");
    }
}