#include <tests/my_call.hpp>

int main() {
    return (
        CONTRACT(
            "call.json",
            my_call()
        )
    );
}