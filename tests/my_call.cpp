#include <tests/my_call.hpp>

cashflow_t my_call() {
    return (
        PAY(
            MAX(
                SPOT("undl1", "2022-05-03") / SPOT("undl1", "2021-06-03") - 1,
                0
            ),
            "2022-05-05",
            "cc1"
        )
    );
}